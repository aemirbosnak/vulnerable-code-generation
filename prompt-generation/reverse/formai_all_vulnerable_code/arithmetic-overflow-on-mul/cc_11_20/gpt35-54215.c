//FormAI DATASET v1.0 Category: Matrix operations ; Style: funny
#include <stdio.h>

int main() {
    // Welcome message
    printf("Greetings, human! I am MatrixBot, here to assist you with Matrix operations.\n");

    // Declare variables and get user input
    int rows, cols;
    printf("How many rows and columns do your matrices have?\n");
    scanf("%d %d", &rows, &cols);

    // Mysterious intro while doing some calculations
    printf("Interesting... %dx%d matrices, just like the Matrix itself. Hold on, let me calculate something...\n");
    int sum = rows + cols;
    int product = rows * cols;
    printf("Yes, yes...the sum of rows and columns is %d, while their product is %d. Hmm...\n", sum, product);

    // Initializing the matrices with user input values
    printf("Now, let me initialize your matrices...\n");
    int matrix1[rows][cols], matrix2[rows][cols];
    printf("For Matrix 1:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("Enter the value for row %d, column %d\n", i+1, j+1);
            scanf("%d", &matrix1[i][j]);
        }
    }
    printf("That looks good!\n");
    printf("And for Matrix 2:\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("Enter the value for row %d, column %d\n", i+1, j+1);
            scanf("%d", &matrix2[i][j]);
        }
    }
    printf("Very interesting!\n");

    // Matrix addition
    printf("Now, let's perform matrix addition...\n");
    int addition[rows][cols];
    printf("Matrix 1 + Matrix 2 =\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            addition[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", addition[i][j]);
        }
        printf("\n");
    }
    printf("Fascinating, isn't it?\n");

    // Matrix subtraction
    printf("Next, let's try matrix subtraction...\n");
    int subtraction[rows][cols];
    printf("Matrix 1 - Matrix 2 =\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            subtraction[i][j] = matrix1[i][j] - matrix2[i][j];
            printf("%d ", subtraction[i][j]);
        }
        printf("\n");
    }
    printf("Mind-blowing stuff!\n");

    // Matrix multiplication
    printf("And finally, the pièce de résistance - matrix multiplication!\n");
    int productMatrix[rows][cols];
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            productMatrix[i][j] = 0;
            for(int k=0; k<cols; k++) {
                productMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    printf("Matrix 1 * Matrix 2 =\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", productMatrix[i][j]);
        }
        printf("\n");
    }
    printf("Wow, we did it! Thanks for using MatrixBot, humans. Until next time...\n");

    return 0;
}