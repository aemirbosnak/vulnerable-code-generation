//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: automated
#include <stdio.h>

void printDiamond(int n) {
    int space, i, j;

    // Print top part of diamond
    for(i = 0; i < n; i++) {
        for(space = 0; space < n - i - 1; space++) {
            printf(" ");
        }
        for(j = 0; j < (2 * i + 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    // Print bottom part of diamond
    for(i = n - 2; i >= 0; i--) {
        for(space = 0; space < n - i - 1; space++) {
            printf(" ");
        }
        for(j = 0; j < (2 * i + 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printHollowSquare(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void printPyramid(int n) {
    int i, j, k;
    
    for(i = 0; i < n; i++) {
        for(j = n; j > i + 1; j--) {
            printf(" ");
        }
        for(k = 0; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }
}

void printInvertedTriangle(int n) {
    for(int i = n; i > 0; i--) {
        for(int j = 0; j < n - i; j++) {
            printf(" ");
        }
        for(int j = 0; j < (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printSolidRhombus(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        for(int j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void printHollowRhombus(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            printf(" ");
        }
        for(int j = 0; j < n; j++) {
            if(j == 0 || j == n - 1 || i == 0 || i == n - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int h, p, d, r, hr, n;

    printf("Enter the height for Diamond Pattern: ");
    scanf("%d", &d);
    printDiamond(d);

    printf("Enter the size for Hollow Square Pattern: ");
    scanf("%d", &h);
    printHollowSquare(h);

    printf("Enter the height for Pyramid Pattern: ");
    scanf("%d", &p);
    printPyramid(p);

    printf("Enter the height for Inverted Triangle Pattern: ");
    scanf("%d", &n);
    printInvertedTriangle(n);

    printf("Enter the height for Solid Rhombus Pattern: ");
    scanf("%d", &r);
    printSolidRhombus(r);

    printf("Enter the height for Hollow Rhombus Pattern: ");
    scanf("%d", &hr);
    printHollowRhombus(hr);

    return 0;
}