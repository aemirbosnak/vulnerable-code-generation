//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: cheerful
#include <stdio.h>

// Define a function to print a pattern
void printPattern(int n) {
  int i, j;

  // Start with a smiley face 😊
  printf("😊\n");

  // Print a series of plus signs (+)
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= i; j++) {
      printf("+");
    }
    printf("\n");
  }

  // Print a series of hearts ❤️
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= i; j++) {
      printf("❤️");
    }
    printf("\n");
  }

  // Print a series of rainbows 🌈
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= i; j++) {
      printf("🌈");
    }
    printf("\n");
  }

  // End with a party popper 🎉
  printf("🎉\n");
}

int main() {
  int n;

  // Ask the user for the number of patterns to print
  printf("Enter the number of patterns to print (1-10): ");
  scanf("%d", &n);

  // Print the patterns
  for (int i = 1; i <= n; i++) {
    printPattern(i);
  }

  return 0;
}