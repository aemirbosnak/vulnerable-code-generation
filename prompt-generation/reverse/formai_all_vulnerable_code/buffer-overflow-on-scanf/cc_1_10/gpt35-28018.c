//FormAI DATASET v1.0 Category: Interprocess communication ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_MSG_LEN 100

// define a structure for holding a message
typedef struct {
    pid_t sender;   // sender's pid
    char msg[MAX_MSG_LEN];  // message content
} Message;

int main() {
    int shm_id; // shared memory id
    char *shmaddr; // pointer to shared memory segment
    size_t mem_size = sizeof(Message); // size of shared memory segment
    pid_t pid; // process id
    Message *msg; // pointer to message in shared memory
    key_t key = ftok(".", 'M'); // generate a key for creating shared memory

    // create shared memory segment
    shm_id = shmget(key, mem_size, 0666 | IPC_CREAT);

    // attach shared memory segment to process address space
    shmaddr = shmat(shm_id, NULL, 0);

    // fork a child process
    pid = fork();

    if (pid == 0) { // child process
        printf("User 2 has joined the chat...\n");

        // set pointer to message in shared memory
        msg = (Message *)shmaddr;

        while (1) {
            // wait for user 1 to send a message
            while (msg->sender != 1);

            // print message content and sender
            printf("User 1 says: %s\n", msg->msg);
            printf("User 2 replies: ");

            // read message from stdin and store in shared memory
            scanf("%s", msg->msg);

            // set sender to user 1
            msg->sender = 2;
        }
    } else { // parent process
        printf("User 1 has joined the chat...\n");

        // set pointer to message in shared memory
        msg = (Message *)shmaddr;

        while (1) {
            // read message from stdin and store in shared memory
            printf("User 1 says: ");
            scanf("%s", msg->msg);

            // set sender to user 2
            msg->sender = 1;

            // wait for user 2 to reply
            while (msg->sender != 2);

            // print message content and sender
            printf("User 2 replies: %s\n", msg->msg);
        }
    }

    // detach shared memory segment from process address space
    shmdt(shmaddr);

    // destroy shared memory segment
    shmctl(shm_id, IPC_RMID, NULL);

    return 0;
}