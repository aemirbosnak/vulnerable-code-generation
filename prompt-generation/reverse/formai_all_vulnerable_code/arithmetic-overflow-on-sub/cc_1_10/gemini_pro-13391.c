//GEMINI-pro DATASET v1.0 Category: Database querying ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>

// Define the shared memory segment
#define SHM_SIZE 1024

// Define the semaphore key
#define SEM_KEY 12345

// Define the maximum number of clients
#define MAX_CLIENTS 10

// Define the client structure
typedef struct {
  int id;
  char name[256];
  char query[256];
} Client;

// Define the shared memory structure
typedef struct {
  int num_clients;
  Client clients[MAX_CLIENTS];
} SharedMemory;

// Define the semaphore operations
#define SEM_LOCK 0
#define SEM_UNLOCK 1

// Function to lock the semaphore
int sem_lock(int semid) {
  struct sembuf op;
  op.sem_num = SEM_LOCK;
  op.sem_op = -1;
  op.sem_flg = 0;
  return semop(semid, &op, 1);
}

// Function to unlock the semaphore
int sem_unlock(int semid) {
  struct sembuf op;
  op.sem_num = SEM_UNLOCK;
  op.sem_op = 1;
  op.sem_flg = 0;
  return semop(semid, &op, 1);
}

// Main function
int main() {
  // Create the shared memory segment
  int shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
  if (shmid == -1) {
    perror("shmget");
    exit(EXIT_FAILURE);
  }

  // Attach the shared memory segment to the current process
  SharedMemory *shared_memory = (SharedMemory *)shmat(shmid, NULL, 0);
  if (shared_memory == NULL) {
    perror("shmat");
    exit(EXIT_FAILURE);
  }

  // Create the semaphore
  int semid = semget(SEM_KEY, 1, IPC_CREAT | 0666);
  if (semid == -1) {
    perror("semget");
    exit(EXIT_FAILURE);
  }

  // Initialize the semaphore
  if (semctl(semid, 0, SETVAL, 1) == -1) {
    perror("semctl");
    exit(EXIT_FAILURE);
  }

  // Loop forever
  while (1) {
    // Lock the semaphore
    if (sem_lock(semid) == -1) {
      perror("sem_lock");
      exit(EXIT_FAILURE);
    }

    // Check if there are any clients
    if (shared_memory->num_clients == 0) {
      // Unlock the semaphore
      if (sem_unlock(semid) == -1) {
        perror("sem_unlock");
        exit(EXIT_FAILURE);
      }

      // Continue to the next iteration of the loop
      continue;
    }

    // Get the next client
    Client client = shared_memory->clients[0];

    // Shift the clients down in the array
    memmove(shared_memory->clients, shared_memory->clients + 1, sizeof(Client) * shared_memory->num_clients);

    // Decrement the number of clients
    shared_memory->num_clients--;

    // Unlock the semaphore
    if (sem_unlock(semid) == -1) {
      perror("sem_unlock");
      exit(EXIT_FAILURE);
    }

    // Process the client's query
    printf("Processing query from client %d: %s\n", client.id, client.query);
  }

  // Detach the shared memory segment from the current process
  if (shmdt(shared_memory) == -1) {
    perror("shmdt");
    exit(EXIT_FAILURE);
  }

  // Delete the shared memory segment
  if (shmctl(shmid, IPC_RMID, NULL) == -1) {
    perror("shmctl");
    exit(EXIT_FAILURE);
  }

  // Delete the semaphore
  if (semctl(semid, 0, IPC_RMID) == -1) {
    perror("semctl");
    exit(EXIT_FAILURE);
  }

  return 0;
}