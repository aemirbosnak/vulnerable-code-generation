//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Happy Password Generator! (tm)

// Generate a random number between min and max
int rand_range(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Generate a random character from the given set
char rand_char(char *set) {
  return set[rand_range(0, strlen(set) - 1)];
}

// Generate a password of the given length
char *generate_password(int length) {
  // Initialize the password string
  char *password = malloc(length + 1);
  password[length] = '\0';

  // Generate the password characters
  for (int i = 0; i < length; i++) {
    // Choose a random character set based on the position
    char *set;
    if (i % 3 == 0) {
      set = "abcdefghijklmnopqrstuvwxyz";
    } else if (i % 3 == 1) {
      set = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    } else {
      set = "0123456789~!@#$%^&*()_+";
    }

    // Append a random character to the password
    password[i] = rand_char(set);
  }

  // Return the password
  return password;
}

// Print the password to the console
void print_password(char *password) {
  printf("Your happy password is: %s\n", password);
}

// The main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the password length from the user
  int length;
  printf("How long do you want your password to be? ");
  scanf("%d", &length);

  // Generate the password
  char *password = generate_password(length);

  // Print the password to the console
  print_password(password);

  // Free the memory allocated for the password
  free(password);

  return 0;
}