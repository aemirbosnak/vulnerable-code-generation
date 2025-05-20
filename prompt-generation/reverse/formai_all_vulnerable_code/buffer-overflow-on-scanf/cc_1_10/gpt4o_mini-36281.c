//GPT-4o-mini DATASET v1.0 Category: Recursive ; Style: shape shifting
#include <stdio.h>

void drawTriangle(int n) {
    if (n <= 0) {
        return; // Base case
    } else {
        drawTriangle(n - 1); // Recursive call first
        for (int i = 0; i < n; i++) {
            printf("*");
        }
        printf("\n"); // New line after each row of the triangle
    }
}

void drawSquare(int n) {
    if (n <= 0) {
        return; // Base case
    } else {
        for (int i = 0; i < n; i++) {
            printf("*");
        }
        printf("\n");
        drawSquare(n - 1); // Recursive call for drawing remaining rows
    }
}

int main() {
    int shapeType, size;

    printf("Choose a shape to draw:\n");
    printf("1. Right-angled Triangle\n");
    printf("2. Square\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &shapeType);

    printf("Enter the size of the shape (number of rows or columns): ");
    scanf("%d", &size);

    if (shapeType == 1) {
        printf("Drawing a Right-angled Triangle of size %d:\n", size);
        drawTriangle(size);
    } else if (shapeType == 2) {
        printf("Drawing a Square of size %d:\n", size);
        drawSquare(size);
    } else {
        printf("Invalid shape type selected.\n");
    }

    return 0;
}