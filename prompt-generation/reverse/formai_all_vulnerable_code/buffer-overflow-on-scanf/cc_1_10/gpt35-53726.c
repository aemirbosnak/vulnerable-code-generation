//FormAI DATASET v1.0 Category: Matrix operations ; Style: calm
#include <stdio.h>

void add(int arr1[10][10], int arr2[10][10], int rows, int columns){
    int result[10][10];
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    printf("\nThe summed matrix is:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void subtract(int arr1[10][10], int arr2[10][10], int rows, int columns){
    int result[10][10];
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            result[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
    printf("\nThe subtracted matrix is:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

void multiply(int arr1[10][10], int arr2[10][10], int rows1, int columns1, int rows2, int columns2){
    if(columns1 != rows2){
        printf("\nThe matrices are not compatible for multiplication.\n");
    }
    else{
        int result[10][10];
        for(int i=0; i<rows1; i++){
            for(int j=0; j<columns2; j++){
                result[i][j] = 0;
                for(int k=0; k<columns1; k++){
                    result[i][j] += arr1[i][k] * arr2[k][j];
                }
            }
        }
        printf("\nThe multiplied matrix is:\n");
        for(int i=0; i<rows1; i++){
            for(int j=0; j<columns2; j++){
                printf("%d ", result[i][j]);
            }
            printf("\n");
        }
    }
}

int main(){
    int rows1, rows2, columns1, columns2, choice;
    int arr1[10][10], arr2[10][10];
    printf("Enter the number of rows of matrix 1: ");
    scanf("%d", &rows1);
    printf("Enter the number of columns of matrix 1: ");
    scanf("%d", &columns1);
    printf("\nEnter the elements of matrix 1:\n");
    for(int i=0; i<rows1; i++){
        for(int j=0; j<columns1; j++){
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("\nEnter the number of rows of matrix 2: ");
    scanf("%d", &rows2);
    printf("Enter the number of columns of matrix 2: ");
    scanf("%d", &columns2);
    printf("\nEnter the elements of matrix 2:\n");
    for(int i=0; i<rows2; i++){
        for(int j=0; j<columns2; j++){
            scanf("%d", &arr2[i][j]);
        }
    }
    printf("\nWhat operation would you like to perform?\n");
    printf("1. Add the matrices\n");
    printf("2. Subtract the matrices\n");
    printf("3. Multiply the matrices\n");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            if(rows1 != rows2 || columns1 != columns2){
                printf("\nThe matrices are not compatible for addition.\n");
            }
            else{
                add(arr1, arr2, rows1, columns1);
            }
            break;
        case 2:
            if(rows1 != rows2 || columns1 != columns2){
                printf("\nThe matrices are not compatible for subtraction.\n");
            }
            else{
                subtract(arr1, arr2, rows1, columns1);
            }
            break;
        case 3:
            multiply(arr1, arr2, rows1, columns1, rows2, columns2);
            break;
        default:
            printf("\nInvalid choice.\n");
            break;
    }
    return 0;
}