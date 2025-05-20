//Falcon2-11B DATASET v1.0 Category: Pattern printing ; Style: safe
#include <stdio.h>

int main()
{
    int rows, cols;

    // Get input from user
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Calculate the number of spaces and asterisks
    int spaces = rows - 1;
    int asterisks = cols - 1;

    // Print the top row
    printf(" ");
    for (int i = 0; i < spaces; i++)
        printf(" ");
    for (int i = 0; i < asterisks; i++)
        printf("*");
    printf("\n");

    // Print the rest of the rows
    for (int i = 1; i <= rows; i++)
    {
        // Calculate the number of spaces and asterisks
        int spaces = rows - i;
        int asterisks = cols - i;

        // Print the left side of the row
        printf(" ");
        for (int j = 0; j < spaces; j++)
            printf(" ");
        for (int j = 0; j < asterisks; j++)
            printf("*");

        // Print the middle of the row
        printf(" ");
        for (int j = 0; j < asterisks; j++)
            printf(" ");
        for (int j = 0; j < asterisks; j++)
            printf("*");
        printf(" ");

        // Print the right side of the row
        printf(" ");
        for (int j = 0; j < spaces; j++)
            printf(" ");
        for (int j = 0; j < asterisks; j++)
            printf("*");

        printf("\n");
    }

    return 0;
}