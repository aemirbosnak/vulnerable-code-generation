//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

int main() {
  char input[100];
  int color;

  printf("Enter a color code (0-7): ");
  scanf("%d", &color);

  printf("Enter a string: ");
  scanf(" %[^\n]%*c", input);

  switch (color) {
    case 0:
      printf("%s%s%s", BLACK, input, RESET);
      break;
    case 1:
      printf("%s%s%s", RED, input, RESET);
      break;
    case 2:
      printf("%s%s%s", GREEN, input, RESET);
      break;
    case 3:
      printf("%s%s%s", YELLOW, input, RESET);
      break;
    case 4:
      printf("%s%s%s", BLUE, input, RESET);
      break;
    case 5:
      printf("%s%s%s", MAGENTA, input, RESET);
      break;
    case 6:
      printf("%s%s%s", CYAN, input, RESET);
      break;
    case 7:
      printf("%s%s%s", WHITE, input, RESET);
      break;
    default:
      printf("Invalid color code.");
  }

  return 0;
}