//FormAI DATASET v1.0 Category: Math exercise ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  int a, b, c;
  char op;

  printf("Welcome to the Brave Math Challenge!\n");
  printf("Here's your first question:\n");

  for(int i = 1; i <= 10; i++) {
    a = rand() % 100;
    b = rand() % 100;
    c = rand() % 100;

    switch(rand() % 3) {
      case 0:
        op = '+';
        printf("%d. %d %c %d + %d = ", i, a, op, b, c);
        if(getchar() != '\n' || a + b + c != getchar() - '0') {
          printf("Incorrect! You have failed the Brave Math Challenge.\n");
          return 0;
        }
        break;
      case 1:
        op = '-';
        printf("%d. %d %c %d + %d = ", i, a, op, b, c);
        if(getchar() != '\n' || a - b + c != getchar() - '0') {
          printf("Incorrect! You have failed the Brave Math Challenge.\n");
          return 0;
        }
        break;
      case 2:
        op = '*';
        printf("%d. %d %c %d + %d = ", i, a, op, b, c);
        if(getchar() != '\n' || a * b + c != getchar() - '0') {
          printf("Incorrect! You have failed the Brave Math Challenge.\n");
          return 0;
        }
        break;
    }

  }

  printf("Congratulations! You have passed the Brave Math Challenge.\n");
  return 0;
}