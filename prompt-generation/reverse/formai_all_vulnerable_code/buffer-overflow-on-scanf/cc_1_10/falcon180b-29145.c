//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: curious
#include <stdio.h>

// Function to print patterns
void print_patterns() {
    // Pattern 1
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Pattern 2
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10 - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Pattern 3
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (j <= 5 - i || j >= 5 + i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Pattern 4
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if ((i + j) % 2 == 0) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Pattern 5
    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    print_patterns();
    return 0;
}