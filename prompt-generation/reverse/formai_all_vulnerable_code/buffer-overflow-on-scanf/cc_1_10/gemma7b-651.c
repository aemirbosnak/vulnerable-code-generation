//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int roll_num, sides, current_roll, total_roll = 0, result = 0;
    char symbol;

    printf("Welcome to the ultimate dice roller!\n");
    printf("Please choose the number of sides you want on the dice: ");
    scanf("%d", &sides);

    printf("How many times do you want to roll the dice? ");
    scanf("%d", &roll_num);

    for (int i = 0; i < roll_num; i++)
    {
        current_roll = rand() % sides + 1;
        total_roll += current_roll;
        result = current_roll;

        switch (current_roll)
        {
            case 1:
                symbol = 'A';
                break;
            case 2:
                symbol = 'B';
                break;
            case 3:
                symbol = 'C';
                break;
            case 4:
                symbol = 'D';
                break;
            case 5:
                symbol = 'E';
                break;
            case 6:
                symbol = 'F';
                break;
        }

        printf("Roll: %c, Result: %d\n", symbol, result);
    }

    printf("Total Roll: %d\n", total_roll);
    printf("Thank you for playing the ultimate dice roller!\n");

    return 0;
}