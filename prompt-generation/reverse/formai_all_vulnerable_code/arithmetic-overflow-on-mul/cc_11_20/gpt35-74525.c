//FormAI DATASET v1.0 Category: Matrix operations ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main(){
    int rows,cols;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);
    int *matrix = (int*) malloc(rows*cols*sizeof(int));
    printf("Enter the matrix elements: ");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            scanf("%d", (matrix + i*cols + j));
        }
    }
    printf("The original matrix is:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", *(matrix + i*cols + j));
        }
        printf("\n");
    }
    int choice;
    do{
        printf("\nMATRIX OPERATIONS MENU\n");
        printf("1. Transpose of the matrix\n");
        printf("2. Sum of all elements of the matrix\n");
        printf("3. Product of all elements of the matrix\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("The transpose of the matrix is:\n");
                for(int i=0; i<cols; i++){
                    for(int j=0; j<rows; j++){
                        printf("%d ", *(matrix + j*cols + i));
                    }
                    printf("\n");
                }
                break;
            case 2:{
                int sum = 0;
                for(int i=0; i<rows; i++){
                    for(int j=0; j<cols; j++){
                        sum += *(matrix + i*cols + j);
                    }
                }
                printf("The sum of all elements of the matrix is %d\n", sum);
                break;
            }
            case 3:{
                int product = 1;
                for(int i=0; i<rows; i++){
                    for(int j=0; j<cols; j++){
                        product *= *(matrix + i*cols + j);
                    }
                }
                printf("The product of all elements of the matrix is %d\n", product);
                break;
            }
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }while(choice!=4);
    free(matrix);
    return 0;
}