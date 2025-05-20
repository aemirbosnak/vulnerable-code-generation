//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: modular
#include <stdio.h>

#define ROWS 10
#define COLS 10

void drawSquare(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void drawDiamond(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void drawTriangle(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int shape, size;

    printf("Enter shape (1 for square, 2 for diamond, 3 for triangle): ");
    scanf("%d", &shape);

    printf("Enter size of shape: ");
    scanf("%d", &size);

    switch (shape) {
        case 1:
            drawSquare(size);
            break;
        case 2:
            drawDiamond(size);
            break;
        case 3:
            drawTriangle(size);
            break;
        default:
            printf("Invalid shape.\n");
            return 0;
    }

    return 0;
}