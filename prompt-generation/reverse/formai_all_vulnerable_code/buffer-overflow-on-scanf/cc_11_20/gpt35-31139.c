//FormAI DATASET v1.0 Category: Pattern printing ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // A program to print a unique C pattern
    int n, i, j, k, m, l;
    char c;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the character to use: ");
    scanf(" %c", &c);

    // Top half of the C
    for (i = 1; i <= n/2; i++) {
        for (j = 1; j <= n/2; j++) {
            if (i == 1 || j == 1)
                printf("%c ", c);
            else
                printf("  ");
        }
        printf("\n");
    }

    // Middle section of the C
    for (k = 1; k <= n/2; k++) {
        for (m = 1; m <= n/2; m++) {
            if (m == 1)
                printf("%c ", c);
            else
                printf("  ");
        }
        for (l = 1; l <= n/2; l++) {
            if (k == n/2/2+1)
                printf("%c ", c);
            else
                printf("  ");
        }
        printf("\n");
    }

    // Bottom half of the C
    for (i = 1; i <= n/2; i++) {
        for (j = 1; j <= n/2; j++) {
            if (j == n/2 || i == n/2)
                printf("%c ", c);
            else
                printf("  ");
        }
        printf("\n");
    }

    return 0;
}