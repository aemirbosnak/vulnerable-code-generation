//FormAI DATASET v1.0 Category: Pattern printing ; Style: curious
#include <stdio.h>

int main() 
{
    printf("Ready to print a unique C Pattern? Let's get curious!\n\n");

    int num_rows, num_cols, i, j;
    char letter = 'C';

    printf("How many rows do you want in your C pattern? ");
    scanf("%d", &num_rows);
    printf("How many columns do you want in your C pattern? ");
    scanf("%d", &num_cols);

    // Printing the top of C
    printf("\n");
    for (i = 1; i <= num_rows; i++) 
    {
        printf("%c", letter);
        for (j = 1; j <= (num_cols-2); j++) 
        {
            if (i == 1 || i == num_rows) 
            {
                printf("%c", letter);
            } 
            else 
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Printing the middle and the bottom of C
    for (i = 1; i <= (num_rows-2); i++) 
    {
        for (j = 1; j <= num_cols; j++) 
        {
            if (j == 1) 
            {
                printf("%c", letter);
            } 
            else 
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Printing the bottom of C
    for (i = 1; i <= num_rows; i++) 
    {
        printf("%c", letter);
        for (j =1; j <= (num_cols-2); j++) 
        {
            if (i == 1 || i == num_rows) 
            {
                printf("%c", letter);
            } 
            else 
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\nYour unique C Pattern has been printed successfully. Curious, right?!");

    return 0;
}