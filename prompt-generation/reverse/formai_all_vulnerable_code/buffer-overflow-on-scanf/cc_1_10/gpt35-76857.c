//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: recursive
#include <stdio.h>
#include <string.h>

void printChar(char c, int n) {
  for (int i = 0; i < n; i++) {
    printf("%c", c);
  }
}

void drawA(int n) {
  if (n == 1) {
    printf("\n");
    printChar(' ', n-1);
    printf("/\\\n");
    printChar(' ', n-1);
    printf("/  \\\n");
    printChar(' ', n-1);
    printf("/____\\\n");
  } else {
    drawA(n-1);
    printChar(' ', n-1);
    printf("/%*s\\\n", n-1, "");
    printChar(' ', n-1);
    printf("/%*s  \\\n", n-1, "");
    printChar(' ', n-1);
    printf("/%*s____\\\n", n*2-1, "");
  }
}

void drawS(int n) {
  if (n == 1) {
    printf("\n");
    printChar(' ', n-1);
    printf("  _______\n");
    printChar(' ', n-1);
    printf(" /_______\\\n");
    printChar(' ', n-1);
    printf(" \\_______/\n");
  } else {
    drawS(n-1);
    printChar(' ', n-1);
    printf("%*s  _______\n", n-1, "");
    printChar(' ', n-1);
    printf("%*s /_______\\\n", n-1, "");
    printChar(' ', n-1);
    printf("%*s \\_______/\n", n-1, "");
  }
}

void drawC(int n) {
  if (n == 1) {
    printf("\n");
    printChar(' ', n-1);
    printf("  _______\n");
    printChar(' ', n-1);
    printf(" /_______\\\n");
    printChar(' ', n-1);
    printf(" \\       \n");
    printChar(' ', n-1);
    printf(" /_______\\\n");
    printChar(' ', n-1);
    printf(" \\_______/\n");
  } else {
    drawC(n-1);
    printChar(' ', n-1);
    printf("%*s  _______\n", n-1, "");
    printChar(' ', n-1);
    printf("%*s /_______\\\n", n-1, "");
    printChar(' ', n-1);
    printf("%*s \\       \\\n", n-1, "");
    printChar(' ', n-1);
    printf("%*s /_______\\\n", n-1, "");
    printChar(' ', n-1);
    printf("%*s \\_______/\n", n-1, "");
  }
}

int main() {
  char input[100];
  printf("Enter text to convert to ASCII art:\n");
  scanf("%s", input);

  for (int i = 0; i < strlen(input); i++) {
    printf("\n");
    switch (input[i]) {
      case 'a':
        drawA(3);
        break;
      case 'c':
        drawC(3);
        break;
      case 's':
        drawS(3);
        break;
      default:
        printf("Invalid input\n");
        break;
    }
  }

  return 0;
}