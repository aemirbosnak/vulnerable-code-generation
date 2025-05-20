//FormAI DATASET v1.0 Category: Interprocess communication ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;

    // User inputs
    int size;
    char message[256];

    // Get the shared memory size from the user input
    printf("Enter the size of the shared memory (in bytes): ");
    scanf("%d", &size);

    // Get the message to be sent from the user input
    printf("Enter the message to be sent: ");
    scanf("%s", message);

    // Generate a unique key for the shared memory
    if ((key = ftok("shmfile", 'R')) == -1) {
        perror("ftok");
        exit(1);
    }

    // Create the shared memory and get the id
    if ((shmid = shmget(key, size, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the shared memory segment to our data space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Copy the message into the shared memory
    strncpy(shm, message, size);

    // Let the user know the message has been sent
    printf("Message sent to shared memory.\n");

    // Wait for the second process to read the message
    while (*shm != '*') {
        sleep(1);
    }

    // Detach the shared memory segment
    shmdt(shm);

    // Delete the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}