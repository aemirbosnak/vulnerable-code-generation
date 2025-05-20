//Code Llama-13B DATASET v1.0 Category: Interprocess communication ; Style: Claude Shannon
// Claude Shannon Interprocess Communication Example Program
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

// Shared memory segment
int *shm;

// Shared memory key
int key = 123456;

// Shared memory size
int shm_size = 1024;

int main(int argc, char **argv) {
  // Create shared memory segment
  int shmid = shmget(key, shm_size, 0666 | IPC_CREAT);
  if (shmid == -1) {
    perror("shmget");
    exit(1);
  }

  // Attach shared memory segment
  shm = (int *)shmat(shmid, NULL, 0);
  if (shm == (void *)-1) {
    perror("shmat");
    exit(1);
  }

  // Parent process
  if (fork() == 0) {
    // Child process
    sleep(5);

    // Write data to shared memory
    *shm = 1234;

    // Detach shared memory segment
    shmdt(shm);

    // Delete shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    exit(0);
  }

  // Parent process
  // Wait for child process to complete
  wait(NULL);

  // Read data from shared memory
  int data = *shm;
  printf("Data from shared memory: %d\n", data);

  // Detach shared memory segment
  shmdt(shm);

  // Delete shared memory segment
  shmctl(shmid, IPC_RMID, NULL);

  exit(0);
}