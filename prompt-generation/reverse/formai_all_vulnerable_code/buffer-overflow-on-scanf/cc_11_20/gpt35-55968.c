//FormAI DATASET v1.0 Category: Pattern printing ; Style: excited
#include <stdio.h>

int main() {
    printf("\n\n\t\tWELCOME TO THE C PATTERN PRINTING MADNESS!!\n\n");
    printf("\t\t------------------------------------------\n\n");

    int rows;
    printf("How many rows do you want to print: ");
    scanf("%d", &rows);

    printf("\n");
    int i, j, k;

    for(i=1; i<=rows; i++) {
        for(j=rows; j>i; j--) {
            printf("  ");
        }
        for(k=1; k<=i; k++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");

    for(i=rows; i>=1; i--) {
        for(j=rows; j>i; j--) {
            printf("  ");
        }
        for(k=1; k<=i; k++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");

    for(i=1; i<=rows; i++) {
        for(j=1; j<=i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    printf("\n");

    for(i=1; i<=rows; i++) {
        for(j=1; j<=rows-i+1; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }

    printf("\n");

    for(i=1; i<=rows; i++) {
        for(j=rows; j>=i; j--) {
            printf("%c ", 64+j);
        }
        printf("\n");
    }

    printf("\n");

    for(i=1; i<=rows; i++) {
        for(j=rows; j>=i; j--) {
            printf("%c ", 64+i);
        }
        printf("\n");
    }

    printf("\n\n\t\tThank you for joining the madness. Now go print some patterns!!");
    printf("\n\n\t\t---------------------------------------------------------\n\n");

    return 0;
}