//FormAI DATASET v1.0 Category: Pattern printing ; Style: lively
#include <stdio.h>

int main() {
    int i, j, rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("\n");

    for(i=1; i<=rows; i++) {
        for(j=1; j<=i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");

    for(i=1; i<=rows; i++) {
        for(j=1; j<=rows-i+1; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");

    for(i=1; i<=rows; i++) {
        for(j=1; j<=rows-i; j++) {
            printf("  ");
        }
        for(j=1; j<=2*i-1; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");

    for(i=1; i<=rows; i++) {
        for(j=1; j<=rows-i; j++) {
            printf("  ");
        }
        for(j=1; j<=i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");

    for(i=1; i<=rows; i++) {
        for(j=1; j<=rows-i; j++) {
            printf(" ");
        }
        for(j=1; j<=2*i-1; j++) {
            printf("%d", i%10);
        }
        printf("\n");
    }

    printf("\n");

    for(i=1; i<=rows; i++) {
        for(j=1; j<=rows-i; j++) {
            printf(" ");
        }
        for(j=1; j<=2*i-1; j++) {
            printf("%c", i%26 + 65);
        }
        printf("\n");
    }

    return 0;
}