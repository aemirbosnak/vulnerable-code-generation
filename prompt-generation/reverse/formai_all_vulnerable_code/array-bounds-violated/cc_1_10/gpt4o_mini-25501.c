//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <mqueue.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define QUEUE_NAME "/example_queue"
#define MAX_SIZE 1024
#define MSG_STOP "exit"

// Function to handle error messages
void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Sender function
void sender() {
    mqd_t mq;
    char buffer[MAX_SIZE];

    // Create a message queue
    mq = mq_open(QUEUE_NAME, O_CREAT | O_WRONLY, 0644, NULL);
    if (mq == (mqd_t) -1) {
        handle_error("Sender: mq_open");
    }

    printf("Sender: Starting to send messages. Type 'exit' to stop.\n");

    while (1) {
        // Read input from user
        printf("Sender: Enter message: ");
        fgets(buffer, MAX_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character

        // Send message to the queue
        if (mq_send(mq, buffer, strlen(buffer), 0) == -1) {
            handle_error("Sender: mq_send");
        }

        // Stop if the message is "exit"
        if (strcmp(buffer, MSG_STOP) == 0) {
            break;
        }
    }

    // Clean up
    mq_close(mq);
    mq_unlink(QUEUE_NAME);
    printf("Sender: Stopped sending messages.\n");
}

// Receiver function
void receiver() {
    mqd_t mq;
    char buffer[MAX_SIZE];
    ssize_t bytes_read;

    // Open the existing message queue
    mq = mq_open(QUEUE_NAME, O_RDONLY);
    if (mq == (mqd_t) -1) {
        handle_error("Receiver: mq_open");
    }

    printf("Receiver: Waiting for messages...\n");

    while (1) {
        // Receive message from the queue
        bytes_read = mq_receive(mq, buffer, MAX_SIZE, NULL);
        if (bytes_read == -1) {
            handle_error("Receiver: mq_receive");
        }

        // Null-terminate and print the received message
        buffer[bytes_read] = '\0';
        printf("Receiver: Received: %s\n", buffer);

        // Stop if the message is "exit"
        if (strcmp(buffer, MSG_STOP) == 0) {
            break;
        }
    }

    // Clean up
    mq_close(mq);
    printf("Receiver: Stopped receiving messages.\n");
}

// Main function
int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        handle_error("Fork failed");
    }

    // If pid is zero, this is the child process (Receiver)
    if (pid == 0) {
        receiver();
    } 
    // Otherwise, this is the parent process (Sender)
    else {
        sender();
    }

    return 0;
}