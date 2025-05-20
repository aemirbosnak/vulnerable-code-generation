//Falcon-180B DATASET v1.0 Category: Recursive ; Style: creative
#include <stdio.h>

// Function to print the pyramid pattern
void printPyramid(int n) {
  int i, j, k = 1;

  // Loop through each row
  for (i = 0; i < n; i++) {

    // Loop through each column
    for (j = 0; j < n; j++) {

      // Print the pyramid pattern
      if (i + j == n - 1) {
        printf("*");
      } else if (i == j) {
        printf("*");
      } else {
        printf(" ");
      }
    }

    // Move to the next row
    printf("\n");
  }
}

// Function to generate the pyramid
void generatePyramid(int n) {
  int i;

  // Loop through each row
  for (i = 0; i < n; i++) {

    // Print the pyramid pattern for the current row
    printPyramid(n);
  }
}

int main() {
  int n;

  // Get the number of rows from the user
  printf("Enter the number of rows: ");
  scanf("%d", &n);

  // Generate the pyramid
  generatePyramid(n);

  return 0;
}