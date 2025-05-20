//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: expert-level
#include <stdio.h>

int main() {
    int rows, cols, i, j, k;
    char ch;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("Enter the character to print: ");
    scanf(" %c", &ch);

    // Print pattern
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c", ch);
        }
        printf("\n");
    }

    // Reverse pattern
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == rows - 1 - j) {
                printf("%c", ch);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Pyramid pattern
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == rows - 1 - j) {
                printf("%c", ch);
            } else if (i == j || i == cols - 1 - j) {
                printf("%c", ch);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Diamond pattern
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (i == rows - 1 - j || j == 0 || j == cols - 1) {
                printf("%c", ch);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}