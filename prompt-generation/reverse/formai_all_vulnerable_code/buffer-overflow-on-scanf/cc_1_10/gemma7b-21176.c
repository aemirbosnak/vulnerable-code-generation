//Gemma-7B DATASET v1.0 Category: Matrix operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char matrix[10][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                              {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
                              {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                              {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                              {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                              {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                              {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                              {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                              {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                              {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    int row = 10;
    int col = 10;

    char key = 'a';

    while (key != 'q')
    {
        printf("Please enter a key: ");
        scanf("%c", &key);

        switch (key)
        {
            case 'w':
                printf("You have pressed W.\n");
                break;
            case 'a':
                printf("You have pressed A.\n");
                break;
            case 's':
                printf("You have pressed S.\n");
                break;
            case 'd':
                printf("You have pressed D.\n");
                break;
            default:
                printf("Invalid key.\n");
                break;
        }

        system("clear");

        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                printf("%c ", matrix[r][c]);
            }
            printf("\n");
        }
    }

    return 0;
}