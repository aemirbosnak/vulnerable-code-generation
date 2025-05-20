//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: modular
#include <stdio.h>

// Function to print a hollow rectangle
void printHollowRectangle(int n, int m)
{
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (i == 1 || i == n || j == 1 || j == m) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to print a solid rectangle
void printSolidRectangle(int n, int m)
{
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print a right triangle
void printRightTriangle(int n)
{
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print a left triangle
void printLeftTriangle(int n)
{
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print a diamond
void printDiamond(int n)
{
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i + 1; j++) {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= n - i + 1; j++) {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

// Function to print a Christmas tree
void printChristmasTree(int n)
{
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i + 1; j++) {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int n, m;

    printf("Enter the number of rows and columns for the hollow rectangle: ");
    scanf("%d %d", &n, &m);
    printHollowRectangle(n, m);

    printf("Enter the number of rows and columns for the solid rectangle: ");
    scanf("%d %d", &n, &m);
    printSolidRectangle(n, m);

    printf("Enter the number of rows for the right triangle: ");
    scanf("%d", &n);
    printRightTriangle(n);

    printf("Enter the number of rows for the left triangle: ");
    scanf("%d", &n);
    printLeftTriangle(n);

    printf("Enter the number of rows for the diamond: ");
    scanf("%d", &n);
    printDiamond(n);

    printf("Enter the number of rows for the Christmas tree: ");
    scanf("%d", &n);
    printChristmasTree(n);

    return 0;
}