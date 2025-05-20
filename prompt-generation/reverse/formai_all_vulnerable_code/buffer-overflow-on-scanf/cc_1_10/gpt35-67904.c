//FormAI DATASET v1.0 Category: Password management ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct Password {
  char *username;
  char *password;
} Password;

Password passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
  if (num_passwords == MAX_PASSWORDS) {
    printf("Error: password database is full");
    return;
  }

  Password new_password = { .username = strdup(username), .password = strdup(password) };
  passwords[num_passwords] = new_password;
  num_passwords++;
}

void list_passwords() {
  for (int i = 0; i < num_passwords; i++) {
    printf("%s: %s\n", passwords[i].username, passwords[i].password);
  }
}

void delete_password(char *username) {
  int index = -1;
  for (int i = 0; i < num_passwords; i++) {
    if (strcmp(passwords[i].username, username) == 0) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("Error: username not found");
    return;
  }

  free(passwords[index].username);
  free(passwords[index].password);
  for (int i = index; i < num_passwords - 1; i++) {
    passwords[i] = passwords[i+1];
  }
  num_passwords--;
}

int main() {
  char command[MAX_PASSWORD_LENGTH];
  while (1) {
    printf("> ");
    scanf("%s", command);

    if (strcmp(command, "add") == 0) {
      char username[MAX_PASSWORD_LENGTH];
      char password[MAX_PASSWORD_LENGTH];
      scanf("%s %s", username, password);
      add_password(username, password);
    } else if (strcmp(command, "list") == 0) {
      list_passwords();
    } else if (strcmp(command, "delete") == 0) {
      char username[MAX_PASSWORD_LENGTH];
      scanf("%s", username);
      delete_password(username);
    } else if (strcmp(command, "quit") == 0) {
      break;
    } else {
      printf("Error: invalid command\n");
    }
  }

  // free allocated memory
  for (int i = 0; i < num_passwords; i++) {
    free(passwords[i].username);
    free(passwords[i].password);
  }

  return 0;
}