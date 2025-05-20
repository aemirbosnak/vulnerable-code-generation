//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: automated
#include <stdio.h>

void displayFibonacci(int n) {
    int n1 = 0, n2 = 1, n3, i;

    printf("%d %d ", n1, n2);

    for (i = 2; i < n; ++i) {
        n3 = n1 + n2;
        printf("%d ", n3);
        n1 = n2;
        n2 = n3;
    }
}

void drawShape(char character, int width, int height) {
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c ", character);
        }
        printf("\n");
    }
}

int main() {
    int choice, n;

    printf("Welcome to the Fibonacci Sequence Visualizer!\n\n");

    do {
        printf("What would you like to do?\n");
        printf("1. Display Fibonacci Sequence\n");
        printf("2. Draw a Shape with a given character\n");
        printf("3. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of terms in the sequence: ");
                scanf("%d", &n);
                displayFibonacci(n);
                printf("\n\n");
                break;
            case 2:
                printf("Enter the character you want to draw with: ");
                getchar(); // clear input buffer
                char character = getchar();

                printf("Enter the width of the shape: ");
                scanf("%d", &n);
                int width = n;

                printf("Enter the height of the shape: ");
                scanf("%d", &n);
                int height = n;

                drawShape(character, width, height);
                printf("\n");
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}