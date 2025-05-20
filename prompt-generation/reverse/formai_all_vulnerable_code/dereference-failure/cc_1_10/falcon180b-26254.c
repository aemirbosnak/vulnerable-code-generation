//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_SIZE 100

typedef struct msg_buffer {
    long mtype;
    char mtext[MAX_SIZE];
} msg_buffer_t;

int main() {
    int msgid;
    key_t key;
    msg_buffer_t msg;
    char *message;

    // Create a unique key
    key = ftok(".", 'A');

    // Get a message queue identifier
    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(1);
    }

    while (1) {
        printf("Enter message: ");

        // Read input from user
        message = (char *) malloc(MAX_SIZE * sizeof(char));
        scanf("%[^\n]", message);

        // Copy input to message buffer
        strncpy(msg.mtext, message, MAX_SIZE);
        msg.mtype = 1;

        // Send message to message queue
        if (msgsnd(msgid, &msg, strlen(msg.mtext) + 1, 0) == -1) {
            perror("msgsnd");
            exit(1);
        }
    }

    return 0;
}