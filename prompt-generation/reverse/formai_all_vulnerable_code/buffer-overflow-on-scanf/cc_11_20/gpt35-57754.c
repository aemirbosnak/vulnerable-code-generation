//FormAI DATASET v1.0 Category: Matrix operations ; Style: imaginative
#include<stdio.h>

int main(){

    // Welcome Message
    printf("Welcome to the Matrix Operations Program!\n");
    printf("Please enter the dimensions of your matrices.\n");

    // Input Matrix Dimensions
    int rows, cols;

    printf("Number of Rows: ");
    scanf("%d", &rows);

    printf("Number of Columns: ");
    scanf("%d", &cols);

    // Matrix Declarations
    int matrix1[rows][cols], matrix2[rows][cols], result[rows][cols];

    // Matrix Input
    printf("Please enter the values for your first matrix:\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("Element[%d][%d]: ", i, j);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Please enter the values for your second matrix:\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("Element[%d][%d]: ", i, j);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Matrix Operations
    printf("Select an operation to perform on your matrices:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Quit\n");

    int choice;
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("Performing Matrix Addition...\n");
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    result[i][j] = matrix1[i][j] + matrix2[i][j];
                }
            }
            break;
        case 2:
            printf("Performing Matrix Subtraction...\n");
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    result[i][j] = matrix1[i][j] - matrix2[i][j];
                }
            }
            break;
        case 3:
            printf("Performing Matrix Multiplication...\n");
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    result[i][j] = 0;
                    for(int k = 0; k < cols; k++){
                        result[i][j] += matrix1[i][k] * matrix2[k][j];
                    }
                }
            }
            break;
        case 4:
            printf("Quitting Program...\n");
            return 0;
        default:
            printf("Invalid Choice!\n");
            return 0;
    }

    // Matrix Output
    printf("Result:\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    // Farewell Message
    printf("Thank you for using the Matrix Operations Program!\n");

    return 0;
}