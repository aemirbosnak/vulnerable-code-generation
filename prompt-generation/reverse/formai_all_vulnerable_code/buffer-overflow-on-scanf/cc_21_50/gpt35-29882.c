//FormAI DATASET v1.0 Category: Pattern printing ; Style: all-encompassing
#include <stdio.h>

int main() {
    printf("Enter the number of rows: ");
    int rows;
    scanf("%d", &rows);
    int i, j, k;

    // Pattern A
    printf("\nPattern A:\n\n");
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    // Pattern B
    printf("\nPattern B:\n\n");
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    // Pattern C
    printf("\nPattern C:\n\n");
    for (i = rows; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    // Pattern D
    printf("\nPattern D:\n\n");
    for (i = 1; i <= rows; i++) {
        for (j = rows; j >= i; j--) {
            printf("* ");
        }
        printf("\n");
    }

    // Pattern E
    printf("\nPattern E:\n\n");
    for (i = 1; i <= rows; i++) {
        for (j = 1; j < i; j++) {
            printf("  ");
        }
        for (k = 1; k <= (2 * rows - 2 * i + 1); k++) {
            printf("* ");
        }
        printf("\n");
    }

    // Pattern F
    printf("\nPattern F:\n\n");
    int num = 1;
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }

    // Pattern G
    printf("\nPattern G:\n\n");
    int space = rows - 1;
    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= space; j++) {
            printf("  ");
        }
        space--;
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("* ");
        }
        printf("\n");
    }

    // Pattern H
    printf("\nPattern H:\n\n");
    for(i = 1; i <= rows; i++) {
        for(j = rows; j >= i; j--) {
            printf(" ");
        }
        for(k = 1; k <= i; k++) {
            printf("%d", k);
        }
        for(k = i-1; k >= 1; k--) {
            printf("%d", k);
        }
        printf("\n");
    }

    return 0;
}