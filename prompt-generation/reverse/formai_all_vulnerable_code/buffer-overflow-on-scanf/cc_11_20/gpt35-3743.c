//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSZ 27

int main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;
    bool running = true;
    int data[3] = {0, 0, 0}; // Data for interprocess communication
    
    // Generate the key for shared memory
    if ((key = ftok("shmfile", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }
    
    // Create shared memory segment
    if ((shmid = shmget(key, SHMSZ, 0666 | IPC_CREAT)) == -1) {
        perror("shmget");
        exit(1);
    }
    
    // Attach shared memory segment to process
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    
    // Write to shared memory segment
    for (s = shm; *s != NULL; s++)
        *s = NULL;
    
    while (running) {
        // Display menu to user and get their choice
        printf("Enter the operation you want to perform: \n");
        printf("1. Add to variable 1\n");
        printf("2. Add to variable 2\n");
        printf("3. Add to variable 3\n");
        printf("4. Exit\n");
        scanf("%c", &c);
        getchar(); // Clear newline character
        
        // Interprocess communication based on user choice
        switch (c) {
            case '1': 
                data[0]++;
                sprintf(shm, "%d %d %d", data[0], data[1], data[2]);
                break;
            case '2': 
                data[1]++;
                sprintf(shm, "%d %d %d", data[0], data[1], data[2]);
                break;
            case '3': 
                data[2]++;
                sprintf(shm, "%d %d %d", data[0], data[1], data[2]);
                break;
            case '4':
                running = false;
                break;
            default:
                printf("Invalid selection\n");
                break;
        }
    }
    
    // Detach shared memory segment from process
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }
    
    // Remove shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }
    
    return 0;
}