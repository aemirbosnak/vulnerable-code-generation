//Code Llama-13B DATASET v1.0 Category: Password management ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Password {
  char* username;
  char* password;
};

void add_password(struct Password* password) {
  printf("Enter username: ");
  scanf("%s", password->username);
  printf("Enter password: ");
  scanf("%s", password->password);
}

void remove_password(struct Password* password) {
  printf("Enter username: ");
  scanf("%s", password->username);
  free(password->username);
  free(password->password);
  password->username = NULL;
  password->password = NULL;
}

int main() {
  struct Password password;
  int choice;
  do {
    printf("1. Add Password\n");
    printf("2. Remove Password\n");
    printf("3. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        add_password(&password);
        break;
      case 2:
        remove_password(&password);
        break;
      case 3:
        break;
      default:
        printf("Invalid choice\n");
        break;
    }
  } while (choice != 3);
  return 0;
}