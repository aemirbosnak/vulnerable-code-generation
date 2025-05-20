//FormAI DATASET v1.0 Category: Password management ; Style: Cryptic
#include <stdio.h>

/* Define user structure */
struct user {
  char username[20];
  char password[20];
};

/* Encryption function */
void encrypt(char password[]) {
  int i;
  for (i = 0; password[i]; ++i) {
    password[i] = password[i] + i * i;
  }
}

/* Decryption function */
void decrypt(char password[]) {
  int i;
  for (i = 0; password[i]; ++i) {
    password[i] = password[i] - i * i;
  }
}

/* Login function */
int login(struct user users[], char username[], char password[]) {
  int i;
  for (i = 0; i < 3; ++i) {
    if (strcmp(users[i].username, username) == 0) {
      decrypt(users[i].password);
      if (strcmp(users[i].password, password) == 0) {
        printf("Login successful!\n");
        return 1;
      } else {
        printf("Incorrect password, please try again.\n");
        return 0;
      }
    }
  }
  printf("User not found, please try again.\n");
  return 0;
}

/* Change password function */
void change_password(struct user users[], char username[], char old_password[], char new_password[]) {
  int i;
  for (i = 0; i < 3; ++i) {
    if (strcmp(users[i].username, username) == 0) {
      decrypt(users[i].password);
      if (strcmp(users[i].password, old_password) == 0) {
        encrypt(new_password);
        strcpy(users[i].password, new_password);
        printf("Password changed successfully!\n");
        return;
      } else {
        printf("Incorrect password, please try again.\n");
        return;
      }
    }
  }
  printf("User not found, please try again.\n");
}

int main() {
  struct user users[3] = {
    {"Alice", "abc123"},
    {"Bob", "def456"},
    {"Charlie", "ghi789"}
  };
  char username[20], password[20], new_password[20];
  int option;
  do {
    printf("\n");
    printf("1. Login\n");
    printf("2. Change password\n");
    printf("3. Exit\n");
    printf("Enter option: ");
    scanf("%d", &option);
    switch (option) {
      case 1:
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);
        encrypt(password);
        login(users, username, password);
        break;
      case 2:
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter old password: ");
        scanf("%s", password);
        printf("Enter new password: ");
        scanf("%s", new_password);
        encrypt(password);
        encrypt(new_password);
        change_password(users, username, password, new_password);
        break;
      case 3:
        printf("Goodbye!\n");
        break;
      default:
        printf("Invalid option, please try again.\n");
    }
  } while (option != 3);
  return 0;
}