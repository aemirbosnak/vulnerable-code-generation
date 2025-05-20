//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
  // Create a shared memory segment
  int shm_id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
  if (shm_id < 0) {
    perror("shmget");
    exit(EXIT_FAILURE);
  }

  // Attach the shared memory segment to the current process
  int *counter = (int *)shmat(shm_id, NULL, 0);
  if (counter == (int *)-1) {
    perror("shmat");
    exit(EXIT_FAILURE);
  }

  // Create a child process
  pid_t child_pid = fork();
  if (child_pid < 0) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  // Increment the counter in the parent process
  if (child_pid > 0) {
    for (int i = 0; i < 1000000; i++) {
      (*counter)++;
    }
  }

  // Increment the counter in the child process
  else {
    for (int i = 0; i < 1000000; i++) {
      (*counter)++;
    }
  }

  // Wait for the child process to finish
  int status;
  waitpid(child_pid, &status, 0);

  // Print the final value of the counter
  printf("The final value of the counter is %d\n", *counter);

  // Detach the shared memory segment from the current process
  if (shmdt(counter) < 0) {
    perror("shmdt");
    exit(EXIT_FAILURE);
  }

  // Delete the shared memory segment
  if (shmctl(shm_id, IPC_RMID, NULL) < 0) {
    perror("shmctl");
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}