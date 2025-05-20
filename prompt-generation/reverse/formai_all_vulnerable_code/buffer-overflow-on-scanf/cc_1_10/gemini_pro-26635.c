//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: paranoid
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

// Constants

#define MAX_SIZE 100

// Function Declarations

void printPattern(char pattern[], int size);
void generatePattern(char pattern[], int size);
bool isPalindrome(char pattern[], int size);

// Main Function

int main() {
  // Initialize variables

  char pattern[MAX_SIZE];
  int size;

  // Get the size of the pattern

  printf("Enter the size of the pattern: ");
  scanf("%d", &size);

  // Generate the pattern

  generatePattern(pattern, size);

  // Print the pattern

  printf("The pattern is: %s\n", pattern);

  // Check if the pattern is a palindrome

  if (isPalindrome(pattern, size)) {
    printf("The pattern is a palindrome.\n");
  } else {
    printf("The pattern is not a palindrome.\n");
  }

  return 0;
}

// Function Definitions

void printPattern(char pattern[], int size) {
  // Initialize variables

  int i;

  // Print the pattern

  for (i = 0; i < size; i++) {
    printf("%c", pattern[i]);
  }
}

void generatePattern(char pattern[], int size) {
  // Initialize variables

  int i;
  int randomIndex;

  // Generate a random pattern

  srand(time(NULL));

  for (i = 0; i < size; i++) {
    // Generate a random index

    randomIndex = rand() % 26;

    // Set the character at the index to a random letter

    if (randomIndex >= 13) {
      pattern[i] = 'A' + (randomIndex - 13);
    } else {
      pattern[i] = 'a' + randomIndex;
    }
  }
}

bool isPalindrome(char pattern[], int size) {
  // Initialize variables

  int i;

  // Check if the pattern is a palindrome

  for (i = 0; i < size / 2; i++) {
    if (pattern[i] != pattern[size - i - 1]) {
      return false;
    }
  }

  return true;
}