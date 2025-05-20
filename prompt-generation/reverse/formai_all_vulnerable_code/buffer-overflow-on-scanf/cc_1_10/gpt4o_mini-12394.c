//GPT-4o-mini DATASET v1.0 Category: Bitwise operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 8

// Function prototype declarations
void drawShape(int shape, int size);
void bitwiseManipulation(int *shapeArray, int size);
void printBinary(int num);
void printShape(int shape, int size);

// Main function
int main() {
    int choice, size;
    int shapeArray[MAX_SIZE];

    do {
        printf("Shape Shifter Program\n");
        printf("======================\n");
        printf("1. Draw a shape\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter the size of the shape (1-%d): ", MAX_SIZE);
            scanf("%d", &size);

            if(size < 1 || size > MAX_SIZE) {
                printf("Invalid size. Please choose between 1 and %d.\n", MAX_SIZE);
                continue;
            }

            printf("Choose a shape to draw:\n");
            printf("1. Triangle\n");
            printf("2. Square\n");
            printf("3. Diamond\n");
            printf("Enter your choice: ");
            int shape;
            scanf("%d", &shape);

            // Draw the chosen shape
            drawShape(shape, size);
            printf("\n");

            // Store shape properties in binary representation
            for (int i = 0; i < size; i++) {
                shapeArray[i] = (1 << i); // setting the i-th bit
            }

            printf("Bitwise Manipulation:\n");
            bitwiseManipulation(shapeArray, size);
        }
    } while(choice != 2);

    return 0;
}

// Function to draw different shapes
void drawShape(int shape, int size) {
    printf("Drawing shape:\n");
    switch(shape) {
        case 1:
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size - i; j++) {
                    printf(" ");
                }
                for (int j = 0; j <= i; j++) {
                    printf("* ");
                }
                printf("\n");
            }
            break;

        case 2:
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    printf("* ");
                }
                printf("\n");
            }
            break;

        case 3:
            for (int i = 0; i < size; i++) {
                for (int j = size - i; j > 1; j--) {
                    printf(" ");
                }
                for (int j = 0; j <= i; j++) {
                    printf("* ");
                }
                printf("\n");
            }
            for (int i = size - 2; i >= 0; i--) {
                for (int j = size - i; j > 1; j--) {
                    printf(" ");
                }
                for (int j = 0; j <= i; j++) {
                    printf("* ");
                }
                printf("\n");
            }
            break;

        default:
            printf("Invalid shape selected.\n");
            break;
    }
}

// Function for bitwise manipulation of shape properties
void bitwiseManipulation(int *shapeArray, int size) {
    printf("Original shapes in binary:\n");
    for(int i = 0; i < size; i++) {
        printf("Shape %d bit pattern: ", i + 1);
        printBinary(shapeArray[i]);
    }
    
    int combinedShape = 0;
    
    for(int i = 0; i < size; i++) {
        combinedShape |= shapeArray[i]; // Bitwise OR to combine shapes
    }
    
    printf("Combined shape bit pattern: ");
    printBinary(combinedShape);
    
    printf("Performing bitwise operations:\n");
    printf("Flipped shape properties:\n");
    for(int i = 0; i < size; i++) {
        shapeArray[i] = ~shapeArray[i];
        printf("Flipped shape %d: ", i + 1);
        printBinary(shapeArray[i]);
    }
    
    printf("Combined shape after flip: ");
    combinedShape = ~combinedShape;
    printBinary(combinedShape);
}

// Function to print the binary representation of a number
void printBinary(int num) {
    for(int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}