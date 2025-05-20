//FormAI DATASET v1.0 Category: Pattern printing ; Style: peaceful
#include <stdio.h>

int main() {
    printf("Peaceful C Pattern Printing Example Program\n\n");

    int rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("\n");

    for(int i=0; i<rows; i++) {
        for(int j=0; j<i; j++) {
            printf(" ");
        }
        for(int j=0; j<rows-i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");

    for(int i=0; i<rows; i++) {
        for(int j=0; j<rows-i-1; j++) {
            printf("  ");
        }
        for(int j=0; j<2*i+1; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");

    for(int i=0; i<rows; i++) {
        for(int j=0; j<i; j++) {
            printf(" ");
        }
        for(int j=0; j<rows-i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    for(int i=0; i<rows; i++) {
        for(int j=rows-i-1; j>0; j--) {
            printf("  ");
        }
        for(int j=0; j<(2*i)+1; j++) {
            printf("* ");
        }
        printf("\n");
    }

    printf("\n");

    for(int i=0; i<=rows/2; i++) {
        for(int j=i; j<rows-i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    for(int i=(rows/2)+1; i<rows; i++) {
        for(int j=0; j<=i; j++) {
            printf("  ");
        }
        for(int j=i; j<rows; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}