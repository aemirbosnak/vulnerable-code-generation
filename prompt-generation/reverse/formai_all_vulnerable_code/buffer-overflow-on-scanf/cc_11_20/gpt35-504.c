//FormAI DATASET v1.0 Category: Pattern printing ; Style: innovative
#include <stdio.h>

int main() {
    printf("\n\n\t\tWelcome to C Pattern printing\n\n");
    int rows, cols, i, j, k, count = 1;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    printf("\n\n");

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= cols; j++) {
            if (i == 1 || i == rows || j == 1 || j == cols) {
                printf("* ");
            }
            else {
                printf("%d ", count);
                count++;
            }
        }
        printf("\n");
    }

    count = 1;
    printf("\n\n");

    for (i = 1; i <= rows; i++) {
        k = i;
        for (j = 1; j <= cols; j++) {
            if (j <= i) {
                printf("%d ", k);
                k--;
                if (k == 0) {
                    break;
                }
            }
            else {
                printf("* ");
            }
        }
        printf("\n");
    }

    count = 1;
    printf("\n\n");

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= cols; j++) {
            if (i == 1 || i == rows || j == 1 || j == cols) {
                printf("* ");
            }
            else {
                printf("%d ", count);
                count += 2;
            }
        }
        printf("\n");
    }

    printf("\n\n\t\tThank you for using C Pattern printing!\n\n");

    return 0;
}