//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Function to print patterns
void printPatterns() {
    int i, j, n;
    printf("\nEnter the number of patterns you want to print: ");
    scanf("%d", &n);

    // Pattern 1
    printf("\nPattern 1:\n");
    for(i=1; i<=10; i++) {
        for(j=1; j<=i; j++) {
            printf("%d", i);
        }
        printf("\n");
    }

    // Pattern 2
    printf("\nPattern 2:\n");
    for(i=1; i<=10; i++) {
        for(j=10; j>=i; j--) {
            printf("%d", j);
        }
        printf("\n");
    }

    // Pattern 3
    printf("\nPattern 3:\n");
    for(i=1; i<=10; i++) {
        for(j=1; j<=10-i; j++) {
            printf(" ");
        }
        for(j=1; j<=2*i-1; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Pattern 4
    printf("\nPattern 4:\n");
    for(i=1; i<=5; i++) {
        for(j=1; j<=5-i; j++) {
            printf(" ");
        }
        for(j=1; j<=2*i-1; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    // Pattern 5
    printf("\nPattern 5:\n");
    for(i=1; i<=5; i++) {
        for(j=5; j>=i; j--) {
            printf("%d", j);
        }
        for(j=1; j<=5-i; j++) {
            printf(" ");
        }
        printf("\n");
    }
}

int main() {
    printPatterns();
    return 0;
}