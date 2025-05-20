//Code Llama-13B DATASET v1.0 Category: Interprocess communication ; Style: ephemeral
// interprocess_communication.c

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUFFER_SIZE 1024
#define SHM_KEY 1234

int main() {
  int shm_id;
  char *shm_addr;
  int status;

  // create shared memory segment
  shm_id = shmget(SHM_KEY, BUFFER_SIZE, IPC_CREAT | 0666);
  if (shm_id == -1) {
    perror("shmget");
    exit(1);
  }

  // attach shared memory segment
  shm_addr = shmat(shm_id, NULL, 0);
  if (shm_addr == (char *)-1) {
    perror("shmat");
    exit(1);
  }

  // write to shared memory
  strcpy(shm_addr, "Hello, world!");

  // fork a child process
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(1);
  }

  // child process
  if (pid == 0) {
    // read from shared memory
    char buffer[BUFFER_SIZE];
    strcpy(buffer, shm_addr);
    printf("Child: %s\n", buffer);
    exit(0);
  }

  // parent process
  wait(&status);
  printf("Parent: %s\n", shm_addr);

  // detach shared memory segment
  if (shmdt(shm_addr) == -1) {
    perror("shmdt");
    exit(1);
  }

  // delete shared memory segment
  if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
    perror("shmctl");
    exit(1);
  }

  return 0;
}