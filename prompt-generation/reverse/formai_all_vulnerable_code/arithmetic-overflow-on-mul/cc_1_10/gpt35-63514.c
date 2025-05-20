//FormAI DATASET v1.0 Category: Interprocess communication ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_KEY 0x1234  // A unique key for shared memory

typedef struct {
    int number;
    int square;
} data_t;

int main() {
    int shmid;
    data_t *data;
    
    // Create shared memory
    shmid = shmget(SHM_KEY, sizeof(data_t), 0666 | IPC_CREAT);
    if(shmid == -1) {
        perror("shmget");
        exit(1);
    }

    // Attach shared memory to our data pointer
    data = (data_t*) shmat(shmid, NULL, 0);
    if(data == (data_t*) -1) {
        perror("shmat");
        exit(1);
    }

    // Read input from user
    printf("Enter a number: ");
    scanf("%d", &data->number);

    // Fork a child process
    pid_t pid = fork();

    if(pid == -1) {
        perror("fork");
        exit(1);
    } else if(pid == 0) {
        // Child process calculates square of number
        data->square = data->number * data->number;
        printf("Child process calculated square of %d\n", data->number);
        exit(0);
    } else {
        // Parent process waits for child to finish
        wait(NULL);
        printf("Parent process received square of %d from child: %d\n", data->number, data->square);
    }

    // Detach and delete shared memory
    shmdt(data);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}