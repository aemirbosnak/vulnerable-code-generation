//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 20

// Function to generate a random password
char *generate_password(int length, int uppercase, int lowercase, int numbers, int symbols) {
  char *password = malloc(length + 1);

  srand(time(NULL));

  for (int i = 0; i < length; i++) {
    int type = rand() % 4;

    if (type == 0 && uppercase) {
      password[i] = rand() % 26 + 'A';
    } else if (type == 1 && lowercase) {
      password[i] = rand() % 26 + 'a';
    } else if (type == 2 && numbers) {
      password[i] = rand() % 10 + '0';
    } else if (type == 3 && symbols) {
      password[i] = rand() % 30 + '!';
    }
  }

  password[length] = '\0';

  return password;
}

// Function to print the password
void print_password(char *password) {
  printf("Your password is: %s\n", password);
}

// Main function
int main() {
  // Get the length of the password
  int length;
  printf("Enter the length of the password: ");
  scanf("%d", &length);

  // Get the options for the password
  int uppercase, lowercase, numbers, symbols;
  printf("Do you want uppercase letters (1 for yes, 0 for no): ");
  scanf("%d", &uppercase);
  printf("Do you want lowercase letters (1 for yes, 0 for no): ");
  scanf("%d", &lowercase);
  printf("Do you want numbers (1 for yes, 0 for no): ");
  scanf("%d", &numbers);
  printf("Do you want symbols (1 for yes, 0 for no): ");
  scanf("%d", &symbols);

  // Generate the password
  char *password = generate_password(length, uppercase, lowercase, numbers, symbols);

  // Print the password
  print_password(password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}