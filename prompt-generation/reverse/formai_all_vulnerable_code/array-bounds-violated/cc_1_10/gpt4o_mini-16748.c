//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <mqueue.h>
#include <fcntl.h>

#define QUEUE_NAME "/my_message_queue"
#define MAX_SIZE 256
#define MSG_STOP "exit"

void handle_exit(int sig) {
    mq_unlink(QUEUE_NAME);
    exit(0);
}

int main() {
    struct sigaction action;
    action.sa_handler = handle_exit;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);

    mqd_t mq;
    char buffer[MAX_SIZE];

    // Creating a message queue
    mq = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0644, NULL);
    if (mq == (mqd_t)-1) {
        perror("Message queue creation failed");
        exit(EXIT_FAILURE);
    }

    if (fork() == 0) {
        // Child process: Receiver
        while (1) {
            ssize_t bytes_read;
            bytes_read = mq_receive(mq, buffer, MAX_SIZE, NULL);
            if (bytes_read >= 0) {
                buffer[bytes_read] = '\0'; // Null-terminate the string
                printf("Received: %s\n", buffer);
                if (strcmp(buffer, MSG_STOP) == 0)
                    break; // Exit on receiving "exit"
            } else {
                perror("mq_receive error");
            }
        }
        mq_close(mq);
        exit(0);
    } else {
        // Parent process: Sender
        char input[MAX_SIZE];
        printf("Type messages to send, type 'exit' to quit:\n");
        while (1) {
            printf("Send message: ");
            if (fgets(input, sizeof(input), stdin) == NULL) {
                perror("fgets error");
                continue;
            }
            input[strcspn(input, "\n")] = 0; // Remove newline

            if (mq_send(mq, input, strlen(input) + 1, 0) == -1) {
                perror("mq_send error");
            }

            if (strcmp(input, MSG_STOP) == 0) {
                break; // Exit on sending "exit"
            }
        }
    }

    // Cleanup
    mq_close(mq);
    return 0;
}