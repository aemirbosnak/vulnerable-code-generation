//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

void draw_dice(int face)
{
    switch(face)
    {
        case 1:
            printf(" \n"
                   "|\n"
                   "|\n"
                   "| \n"
                   " \n");
            break;
        case 2:
            printf(" \n"
                   "|/ \n"
                   "|\n"
                   "| \n"
                   " \n");
            break;
        case 3:
            printf(" \n"
                   "| \__| \n"
                   "|\n"
                   "| \n"
                   " \n");
            break;
        case 4:
            printf(" \n"
                   "|__ \n"
                   "|\n"
                   "|__| \n"
                   " \n");
            break;
        case 5:
            printf(" \n"
                   "|__/ \n"
                   "|\n"
                   "|__| \n"
                   " \n");
            break;
        case 6:
            printf(" \n"
                   "|__/ \n"
                   "|\n"
                   "|__| \n"
                   "| \n");
            break;
    }
}

int main()
{
    int roll_number;
    printf("Enter the number of rolls: ");
    scanf("%d", &roll_number);

    for(int i = 0; i < roll_number; i++)
    {
        roll_number = rand() % 6 + 1;
        draw_dice(roll_number);
        printf("The number rolled is: %d\n", roll_number);
    }

    return 0;
}