//FormAI DATASET v1.0 Category: System administration ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int user_input, random_number;
  char choice;

  // Seed the random number generator
  srand(time(NULL));

  printf("You have discovered a secret program!\n");
  printf("As the chosen one, you must prove your worth by answering the following question.\n\n");

  // Generate a random number between 1 and 10
  random_number = rand() % 10 + 1;

  do {
    printf("What is the secret number? (Hint: it's between 1 and 10)\n");
    scanf("%d", &user_input);

    if (user_input == random_number) {
      printf("\nCongratulations! You have proven your worth and gained access to the hidden system administration program.\n");
      printf("Press any key to continue...\n");
      getchar();
      break;
    } else {
      printf("The secret number is not %d. Would you like to guess again? (y/n) \n", user_input);
      scanf(" %c", &choice);
    }
  } while (choice == 'y' || choice == 'Y');

  // Secret Program
  printf("\n\nWelcome to the Secret System Administration Program!\n\n");
  printf("You have access to the following options:\n");
  printf("1. Change user password.\n");
  printf("2. Run system backups.\n");
  printf("3. Manage disk space.\n");
  printf("4. Exit.\n\n");

  int option;
  do {
    printf("What would you like to do?\n");
    scanf("%d", &option);

    switch (option) {
      case 1:
        printf("Please enter the username for the password change:\n");
        char username[20];
        scanf("%s", username);
        printf("Password for user %s has been changed.\n", username);
        break;
      case 2:
        printf("Running system backups...\n");
        break;
      case 3:
        printf("Checking disk space...\n");
        break;
      case 4:
        printf("Exiting program...\n");
        exit(0);
        break;
      default:
        printf("Invalid option. Please try again.\n");
        break;
    }
  } while (option != 4);

  return 0;
}