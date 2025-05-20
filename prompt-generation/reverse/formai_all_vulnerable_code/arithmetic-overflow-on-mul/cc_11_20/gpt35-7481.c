//FormAI DATASET v1.0 Category: Matrix operations ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main() {
  int matrix[10][10], rows, columns, counter, option, constant;

  printf("\n\nWelcome to the Matrix Operations Program!\n");
  printf("What would you like to do?\n1. Create a New Matrix\n2. Perform Scalar Multiplication\n3. Transpose Matrix\n4. Print the Matrix\n5. Quit Program\n\n");

  do {
    printf("Enter an option (1-5): ");
    scanf("%d", &option);
    switch(option) {
      case 1:
        printf("\nEnter the number of rows: ");
        scanf("%d",&rows);
        printf("\nEnter the number of columns: ");
        scanf("%d",&columns);
        printf("\nEnter the elements of the matrix:\n");
        for(counter = 0; counter < rows; counter++){
            for(int j = 0; j < columns; j++){
                scanf("%d",&matrix[counter][j]);
            }
        }
        break;
        
      case 2:
        printf("\nEnter the scalar constant: ");
        scanf("%d", &constant);
        for(counter = 0; counter < rows; counter++){
            for(int j = 0; j < columns; j++){
                matrix[counter][j] *= constant;
            }
        }
        printf("\nMultiplication successful!\n");
        break;
        
      case 3:
        for(counter = 0; counter < rows; counter++){
            for(int j = 0; j < columns; j++){
                printf("%d  ",matrix[counter][j]);
            }
            printf("\n");
        }
        printf("\nTranspose: \n");
        for(counter = 0; counter < columns; counter++){
            for(int j = 0; j < rows; j++){
                printf("%d  ",matrix[j][counter]);
            }
            printf("\n");
        }
        break;
        
      case 4:
        for(counter = 0; counter < rows; counter++){
            for(int j = 0; j < columns; j++){
                printf("%d  ",matrix[counter][j]);
            }
            printf("\n");
        }
        break;
        
      case 5:
        printf("\nExiting program...\n");
        exit(0);
        
      default:
        printf("\nInvalid option selected. Please try again.\n");
        break;
    }
  } while(1);

  return 0;
}