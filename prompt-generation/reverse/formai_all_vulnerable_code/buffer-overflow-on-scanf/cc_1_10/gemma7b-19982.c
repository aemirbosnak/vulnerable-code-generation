//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int roll_again = 1;
    int roll_number = 0;
    int result = 0;
    char character_rolled = 'a';

    printf("Welcome to the Enchanted Forest of Dice Rolling!\n");

    while (roll_again)
    {
        roll_number = rand() % 6 + 1;
        result = roll_number + character_rolled - 'a';

        switch (result)
        {
            case 2:
                character_rolled = 'b';
                printf("You rolled a 2, the mischievous elf has stolen your shoe!\n");
                break;
            case 3:
                character_rolled = 'c';
                printf("You rolled a 3, the grumpy dwarf has challenged you to a duel.\n");
                break;
            case 4:
                character_rolled = 'd';
                printf("You rolled a 4, the mischievous dwarf has hidden your socks.\n");
                break;
            case 5:
                character_rolled = 'e';
                printf("You rolled a 5, the evil dragon has breathed fire on your house.\n");
                break;
            case 6:
                character_rolled = 'f';
                printf("You rolled a 6, the wise wizard has granted you a wish.\n");
                break;
            default:
                printf("Something unexpected happened, please try again.\n");
                break;
        }

        printf("Would you like to roll again? (y/n): ");
        scanf("%c", &roll_again);
    }

    return 0;
}