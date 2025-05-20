//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define SERVER_MSG_QUEUE_KEY 0x01234567
#define CLIENT_MSG_QUEUE_KEY 0x76543210
#define MAX_FILE_NAME_SIZE 256

typedef struct {
  long mtype;
  char filename[MAX_FILE_NAME_SIZE];
} file_backup_message_t;

int main(int argc, char **argv) {

  // Check if the user provided a filename as an argument
  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Generate IPC message keys for communication
  key_t server_msg_queue_key = ftok(".", SERVER_MSG_QUEUE_KEY);
  if (server_msg_queue_key == -1) {
    perror("ftok() failed");
    return EXIT_FAILURE;
  }

  key_t client_msg_queue_key = ftok(".", CLIENT_MSG_QUEUE_KEY);
  if (client_msg_queue_key == -1) {
    perror("ftok() failed");
    return EXIT_FAILURE;
  }

  // Create a client message queue
  int client_msg_queue_id = msgget(client_msg_queue_key, IPC_CREAT | IPC_EXCL | 0600);
  if (client_msg_queue_id == -1) {
    if (errno == EEXIST) {
      // Client message queue already exists, connect to it
      client_msg_queue_id = msgget(client_msg_queue_key, 0);
      if (client_msg_queue_id == -1) {
        perror("msgget() failed");
        return EXIT_FAILURE;
      }
    } else {
      perror("msgget() failed");
      return EXIT_FAILURE;
    }
  }

  // Open the server message queue
  int server_msg_queue_id = msgget(server_msg_queue_key, 0);
  if (server_msg_queue_id == -1) {
    perror("msgget() failed");
    return EXIT_FAILURE;
  }

  // Read the file specified by the user
  char buffer[4096];
  int file_fd = open(argv[1], O_RDONLY);
  if (file_fd == -1) {
    perror("open() failed");
    return EXIT_FAILURE;
  }

  size_t bytes_read;
  while ((bytes_read = read(file_fd, buffer, sizeof(buffer))) > 0) {
    // Send the filename and file data to the backup server
    file_backup_message_t msg;
    msg.mtype = 1;
    strncpy(msg.filename, argv[1], MAX_FILE_NAME_SIZE);
    if (msgsnd(server_msg_queue_id, &msg, sizeof(msg.filename), 0) == -1) {
      perror("msgsnd() failed");
      return EXIT_FAILURE;
    }

    if (msgsnd(server_msg_queue_id, buffer, bytes_read, 0) == -1) {
      perror("msgsnd() failed");
      return EXIT_FAILURE;
    }
  }

  if (bytes_read == -1) {
    perror("read() failed");
    return EXIT_FAILURE;
  }

  // Close the file and message queues
  close(file_fd);
  msgctl(client_msg_queue_id, IPC_RMID, NULL);
  msgctl(server_msg_queue_id, IPC_RMID, NULL);

  return EXIT_SUCCESS;
}