//FormAI DATASET v1.0 Category: Pattern printing ; Style: recursive
#include <stdio.h>

// Function to print the upper half of the C pattern
void printUpperHalf(int width, int height, int currentRow, int currentCol)
{
    // Base condition for recursion
    if (currentRow == 0) return;

    // Print the first character of the upper half
    if (currentCol == 0) printf("*");
    
    // Print the spaces between the two vertical lines
    else if (currentCol == width - 1) printf("\n");
    else printf(" ");
    
    // Move to the next element recursively
    printUpperHalf(width, height, currentRow - 1, currentCol + 1);
}

// Function to print the lower half of the C pattern
void printLowerHalf(int width, int height, int currentRow, int currentCol)
{
    // Base condition for recursion
    if (currentRow == height - 1) return;

    // Print the first character of the lower half
    if (currentCol == 0) printf("*");
    
    // Print the spaces between the two vertical lines
    else if (currentCol == width - 1) printf("\n");
    else printf(" ");
    
    // Move to the next element recursively
    printLowerHalf(width, height, currentRow + 1, currentCol + 1);
}

// Function to print the vertical line of the C pattern
void printVerticalLine(int height)
{
    // Base condition for recursion
    if (height == 0) return;

    printf("*\n");
    printVerticalLine(height - 1);
}

// Function to print the full C pattern
void printCPattern(int width, int height)
{
    if (width < 3 || height < 3)
    {
        printf("Invalid dimensions, please enter a value greater than or equal to 3.\n");
        return;
    }

    // Print upper half of C pattern
    printUpperHalf(width, height / 2, height / 2, 0);

    // Print vertical line of C pattern
    printVerticalLine(height);

    // Print lower half of C pattern
    printLowerHalf(width, height / 2 + 1, 0, 0);
}

int main()
{
    int width, height;
    printf("Enter the width and height of the C pattern (both should be greater than or equal to 3): ");
    scanf("%d %d", &width, &height);
    printf("\n");
    printCPattern(width, height);
    printf("\n");
    return 0;
}