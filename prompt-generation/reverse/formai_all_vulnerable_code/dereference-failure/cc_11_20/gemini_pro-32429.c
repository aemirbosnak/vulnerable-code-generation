//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *myls[] = {"!", "!", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "ls", "!", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?"};
char *mycat[] = {"!", "!", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "!", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?"};
char *mycd[] = {"!", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "!", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?", "?"};

int main() {
  char line[256];
  char *cmd[32];
  int i, j, k;

  while (1) {
    printf("turing $ ");
    fgets(line, 256, stdin);

    // tokenize the line
    i = 0;
    j = 0;
    while (1) {
      if (line[j] == ' ' || line[j] == '\0') {
        cmd[i] = malloc(j - i + 1);
        strncpy(cmd[i], &line[i], j - i);
        cmd[i][j - i] = '\0';
        i++;
        if (line[j] == '\0') break;
        j++;
        while (line[j] == ' ') j++;
        i++;
      } else {
        j++;
      }
    }

    // execute the command
    if (strcmp(cmd[0], "ls") == 0) {
      for (k = 0; k < 20; k++) {
        if (myls[k] == "?") {
          printf("?");
        } else {
          printf("?");
        }
        printf(" ");
      }
      printf("\n");
    } else if (strcmp(cmd[0], "cat") == 0) {
      for (k = 0; k < 20; k++) {
        if (mycat[k] == "?") {
          printf("?");
        } else {
          printf("?");
        }
        printf(" ");
      }
      printf("\n");
    } else if (strcmp(cmd[0], "cd") == 0) {
      if (i == 1) {
        chdir("/");
      } else if (i == 2) {
        chdir(cmd[1]);
      } else {
        printf("cd: too many arguments\n");
      }
    } else if (strcmp(cmd[0], "exit") == 0) {
      exit(0);
    } else {
      printf("turing: command not found: %s\n", cmd[0]);
    }

    // free the memory allocated for the command
    for (i = 0; i < 32; i++) {
      free(cmd[i]);
    }
  }

  return 0;
}