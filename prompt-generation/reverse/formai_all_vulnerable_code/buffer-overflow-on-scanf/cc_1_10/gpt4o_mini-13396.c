//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: thoughtful
#include <stdio.h>

void printPyramid(int n) {
    int space, star;
    for (space = 0; space < n; space++) {
        for (star = 0; star < n - space - 1; star++) {
            printf(" ");
        }
        for (star = 0; star < (2 * space + 1); star++) {
            printf("*");
        }
        printf("\n");
    }
}

void printInvertedPyramid(int n) {
    int space, star;
    for (space = 0; space < n; space++) {
        for (star = 0; star < space; star++) {
            printf(" ");
        }
        for (star = 0; star < (2 * (n - space) - 1); star++) {
            printf("*");
        }
        printf("\n");
    }
}

void printDiamond(int n) {
    printPyramid(n);
    printInvertedPyramid(n - 1);
}

void printHollowDiamond(int n) {
    int space, star;
    
    // Upper part
    for (space = 0; space < n; space++) {
        for (star = 0; star < n - space - 1; star++) {
            printf(" ");
        }
        if (space == 0) {
            printf("*");
        } else {
            printf("*");
            for (star = 0; star < (2 * space - 1); star++) {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
    
    // Lower part
    for (space = n - 2; space >= 0; space--) {
        for (star = 0; star < n - space - 1; star++) {
            printf(" ");
        }
        if (space == 0) {
            printf("*");
        } else {
            printf("*");
            for (star = 0; star < (2 * space - 1); star++) {
                printf(" ");
            }
            printf("*");
        }
        printf("\n");
    }
}

void printPyramidWithNumbers(int n) {
    int i, j, num;

    for (i = 1; i <= n; i++) {
        for (j = i; j < n; j++) {
            printf(" ");
        }
        for (num = 1; num <= (2 * i - 1); num++) {
            printf("%d", num);
        }
        printf("\n");
    }
}

void printInvertedNumberPyramid(int n) {
    int i, j, num;

    for (i = n; i >= 1; i--) {
        for (j = n; j > i; j--) {
            printf(" ");
        }
        for (num = 1; num <= (2 * i - 1); num++) {
            printf("%d", num);
        }
        printf("\n");
    }
}

void printHollowPyramid(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = i; j < n; j++) {
            printf(" ");
        }
        for(int j = 1; j <= (2 * i - 1); j++) {
            if (j == 1 || j == (2 * i - 1) || i == n) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the height of the diamond pattern: ");
    scanf("%d", &n);
    printf("\nDiamond Pattern:\n");
    printDiamond(n);
    
    printf("\nHollow Diamond Pattern:\n");
    printHollowDiamond(n);

    printf("\nPyramid Pattern with Numbers:\n");
    printPyramidWithNumbers(n);

    printf("\nInverted Number Pyramid:\n");
    printInvertedNumberPyramid(n);
    
    printf("\nHollow Pyramid Pattern:\n");
    printHollowPyramid(n);

    return 0;
}