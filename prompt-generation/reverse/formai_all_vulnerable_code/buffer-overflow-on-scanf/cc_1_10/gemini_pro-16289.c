//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msgbuf {
    long mtype;
    char mtext[200];
};

int main() {
    key_t key;
    int msgid;

    key = ftok("ipc_demo.c", 'a');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    struct my_msgbuf msg;
    while (1) {
        printf("Enter a message type (1-10): ");
        scanf("%ld", &msg.mtype);
        if (msg.mtype <= 0 || msg.mtype > 10) {
            printf("Invalid message type\n");
            continue;
        }

        printf("Enter a message text: ");
        scanf(" %[^\n]%*c", msg.mtext);

        if (msgsnd(msgid, &msg, sizeof(msg.mtext), 0) == -1) {
            perror("msgsnd");
            exit(1);
        }

        printf("Message sent successfully\n\n");
    }

    return 0;
}