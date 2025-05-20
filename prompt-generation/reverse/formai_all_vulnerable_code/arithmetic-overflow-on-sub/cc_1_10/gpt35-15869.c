//FormAI DATASET v1.0 Category: Pattern printing ; Style: happy
// A fun and happy program to print a unique C pattern!
#include <stdio.h>

int main() {
      int height, width, i, j, k, n, m;
      
      // Get user input for height of the C
      printf("Enter the height of C: ");
      scanf("%d", &height);

      // Get user input for width of the C
      printf("Enter the width of C: ");
      scanf("%d", &width);

      // Print the top horizontal line of the C
      for (i = 1; i <= width; i++) {
            printf("*");
      }

      printf("\n");

      // Calculate number of spaces and stars for middle of the C
      n = (width - 2) / 2;
      m = height / 2;

      // Print the middle part of the C
      for (j = 1; j <= m; j++) {
            printf("*");

            for (k = 1; k <= n; k++) {
                  printf(" ");
            }

            printf("*\n");
      }

      // Print the bottom horizontal line of the C
      for (i = 1; i <= width; i++) {
            printf("*");
      }

      printf("\n");

      // Print the stem of the C
      for (j = 1; j <= m; j++) {
            for (k = 1; k <= width / 2; k++) {
                  printf(" ");
            }

            printf("*\n");
      }

      // Happy message to end program
      printf("\nYay! You made a happy C pattern! Keep on coding! :)\n");

      return 0;
}