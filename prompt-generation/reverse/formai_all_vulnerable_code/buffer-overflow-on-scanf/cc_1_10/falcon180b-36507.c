//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

// Message structure
typedef struct {
    long mtype;
    char mtext[MAX_SIZE];
} message;

// Function to create a message queue
int create_queue(key_t key) {
    int msgid;
    msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1) {
        printf("Error creating message queue.\n");
        exit(1);
    }
    printf("Message queue created with ID: %d\n", msgid);
    return msgid;
}

// Function to send a message
void send_message(int msgid, int type, char *text) {
    message msg;
    msg.mtype = type;
    strcpy(msg.mtext, text);
    msgsnd(msgid, &msg, strlen(text) + 1, 0);
    printf("Message sent: %s\n", text);
}

// Function to receive a message
void receive_message(int msgid, int type) {
    message msg;
    printf("Waiting for message of type %d...\n", type);
    msgrcv(msgid, &msg, MAX_SIZE, type, 0);
    printf("Message received: %s\n", msg.mtext);
}

int main() {
    int msgid;
    int choice;

    printf("Romeo and Juliet Interprocess Communication Example\n");

    msgid = create_queue(ftok(".", 65)); // Create message queue with unique key

    while (TRUE) {
        printf("\n");
        printf("Choose an option:\n");
        printf("1. Send a message\n");
        printf("2. Receive a message\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter message type (1-10): ");
                scanf("%d", &choice);
                printf("Enter message: ");
                char msg[MAX_SIZE];
                scanf("%s", msg);
                send_message(msgid, choice, msg);
                break;
            case 2:
                printf("Enter message type (1-10): ");
                scanf("%d", &choice);
                receive_message(msgid, choice);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}