//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define BUFFER_SIZE 100
#define MSG_QUEUE_KEY 1234
#define MSG_TYPE_REQUEST 1
#define MSG_TYPE_RESPONSE 2

typedef struct {
    long mtype; // message type
    char mtext[BUFFER_SIZE]; // message text
} message;

int main() {
    int msgid;
    message msg;
    char input[BUFFER_SIZE];
    int choice;

    msgid = msgget(MSG_QUEUE_KEY, IPC_CREAT | 0666);
    if (msgid == -1) {
        printf("Error creating message queue.\n");
        exit(1);
    }

    while (true) {
        printf("\nEnter your choice:\n");
        printf("1. Send request\n");
        printf("2. Receive response\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter request message:\n");
                scanf("%s", input);
                strncpy(msg.mtext, input, BUFFER_SIZE - 1);
                msg.mtype = MSG_TYPE_REQUEST;
                msgsnd(msgid, &msg, strlen(input) + 1, 0);
                break;
            case 2:
                msgrcv(msgid, &msg, BUFFER_SIZE, MSG_TYPE_RESPONSE, 0);
                printf("Response message: %s\n", msg.mtext);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}