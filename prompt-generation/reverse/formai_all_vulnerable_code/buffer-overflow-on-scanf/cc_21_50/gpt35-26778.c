//FormAI DATASET v1.0 Category: Matrix operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// This is a hilarious program that will perform some matrix operations!

int main() {
    printf("Hello, I am your matrix friend! Let's have some fun with numbers.\n");

    int rows, cols;
    printf("How many rows would you like in your matrix?\n");
    scanf("%d", &rows);
    printf("How many columns?\n");
    scanf("%d", &cols);

    int **matrix;
    matrix = (int**)malloc(rows * sizeof(int*));
    for(int i=0; i<rows; i++) {
       matrix[i] =(int*)malloc(cols * sizeof(int));
    }

    printf("Enter the numbers for your matrix like you are painting a rainbow.\n");
    printf("ROYGBIV, starting with red i.e. row 0, column 0, then move up the column (to y)eii(p)n and fill the row.\n");
    printf("Got it? Good!\n");

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Awesome! I bet your matrix is beautiful.\n");
    printf("Here it is:\n");

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Now, let's make this matrix even better!\n");
    printf("I will multiply each element by 2.\n");

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            matrix[i][j] = matrix[i][j] * 2;
        }
    }

    printf("Check it out now:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("This is so much fun, don't you think?\n");
    printf("Let's add another matrix to this one!\n");

    int **matrix2;
    matrix2 = (int**)malloc(rows * sizeof(int*));
    for(int i=0; i<rows; i++) {
        matrix2[i] =(int*)malloc(cols * sizeof(int));
    }

    printf("Enter the second matrix numbers in a similar format as before.\n");

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("Here is your second matrix:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    printf("Let's add these two matrices up!\n");

    int **sum;
    sum = (int**)malloc(rows * sizeof(int*));
    for(int i=0; i<rows; i++) {
        sum[i] =(int*)malloc(cols * sizeof(int));
    }

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            sum[i][j] = matrix[i][j] + matrix2[i][j];
        }
    }

    printf("Ta daaa! Here is the sum of your two matrices:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    printf("I hope you had as much fun as I did! See you later.\n");

    // free the arrays to avoid memory leaks
    for(int i=0; i<rows; i++){
        free(matrix[i]);
    }
    free(matrix);

    for(int i=0; i<rows; i++){
        free(matrix2[i]);
    }
    free(matrix2);

    for(int i=0; i<rows; i++){
        free(sum[i]);
    }
    free(sum);

    return 0;
}