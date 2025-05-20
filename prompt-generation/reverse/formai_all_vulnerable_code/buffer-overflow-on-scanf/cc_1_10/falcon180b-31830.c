//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printPattern(int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int main() {
    int n, m, choice;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);
    printf("Enter your choice:\n");
    printf("1. Square\n");
    printf("2. Triangle\n");
    printf("3. Diamond\n");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printPattern(n, m);
            break;
        case 2:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i == j || i + j == m - 1) {
                        printf("* ");
                    } else {
                        printf("  ");
                    }
                }
                printf("\n");
            }
            break;
        case 3:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i == j || i + j == m - 1 || i - j + m - 1 == 0) {
                        printf("* ");
                    } else {
                        printf("  ");
                    }
                }
                printf("\n");
            }
            break;
        default:
            printf("Invalid choice!");
    }
    return 0;
}