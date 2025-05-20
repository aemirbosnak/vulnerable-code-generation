//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MAX_SIZE 100
#define SHM_KEY 1234
#define SEM_KEY 5678

int shm_id;
char *shm_ptr;
int sem_id;

void create_shared_memory() {
  shm_id = shmget(SHM_KEY, MAX_SIZE, IPC_CREAT | 0666);
  if (shm_id == -1) {
    printf("Error creating shared memory\n");
    exit(1);
  }
  shm_ptr = (char *) shmat(shm_id, NULL, 0);
  if (shm_ptr == (char *) -1) {
    printf("Error attaching shared memory\n");
    exit(1);
  }
  memset(shm_ptr, 0, MAX_SIZE);
}

void create_semaphore() {
  sem_id = semget(SEM_KEY, 1, IPC_CREAT | 0666);
  if (sem_id == -1) {
    printf("Error creating semaphore\n");
    exit(1);
  }
}

void write_to_shared_memory(int pid) {
  sprintf(shm_ptr, "Hello from process %d", pid);
}

void read_from_shared_memory() {
  char *ptr = shm_ptr;
  while (*ptr!= '\0') {
    printf("%c", *ptr);
    ptr++;
  }
}

int main() {
  int pid, status;
  create_shared_memory();
  create_semaphore();
  if ((pid = fork()) == 0) {
    write_to_shared_memory(pid);
    exit(0);
  } else {
    waitpid(pid, &status, 0);
    if (status == 0) {
      printf("Child process has written to shared memory\n");
      read_from_shared_memory();
    } else {
      printf("Child process has exited with status %d\n", status);
    }
  }
  return 0;
}