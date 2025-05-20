//FormAI DATASET v1.0 Category: Pattern printing ; Style: grateful
#include<stdio.h>

int main()
{
    // Grateful message
    printf("Thank you for using this program!\n\n");

    int rows, i, j, space;

    printf("How many rows do you want to print for the C pattern?\n");
    scanf("%d", &rows);

    printf("\n");

    // Loop for upper half of C
    for(i=1;i<=rows/2;i++)
    {
        printf("*");

        for(j=1;j<(rows/2);j++)
            printf(" ");

        printf("*\n");
    }

    // Loop for middle line of C
    if(rows%2 == 0)
    {
        for(i=1;i<=(rows/2)+1;i++)
            printf("*");

        printf("\n");
    }
    else
    {
        for(i=1;i<=(rows/2)+2;i++)
            printf("*");

        printf("\n");
    }

    // Loop for lower half of C
    for(i=1;i<=rows/2;i++)
    {
        for(space=1;space<i+1;space++)
            printf(" ");

        printf("*");

        for(j=1;j<(rows/2);j++)
            printf(" ");

        printf("*\n");
    }

    // Grateful message
    printf("\n\nThank you for using this program! Have a great day.\n");

    return 0;
}