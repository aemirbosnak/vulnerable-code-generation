//Falcon2-11B DATASET v1.0 Category: Arithmetic ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
  int fd[2];
  int i, n, sum = 0;
  int status;

  /* Create pipe */
  if (pipe(fd) == -1) {
    printf("Error creating pipe\n");
    return 1;
  }

  /* Fork */
  pid_t pid = fork();
  if (pid == -1) {
    printf("Error forking\n");
    return 1;
  }

  if (pid == 0) { /* Child process */
    close(fd[1]); /* Close the write end of the pipe */

    /* Read numbers from pipe */
    for (i = 0; i < n; i++) {
      if (read(fd[0], &n, sizeof(int)) == -1) {
        printf("Error reading from pipe\n");
        exit(1);
      }

      sum += n;
    }

    printf("Child sum: %d\n", sum);
    exit(0);
  } else { /* Parent process */
    close(fd[0]); /* Close the read end of the pipe */

    /* Write numbers to pipe */
    for (i = 0; i < n; i++) {
      printf("Parent writing %d to pipe\n", i + 1);
      write(fd[1], &i + 1, sizeof(int));
    }

    /* Wait for child to finish */
    wait(&status);
    printf("Parent sum: %d\n", sum);
    exit(0);
  }

  return 0;
}