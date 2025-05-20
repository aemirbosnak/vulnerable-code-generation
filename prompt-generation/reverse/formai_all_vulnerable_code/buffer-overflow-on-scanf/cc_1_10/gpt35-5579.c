//FormAI DATASET v1.0 Category: Matrix operations ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    int matrix1[3][3], matrix2[3][3], result[3][3];
    int i, j;

    printf("Wow! We are going to do some Matrix operations today!\n");
    printf("Please enter elements of first matrix\n");

    // Taking input for first matrix
    for(i=0;i<3;i++) {
        for(j=0;j<3;j++) {
            printf("Element (%d,%d): ",i+1,j+1);
            scanf("%d",&matrix1[i][j]);
        }
    }

    printf("\nPlease enter elements of second matrix\n");

    // Taking input for second matrix
    for(i=0;i<3;i++) {
        for(j=0;j<3;j++) {
            printf("Element (%d,%d): ",i+1,j+1);
            scanf("%d",&matrix2[i][j]);       
        }
    }

    // Performing Matrix Addition
    printf("\nAdding these two matrices produces: \n");
    for(i=0;i<3;i++) {
        for(j=0;j<3;j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }

    // Performing Matrix Multiplication
    printf("\nMultiplying these two matrices produces:\n");
    for(i=0;i<3;i++) {
        for(j=0;j<3;j++) {
            result[i][j] = 0;
            for(int k=0;k<3;k++) 
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            printf("%d ",result[i][j]);  
        }
        printf("\n");
    }

    printf("\nSurprise! We're done!\n");
    return 0;
}