//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int size;
} message_t;

void send_message(int fd, message_t *message) {
    int bytes_sent = 0;
    while (bytes_sent < message->size) {
        int bytes_to_send = message->size - bytes_sent;
        int bytes_written = write(fd, message->data + bytes_sent, bytes_to_send);
        if (bytes_written == -1) {
            printf("Error writing to pipe: %s\n", strerror(errno));
            exit(1);
        }
        bytes_sent += bytes_written;
    }
}

void receive_message(int fd, message_t *message) {
    int bytes_received = 0;
    while (bytes_received < message->size) {
        int bytes_to_read = message->size - bytes_received;
        int bytes_read = read(fd, message->data + bytes_received, bytes_to_read);
        if (bytes_read == -1) {
            printf("Error reading from pipe: %s\n", strerror(errno));
            exit(1);
        }
        bytes_received += bytes_read;
    }
}

int main() {
    int fd[2];
    if (pipe(fd) == -1) {
        printf("Error creating pipe: %s\n", strerror(errno));
        exit(1);
    }

    message_t message1 = { "Hello, World!", strlen("Hello, World!") };
    message_t message2 = { "Interprocess communication is fun!", strlen("Interprocess communication is fun!") };

    pid_t child_pid = fork();
    if (child_pid == -1) {
        printf("Error forking: %s\n", strerror(errno));
        exit(1);
    } else if (child_pid == 0) {
        // Child process
        close(fd[0]);
        send_message(fd[1], &message1);
        send_message(fd[1], &message2);
        close(fd[1]);
        exit(0);
    } else {
        // Parent process
        close(fd[1]);
        message_t received_message1;
        message_t received_message2;
        receive_message(fd[0], &received_message1);
        receive_message(fd[0], &received_message2);
        printf("Received message 1: %s\n", received_message1.data);
        printf("Received message 2: %s\n", received_message2.data);
        close(fd[0]);
        exit(0);
    }

    return 0;
}