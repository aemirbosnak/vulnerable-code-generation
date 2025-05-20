//FormAI DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSG_SIZE 1024

struct message {
    long type;
    char text[MSG_SIZE];
};

int main() {
    pid_t pid;
    key_t key;
    int msgid;
    struct message msg;
    char str[MSG_SIZE];

    printf("Grateful Interprocess Communication Program\n");

    // create a unique key
    key = ftok(".", 'a');

    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // create a message queue
    msgid = msgget(key, 0644 | IPC_CREAT);

    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // fork a child process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // child process
        while (1) {
            // receive message from parent
            if (msgrcv(msgid, &msg, sizeof(struct message), 1, 0) == -1) {
                perror("msgrcv");
                exit(EXIT_FAILURE);
            }

            printf("Received Message from Parent: %s\n", msg.text);
            // convert message to uppercase
            for (int i = 0; i < strlen(msg.text); i++) {
                msg.text[i] = toupper(msg.text[i]);
            }

            // send message back to parent
            msg.type = 2;
            if (msgsnd(msgid, &msg, sizeof(struct message), 0) == -1) {
                perror("msgsnd");
                exit(EXIT_FAILURE);
            }
        }
    } else { // parent process
        while(1) {
            printf("Enter a message: ");
            fgets(str, MSG_SIZE, stdin);
            str[strlen(str)-1] = '\0';

            // send message to child
            msg.type = 1;
            strcpy(msg.text, str);
            if (msgsnd(msgid, &msg, sizeof(struct message), 0) == -1) {
                perror("msgsnd");
                exit(EXIT_FAILURE);
            }

            // receive message from child
            if (msgrcv(msgid, &msg, sizeof(struct message), 2, 0) == -1) {
                perror("msgrcv");
                exit(EXIT_FAILURE);
            }

            printf("Received Message from Child: %s\n", msg.text);
        }
    }

    // remove message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}