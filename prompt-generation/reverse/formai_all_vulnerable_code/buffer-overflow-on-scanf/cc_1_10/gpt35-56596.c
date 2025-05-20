//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20

char* generatePassword(int length) {
  static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{};:,.<>?`~";
  char* password = malloc(length + 1);

  if (password) {
    for (int i = 0; i < length; i++) {
      int randIndex = rand() % (int)(sizeof(charset) - 1);
      password[i] = charset[randIndex];
    }

    password[length] = '\0';
  }

  return password;
}

int main() {
  int length, choice;
  char* password;

  srand(time(NULL));

  printf("Welcome to the C Secure Password Generator!\n");
  printf("Choose length of the password (minimum 8, maximum 20): ");
  scanf("%d", &length);

  if (length < MIN_LENGTH || length > MAX_LENGTH) {
    printf("Invalid length!\n");
    return 1;
  }

  printf("Your password will be generated with length %d.\n", length);

  do {
    printf("Do you want to generate a password?\n");
    printf("1) Yes\n");
    printf("2) No\n");
    printf("Selection: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        password = generatePassword(length);
        printf("Your password is: %s\n", password);
        free(password);
        break;
      case 2:
        printf("Thank you for using the C Secure Password Generator!\n");
        break;
      default:
        printf("Invalid selection!\n");
        break;
    }
  } while (choice != 2);

  return 0;
}