//FormAI DATASET v1.0 Category: Syntax parsing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 100

int main(void) {
  char input[BUFSIZE];
  char cmd[BUFSIZE];
  char arg[BUFSIZE];
  char *ptr_arg;
  
  while (1) {
    printf("Enter a command: ");
    fgets(input, BUFSIZE, stdin);

    if (sscanf(input, "%s %s", cmd, arg) < 2) {
      ptr_arg = NULL;
    } else {
      ptr_arg = arg;
    }

    if (strcmp(cmd, "add") == 0) {
      if (ptr_arg != NULL) {
        printf("add %s\n", ptr_arg);
      } else {
        printf("add usage: add <number>\n");
      }
    } else if (strcmp(cmd, "sub") == 0) {
      if (ptr_arg != NULL) {
        printf("sub %s\n", ptr_arg);
      } else {
        printf("sub usage: sub <number>\n");
      }
    } else if (strcmp(cmd, "mul") == 0) {
      if (ptr_arg != NULL) {
        printf("mul %s\n", ptr_arg);
      } else {
        printf("mul usage: mul <number>\n");
      }
    } else if (strcmp(cmd, "div") == 0) {
      if (ptr_arg != NULL) {
        printf("div %s\n", ptr_arg);
      } else {
        printf("div usage: div <number>\n");
      }
    } else if (strcmp(cmd, "quit") == 0) {
      exit(0);
    } else {
      printf("Invalid command: %s\n", cmd);
    }
  }

  return 0;
}