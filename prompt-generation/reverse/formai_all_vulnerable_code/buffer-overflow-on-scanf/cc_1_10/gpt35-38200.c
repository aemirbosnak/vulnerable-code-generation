//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: shape shifting
#include <stdio.h>
#include <string.h>

void printHorizontalLine(int width) {
    for (int i = 0; i < width; i++) {
        printf("*");
    }
    printf("\n");
}

void printVerticalLine(int height) {
    for (int i = 0; i < height; i++) {
        printf("*\n");
    }
}

void printTriangle(int height) {
    for (int i = 1; i <= height; i++) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printRectangle(int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    char text[100];
    int shape;

    printf("Enter text: ");
    scanf("%s", text);

    printf("Select shape (1=rectangle, 2=triangle): ");
    scanf("%d", &shape);

    int width = strlen(text) + 4;
    int height = strlen(text) + 2;

    if (shape == 1) {
        printHorizontalLine(width);
        printRectangle(width - 2, height - 2);
        printHorizontalLine(width);
    } else if (shape == 2) {
        printVerticalLine(1);
        printTriangle(height - 2);
        printHorizontalLine(width);
    } else {
        printf("Invalid shape selected\n");
    }

    return 0;
}