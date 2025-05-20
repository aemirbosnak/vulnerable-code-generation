//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: complex
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define SEM_KEY 1234
#define SHM_KEY 5678
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int shmid, semid;
  char *shm_ptr;
  struct sembuf sem_op;

  // Create shared memory segment
  if ((shmid = shmget(SHM_KEY, BUFFER_SIZE, IPC_CREAT | 0666)) == -1) {
    perror("shmget");
    exit(1);
  }

  // Attach shared memory segment to process's address space
  if ((shm_ptr = shmat(shmid, NULL, 0)) == (void *)-1) {
    perror("shmat");
    exit(1);
  }

  // Create semaphore set
  if ((semid = semget(SEM_KEY, 1, IPC_CREAT | 0666)) == -1) {
    perror("semget");
    exit(1);
  }

  // Initialize semaphore to 1
  sem_op.sem_num = 0;
  sem_op.sem_op = 1;
  sem_op.sem_flg = 0;
  if (semop(semid, &sem_op, 1) == -1) {
    perror("semop");
    exit(1);
  }

  // Fork child process
  int pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(1);
  }

  // Child process
  if (pid == 0) {
    while (1) {
      // Wait for semaphore to be signaled
      sem_op.sem_op = -1;
      if (semop(semid, &sem_op, 1) == -1) {
        perror("semop");
        exit(1);
      }

      // Read data from shared memory segment
      printf("Child: %s\n", shm_ptr);

      // Signal semaphore to indicate that data has been processed
      sem_op.sem_op = 1;
      if (semop(semid, &sem_op, 1) == -1) {
        perror("semop");
        exit(1);
      }
    }
  }

  // Parent process
  else {
    while (1) {
      // Prompt user for data
      printf("Parent: Enter data: ");
      fgets(shm_ptr, BUFFER_SIZE, stdin);

      // Signal semaphore to indicate that data has been written
      sem_op.sem_op = 1;
      if (semop(semid, &sem_op, 1) == -1) {
        perror("semop");
        exit(1);
      }

      // Wait for semaphore to be signaled to indicate that data has been processed
      sem_op.sem_op = -1;
      if (semop(semid, &sem_op, 1) == -1) {
        perror("semop");
        exit(1);
      }
    }
  }

  // Cleanup
  shmdt(shm_ptr);
  shmctl(shmid, IPC_RMID, NULL);
  semctl(semid, 0, IPC_RMID);

  return 0;
}