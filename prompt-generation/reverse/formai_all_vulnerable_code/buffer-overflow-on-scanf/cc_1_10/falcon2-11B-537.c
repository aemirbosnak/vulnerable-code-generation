//Falcon2-11B DATASET v1.0 Category: Pattern printing ; Style: multivariable
#include <stdio.h>

void printPattern(int n, int m) {
    int i, j;

    // Initialize the two variables
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            putchar(' ');
        }
        putchar('\n');
    }

    // Print the numbers
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (j == 1 || j == m) {
                putchar('*');
            } else {
                putchar(j + '0');
            }
        }
        putchar('\n');
    }

    // Print the characters
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (j == 1 || j == m) {
                putchar('*');
            } else {
                putchar('*');
            }
        }
        putchar('\n');
    }
}

int main() {
    int n, m;

    // Get the size of the pattern from the user
    printf("Enter the size of the pattern (rows): ");
    scanf("%d", &n);

    printf("Enter the size of the pattern (columns): ");
    scanf("%d", &m);

    // Print the pattern
    printPattern(n, m);

    return 0;
}