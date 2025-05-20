//GPT-4o-mini DATASET v1.0 Category: Interprocess communication ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <unistd.h>
#include <errno.h>

#define QUEUE_NAME "/my_message_queue"
#define MAX_MESSAGE_SIZE 256
#define MAX_MESSAGES 10

void server() {
    mqd_t mq;
    char buffer[MAX_MESSAGE_SIZE];

    // Open the message queue
    mq = mq_open(QUEUE_NAME, O_RDONLY);
    if (mq == (mqd_t)-1) {
        perror("Server: mq_open");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Receive messages from the queue
        ssize_t bytes_read = mq_receive(mq, buffer, MAX_MESSAGE_SIZE, NULL);
        if (bytes_read >= 0) {
            buffer[bytes_read] = '\0'; // Null-terminate the string
            printf("Server received: %s\n", buffer);
            if (strcmp(buffer, "exit") == 0) {
                printf("Server exiting...\n");
                break;
            }
        } else {
            perror("Server: mq_receive");
        }
    }

    mq_close(mq);
    mq_unlink(QUEUE_NAME);
}

void client(const char *message) {
    mqd_t mq;

    // Open the message queue
    mq = mq_open(QUEUE_NAME, O_WRONLY);
    if (mq == (mqd_t)-1) {
        perror("Client: mq_open");
        exit(EXIT_FAILURE);
    }

    // Send message to the queue
    if (mq_send(mq, message, strlen(message) + 1, 0) == -1) {
        perror("Client: mq_send");
    } else {
        printf("Client sent: %s\n", message);
    }

    mq_close(mq);
}

int main(int argc, char *argv[]) {
    pid_t pid;

    // Create message queue
    mqd_t mq;
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = MAX_MESSAGES;
    attr.mq_msgsize = MAX_MESSAGE_SIZE;
    attr.mq_curmsgs = 0;

    // Create the message queue
    mq = mq_open(QUEUE_NAME, O_CREAT | O_EXCL | O_RDWR, 0644, &attr);
    if (mq == (mqd_t)-1) {
        perror("Main: mq_open");
        exit(EXIT_FAILURE);
    }

    // Fork a server process
    pid = fork();
    if (pid < 0) {
        perror("Main: fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // This is the server process
        server();
        exit(EXIT_SUCCESS);
    }

    // Allow time for the server to start
    sleep(1);

    // Send messages from client
    const char *messages[] = {
        "Hello, Server!",
        "How are you?",
        "This is a test.",
        "Interprocess Communication is cool!",
        "exit"
    };
    
    for (int i = 0; i < sizeof(messages) / sizeof(messages[0]); ++i) {
        client(messages[i]);
        sleep(1); // Sleep to allow time between messages
    }

    // Wait for server to finish
    wait(NULL);

    // Cleanup
    mq_unlink(QUEUE_NAME);
    return 0;
}