//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef struct {
    long int mtype;
    char mtext[MAX_SIZE];
} message;

int main() {
    int msgid;
    key_t key;
    message msg;

    // Create a unique key
    key = ftok(".", 65);

    // Get a message queue identifier
    msgid = msgget(key, IPC_CREAT | 0666);

    if (msgid == -1) {
        printf("Error: Unable to create message queue.\n");
        return 1;
    }

    int choice;
    do {
        printf("Enter your choice:\n1. Send message\n2. Receive message\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Send message
                printf("Enter message to send: ");
                scanf("%[^\n]", msg.mtext);
                msg.mtype = 1;
                if (msgsnd(msgid, &msg, MAX_SIZE, 0) == -1) {
                    printf("Error: Unable to send message.\n");
                }
                break;

            case 2:
                // Receive message
                if (msgrcv(msgid, &msg, MAX_SIZE, 1, 0) == -1) {
                    printf("Error: Unable to receive message.\n");
                } else {
                    printf("Received message: %s\n", msg.mtext);
                }
                break;

            case 3:
                // Exit
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}