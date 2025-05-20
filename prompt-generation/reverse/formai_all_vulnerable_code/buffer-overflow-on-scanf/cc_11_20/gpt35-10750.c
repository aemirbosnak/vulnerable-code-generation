//FormAI DATASET v1.0 Category: Matrix operations ; Style: all-encompassing
#include<stdio.h>

int main(){

int matrix1[3][3], matrix2[3][3], sum[3][3], transpose[3][3];
int i, j;

//Taking input for first matrix
printf("Enter the elements of first 3x3 matrix: ");
for(i=0; i<3; i++){
  for(j=0; j<3; j++){
    scanf("%d", &matrix1[i][j]);
  }
}

//Taking input for second matrix
printf("Enter the elements of second 3x3 matrix: ");
for(i=0; i<3; i++){
  for(j=0; j<3; j++){
    scanf("%d", &matrix2[i][j]);
  }
}

//Printing the first matrix
printf("\nFirst Matrix:\n");
for(i=0; i<3; i++){
  for(j=0; j<3; j++){
    printf("%d ", matrix1[i][j]);
  }
  printf("\n");
}


//Printing the second matrix
printf("\nSecond Matrix:\n");
for(i=0; i<3; i++){
  for(j=0; j<3; j++){
    printf("%d ", matrix2[i][j]);
  }
  printf("\n");
}

//Adding both the matrices
for(i=0; i<3; i++){
  for(j=0; j<3; j++){
    sum[i][j] = matrix1[i][j] + matrix2[i][j];
  }
}

//Printing the added matrix
printf("\nSum of both matrices:\n");
for(i=0; i<3; i++){
  for(j=0; j<3; j++){
    printf("%d ", sum[i][j]);
  }
  printf("\n");
}

//Finding the transpose of first matrix
for(i=0; i<3; i++){
  for(j=0; j<3; j++){
    transpose[j][i] = matrix1[i][j];
  }
}

//Printing the transpose matrix
printf("\nTranspose of first matrix:\n");
for(i=0; i<3; i++){
  for(j=0; j<3; j++){
    printf("%d ", transpose[i][j]);
  }
  printf("\n");
}

return 0;
}