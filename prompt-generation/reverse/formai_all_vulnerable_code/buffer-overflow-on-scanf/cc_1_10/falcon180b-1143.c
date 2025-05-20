//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MSG_SIZE 100
#define MSG_KEY 1234
#define MSG_QUEUE_ID 5678

typedef struct {
    long mtype;
    char mtext[MAX_MSG_SIZE];
} message_t;

int main() {
    int msgid;
    key_t key = MSG_KEY;
    int msgqid;

    // Create a message queue
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        printf("Error creating message queue\n");
        exit(1);
    }

    // Set message queue ID for later use
    msgqid = msgid;

    // Fork a child process
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        char input[MAX_MSG_SIZE];
        while (1) {
            printf("Child: Enter message to send: ");
            scanf("%s", input);

            // Send message to parent process
            message_t msg;
            msg.mtype = 1;
            strncpy(msg.mtext, input, MAX_MSG_SIZE);
            msgsnd(msgid, &msg, strlen(input) + 1, 0);

            sleep(1);
        }
    } else {
        // Parent process
        char buffer[MAX_MSG_SIZE];
        while (1) {
            // Receive message from child process
            message_t msg;
            int msg_size = msgrcv(msgid, &msg, MAX_MSG_SIZE, 1, 0);
            if (msg_size <= 0) {
                printf("Error receiving message\n");
                exit(1);
            }

            printf("Parent: Received message: %s\n", msg.mtext);

            // Send reply to child process
            sprintf(buffer, "Reply: %s", msg.mtext);
            msg.mtype = 2;
            strncpy(msg.mtext, buffer, MAX_MSG_SIZE);
            msgsnd(msgqid, &msg, strlen(buffer) + 1, 0);

            sleep(1);
        }
    }

    return 0;
}