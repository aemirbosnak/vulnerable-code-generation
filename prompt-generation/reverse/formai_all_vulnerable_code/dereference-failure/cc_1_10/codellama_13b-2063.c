//Code Llama-13B DATASET v1.0 Category: Interprocess communication ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
  // Create a shared memory segment
  int shm_id = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
  if (shm_id == -1) {
    perror("shmget");
    exit(1);
  }

  // Attach the shared memory segment to the process's address space
  void *shm_addr = shmat(shm_id, NULL, 0);
  if (shm_addr == (void *)-1) {
    perror("shmat");
    exit(1);
  }

  // Create a pipe
  int pipe_fd[2];
  if (pipe(pipe_fd) == -1) {
    perror("pipe");
    exit(1);
  }

  // Fork a child process
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(1);
  }

  // Parent process
  if (pid > 0) {
    // Close the write end of the pipe
    close(pipe_fd[1]);

    // Read from the pipe
    char buf[1024];
    ssize_t n = read(pipe_fd[0], buf, 1024);
    if (n == -1) {
      perror("read");
      exit(1);
    }

    // Write the data to the shared memory segment
    memcpy(shm_addr, buf, n);

    // Detach the shared memory segment
    shmdt(shm_addr);

    // Wait for the child process to exit
    wait(NULL);

    // Close the read end of the pipe
    close(pipe_fd[0]);
  }

  // Child process
  if (pid == 0) {
    // Close the read end of the pipe
    close(pipe_fd[0]);

    // Write some data to the pipe
    char buf[] = "Hello, world!";
    ssize_t n = write(pipe_fd[1], buf, sizeof(buf));
    if (n == -1) {
      perror("write");
      exit(1);
    }

    // Close the write end of the pipe
    close(pipe_fd[1]);
  }

  return 0;
}