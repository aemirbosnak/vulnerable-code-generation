//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PW_MIN 8
#define PW_MAX 64

// Cyberpunk-themed character sets
char *charset_alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char *charset_numeric = "0123456789";
char *charset_special = "!@#$%^&*()_+=-`~";
char *charset_cyber = "<>[]{}\\|/?.,;:'\"";

// Generate a random number in the range [min, max]
int rand_range(int min, int max) {
  return min + rand() % (max - min + 1);
}

// Generate a random character from the given charset
char rand_char(char *charset) {
  int index = rand_range(0, strlen(charset) - 1);
  return charset[index];
}

// Generate a random password with the given length and character sets
char *generate_password(int length, char *charset) {
  char *password = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    password[i] = rand_char(charset);
  }
  password[length] = '\0';
  return password;
}

// Print a Cyberpunk-themed banner
void print_banner() {
  printf("███████╗███╗   ██╗██████╗  ██████╗ ███████╗███████╗\n");
  printf("██╔════╝████╗  ██║██╔══██╗██╔═══██╗██╔════╝██╔════╝\n");
  printf("███████╗██╔██╗ ██║██████╔╝██║   ██║█████╗  ███████╗\n");
  printf("╚════██║██║╚██╗██║██╔══██╗██║   ██║██╔══╝  ╚════██║\n");
  printf("███████║██║ ╚████║██║  ██║╚██████╔╝███████╗███████║\n");
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Print the Cyberpunk banner
  print_banner();

  // Get the desired password length from the user
  int length;
  printf("Enter desired password length (8-64): ");
  scanf("%d", &length);

  // Validate the password length
  if (length < PW_MIN || length > PW_MAX) {
    printf("Invalid password length. Must be between %d and %d.\n", PW_MIN, PW_MAX);
    return 1;
  }

  // Generate a random password
  char *password = generate_password(length, charset_alpha);

  // Print the generated password
  printf("Your Cyberpunk-themed password: %s\n", password);

  // Free the allocated memory
  free(password);

  return 0;
}