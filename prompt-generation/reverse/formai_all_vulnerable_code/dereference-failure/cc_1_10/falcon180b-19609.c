//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100
#define DELAY 3

typedef struct {
    long mtype;
    char mtext[MAX_SIZE];
} message;

int main() {
    int msgid, msgsz;
    key_t key;
    message msg;
    pid_t pid;
    int status;
    char *msg_ptr;

    /* Create a unique key */
    key = ftok(".", 65);

    /* Create the message queue */
    if ((msgid = msgget(key, IPC_CREAT | 0666)) == -1) {
        perror("msgget");
        exit(1);
    }

    /* Fork a child process */
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        /* Child process */
        printf("Child process started...\n");
        sleep(DELAY);
        sprintf(msg.mtext, "Hello from child process! ");
        msgsz = strlen(msg.mtext) + 1;
        if (msgsnd(msgid, &msg, msgsz, 0) == -1) {
            perror("msgsnd");
            exit(1);
        }
        printf("Message sent to queue.\n");
        exit(0);
    } else {
        /* Parent process */
        printf("Parent process started...\n");
        sleep(DELAY);
        if (msgrcv(msgid, &msg, MAX_SIZE, 1, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }
        printf("Message received from queue: %s\n", msg.mtext);
        exit(0);
    }
}