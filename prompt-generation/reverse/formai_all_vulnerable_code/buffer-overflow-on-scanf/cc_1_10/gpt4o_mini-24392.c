//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: visionary
#include <stdio.h>

void printInlineSpaces(int spaces)
{
    for (int j = 0; j < spaces; j++)
    {
        printf(" ");
    }
}

void printStars(int stars)
{
    for (int j = 0; j < stars; j++)
    {
        printf("* ");
    }
}

void drawPyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        int spaces = height - i - 1; // Spaces on the left side
        int stars = i + 1;            // Stars in the current row

        printInlineSpaces(spaces);
        printStars(stars);

        // Move to the next line after one row is printed
        printf("\n");
    }
}

void drawReversePyramid(int height)
{
    for (int i = height - 1; i >= 0; i--)
    {
        int spaces = height - i - 1; // Spaces on the left side
        int stars = i + 1;            // Stars in the current row

        printInlineSpaces(spaces);
        printStars(stars);

        // Move to the next line after one row is printed
        printf("\n");
    }
}

void drawDiamond(int height)
{
    drawPyramid(height);
    drawReversePyramid(height - 1); // Drawing the bottom part
}

void drawHollowDiamond(int height)
{
    // Draw the upper part of the hollow diamond
    for (int i = 0; i < height; i++)
    {
        for (int j = height - i; j > 1; j--)
            printf(" ");
        printf("*");
        if (i > 0)
        {
            for (int j = 0; j < 2 * i - 1; j++)
                printf(" ");
            printf("*");
        }
        printf("\n");
    }

    // Draw the lower part of the hollow diamond
    for (int i = height - 1; i > 0; i--)
    {
        for (int j = height - i; j > 0; j--)
            printf(" ");
        printf("*");
        if (i > 1)
        {
            for (int j = 0; j < 2 * (i - 1) - 1; j++)
                printf(" ");
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int height;

    // Get the height of the diamond from the user
    printf("Enter the height of the diamond (odd number recommended): ");
    scanf("%d", &height);
    
    // Ensure height is a positive integer
    if (height < 1)
    {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    printf("\nFull Diamond Pattern:\n");
    drawDiamond(height);

    printf("\nHollow Diamond Pattern:\n");
    drawHollowDiamond(height);

    return 0;
}