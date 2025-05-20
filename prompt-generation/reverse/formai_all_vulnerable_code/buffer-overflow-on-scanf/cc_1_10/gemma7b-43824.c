//Gemma-7B DATASET v1.0 Category: Ebook reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

void draw_book(int x, int y);

int main()
{
    int x = 0, y = 0;

    system("clear");

    while (1)
    {
        draw_book(x, y);

        printf("Enter 'n' to turn the page, 'q' to quit: ");
        char input;
        scanf("%c", &input);

        if (input == 'n')
        {
            x++;
        }
        else if (input == 'q')
        {
            exit(0);
        }
    }

    return 0;
}

void draw_book(int x, int y)
{
    system("clear");

    // Draw the book cover
    printf("           /\n");
    printf("          |||||\n");
    printf("           \__) |\n");

    // Draw the pages
    for (int i = 0; i < x; i++)
    {
        printf("-----------------------\n");
        printf("Page %d\n", i + 1);
        printf("-----------------------\n\n");
    }

    // Draw the cursor
    printf("           /\n");
    printf("          ||||| %c |\n", y);
    printf("           \__) |\n");

    // Draw the page number
    printf("Page %d", x);
}