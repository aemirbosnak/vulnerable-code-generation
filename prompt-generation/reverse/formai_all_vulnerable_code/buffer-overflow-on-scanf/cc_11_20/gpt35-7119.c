//FormAI DATASET v1.0 Category: Matrix operations ; Style: excited
#include <stdio.h>

int main() {
    printf("I am so excited to share with you this amazing C program that performs Matrix Operations!\n\n");
    
    int matrix[3][3];
    printf("Enter values for a 3x3 matrix:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    printf("\n\nThe matrix you entered is:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    int determinant = (matrix[0][0]*(matrix[1][1]*matrix[2][2]-matrix[2][1]*matrix[1][2])) - (matrix[0][1]*(matrix[1][0]*matrix[2][2]-matrix[2][0]*matrix[1][2])) + (matrix[0][2]*(matrix[1][0]*matrix[2][1]-matrix[2][0]*matrix[1][1]));
    printf("\n\nThe determinant of the matrix is: %d\n", determinant);
    
    int inverse[3][3];
    inverse[0][0] = (matrix[1][1]*matrix[2][2] - matrix[2][1]*matrix[1][2]);
    inverse[0][1] = (-(matrix[1][0]*matrix[2][2] - matrix[2][0]*matrix[1][2]));
    inverse[0][2] = (matrix[1][0]*matrix[2][1] - matrix[2][0]*matrix[1][1]);
    inverse[1][0] = (-(matrix[0][1]*matrix[2][2] - matrix[2][1]*matrix[0][2]));
    inverse[1][1] = (matrix[0][0]*matrix[2][2] - matrix[2][0]*matrix[0][2]);
    inverse[1][2] = (-(matrix[0][0]*matrix[2][1] - matrix[2][0]*matrix[0][1]));
    inverse[2][0] = (matrix[0][1]*matrix[1][2] - matrix[1][1]*matrix[0][2]);
    inverse[2][1] = (-(matrix[0][0]*matrix[1][2] - matrix[1][0]*matrix[0][2]));
    inverse[2][2] = (matrix[0][0]*matrix[1][1] - matrix[1][0]*matrix[0][1]);
    
    printf("\n\nThe inverse of the matrix is:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", inverse[i][j]);
        }
        printf("\n");
    }

    int product[3][3] = {0};
    int second_matrix[3][3];
    printf("\n\nEnter values for the second 3x3 matrix:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            scanf("%d", &second_matrix[i][j]);
        }
    }
    
    printf("\n\nThe second matrix you entered is:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", second_matrix[i][j]);
        }
        printf("\n");
    }
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            for(int k=0; k<3; k++) {
                product[i][j] += matrix[i][k] * second_matrix[k][j];
            }
        }
    }
    
    printf("\n\nThe product of the two matrices is:\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", product[i][j]);
        }
        printf("\n");
    }
    
    printf("\n\nThank you for using this Matrix Operations program! Stay excited about coding!\n");
    
    return 0; 
}