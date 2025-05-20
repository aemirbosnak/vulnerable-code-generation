//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: shape shifting
#include <stdio.h>

int main() {
    int shape = 0;

    while (1) {
        printf("Enter a shape to transform (1 = square, 2 = triangle, 3 = circle): ");
        scanf("%d", &shape);

        printf("Enter the x and y coordinates of the center of the shape: ");
        int x, y;
        scanf("%d %d", &x, &y);

        printf("Enter the size of the shape: ");
        int size;
        scanf("%d", &size);

        if (shape == 1) {
            for (int i = 0; i <= size; i++) {
                for(int j = 0; j <= size; j++) {
                    if (i == 0 || i == size || j == 0 || j == size) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        } else if (shape == 2) {
            for (int i = 0; i <= size; i++) {
                for(int j = 1; j <= size-i; j++) {
                    printf(" ");
                }
                for (int j = 0; j <= i*2; j++) {
                    printf("*");
                }
                printf("\n");
            }
        } else if (shape == 3) {
            for (int i = 0; i <= size; i++) {
                for(int j = 0; j <= size*2; j++) {
                    int dx = i - size;
                    int dy = j - size;
                    if (dx * dx + dy * dy <= size * size) {
                        printf("*");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }

        printf("\nEnter 1 to transform again, or any other key to exit: ");
        int again;
        scanf("%d", &again);

        if (again != 1) {
            break;
        }
    }

    return 0;
}