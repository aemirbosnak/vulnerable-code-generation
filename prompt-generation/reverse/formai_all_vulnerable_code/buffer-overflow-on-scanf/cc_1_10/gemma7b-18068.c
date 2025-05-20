//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int roll_num, side_num, result;
    char symbol;

    // Setting the scene
    printf("You are in a smoky tavern, the air thick with the scent of ale and desperation.\n");
    printf("A lone die sits on the table, illuminated by a single candle.\n");

    // Asking for the number of rolls
    printf("How many times do you want to roll the die? ");
    scanf("%d", &roll_num);

    // Looping through the rolls
    for (int i = 0; i < roll_num; i++)
    {
        // Rolling the die
        side_num = rand() % 6 + 1;

        // Getting the symbol for the side
        switch (side_num)
        {
            case 1:
                symbol = 'D';
                break;
            case 2:
                symbol = 'T';
                break;
            case 3:
                symbol = 'C';
                break;
            case 4:
                symbol = 'R';
                break;
            case 5:
                symbol = 'A';
                break;
            case 6:
                symbol = 'S';
                break;
        }

        // Displaying the result
        printf("The die landed on the %c side.\n", symbol);

        // Calculating the result
        result = side_num + 2;

        // Displaying the result
        printf("Your result is: %d\n", result);
    }

    // Ending the scene
    printf("You have finished rolling the die. The tavern fades into darkness.\n");
}