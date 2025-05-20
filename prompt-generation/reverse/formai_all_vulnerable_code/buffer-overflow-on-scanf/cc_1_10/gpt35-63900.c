//FormAI DATASET v1.0 Category: Password management ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_LOGIN_ATTEMPTS 3

struct Login {
  char username[MAX_USERNAME_LENGTH + 1]; // +1 for null terminator
  char password[MAX_PASSWORD_LENGTH + 1]; // +1 for null terminator
};

int main(void) {
  struct Login login;
  int remaining_attempts = MAX_LOGIN_ATTEMPTS;

  printf("Welcome to Password Manager. Please log in to continue.\n");

  while (remaining_attempts > 0) {
    printf("Username: ");
    scanf("%s", login.username);

    printf("Password: ");
    scanf("%s", login.password);

    if (strcmp(login.username, "myusername") == 0 &&
        strcmp(login.password, "mypassword") == 0) {
      printf("Login successful! You may now access your passwords.\n");
      break;
    } else {
      remaining_attempts--;
      printf("Incorrect username or password. You have %d remaining login attempts.\n", remaining_attempts);
    }
  }

  if (remaining_attempts == 0) {
    printf("You have exceeded the maximum amount of login attempts. Please try again later.\n");
    exit(EXIT_FAILURE);
  }

  char password[100];
  printf("Please enter a new password: ");
  scanf("%s", password);

  FILE *fp;
  fp = fopen("passwords.txt", "a");
  fprintf(fp, "%s\n", password);
  fclose(fp);

  printf("Your password has been successfully saved. Thank you for using Password Manager!\n");

  return 0;
}