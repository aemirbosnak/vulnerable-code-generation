//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Function to convert character to ASCII art
void printAsciiArt(char ch, int style) {
  // configurable ASCII art styles
  char bold[] = "@@@@@\n@@  @@\n@@@@@@\n@@  @@\n@@  @@\n";
  char italic[] = " /\\    |\n/  \\   |\n\\   \\  |\n \\   \\ |\n  \\__\\|_|\n";
  char underline[] = "   _     \n /  |    \n( /   O  \n \\___.|_/\n";
  
  // print ASCII art based on selected style
  switch (style) {
    case 1:
      printf("%s", bold);
      break;
    case 2:
      printf("%s", italic);
      break;
    case 3:
      printf("%s", underline);
      break;
    default:
      printf("No style selected.\n");
      break;
  }
  
  // print ASCII art based on character
  switch (ch) {
    case 'A':
      printf("  /\\   \n /  \\  \n/ /\\ \\ \n////\\\\\\\n/    \\\\\n");
      break;
    case 'B':
      printf(" /----\\\n| |__   \\\n|  __|   |\n| |__   /\n|_____/\\\n");
      break;
    case 'C':
      printf("  /----\\\n /     /\n/___  /\n\\   \\/\n \\___\\\n");
      break;
    case 'D':
      printf(" /----\\\n| |__   \\\n|  __|   \\\n| |__    /\n|_______/\n");
      break;
    // additional cases for other letters can be added here
    default:
      printf("No ASCII art available.\n");
      break;
  }
}

int main() {
  char input[MAX_LENGTH];
  int style;

  printf("Enter the text to convert to ASCII art: ");
  fgets(input, MAX_LENGTH, stdin);

  printf("Select the style of ASCII art (1-3):\n");
  printf("1. Bold\n2. Italic\n3. Underline\n");
  scanf("%d", &style);

  // loop through input string and print ASCII art for each character
  for (int i = 0; i < strlen(input) - 1; i++) {
    printAsciiArt(input[i], style);
    printf("\n");
  }

  return 0;
}