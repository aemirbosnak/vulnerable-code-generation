//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

char *args[MAX_ARGS];
int num_args;

void *thread_run(void *arg) {
  execvp(args[0], args);
  perror("execvp");
  exit(1);
}

int main() {
  pthread_t tid;
  char line[MAX_LINE];

  while (1) {
    printf("sh> ");
    fflush(stdout);

    if (!fgets(line, MAX_LINE, stdin)) {
      printf("\n");
      exit(0);
    }

    num_args = 0;
    char *ptr = strtok(line, " ");
    while (ptr != NULL) {
      args[num_args++] = ptr;
      ptr = strtok(NULL, " ");
    }

    int len = strlen(args[num_args - 1]);
    if (args[num_args - 1][len - 1] == '\n') {
      args[num_args - 1][len - 1] = '\0';
    }

    if (strcmp(args[0], "exit") == 0) {
      exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
      if (num_args < 2) {
        fprintf(stderr, "cd: missing operand\n");
        continue;
      }
      if (chdir(args[1]) < 0) {
        perror("chdir");
        continue;
      }
    } else {
      if (pthread_create(&tid, NULL, thread_run, NULL) < 0) {
        perror("pthread_create");
        continue;
      }
      pthread_join(tid, NULL);
    }
  }

  return 0;
}