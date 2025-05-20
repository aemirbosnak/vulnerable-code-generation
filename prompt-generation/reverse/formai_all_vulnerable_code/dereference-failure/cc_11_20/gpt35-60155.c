//FormAI DATASET v1.0 Category: Interprocess communication ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 100

typedef struct message
{
    long msg_type;
    char data[MAX_SIZE];
}message;

int main(int argc, char **argv)
{
    int parent_to_child_key = 1234; // key for message queue from parent to child
    int child_to_parent_key = 5678; // key for message queue from child to parent

    int parent_to_child_queue = msgget(parent_to_child_key, IPC_CREAT | 0666); // create a message queue from parent to child
    if(parent_to_child_queue == -1)
    {
        printf("Error creating parent-to-child message queue: %s\n", strerror(errno));
        exit(1);
    }

    int child_to_parent_queue = msgget(child_to_parent_key, IPC_CREAT | 0666); // create a message queue from child to parent
    if(child_to_parent_queue == -1)
    {
        printf("Error creating child-to-parent message queue: %s\n", strerror(errno));
        exit(1);
    }

    pid_t pid = fork(); // fork the process

    if(pid == 0) // child process
    {
        message message_received;

        while(1)
        {
            int bytes_received = msgrcv(parent_to_child_queue, &message_received, sizeof(message_received), 1, 0); // receive message from parent
            if(bytes_received == -1)
            {
                printf("Error receiving message from parent: %s\n", strerror(errno));
                exit(1);
            }

            printf("Child received message: %s\n", message_received.data);

            // send message back to parent
            message message_to_send;
            message_to_send.msg_type = 1;
            sprintf(message_to_send.data, "Child received message: %s", message_received.data);
            int bytes_sent = msgsnd(child_to_parent_queue, &message_to_send, strlen(message_to_send.data) + 1, 0);
            if(bytes_sent == -1)
            {
                printf("Error sending message to parent: %s\n", strerror(errno));
                exit(1);
            }
        }
    }
    else if(pid > 0) // parent process
    {
        message message_to_send;

        while(1)
        {
            char input[MAX_SIZE];

            printf("Parent: ");
            fgets(input, MAX_SIZE, stdin); // get user input

            // send message to child process
            message_to_send.msg_type = 1;
            strncpy(message_to_send.data, input, MAX_SIZE);
            int bytes_sent = msgsnd(parent_to_child_queue, &message_to_send, strlen(message_to_send.data) + 1, 0);
            if(bytes_sent == -1)
            {
                printf("Error sending message to child: %s\n", strerror(errno));
                exit(1);
            }

            // receive message from child process
            message message_received;
            int bytes_received = msgrcv(child_to_parent_queue, &message_received, sizeof(message_received), 1, 0);
            if(bytes_received == -1)
            {
                printf("Error receiving message from child: %s\n", strerror(errno));
                exit(1);
            }

            printf("Child: %s\n", message_received.data);
        }
    }
    else // error
    {
        printf("Error forking process: %s\n", strerror(errno));
        exit(1);
    }

    // delete message queues
    msgctl(parent_to_child_queue, IPC_RMID, NULL);
    msgctl(child_to_parent_queue, IPC_RMID, NULL);

    return 0;
}