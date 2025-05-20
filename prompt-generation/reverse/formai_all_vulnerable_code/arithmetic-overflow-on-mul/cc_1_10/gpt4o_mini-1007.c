//GPT-4o-mini DATASET v1.0 Category: Geometric algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

void drawSquare(int size) {
    printf("\nSquare:\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");
}

void drawTriangle(int height) {
    printf("Triangle:\n");
    for(int i = 1; i <= height; i++) {
        for(int j = i; j < height; j++) {
            printf(" ");
        }
        for(int k = 1; k <= (2*i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

void drawCircle(int radius) {
    printf("Circle:\n");
    for (int y = radius; y >= -radius; y--) {
        for (int x = -radius; x <= radius; x++) {
            if (x*x + y*y <= radius*radius) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void drawRhombus(int diagonal) {
    printf("Rhombus:\n");
    int height = diagonal / 2;
    for(int i = -height; i <= height; i++) {
        for(int j = -height; j <= height; j++) {
            if(abs(i) + abs(j) == height) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int choice, size, height, radius, diagonal;

    printf("Welcome to the ASCII Art Geometry Drawer!\n");
    printf("Select a shape to draw:\n");
    printf("1. Square\n");
    printf("2. Triangle\n");
    printf("3. Circle\n");
    printf("4. Rhombus\n");
    printf("5. Exit\n");

    while(1) {
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the size of the square: ");
                scanf("%d", &size);
                drawSquare(size);
                break;
            case 2:
                printf("Enter the height of the triangle: ");
                scanf("%d", &height);
                drawTriangle(height);
                break;
            case 3:
                printf("Enter the radius of the circle: ");
                scanf("%d", &radius);
                drawCircle(radius);
                break;
            case 4:
                printf("Enter the diagonal size of the rhombus: ");
                scanf("%d", &diagonal);
                drawRhombus(diagonal);
                break;
            case 5:
                printf("Thank you for using the ASCII Art Geometry Drawer! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}