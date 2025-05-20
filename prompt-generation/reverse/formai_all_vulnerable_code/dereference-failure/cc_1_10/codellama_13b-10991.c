//Code Llama-13B DATASET v1.0 Category: Interprocess communication ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
  int shmid;
  char *shared_memory;
  key_t key = 1234;
  int *ptr;

  // Create a shared memory segment
  shmid = shmget(key, 1024, IPC_CREAT | 0666);
  if (shmid < 0) {
    perror("shmget");
    exit(1);
  }

  // Attach the shared memory segment to the process's address space
  shared_memory = shmat(shmid, NULL, 0);
  if (shared_memory == (char *)(-1)) {
    perror("shmat");
    exit(1);
  }

  // Initialize the shared memory segment with a string
  ptr = (int *)shared_memory;
  *ptr = 10;

  // Fork a new process
  pid_t pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(1);
  }

  // Parent process
  if (pid > 0) {
    // Wait for the child process to finish
    wait(NULL);

    // Read the value from the shared memory segment
    printf("Value from shared memory: %d\n", *ptr);

    // Detach the shared memory segment from the process's address space
    shmdt(shared_memory);
  }

  // Child process
  if (pid == 0) {
    // Read the value from the shared memory segment
    int value = *ptr;

    // Increment the value in the shared memory segment
    *ptr = value + 1;

    // Detach the shared memory segment from the process's address space
    shmdt(shared_memory);

    // Exit the child process
    exit(0);
  }

  return 0;
}