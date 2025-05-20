//FormAI DATASET v1.0 Category: Matrix operations ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

int main() {
    
    int option, rows, cols, i, j, k, l;
    
    printf("\n\t\t-----MATRIX OPERATIONS-----\n\n");
    
    shape1:
    printf("Choose a shape:\n\n1. Square Matrix.\n2. Lower Triangular Matrix.\n3. Upper Triangular Matrix.\n4. Diagonal Matrix.\n");
    scanf("%d", &option);
    
    if(option != 1 && option != 2 && option != 3 && option != 4) {
        printf("\nInvalid Input!");
        goto shape1;
    }
    
    printf("\nEnter the number of rows in the matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &cols);
    
    int arr1[rows][cols], arr2[rows][cols], result[rows][cols];
    
    printf("\nEnter the elements of the matrix:\n\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &arr1[i][j]);
            arr2[i][j] = arr1[i][j];
        }
    }
    
    printf("\nMatrix entered:\n\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }
    
    switch(option) {
        case 1:
            printf("\n\n------ SQUARE MATRIX ------\n\n");
            for(i=0; i<rows; i++) {
                for(j=0; j<cols; j++) {
                    result[i][j] = 0;
                    for(k=0; k<cols; k++) {
                        result[i][j] += arr1[i][k] * arr2[k][j];
                    }
                }
            }
            break;
            
        case 2:
            printf("\n\n------ LOWER TRIANGULAR MATRIX ------\n\n");
            for(i=0; i<rows; i++) {
                for(j=0; j<cols; j++) {
                    result[i][j] = 0;
                    if(i >= j) {
                        for(k=0; k<=i; k++) {
                            result[i][j] += arr1[i][k] * arr2[k][j];
                        }
                    }
                }
            }
            break;
            
        case 3:
            printf("\n\n------ UPPER TRIANGULAR MATRIX ------\n\n");
            for(i=0; i<rows; i++) {
                for(j=0; j<cols; j++) {
                    result[i][j] = 0;
                    if(i <= j) {
                        for(k=0; k<cols; k++) {
                            result[i][j] += arr1[i][k] * arr2[k][j];
                        }
                    }
                }
            }
            break;
            
        case 4:
            printf("\n\n------ DIAGONAL MATRIX ------\n\n");
            for(i=0; i<rows; i++) {
                for(j=0; j<cols; j++) {
                    result[i][j] = 0;
                    if(i == j) {
                        result[i][j] = arr1[i][j] * arr2[i][j];
                    }
                }
            }
            break;
    }
    
    printf("\nResultant matrix:\n\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    printf("---------------------------------------\n");
    printf("Do you want to perform another operation? (1-Yes / 0-No): ");
    
    int repeat;
    scanf("%d", &repeat);
    
    if(repeat != 0 && repeat != 1) {
        printf("\nInvalid Input!");
    }
    
    if(repeat == 1) {
        goto shape1;
    }
    
    printf("\nThank you for using Matrix Operations program.\n");
    
    return 0;
}