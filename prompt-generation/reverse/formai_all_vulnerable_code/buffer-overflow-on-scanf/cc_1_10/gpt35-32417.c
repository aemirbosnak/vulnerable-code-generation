//FormAI DATASET v1.0 Category: Interprocess communication ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 24601
#define ARRAY_SIZE 10

int main()
{
    int shmid;
    pid_t pid1, pid2;
    int *shm_array;
    int i, sum = 0;
    
    // Create Shared Memory
    shmid = shmget(SHM_KEY, ARRAY_SIZE * sizeof(int), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("Failed to create shared memory");
        exit(1);
    }
    
    // Attach Shared Memory
    shm_array = shmat(shmid, NULL, 0);
    if (shm_array == (int *) -1) {
        perror("Failed to attach shared memory");
        exit(1);
    }
    
    // Fill Shared Memory
    printf("Enter %d integers: ", ARRAY_SIZE);
    for (i = 0; i < ARRAY_SIZE; i++) {
        scanf("%d", &shm_array[i]);
    }
    
    // Create Child Processes
    pid1 = fork();
    if (pid1 < 0) {
        perror("Failed to create first child process");
        exit(1);
    }
    else if (pid1 == 0) { // First Child Process
        printf("Contents of shared memory in first child process: ");
        for (i = 0; i < ARRAY_SIZE; i++) {
            printf("%d ", shm_array[i]);
        }
        printf("\n");
        _exit(0);
    }
    else {
        pid2 = fork();
        if (pid2 < 0) {
            perror("Failed to create second child process");
            exit(1);
        }
        else if (pid2 == 0) { // Second Child Process
            for (i = 0; i < ARRAY_SIZE; i++) {
                sum += shm_array[i];
            }
            printf("Sum of integers in shared memory in second child process: %d\n", sum);
            _exit(0);
        }
        else { // Parent Process
            waitpid(pid1, NULL, 0);
            waitpid(pid2, NULL, 0);
            // Detach Shared Memory
            shmdt(shm_array);
            // Destroy Shared Memory
            shmctl(shmid, IPC_RMID, NULL);
        }
    }
    
    return 0;
}