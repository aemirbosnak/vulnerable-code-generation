//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, n, r, seed, fortune;
  char ch;

  seed = time(NULL);
  srand(seed);

  printf("Would you like to hear your fortune? (y/n): ");
  scanf(" %c", &ch);

  if (ch == 'y') {
    n = rand() % 10;
    r = rand() % 4;

    switch (n) {
      case 0:
        fortune = 3;
        break;
      case 1:
        fortune = 5;
        break;
      case 2:
        fortune = 7;
        break;
      case 3:
        fortune = 9;
        break;
      case 4:
        fortune = 11;
        break;
      case 5:
        fortune = 13;
        break;
      case 6:
        fortune = 15;
        break;
      case 7:
        fortune = 17;
        break;
      case 8:
        fortune = 19;
        break;
      case 9:
        fortune = 21;
        break;
    }

    switch (r) {
      case 0:
        fortune *= 2;
        break;
      case 1:
        fortune *= 3;
        break;
      case 2:
        fortune *= 4;
        break;
      case 3:
        fortune *= 5;
        break;
    }

    printf("Your fortune is: %d", fortune);
  } else {
    printf("Thank you for your time.");
  }

  return 0;
}