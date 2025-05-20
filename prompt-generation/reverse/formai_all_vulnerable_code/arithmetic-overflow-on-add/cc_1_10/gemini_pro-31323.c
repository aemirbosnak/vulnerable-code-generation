//GEMINI-pro DATASET v1.0 Category: Password management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length of a password
#define MAX_PASSWORD_LENGTH 256

// Define the number of different character sets to use
#define NUM_CHARSETS 4

// Define the character sets
char charset1[] = "abcdefghijklmnopqrstuvwxyz";
char charset2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char charset3[] = "0123456789";
char charset4[] = "!@#$%^&*()_+=-";

// Define the probability distribution for each character set
double prob_charset1 = 0.4;
double prob_charset2 = 0.3;
double prob_charset3 = 0.2;
double prob_charset4 = 0.1;

// Generate a random password of the given length
char *generate_password(int length) {
  // Allocate memory for the password
  char *password = malloc(length + 1);

  // Seed the random number generator
  srand(time(NULL));

  // Generate the password
  for (int i = 0; i < length; i++) {
    // Choose a random character set
    double r = (double)rand() / (double)RAND_MAX;
    if (r < prob_charset1) {
      password[i] = charset1[rand() % strlen(charset1)];
    } else if (r < prob_charset1 + prob_charset2) {
      password[i] = charset2[rand() % strlen(charset2)];
    } else if (r < prob_charset1 + prob_charset2 + prob_charset3) {
      password[i] = charset3[rand() % strlen(charset3)];
    } else {
      password[i] = charset4[rand() % strlen(charset4)];
    }
  }

  // Terminate the password with a null character
  password[length] = '\0';

  // Return the password
  return password;
}

// Print the password to the console
void print_password(char *password) {
  printf("Your password is: %s\n", password);
}

// Get the length of the password from the user
int get_password_length() {
  int length;
  printf("Enter the desired length of the password: ");
  scanf("%d", &length);
  return length;
}

// Main function
int main() {
  // Get the length of the password from the user
  int length = get_password_length();

  // Generate a random password of the given length
  char *password = generate_password(length);

  // Print the password to the console
  print_password(password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}