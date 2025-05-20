//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 80

int main() {
  int x, y, w, h, r, g, b;
  char c;
  time_t t;

  srand(time(NULL));

  printf("Enter the width of the ASCII art (max %d): ", MAX_WIDTH);
  scanf("%d", &w);

  printf("Enter the height of the ASCII art: ");
  scanf("%d", &h);

  printf("Enter the number of rows of randomness (optional): ");
  scanf("%d", &r);

  printf("Enter the number of rows of green (optional): ");
  scanf("%d", &g);

  printf("Enter the number of rows of blue (optional): ");
  scanf("%d", &b);

  x = rand() % w;
  y = rand() % h;

  c = (rand() % 3) + 32;

  printf("\n");
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (j == x && i == y) {
        printf("%c", c);
      } else if (r && rand() % r == 0) {
        printf("%c", rand() % 26 + 65);
      } else if (g && rand() % g == 0) {
        printf("%c", 92);
      } else if (b && rand() % b == 0) {
        printf("%c", 94);
      } else {
        printf("%c", 32);
      }
    }
    printf("\n");
  }

  return 0;
}