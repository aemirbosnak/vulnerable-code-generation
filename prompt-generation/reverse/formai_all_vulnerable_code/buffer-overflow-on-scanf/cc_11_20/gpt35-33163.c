//FormAI DATASET v1.0 Category: Matrix operations ; Style: shocked
#include <stdio.h>

int main() {

int a[4][3], b[4][3], sum[4][3], product[4][3], transpose[3][4], i, j;

// Input for Matrix A
for(i=0; i<4; i++) {
    for(j=0; j<3; j++) {
        printf("Enter value for a[%d][%d]: ", i, j);
        scanf("%d", &a[i][j]);
    }
}

// Input for Matrix B
for(i=0; i<4; i++) {
    for(j=0; j<3; j++) {
        printf("Enter value for b[%d][%d]: ", i, j);
        scanf("%d", &b[i][j]);
    }
}

// Matrix Addition
printf("\nMatrix Addition:\n");
for(i=0; i<4; i++) {
    for(j=0; j<3; j++) {
        sum[i][j] = a[i][j] + b[i][j];
        printf("%d ", sum[i][j]);
    }
    printf("\n");
}

// Matrix Subtraction
printf("\nMatrix Subtraction:\n");
for(i=0; i<4; i++) {
    for(j=0; j<3; j++) {
        sum[i][j] = a[i][j] - b[i][j];
        printf("%d ", sum[i][j]);
    }
    printf("\n");
}

// Matrix Multiplication
printf("\nMatrix Multiplication:\n");
for(i=0; i<4; i++) {
    for(j=0; j<3; j++) {
        product[i][j] = a[i][j] * b[i][j];
        printf("%d ", product[i][j]);
    }
    printf("\n");
}

// Matrix Transpose
printf("\nMatrix Transpose:\n");
for(i=0; i<3; i++) {
    for(j=0; j<4; j++) {
        transpose[i][j] = a[j][i];
        printf("%d ", transpose[i][j]);
    }
    printf("\n");
}

return 0;
}