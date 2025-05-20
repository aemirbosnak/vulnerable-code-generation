//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define BUFFER_SIZE 32
#define SERVER_QUEUE_KEY 1000
#define CLIENT_QUEUE_KEY 2000

typedef struct {
    long mtype;
    char mtext[BUFFER_SIZE];
} message_t;

int main(int argc, char* argv[]) {
    int msgid;
    key_t key;
    int clients[10];
    int n;
    int i;
    char input[BUFFER_SIZE];
    message_t msg;

    // Create the server queue
    key = ftok("server.c", 65);
    if ((msgid = msgget(key, IPC_CREAT | 0666)) == -1) {
        printf("Error creating server queue\n");
        exit(1);
    }

    // Accept connections from clients
    while (1) {
        if (msgrcv(msgid, &msg, BUFFER_SIZE, 0, 0) == -1) {
            printf("Error receiving message\n");
            exit(1);
        }

        // Add client to list
        for (i = 0; i < n; i++) {
            if (clients[i] == msg.mtype) {
                break;
            }
        }
        if (i == n) {
            if (n == 10) {
                printf("Server full\n");
                msgsnd(msgid, &msg, BUFFER_SIZE, 0);
                continue;
            }
            clients[n++] = msg.mtype;
        }

        // Send welcome message to client
        sprintf(msg.mtext, "Welcome client %d", msg.mtype);
        if (msgsnd(msgid, &msg, BUFFER_SIZE, 0) == -1) {
            printf("Error sending message\n");
            exit(1);
        }
    }

    return 0;
}