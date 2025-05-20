//FormAI DATASET v1.0 Category: Interprocess communication ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>

// Function to calculate the factorial of input
int calculateFactorial(int n) {
    int factorial = 1;
    
    for(int i=1; i<=n; i++) {
        factorial *= i;
    }
    
    return factorial;
}

int main() {
    // Declare shared memory variables
    int sharedMemoryId, *sharedMemoryPointer;
    key_t key = ftok("genius.txt", 'R');

    // Create shared memory segment
    sharedMemoryId = shmget(key, 4096, IPC_CREAT | 0666);
    
    if(sharedMemoryId < 0) {
        perror("Error creating shared memory segment");
        exit(1);
    }

    // Attach shared memory segment to this process
    sharedMemoryPointer = (int*) shmat(sharedMemoryId, NULL, 0);
    
    if(sharedMemoryPointer == (int *) -1) {
        perror("Error attaching shared memory segment to process");
        exit(1);
    }

    // Ask user for input and store in shared memory
    printf("Enter a number to calculate its factorial: ");
    int inputNumber;
    scanf("%d", &inputNumber);
    
    *sharedMemoryPointer = inputNumber;

    // Fork process to create child process
    pid_t pid = fork();

    if(pid < 0) {
        perror("Error forking process");
        exit(1);
    }
    else if(pid == 0) { // Child process
        // Retrieve input number from shared memory
        int inputNumber = *sharedMemoryPointer;

        // Calculate factorial of input number
        int factorial = calculateFactorial(inputNumber);

        // Store factorial value in shared memory
        *sharedMemoryPointer = factorial;

        printf("Child Process:\nFactorial of %d is %d\n", inputNumber, factorial);
        printf("Child process exiting...\n");

        // Detach shared memory segment from child process
        shmdt(sharedMemoryPointer);
        exit(0);
    }
    else { // Parent process
        printf("Parent process waiting for child...\n");
        wait(NULL);

        // Retrieve factorial value from shared memory
        int factorial = *sharedMemoryPointer;

        printf("Parent Process:\nFactorial result from child process is %d\n", factorial);

        // Detach and remove shared memory segment
        shmdt(sharedMemoryPointer);
        shmctl(sharedMemoryId, IPC_RMID, NULL);
        
        printf("Parent process exiting...\n");

        exit(0);
    }
    return 0;
}