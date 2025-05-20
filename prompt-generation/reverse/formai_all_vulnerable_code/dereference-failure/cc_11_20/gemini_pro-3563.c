//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <source directory> <destination directory>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Get the source and destination directories
  char *source_dir = argv[1];
  char *destination_dir = argv[2];

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Bind the socket to an address
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(5000);

  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("bind");
    return EXIT_FAILURE;
  }

  // Listen for connections
  if (listen(sockfd, 5) == -1) {
    perror("listen");
    return EXIT_FAILURE;
  }

  // Accept a connection
  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
  if (client_sockfd == -1) {
    perror("accept");
    return EXIT_FAILURE;
  }

  // Send the source and destination directories to the client
  int source_dir_len = strlen(source_dir);
  if (send(client_sockfd, &source_dir_len, sizeof(int), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }
  if (send(client_sockfd, source_dir, source_dir_len, 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }
  int destination_dir_len = strlen(destination_dir);
  if (send(client_sockfd, &destination_dir_len, sizeof(int), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }
  if (send(client_sockfd, destination_dir, destination_dir_len, 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the files from the client
  int num_files;
  if (recv(client_sockfd, &num_files, sizeof(int), 0) == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  for (int i = 0; i < num_files; i++) {
    // Receive the file name
    int file_name_len;
    if (recv(client_sockfd, &file_name_len, sizeof(int), 0) == -1) {
      perror("recv");
      return EXIT_FAILURE;
    }
    char *file_name = malloc(file_name_len + 1);
    if (recv(client_sockfd, file_name, file_name_len, 0) == -1) {
      perror("recv");
      return EXIT_FAILURE;
    }
    file_name[file_name_len] = '\0';

    // Receive the file size
    int file_size;
    if (recv(client_sockfd, &file_size, sizeof(int), 0) == -1) {
      perror("recv");
      return EXIT_FAILURE;
    }

    // Open the file
    int fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
      perror("open");
      return EXIT_FAILURE;
    }

    // Receive the file data
    char buf[BUF_SIZE];
    int bytes_received = 0;
    while (bytes_received < file_size) {
      int bytes_to_read = BUF_SIZE;
      if (bytes_to_read > file_size - bytes_received) {
        bytes_to_read = file_size - bytes_received;
      }
      int bytes_read = recv(client_sockfd, buf, bytes_to_read, 0);
      if (bytes_read == -1) {
        perror("recv");
        return EXIT_FAILURE;
      }
      bytes_received += bytes_read;
      if (write(fd, buf, bytes_read) == -1) {
        perror("write");
        return EXIT_FAILURE;
      }
    }

    // Close the file
    close(fd);

    // Free the file name
    free(file_name);
  }

  // Close the client socket
  close(client_sockfd);

  // Close the server socket
  close(sockfd);

  return EXIT_SUCCESS;
}