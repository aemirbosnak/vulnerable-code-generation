//Gemma-7B DATASET v1.0 Category: Password management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

typedef struct Password {
  char *name;
  char *pass;
  int valid;
} Password;

void generate_passwords(Password *passwords) {
  for (int i = 0; i < MAX_PASSWORDS; i++) {
    passwords[i].name = malloc(20);
    passwords[i].pass = malloc(20);
    passwords[i].valid = 0;
  }
}

void set_passwords(Password *passwords) {
  for (int i = 0; i < MAX_PASSWORDS; i++) {
    printf("Enter name for password %d: ", i + 1);
    scanf("%s", passwords[i].name);

    printf("Enter password for %s: ", passwords[i].name);
    scanf("%s", passwords[i].pass);

    passwords[i].valid = 1;
  }
}

void print_passwords(Password *passwords) {
  for (int i = 0; i < MAX_PASSWORDS; i++) {
    if (passwords[i].valid) {
      printf("Name: %s\n", passwords[i].name);
      printf("Password: %s\n", passwords[i].pass);
      printf("\n");
    }
  }
}

int main() {
  Password passwords[MAX_PASSWORDS];
  generate_passwords(passwords);
  set_passwords(passwords);
  print_passwords(passwords);

  return 0;
}