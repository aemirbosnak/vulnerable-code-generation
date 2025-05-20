//FormAI DATASET v1.0 Category: Interprocess communication ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>

#define MSGSZ 128

typedef struct msgbuf {
    long mtype;
    char mtext[MSGSZ];
} message;

int msgqid;

void handler(int signo) {
    if (signo == SIGINT) {
        printf("Ctrl+C interrupt received. Closing message queue...\n");
        msgctl(msgqid, IPC_RMID, NULL);
        exit(0);
    }
}

int main() {
    message msg;
    key_t key;
    int pid, recv_pid;
    char buf[MSGSZ], sendmsg[MSGSZ];
    int length, n;

    signal(SIGINT, handler);

    pid = getpid();
    key = ftok("progfile", 65);
    msgqid = msgget(key, 0666 | IPC_CREAT);

    printf("This is process %d. Enter 'q' to quit.\n", pid);

    while (strcmp(buf, "q") != 0) {
        printf("Enter message for process to send: ");
        fgets(sendmsg, MSGSZ, stdin);
        length = strlen(sendmsg);
        sendmsg[length - 1] = '\0';
        strcpy(msg.mtext, sendmsg);
        msg.mtype = 1;

        if (msgsnd(msgqid, &msg, MSGSZ, IPC_NOWAIT) == -1) {
            printf("Error: message send failed.\n");
            exit(1);
        }

        printf("Message sent from process %d\n", pid);

        printf("Enter the PID of the receiving process: ");
        scanf("%d", &recv_pid);
        getchar();

        n = msgrcv(msgqid, &msg, MSGSZ, recv_pid, 0);

        if (n < 0) {
            printf("Error receiving message.\n");
            exit(1);
        }

        printf("Received message from process %d: %s\n", recv_pid, msg.mtext);

        printf("Continue (type any key, or 'q' to exit): ");
        fgets(buf, MSGSZ, stdin);
        printf("\n");
    }

    msgctl(msgqid, IPC_RMID, NULL);
    printf("Message queue closed.\n");
    exit(0);
}