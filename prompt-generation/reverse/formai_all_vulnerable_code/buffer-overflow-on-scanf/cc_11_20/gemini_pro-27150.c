//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Let's set the stage for our cheerful pattern!
    int rows, columns;

    // Ask the user to choose the dimensions of their pattern.
    printf("Welcome to the Pattern Painting Party!\n");
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    // Create a canvas to paint our pattern on.
    char canvas[rows][columns];

    // Initialize our canvas with empty spaces.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            canvas[i][j] = ' ';
        }
    }

    // Time to paint some colorful shapes!
    // We'll start with a vibrant triangle.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            canvas[i][j] = '*';
        }
    }

    // Now, let's add a cheerful circle.
    int radius = rows / 2;
    int center_x = columns / 2;
    int center_y = rows / 2;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (((i - center_x) * (i - center_x) + (j - center_y) * (j - center_y)) <= (radius * radius))
            {
                canvas[i][j] = 'o';
            }
        }
    }

    // Don't forget the playful squares!
    int square_size = rows / 3;
    for (int i = 0; i < square_size; i++)
    {
        for (int j = 0; j < square_size; j++)
        {
            canvas[i][j] = '#';
            canvas[i][columns - j - 1] = '#';
            canvas[rows - i - 1][j] = '#';
            canvas[rows - i - 1][columns - j - 1] = '#';
        }
    }

    // Let's finish off with some twinkling stars.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (rand() % 10 == 0)
            {
                canvas[i][j] = '*';
            }
        }
    }

    // Ta-da! Our cheerful pattern is complete!
    printf("\nYour vibrant masterpiece:\n");

    // Display our colorful creation.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }

    return 0;
}