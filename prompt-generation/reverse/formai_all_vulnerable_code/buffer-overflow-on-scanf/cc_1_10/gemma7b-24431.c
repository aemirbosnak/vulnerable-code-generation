//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: funny
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int roll_result;
    int number_of_rolls = 0;
    char symbol;

    printf("Welcome to the craziest dice roller ever!\n");
    printf("Please choose a symbol to represent your character: ");
    scanf("%c", &symbol);

    while (1)
    {
        roll_result = rand() % 6 + 1;
        number_of_rolls++;

        switch (roll_result)
        {
            case 1:
                printf("%c landed on 1! What a loser!\n", symbol);
                break;
            case 2:
                printf("%c landed on 2! You're a bit better than a loser.\n", symbol);
                break;
            case 3:
                printf("%c landed on 3! You're almost winning!\n", symbol);
                break;
            case 4:
                printf("%c landed on 4! You're close to winning!\n", symbol);
                break;
            case 5:
                printf("%c landed on 5! You're a winner! Prepare for glory!\n", symbol);
                break;
            case 6:
                printf("%c landed on 6! You're a champion! Go celebrate!\n", symbol);
                break;
        }

        printf("Do you want to roll again? (Y/N): ");
        scanf("%c", &symbol);

        if (symbol == 'N')
        {
            break;
        }
    }

    printf("Thanks for playing, %c! You rolled a total of %d times.\n", symbol, number_of_rolls);

    return 0;
}