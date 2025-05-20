//GEMINI-pro DATASET v1.0 Category: Password management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 256

typedef struct {
  char *password;
  int length;
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *password) {
  if (num_passwords >= MAX_PASSWORDS) {
    fprintf(stderr, "Error: Too many passwords!\n");
    return;
  }

  passwords[num_passwords].password = strdup(password);
  passwords[num_passwords].length = strlen(password);
  num_passwords++;
}

void print_passwords() {
  for (int i = 0; i < num_passwords; i++) {
    printf("%s\n", passwords[i].password);
  }
}

void free_passwords() {
  for (int i = 0; i < num_passwords; i++) {
    free(passwords[i].password);
  }
}

int main() {
  char *password;

  while (1) {
    printf("Enter a password (or 'q' to quit): ");
    scanf("%s", password);

    if (strcmp(password, "q") == 0) {
      break;
    }

    add_password(password);
  }

  print_passwords();
  free_passwords();

  return 0;
}