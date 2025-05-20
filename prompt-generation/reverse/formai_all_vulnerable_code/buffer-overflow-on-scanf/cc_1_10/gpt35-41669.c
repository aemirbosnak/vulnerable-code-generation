//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: excited
#include <stdio.h>

int main() {
  printf("Excited ASCII Art Generator!\n");
  printf("Enter your message: ");
  
  char message[100];
  scanf("%[^\n]", message);
  
  printf("\n");
  int len = strlen(message);
  for (int i = 0; i < len; i++) {
    char c = message[i];
    switch(c) {
      case 'A':
        printf("   /\\   \n");
        printf("  /  \\  \n");
        printf(" /    \\ \n");
        printf("/------\\\n");
        printf("|      |\n");
        printf("|      |\n");
        printf("|------|\n");
        break;
      case 'B':
        printf(" -------\n");
        printf("|       |\n");
        printf("|       |\n");
        printf("|-------\n");
        printf("|       |\n");
        printf("|       |\n");
        printf(" -------\n");
        break;
      case 'C':
        printf("  .----.\n");
        printf(" /      \\\n");
        printf("|        \\\n");
        printf("|        /\n");
        printf(" \\      /\n");
        printf("  '----'\n");
        break;
      case 'D':
        printf(" -------\n");
        printf("|       \\ \n");
        printf("|        \\\n");
        printf("|        /\n");
        printf("|       /\n");
        printf(" -------\n");
        break;
      case 'E':
        printf(" -------\n");
        printf("|        \n");
        printf("|        \n");
        printf("|------\n");
        printf("|        \n");
        printf("|        \n");
        printf(" -------\n");
        break;
      case 'F':
        printf(" -------\n");
        printf("|        \n");
        printf("|        \n");
        printf("|------\n");
        printf("|        \n");
        printf("|        \n");
        printf("|        \n");
        break;
      default:
        printf("Unknown character: %c\n", c);
    }
  }
  
  return 0;
}