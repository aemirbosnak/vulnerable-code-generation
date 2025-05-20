//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_KEY 123456L

typedef struct {
    long mtype;
    char mtext[100];
} message_t;

int main() {
    int msgid = msgget(MSG_KEY, IPC_CREAT | 0644);
    if (msgid == -1) {
        perror("msgget");
        return EXIT_FAILURE;
    }

    message_t message;
    message.mtype = 1;
    sprintf(message.mtext, "Hello from parent process!");

    if (msgsnd(msgid, &message, sizeof(message_t), 0) == -1) {
        perror("msgsnd");
        return EXIT_FAILURE;
    }

    if (fork() == 0) {
        // Child process
        while (1) {
            if (msgrcv(msgid, &message, sizeof(message_t), 1, 0) == -1) {
                perror("msgrcv");
                return EXIT_FAILURE;
            }

            printf("Child process received message: %s\n", message.mtext);

            if (strcmp(message.mtext, "exit") == 0) {
                break;
            }
        }
    } else {
        // Parent process
        while (1) {
            printf("Parent process: ");
            fgets(message.mtext, sizeof(message.mtext), stdin);
            message.mtext[strlen(message.mtext) - 1] = '\0'; // Remove newline

            if (msgsnd(msgid, &message, sizeof(message_t), 0) == -1) {
                perror("msgsnd");
                return EXIT_FAILURE;
            }

            if (strcmp(message.mtext, "exit") == 0) {
                break;
            }
        }

        wait(NULL);
    }

    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}