//Gemma-7B DATASET v1.0 Category: Firewall ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char **firewall = NULL;
    int rows = 0, columns = 0;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    firewall = (char **)malloc(rows * columns * sizeof(char *));

    for (int r = 0; r < rows; r++)
    {
        firewall[r] = (char *)malloc(columns * sizeof(char));
    }

    // Build the firewall
    printf("Enter the firewall rules (one per line):\n");
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            scanf(" %c ", &firewall[r][c]);
        }
    }

    // Check if the firewall is valid
    if (validateFirewall(firewall, rows, columns))
    {
        // Print the firewall
        printf("Your firewall is valid:\n");
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < columns; c++)
            {
                printf("%c ", firewall[r][c]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Your firewall is invalid.\n");
    }

    // Free the firewall
    for (int r = 0; r < rows; r++)
    {
        free(firewall[r]);
    }
    free(firewall);

    return 0;
}

int validateFirewall(char **firewall, int rows, int columns)
{
    // Check if the firewall is symmetrical
    if (!isSymmetrical(firewall, rows, columns))
    {
        return 0;
    }

    // Check if the firewall has any holes
    if (!hasNoHoles(firewall, rows, columns))
    {
        return 0;
    }

    // Check if the firewall is valid
    return 1;
}

int isSymmetrical(char **firewall, int rows, int columns)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            if (firewall[r][c] != firewall[r][columns - 1 - c])
            {
                return 0;
            }
        }
    }

    return 1;
}

int hasNoHoles(char **firewall, int rows, int columns)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            if (firewall[r][c] == 'H')
            {
                return 0;
            }
        }
    }

    return 1;
}