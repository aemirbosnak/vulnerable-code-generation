//FormAI DATASET v1.0 Category: Pattern printing ; Style: future-proof
#include <stdio.h>

int main() {

  int width, height, i, j, k, center;
  char c;

  printf("Enter the height of the C (odd number): ");
  scanf("%d", &height);

  if (height%2 == 0) {
    printf("Please enter an odd number.\n");
    return 1;
  }

  width = (height/2)+1;
  center = width - 1;

  printf("Enter the character to be used for the C: ");
  scanf(" %c", &c);

  printf("\n");

  for (i=0; i<height; i++) {

    if (i == 0 || i == height-1) {
      for (j=0; j<width; j++) {
        printf("%c ", c);
      }
    } else if (i == center) {
      for (j=0; j<width; j++) {
        printf("%c", c);
      }
      printf("\n");
    } else if (i < center) {
      for (j=0; j<width-i; j++) {
        printf("%c", c);
      }
      for (k=0; k<(i*2)-1; k++) {
        printf(" ");
      }
      printf("%c\n", c);
    } else {
      for (j=0; j<=i-center; j++) {
        printf("%c", c);
      }
      for (k=0; k<(2*(center-j))+1; k++) {
        printf(" ");
      }
      printf("%c\n", c);
    }

  }

  return 0;
}