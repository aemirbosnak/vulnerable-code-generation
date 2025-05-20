//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10

int main() {
  int shmid;
  int *shmptr;
  int i;
  pid_t pid;
  int status;

  // Create shared memory segment
  shmid = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0666);
  if (shmid == -1) {
    printf("Error creating shared memory segment\n");
    exit(1);
  }

  // Attach shared memory segment to process
  shmptr = shmat(shmid, NULL, 0);
  if (shmptr == (int *) -1) {
    printf("Error attaching shared memory segment\n");
    exit(1);
  }

  // Initialize shared memory segment
  for (i = 0; i < SIZE; i++) {
    shmptr[i] = i;
  }

  // Fork child process
  pid = fork();
  if (pid == 0) {
    // Child process
    for (i = 0; i < SIZE; i++) {
      shmptr[i] *= 2;
    }
  } else {
    // Parent process
    wait(&status);
    for (i = 0; i < SIZE; i++) {
      printf("%d = %d\n", i, shmptr[i]);
    }
  }

  // Detach shared memory segment
  if (shmdt(shmptr) == -1) {
    printf("Error detaching shared memory segment\n");
    exit(1);
  }

  // Delete shared memory segment
  if (shmctl(shmid, IPC_RMID, NULL) == -1) {
    printf("Error deleting shared memory segment\n");
    exit(1);
  }

  return 0;
}