//Gemma-7B DATASET v1.0 Category: Data mining ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {

  // Declare variables
  char **arr = NULL;
  int i = 0, j = 0, k = 0, l = 0, n = 0;
  long int t = 0, h = 0, m = 0, s = 0, e = 0;

  // Allocate memory for the array
  arr = malloc(n * sizeof(char *));

  // Read data from the keyboard
  printf("Enter the number of rows: ");
  scanf("%d", &n);

  // Read data from the keyboard
  printf("Enter the number of columns: ");
  scanf("%d", &m);

  // Read data from the keyboard
  printf("Enter the data: ");
  for (i = 0; i < n; i++) {
    arr[i] = malloc(m * sizeof(char));
    for (j = 0; j < m; j++) {
      scanf("%c", &arr[i][j]);
    }
  }

  // Calculate the sum of each column
  for (k = 0; k < m; k++) {
    s = 0;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if (arr[i][j] == 'x') {
          s++;
        }
      }
    }
    e = e + s;
  }

  // Print the sum of each column
  printf("The sum of each column is: ");
  for (k = 0; k < m; k++) {
    printf("%d ", e / m);
  }

  // Free memory
  for (i = 0; i < n; i++) {
    free(arr[i]);
  }
  free(arr);

  return 0;
}