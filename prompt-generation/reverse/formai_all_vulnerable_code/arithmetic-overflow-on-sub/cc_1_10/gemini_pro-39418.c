//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Function to print a hollow diamond pattern
void printDiamond(int n)
{
    int i, j, k, l;
    for (i = 0; i < n; i++)
    {
        // Print spaces for left triangle
        for (j = 0; j < n - i - 1; j++)
            printf(" ");

        // Print stars for left triangle
        for (k = 0; k < 2 * i + 1; k++)
            printf("*");

        // Print spaces for right triangle
        for (l = 0; l < n - i - 1; l++)
            printf(" ");

        // Move to the next line
        printf("\n");
    }

    // Print the bottom half of the diamond
    for (i = n - 1; i >= 0; i--)
    {
        // Print spaces for left triangle
        for (j = 0; j < n - i; j++)
            printf(" ");

        // Print stars for left triangle
        for (k = 0; k < 2 * i + 1; k++)
            printf("*");

        // Print spaces for right triangle
        for (l = 0; l < n - i; l++)
            printf(" ");

        // Move to the next line
        printf("\n");
    }
}

// Function to print a solid diamond pattern
void printSolidDiamond(int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        // Print spaces for left triangle
        for (j = 0; j < n - i - 1; j++)
            printf(" ");

        // Print stars for left triangle
        for (j = 0; j < 2 * i + 1; j++)
            printf("*");

        // Print stars for right triangle
        for (j = 0; j < 2 * i + 1; j++)
            printf("*");

        // Move to the next line
        printf("\n");
    }

    // Print the bottom half of the diamond
    for (i = n - 1; i >= 0; i--)
    {
        // Print spaces for left triangle
        for (j = 0; j < n - i; j++)
            printf(" ");

        // Print stars for left triangle
        for (j = 0; j < 2 * i + 1; j++)
            printf("*");

        // Print stars for right triangle
        for (j = 0; j < 2 * i + 1; j++)
            printf("*");

        // Move to the next line
        printf("\n");
    }
}

// Function to print a pyramid pattern
void printPyramid(int n)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        // Print spaces for left triangle
        for (j = 0; j < n - i - 1; j++)
            printf(" ");

        // Print stars for left triangle
        for (k = 0; k < 2 * i + 1; k++)
            printf("*");

        // Move to the next line
        printf("\n");
    }
}

// Function to print an inverted pyramid pattern
void printInvertedPyramid(int n)
{
    int i, j, k;
    for (i = n - 1; i >= 0; i--)
    {
        // Print spaces for left triangle
        for (j = 0; j < n - i - 1; j++)
            printf(" ");

        // Print stars for left triangle
        for (k = 0; k < 2 * i + 1; k++)
            printf("*");

        // Move to the next line
        printf("\n");
    }
}

// Function to print a right triangle pattern
void printRightTriangle(int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        // Print stars for left triangle
        for (j = 0; j <= i; j++)
            printf("*");

        // Move to the next line
        printf("\n");
    }
}

// Function to print an inverted right triangle pattern
void printInvertedRightTriangle(int n)
{
    int i, j;
    for (i = n - 1; i >= 0; i--)
    {
        // Print stars for left triangle
        for (j = 0; j <= i; j++)
            printf("*");

        // Move to the next line
        printf("\n");
    }
}

// Function to print a half pyramid pattern
void printHalfPyramid(int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        // Print spaces for left triangle
        for (j = 0; j < n - i - 1; j++)
            printf(" ");

        // Print stars for left triangle
        for (j = 0; j <= i; j++)
            printf("*");

        // Move to the next line
        printf("\n");
    }
}

// Function to print an inverted half pyramid pattern
void printInvertedHalfPyramid(int n)
{
    int i, j;
    for (i = n - 1; i >= 0; i--)
    {
        // Print spaces for left triangle
        for (j = 0; j < n - i - 1; j++)
            printf(" ");

        // Print stars for left triangle
        for (j = 0; j <= i; j++)
            printf("*");

        // Move to the next line
        printf("\n");
    }
}

// Function to print a Christmas tree pattern
void printChristmasTree(int n)
{
    int i, j, k, l;
    for (i = 0; i < n; i++)
    {
        // Print spaces for left triangle
        for (j = 0; j < n - i - 1; j++)
            printf(" ");

        // Print stars for left triangle
        for (k = 0; k < 2 * i + 1; k++)
            printf("*");

        // Print spaces for right triangle
        for (l = 0; l < n - i - 1; l++)
            printf(" ");

        // Move to the next line
        printf("\n");
    }

    // Print the trunk of the tree
    for (i = 0; i < n / 2; i++)
    {
        for (j = 0; j < (n - 1) / 2; j++)
            printf(" ");

        for (j = 0; j < 3; j++)
            printf("*");

        printf("\n");
    }
}

int main()
{
    int n;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    printf("\nHollow Diamond Pattern:\n");
    printDiamond(n);

    printf("\nSolid Diamond Pattern:\n");
    printSolidDiamond(n);

    printf("\nPyramid Pattern:\n");
    printPyramid(n);

    printf("\nInverted Pyramid Pattern:\n");
    printInvertedPyramid(n);

    printf("\nRight Triangle Pattern:\n");
    printRightTriangle(n);

    printf("\nInverted Right Triangle Pattern:\n");
    printInvertedRightTriangle(n);

    printf("\nHalf Pyramid Pattern:\n");
    printHalfPyramid(n);

    printf("\nInverted Half Pyramid Pattern:\n");
    printInvertedHalfPyramid(n);

    printf("\nChristmas Tree Pattern:\n");
    printChristmasTree(n);

    return 0;
}