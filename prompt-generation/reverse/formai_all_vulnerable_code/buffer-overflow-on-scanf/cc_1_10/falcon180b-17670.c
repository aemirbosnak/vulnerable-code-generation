//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX 10

typedef struct {
    long mtype;
    char mtext[80];
} message;

void send_message(int msgid, int value) {
    message msg;
    msg.mtype = value;
    sprintf(msg.mtext, "Value: %d", value);
    msgsnd(msgid, &msg, sizeof(msg.mtext), 0);
}

void receive_message(int msgid) {
    message msg;
    msgrcv(msgid, &msg, sizeof(msg.mtext), 0, 0);
    printf("Received message: %s\n", msg.mtext);
}

void interprocess_communication(int num_processes) {
    int msgid;
    key_t key = ftok("interprocess_communication.c", 'a');
    msgid = msgget(key, 0666 | IPC_CREAT);

    for (int i = 0; i < num_processes; i++) {
        if (fork() == 0) {
            send_message(msgid, i);
            exit(0);
        }
    }

    for (int i = 0; i < num_processes; i++) {
        receive_message(msgid);
    }

    msgctl(msgid, IPC_RMID, NULL);
}

int main() {
    int num_processes;
    printf("Enter the number of processes to be created: ");
    scanf("%d", &num_processes);

    interprocess_communication(num_processes);

    return 0;
}