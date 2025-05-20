//FormAI DATASET v1.0 Category: Educational ; Style: shape shifting
#include <stdio.h>

int main() {
    int choice, size;
    printf("Enter the initial size of the shape: ");
    scanf("%d", &size);
    printf("Enter the shape you want to create:\n");
    printf("1. Square\n");
    printf("2. Triangle\n");
    printf("3. Rectangle\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("Creating a square...\n");
            for(int row = 1; row <= size; row++) {
                for(int col = 1; col <= size; col++) {
                    if(row == 1 || row == size || col == 1 || col == size) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            break;
        case 2:
            printf("Creating a triangle...\n");
            for(int row = 1; row <= size; row++) {
                for(int col = 1; col <= row; col++) {
                    printf("*");
                }
                printf("\n");
            }
            break;
        case 3:
            printf("Creating a rectangle...\n");
            for(int row = 1; row <= size; row++) {
                for(int col = 1; col <= size*2; col++) {
                    if(row == 1 || row == size || col == 1 || col == size*2) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            break;
        default:
            printf("Invalid choice!\n");
    }
    
    return 0;
}