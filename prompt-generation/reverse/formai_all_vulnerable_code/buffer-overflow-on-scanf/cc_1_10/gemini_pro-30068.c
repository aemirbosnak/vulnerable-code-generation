//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSGKEY 1234

typedef struct {
    long mtype;
    float temp;
} msgbuf;

int main() {
    int msqid;
    msgbuf msg;
    key_t key;

    key = MSGKEY;

    if ((msqid = msgget(key, 0666 | IPC_CREAT)) < 0) {
        perror("msgget");
        exit(1);
    }

    printf("Enter a temperature in Fahrenheit: ");
    scanf("%f", &msg.temp);

    msg.mtype = 1;

    if (msgsnd(msqid, &msg, sizeof(msgbuf), 0) < 0) {
        perror("msgsnd");
        exit(1);
    }

    if (msgrcv(msqid, &msg, sizeof(msgbuf), 2, 0) < 0) {
        perror("msgrcv");
        exit(1);
    }

    printf("Temperature in Celsius: %.2f\n", msg.temp);

    if (msgctl(msqid, IPC_RMID, NULL) < 0) {
        perror("msgctl");
        exit(1);
    }

    return 0;
}