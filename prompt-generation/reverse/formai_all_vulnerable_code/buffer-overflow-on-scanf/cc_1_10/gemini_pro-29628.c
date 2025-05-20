//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int rand_range(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to print a pattern of stars
void print_stars(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j || i + j == n - 1) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

// Function to print a pattern of numbers
void print_numbers(int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", rand_range(1, 9));
    }
    printf("\n");
  }
}

// Function to print a pattern of letters
void print_letters(int n) {
  char c = 'A';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%c ", c++);
    }
    printf("\n");
  }
}

// Function to print a pattern of special characters
void print_special_characters(int n) {
  char c = '!';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%c ", c++);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Initialize random seed
  srand(time(NULL));

  // Print a menu of options
  printf("Choose a pattern to print:\n");
  printf("1. Stars\n");
  printf("2. Numbers\n");
  printf("3. Letters\n");
  printf("4. Special characters\n");
  printf("5. Quit\n");

  // Get user input
  int choice;
  scanf("%d", &choice);

  // Print the chosen pattern
  switch (choice) {
    case 1:
      print_stars(5);
      break;
    case 2:
      print_numbers(5);
      break;
    case 3:
      print_letters(5);
      break;
    case 4:
      print_special_characters(5);
      break;
    case 5:
      printf("Goodbye!\n");
      break;
    default:
      printf("Invalid choice\n");
  }

  return 0;
}