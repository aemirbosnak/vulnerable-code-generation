//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: peaceful
#include<stdio.h>
#include<string.h>

void print_art(char c) {
  switch(c) {
    case 'a':
    case 'A':
      printf("    /\\ \n");
      printf("   /  \\ \n");
      printf("  /----\\ \n");
      printf(" /      \\ \n");
      printf("/________\\ \n");
      break;

    case 'b':
    case 'B':
      printf(" ______ \n");
      printf("|      \\ \n");
      printf("|_____/ \n");
      printf("|      \\ \n");
      printf("|_____/ \n");
      break;

    case 'c':
    case 'C':
      printf("  _____ \n");
      printf(" /      \\\n");
      printf("|        \n");
      printf("|        \n");
      printf(" \\_____/\n");
      break;

    case 'd':
    case 'D':
      printf(" _____  \n");
      printf("|     \\ \n");
      printf("|      |\n");
      printf("|      |\n");
      printf("|_____/ \n");
      break;

    default:
      printf("Character not supported!\n");
  }
}

int main() {

  char input[100];
  int i, len;

  printf("Enter a string: ");
  scanf("%s", input);

  len = strlen(input);

  for(i = 0; i < len; i++) {
    print_art(input[i]);
  }

  return 0;
}