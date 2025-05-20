//GEMINI-pro DATASET v1.0 Category: Password management ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 32
#define MASTER_PASSWORD "Wibblywobblytimeywimey"

typedef struct password {
  char username[MAX_PASSWORD_LEN];
  char password[MAX_PASSWORD_LEN];
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
  if (num_passwords == MAX_PASSWORDS) {
    printf("Password database is full.\n");
    return;
  }

  strcpy(passwords[num_passwords].username, username);
  strcpy(passwords[num_passwords].password, password);
  num_passwords++;
}

void list_passwords() {
  int i;

  for (i = 0; i < num_passwords; i++) {
    printf("%s: %s\n", passwords[i].username, passwords[i].password);
  }
}

void search_password(char *username) {
  int i;

  for (i = 0; i < num_passwords; i++) {
    if (strcmp(passwords[i].username, username) == 0) {
      printf("Password for %s: %s\n", username, passwords[i].password);
      return;
    }
  }

  printf("Password not found.\n");
}

bool verify_master_password(char *password) {
  return strcmp(password, MASTER_PASSWORD) == 0;
}

int main() {
  char input[1024];
  bool running = true;

  srand(time(NULL));

  printf("Welcome to the Mind-Bending Password Manager.\n");

  while (running) {
    printf("\n> ");
    fgets(input, sizeof(input), stdin);

    if (strncmp(input, "add", 3) == 0) {
      char username[MAX_PASSWORD_LEN];
      char password[MAX_PASSWORD_LEN];

      sscanf(input, "add %s %s", username, password);
      add_password(username, password);
    } else if (strncmp(input, "list", 4) == 0) {
      list_passwords();
    } else if (strncmp(input, "search", 6) == 0) {
      char username[MAX_PASSWORD_LEN];

      sscanf(input, "search %s", username);
      search_password(username);
    } else if (strncmp(input, "master", 6) == 0) {
      char password[MAX_PASSWORD_LEN];

      sscanf(input, "master %s", password);
      if (verify_master_password(password)) {
        printf("Master password entered correctly.\n");
      } else {
        printf("Incorrect master password.\n");
      }
    } else if (strncmp(input, "quit", 4) == 0) {
      running = false;
    } else {
      printf("Invalid command.\n");
    }
  }

  printf("Exiting Mind-Bending Password Manager.\n");
  return 0;
}