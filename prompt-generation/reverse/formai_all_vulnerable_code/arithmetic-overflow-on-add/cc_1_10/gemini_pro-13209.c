//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

// Declare the semaphore union
union semun {
  int val;               // Value for SETVAL
  struct semid_ds *buf;  // Buffer for IPC_STAT, IPC_SET
  unsigned short *array;  // Array for GETALL, SETALL
  struct seminfo *__buf;  // Buffer for IPC_INFO
};

// Initialize the semaphore
int init_semaphore(key_t key, int value) {
  int semid;
  union semun arg;

  // Create a semaphore set with the given key
  semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666);
  if (semid == -1) {
    perror("semget");
    return -1;
  }

  // Set the semaphore value
  arg.val = value;
  if (semctl(semid, 0, SETVAL, arg) == -1) {
    perror("semctl");
    return -1;
  }

  return semid;
}

// Acquire the semaphore
int acquire_semaphore(int semid) {
  struct sembuf op;

  // Set the semaphore operation
  op.sem_num = 0;     // Semaphore number
  op.sem_op = -1;    // Decrement the semaphore value
  op.sem_flg = SEM_UNDO;  // Set the undo flag

  // Perform the semaphore operation
  if (semop(semid, &op, 1) == -1) {
    perror("semop");
    return -1;
  }

  return 0;
}

// Release the semaphore
int release_semaphore(int semid) {
  struct sembuf op;

  // Set the semaphore operation
  op.sem_num = 0;     // Semaphore number
  op.sem_op = 1;    // Increment the semaphore value
  op.sem_flg = SEM_UNDO;  // Set the undo flag

  // Perform the semaphore operation
  if (semop(semid, &op, 1) == -1) {
    perror("semop");
    return -1;
  }

  return 0;
}

// Main function
int main(int argc, char *argv[]) {
    pid_t child_pid;
    key_t key;
    int semid, i;
    int var;

    // Get the key for the semaphore
    key = ftok("semaphore.c", 'a');

    // Initialize the semaphore
    semid = init_semaphore(key, 1);
    if (semid == -1) {
        perror("init_semaphore");
        return -1;
    }

    // Create a new process
    child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return -1;
    }

    if (child_pid == 0) {
        // Child process
        for (i=0; i<3; i++) {
            // Acquire the semaphore
            if (acquire_semaphore(semid) == -1) {
                perror("acquire_semaphore");
                return -1;
            }

            // Critical section
            var++;
            printf("Child process: var = %d\n", var);

            // Release the semaphore
            if (release_semaphore(semid) == -1) {
                perror("release_semaphore");
                return -1;
            }

            // Sleep for a while
            sleep(1);
        }
    }
    else {
        // Parent process
        for (i=0; i<3; i++) {
            // Acquire the semaphore
            if (acquire_semaphore(semid) == -1) {
                perror("acquire_semaphore");
                return -1;
            }

            // Critical section
            var++;
            printf("Parent process: var = %d\n", var);

            // Release the semaphore
            if (release_semaphore(semid) == -1) {
                perror("release_semaphore");
                return -1;
            }

            // Sleep for a while
            sleep(1);
        }
    }

    return 0;
}