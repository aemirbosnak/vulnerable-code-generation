//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
  // create pipes
  int readPipe[2], writePipe[2];
  if (pipe(readPipe) == -1 || pipe(writePipe) == -1) {
    perror("pipe");
    exit(1);
  }

  // fork child process
  int childPid = fork();
  if (childPid == -1) {
    perror("fork");
    exit(1);
  }

  // child process reads from pipes
  if (childPid == 0) {
    close(writePipe[0]);

    // read from pipe
    char input[256];
    while (read(readPipe[1], input, sizeof(input)) > 0) {
      printf("Input: %s\n", input);
    }

    // exit child process
    exit(0);
  }

  // parent process writes to pipes
  else {
    close(readPipe[1]);

    // write to pipe
    char vote[256];
    printf("Enter your vote: ");
    scanf("%s", vote);

    while (write(writePipe[0], vote, sizeof(vote)) == sizeof(vote)) {
      printf("Vote sent\n");
    }

    // close pipes and join child process
    close(writePipe[1]);
    wait(NULL);
  }

  return 0;
}