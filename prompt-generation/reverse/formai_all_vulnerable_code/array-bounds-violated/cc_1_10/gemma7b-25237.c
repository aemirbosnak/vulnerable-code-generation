//Gemma-7B DATASET v1.0 Category: Password management ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORDS 10

typedef struct Password {
  char name[20];
  char password[20];
  int used;
} Password;

int main() {
  Password passwords[MAX_PASSWORDS];

  for (int i = 0; i < MAX_PASSWORDS; i++) {
    passwords[i].used = 0;
  }

  char input[20];
  int index = -1;

  printf("Enter a command (add, list, exit): ");
  scanf("%s", input);

  switch (input[0]) {
    case 'a':
      printf("Enter the name of the password: ");
      scanf("%s", passwords[index].name);

      printf("Enter the password: ");
      scanf("%s", passwords[index].password);

      passwords[index].used = 1;
      break;

    case 'l':
      for (int i = 0; i < MAX_PASSWORDS; i++) {
        if (passwords[i].used) {
          printf("Name: %s, Password: %s\n", passwords[i].name, passwords[i].password);
        }
      }
      break;

    case 'e':
      exit(0);
      break;

    default:
      printf("Invalid command.\n");
  }

  return 0;
}