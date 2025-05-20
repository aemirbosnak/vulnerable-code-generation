//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <file>\n", argv[0]);
    return EXIT_FAILURE;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  char buffer[1024];
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    int len = strlen(buffer);
    if (buffer[len - 1] == '\n') {
      buffer[len - 1] = '\0';
    }

    pid_t pid = fork();
    if (pid == 0) { // child process
      execlp("./spam_check", "./spam_check", buffer, NULL);
      perror("execlp");
      exit(EXIT_FAILURE);
    } else { // parent process
      int status;
      wait(&status);
      if (WIFEXITED(status)) {
        if (WEXITSTATUS(status) == 0) {
          printf("%s is not spam\n", buffer);
        } else {
          printf("%s is spam\n", buffer);
        }
      } else {
        perror("wait");
      }
    }
  }

  fclose(fp);
  return EXIT_SUCCESS;
}