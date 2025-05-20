//FormAI DATASET v1.0 Category: Arithmetic ; Style: distributed
/*
Distributed C Arithmetic Example Program
By: [Your Name]

Description:
This program distributes a large arithmetic operation across multiple processes, utilizing
IPC (Interprocess Communication) via shared memory to collect and combine the results.

Instructions:
1. Enter the numbers and operator to be used in the operation.
2. Choose the number of processes to distribute the operation across.
3. The program will output the result of the operation after it has been distributed and combined.

Note: This program assumes that input will always be valid (e.g. proper numbers and operators).
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define MAX_PROCESSES 10

// Struct to hold the distributed operation data
typedef struct {
    float num1;
    float num2;
    char op;
} DistributedOperation;

// Struct to hold the shared memory data
typedef struct {
    float results[MAX_PROCESSES];
    int numProcesses;
} SharedMemoryData;

int main() {
    DistributedOperation dOp;
    printf("Enter first number: ");
    scanf("%f", &dOp.num1);
    printf("Enter second number: ");
    scanf("%f", &dOp.num2);
    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &dOp.op);

    // Create shared memory segment
    int shmid = shmget(IPC_PRIVATE, sizeof(SharedMemoryData), 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget error");
        exit(EXIT_FAILURE);
    }

    // Attach shared memory segment to process
    SharedMemoryData* shmData = (SharedMemoryData*) shmat(shmid, NULL, 0);
    if (shmData == (void*) -1) {
        perror("shmat error");
        exit(EXIT_FAILURE);
    }

    // Initialize shared memory data
    shmData->numProcesses = 0;
    for (int i = 0; i < MAX_PROCESSES; i++) {
        shmData->results[i] = 0;
    }

    // Distribute operation across processes
    int numProcesses;
    printf("Enter number of processes to use (max %d): ", MAX_PROCESSES);
    scanf("%d", &numProcesses);
    if (numProcesses > MAX_PROCESSES) {
        printf("Too many processes. Max is %d.\n", MAX_PROCESSES);
        exit(EXIT_FAILURE);
    }

    float num1Chunks[numProcesses];
    float num2Chunks[numProcesses];
    char opChunks[numProcesses];
    int rangeStart = 0;
    int rangeSize = (int) (dOp.num1 + numProcesses - 1) / numProcesses; // Round up division
    for (int i = 0; i < numProcesses; i++) {
        if (i == numProcesses - 1) {
            rangeSize = dOp.num1 - rangeStart; // Last process: take remainder
        }
        num1Chunks[i] = dOp.num1 - rangeStart;
        num2Chunks[i] = dOp.num2;
        opChunks[i] = dOp.op;
        rangeStart += rangeSize;
    }

    pid_t pid, childPid;
    for (int i = 0; i < numProcesses; i++) {
        pid = fork();
        if (pid == -1) {
            perror("fork error");
            exit(EXIT_FAILURE);
        } else if (pid == 0) { // Child process
            float result = 0;
            switch (opChunks[i]) {
                case '+': result = num1Chunks[i] + num2Chunks[i]; break;
                case '-': result = num1Chunks[i] - num2Chunks[i]; break;
                case '*': result = num1Chunks[i] * num2Chunks[i]; break;
                case '/': result = num1Chunks[i] / num2Chunks[i]; break;
            }

            // Attach to shared memory segment
            shmData = (SharedMemoryData*) shmat(shmid, NULL, 0);
            if (shmData == (void*) -1) {
                perror("shmat error");
                exit(EXIT_FAILURE);
            }

            // Save result in shared memory
            shmData->results[shmData->numProcesses] = result;
            shmData->numProcesses++;

            // Detach from shared memory segment
            if (shmdt(shmData) == -1) {
                perror("shmdt error");
                exit(EXIT_FAILURE);
            }

            exit(EXIT_SUCCESS);
        }
    }

    // Wait for child processes to finish
    while ((childPid = wait(NULL)) > 0);

    // Combine results from shared memory
    float finalResult = 0;
    for (int i = 0; i < numProcesses; i++) {
        finalResult += shmData->results[i];
    }

    printf("Result: %f\n", finalResult);

    // Detach and remove shared memory segment
    if (shmdt(shmData) == -1) {
        perror("shmdt error");
        exit(EXIT_FAILURE);
    }
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl error");
        exit(EXIT_FAILURE);
    }

    return 0;
}