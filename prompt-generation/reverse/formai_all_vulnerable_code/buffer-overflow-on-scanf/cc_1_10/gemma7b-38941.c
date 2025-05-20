//Gemma-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the ASCII Art Generator!\n");
    printf("Please enter the name of your ASCII artwork: ");
    char name[20];
    scanf("%s", name);

    printf("Please enter the number of rows you want in your artwork: ");
    int rows;
    scanf("%d", &rows);

    printf("Please enter the number of columns you want in your artwork: ");
    int cols;
    scanf("%d", &cols);

    int **arr = NULL;
    arr = (int **)malloc(rows * sizeof(int *) + rows);
    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int) + cols);
    }

    printf("Please enter the ASCII characters you want to use: ");
    char ch;
    scanf("%c", &ch);

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            arr[r][c] = ch;
        }
    }

    printf("\nYour ASCII artwork: \n");
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            printf("%c ", arr[r][c]);
        }
        printf("\n");
    }

    free(arr);

    return 0;
}