//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main() {
  // Create a shared memory segment
  int shmid = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0600);
  if (shmid < 0) {
    perror("shmget");
    exit(1);
  }

  // Attach the shared memory segment to the current process
  int *shared_memory = (int *)shmat(shmid, NULL, 0);
  if (shared_memory == (int *)-1) {
    perror("shmat");
    exit(1);
  }

  // Create a child process
  pid_t child_pid = fork();
  if (child_pid < 0) {
    perror("fork");
    exit(1);
  }

  // In the child process, increment the shared memory value
  if (child_pid == 0) {
    *shared_memory += 1;
    exit(0);
  }

  // In the parent process, wait for the child process to complete
  int status;
  wait(&status);

  // Print the shared memory value
  printf("The shared memory value is: %d\n", *shared_memory);

  // Detach the shared memory segment from the current process
  shmdt(shared_memory);

  // Remove the shared memory segment
  shmctl(shmid, IPC_RMID, NULL);

  return 0;
}