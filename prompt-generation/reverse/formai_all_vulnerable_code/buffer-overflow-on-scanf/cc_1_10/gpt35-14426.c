//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int password_length, i;
  char password[20];
  const char alpha[] = "abcdefghijklmnopqrstuvwxyz";
  const char numeric[] = "0123456789";
  const char special[] = "!@#$%^&*()_+-=";
  const int alpha_length = sizeof(alpha) - 1;
  const int numeric_length = sizeof(numeric) - 1;
  const int special_length = sizeof(special) - 1;
  srand(time(NULL));

  printf("Welcome to the Secure Password Generator\n");
  printf("Please enter desired password length: ");
  scanf("%d", &password_length);

  if (password_length < 1 || password_length > 20) {
    printf("Invalid password length, please enter a value between 1 and 20\n");
    return 0;
  }

  printf("Do you want to include alphabets (y/n)? ");
  char choice;
  scanf(" %c", &choice);
  if (choice == 'y') {
    int random_index = rand() % alpha_length;
    password[i] = alpha[random_index];
  }

  printf("Do you want to include numerics (y/n)? ");
  scanf(" %c", &choice);
  if (choice == 'y') {
    int random_index = rand() % numeric_length;
    password[i] = numeric[random_index];
  }

  printf("Do you want to include special characters (y/n)? ");
  scanf(" %c", &choice);
  if (choice == 'y') {
    int random_index = rand() % special_length;
    password[i] = special[random_index];
  }

  for (i = 0; i < password_length; i++) {
    int category = rand() % 3;
    switch (category) {
      case 0:
        password[i] = alpha[rand() % alpha_length];
        break;
      case 1:
        password[i] = numeric[rand() % numeric_length];
        break;
      case 2:
        password[i] = special[rand() % special_length];
        break;
    }
  }
  password[password_length] = '\0';
  printf("Your Password: %s\n", password);
  return 0;
}