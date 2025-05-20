//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the character set for the password
#define CHARSET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()"

// Generate a random number between min and max
int rand_range(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Generate a random character from the character set
char rand_char() {
  return CHARSET[rand_range(0, strlen(CHARSET) - 1)];
}

// Generate a random password of length n
char *rand_pw(int n) {
  char *pw = malloc(n + 1);
  for (int i = 0; i < n; i++) {
    pw[i] = rand_char();
  }
  pw[n] = '\0';
  return pw;
}

// Get the current time in milliseconds
long long get_time() {
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  return ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

// Seed the random number generator with the current time
void seed_rand() {
  srand(get_time());
}

// Get a random password of a given length
char *get_pw(int length) {
  seed_rand();
  return rand_pw(length);
}

// Print the password
void print_pw(char *pw) {
  printf("Password: %s\n", pw);
}

// Free the memory allocated for the password
void free_pw(char *pw) {
  free(pw);
}

// Main function
int main() {
  // Get the password length from the user
  int length;
  printf("Enter the desired password length: ");
  scanf("%d", &length);

  // Generate and print the password
  char *pw = get_pw(length);
  print_pw(pw);

  // Free the memory allocated for the password
  free_pw(pw);

  return 0;
}