#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char input[1024];
  int room = 1;

  while (room) {
    switch (room) {
      case 1:
        printf("You are in the first room.\n");
        printf("Enter the command: ");
        fgets(input, 1024, stdin);
        if (strcmp(input, "go north") == 0) {
          room = 2;
        }
        break;
      case 2:
        printf("You are in the second room.\n");
        printf("Enter the command: ");
        fgets(input, 1024, stdin);
        if (strcmp(input, "go south") == 0) {
          room = 1;
        }
        break;
      case 3:
        printf("You are in the third room.\n");
        printf("Enter the command: ");
        fgets(input, 1024, stdin);
        if (strcmp(input, "go east") == 0) {
          room = 4;
        }
        break;
      case 4:
        printf("You are in the fourth room.\n");
        printf("Enter the command: ");
        fgets(input, 1024, stdin);
        if (strcmp(input, "go west") == 0) {
          room = 3;
        }
        break;
      case 5:
        printf("You are in the fifth room.\n");
        printf("Enter the command: ");
        fgets(input, 1024, stdin);
        if (strcmp(input, "exit") == 0) {
          room = 0;
        }
        break;
    }
  }

  return 0;
}
