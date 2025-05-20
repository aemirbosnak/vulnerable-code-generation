//Code Llama-13B DATASET v1.0 Category: Interprocess communication ; Style: lively
/*
 * C Interprocess Communication Example Program
 *
 * This program demonstrates the use of interprocess communication (IPC) in C.
 * It uses the POSIX shared memory and message queue APIs to communicate between
 * two processes.
 *
 * The program creates two processes, a "producer" and a "consumer", which
 * communicate through a shared memory and a message queue. The producer
 * writes a random number to the shared memory and then sends a message to
 * the consumer through the message queue. The consumer then reads the
 * number from the shared memory and prints it to the console.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <unistd.h>
#include <string.h>

#define SHM_SIZE 1024
#define QUEUE_KEY 0x12345678
#define QUEUE_SIZE 10

struct message {
    long mtype;
    int data;
};

int main(void) {
    // Create the shared memory
    int shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory to the process
    int *shm = shmat(shmid, NULL, 0);
    if (shm == (int *)-1) {
        perror("shmat");
        exit(1);
    }

    // Create the message queue
    int qid = msgget(QUEUE_KEY, IPC_CREAT | 0666);
    if (qid == -1) {
        perror("msgget");
        exit(1);
    }

    // Fork the process to create the producer and consumer
    int pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Producer process
        while (1) {
            // Generate a random number
            int num = rand() % 100;

            // Write the number to the shared memory
            *shm = num;

            // Send a message to the consumer
            struct message msg;
            msg.mtype = 1;
            msg.data = num;
            if (msgsnd(qid, &msg, sizeof(msg), 0) == -1) {
                perror("msgsnd");
                exit(1);
            }

            // Wait for the consumer to read the message
            sleep(1);
        }
    } else {
        // Consumer process
        while (1) {
            // Receive a message from the producer
            struct message msg;
            if (msgrcv(qid, &msg, sizeof(msg), 1, 0) == -1) {
                perror("msgrcv");
                exit(1);
            }

            // Read the number from the shared memory
            int num = *shm;

            // Print the number to the console
            printf("Received number: %d\n", num);
        }
    }

    // Detach the shared memory
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Remove the shared memory
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    // Remove the message queue
    if (msgctl(qid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }

    return 0;
}