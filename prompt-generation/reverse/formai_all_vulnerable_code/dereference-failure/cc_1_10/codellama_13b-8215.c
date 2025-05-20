//Code Llama-13B DATASET v1.0 Category: Interprocess communication ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 4096

int main() {
  // Create a shared memory segment
  int shm_id = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);
  if (shm_id == -1) {
    perror("shmget");
    exit(1);
  }

  // Attach the shared memory segment to the current process
  char *shm_addr = shmat(shm_id, NULL, 0);
  if (shm_addr == (char *)-1) {
    perror("shmat");
    exit(1);
  }

  // Create a pipe
  int fds[2];
  if (pipe(fds) == -1) {
    perror("pipe");
    exit(1);
  }

  // Fork a child process
  pid_t pid = fork();
  if (pid == 0) {
    // Child process

    // Close the write end of the pipe
    close(fds[1]);

    // Read from the shared memory segment and the pipe
    char buffer[SHM_SIZE];
    ssize_t bytes_read = read(fds[0], buffer, SHM_SIZE);
    if (bytes_read == -1) {
      perror("read");
      exit(1);
    }
    printf("Child received message: %s\n", buffer);

    // Read from the shared memory segment
    printf("Child read from shared memory: %s\n", shm_addr);

    // Detach the shared memory segment
    shmdt(shm_addr);

    // Close the shared memory segment
    shmctl(shm_id, IPC_RMID, 0);

    // Close the pipe
    close(fds[0]);

    exit(0);
  } else if (pid > 0) {
    // Parent process

    // Close the read end of the pipe
    close(fds[0]);

    // Write to the shared memory segment and the pipe
    char buffer[] = "Hello, world!";
    ssize_t bytes_written = write(fds[1], buffer, strlen(buffer));
    if (bytes_written == -1) {
      perror("write");
      exit(1);
    }
    printf("Parent wrote message: %s\n", buffer);

    // Write to the shared memory segment
    strcpy(shm_addr, buffer);
    printf("Parent wrote to shared memory: %s\n", shm_addr);

    // Detach the shared memory segment
    shmdt(shm_addr);

    // Close the shared memory segment
    shmctl(shm_id, IPC_RMID, 0);

    // Close the pipe
    close(fds[1]);

    // Wait for the child process to finish
    wait(NULL);

    exit(0);
  } else {
    perror("fork");
    exit(1);
  }
}