//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_MSG_SIZE 100
#define MAX_CLIENTS 10
#define MAX_REQUESTS 50
#define MAX_RESPONSES 50
#define MAX_REQUEST_SIZE 50
#define MAX_RESPONSE_SIZE 100

typedef struct {
    long mtype;
    char mtext[MAX_MSG_SIZE];
} message_t;

int main() {
    int queue_id, client_id[MAX_CLIENTS], i;
    key_t key;
    message_t queue[MAX_REQUESTS], response[MAX_RESPONSES];
    int num_requests = 0, num_responses = 0;

    // Create a unique key for the message queue
    key = ftok("message_queue", 65);

    // Create the message queue
    if ((queue_id = msgget(key, 0666 | IPC_CREAT)) == -1) {
        printf("Error creating message queue\n");
        exit(1);
    }

    // Create client IDs
    for (i = 0; i < MAX_CLIENTS; i++) {
        client_id[i] = msgget(key, 0666);
    }

    // Loop to receive requests from clients
    while (1) {
        // Receive a message from the message queue
        if (msgrcv(queue_id, &queue[num_requests], MAX_MSG_SIZE, 0, 0) == -1) {
            printf("Error receiving message\n");
            exit(1);
        }

        // Process the request and generate a response
        switch (queue[num_requests].mtype) {
            case 1:
                // Request type 1
                sprintf(response[num_responses].mtext, "Response to request 1");
                break;
            case 2:
                // Request type 2
                sprintf(response[num_responses].mtext, "Response to request 2");
                break;
            default:
                // Invalid request type
                sprintf(response[num_responses].mtext, "Invalid request");
                break;
        }

        // Send the response back to the client
        if (msgsnd(client_id[num_requests], &response[num_responses], MAX_RESPONSE_SIZE, 0) == -1) {
            printf("Error sending response\n");
            exit(1);
        }

        // Increment the number of requests and responses
        num_requests++;
        num_responses++;
    }

    return 0;
}