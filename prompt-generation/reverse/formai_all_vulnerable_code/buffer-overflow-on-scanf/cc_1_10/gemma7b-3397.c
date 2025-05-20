//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **ascii_art = NULL;
    int rows, columns, i, j;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    ascii_art = (char **)malloc(rows * columns * sizeof(char *));

    for(i = 0; i < rows; i++)
    {
        ascii_art[i] = (char *)malloc(columns * sizeof(char));
    }

    printf("Enter the ASCII art: ");

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            ascii_art[i][j] = getchar();
        }
    }

    printf("\nYour ASCII art: \n");

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < columns; j++)
        {
            printf("%c ", ascii_art[i][j]);
        }

        printf("\n");
    }

    for(i = 0; i < rows; i++)
    {
        free(ascii_art[i]);
    }

    free(ascii_art);

    return 0;
}