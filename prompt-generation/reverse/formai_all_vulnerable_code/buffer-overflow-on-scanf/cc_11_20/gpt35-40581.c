//FormAI DATASET v1.0 Category: Matrix operations ; Style: inquisitive
#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d%d", &rows, &cols);
    
    int matrix[rows][cols];
    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    printf("The matrix you have entered:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    int choice;
    printf("What operation do you want to perform?\n");
    printf("1. Transpose the matrix\n");
    printf("2. Find the sum of all elements\n");
    printf("3. Multiply the matrix with a scalar\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: {
            printf("The transpose of the matrix is:\n");
            for(int i = 0; i < cols; i++) {
                for(int j = 0; j < rows; j++) {
                    printf("%d ", matrix[j][i]);
                }
                printf("\n");
            }
            break;
        }
        case 2: {
            int sum = 0;
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    sum += matrix[i][j];
                }
            }
            printf("The sum of all elements of the matrix is: %d\n", sum);
            break;
        }
        case 3: {
            int scalar;
            printf("Enter the scalar value to multiply with: ");
            scanf("%d", &scalar);
            
            printf("The matrix after multiplication with %d is:\n", scalar);
            for(int i = 0; i < rows; i++) {
                for(int j = 0; j < cols; j++) {
                    matrix[i][j] *= scalar;
                    printf("%d ", matrix[i][j]);
                }
                printf("\n");
            }
            break;
        }
        case 4: {
            printf("Thank you for using this program.\n");
            break;
        }
        default: {
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}