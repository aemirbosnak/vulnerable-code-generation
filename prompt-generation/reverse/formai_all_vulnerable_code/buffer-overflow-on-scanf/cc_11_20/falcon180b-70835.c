//Falcon-180B DATASET v1.0 Category: Matrix operations ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main() {
  int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX], i, j, k, n;
  printf("Enter the number of rows and columns for the matrices: ");
  scanf("%d %d", &n, &n);
  
  //Initialize matrices A and B with random values
  srand(time(NULL));
  for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
      A[i][j] = rand()%10;
      B[i][j] = rand()%10;
    }
  }
  
  //Display matrices A and B
  printf("\nMatrix A:\n");
  for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
  
  printf("\nMatrix B:\n");
  for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
      printf("%d ", B[i][j]);
    }
    printf("\n");
  }
  
  //Multiply matrices A and B
  for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
      for(k=0;k<n;k++) {
        C[i][j] += A[i][k]*B[k][j];
      }
    }
  }
  
  //Display the resultant matrix C
  printf("\nResultant matrix C:\n");
  for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
      printf("%d ", C[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}