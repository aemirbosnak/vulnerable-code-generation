//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_cards = 0;
    char answer = 'n';
    int fate_number = 0;
    char oracle_message[200];

    printf("Welcome to the Enchanted Oracle of Zolander!\n");
    printf("Would you like to seek wisdom today? (Y/N): ");
    scanf("%c", &answer);

    if (answer == 'Y')
    {
        printf("Please draw a number of cards (1-5): ");
        scanf("%d", &num_cards);

        fate_number = rand() % 10 + 1;

        switch (num_cards)
        {
            case 1:
                sprintf(oracle_message, "Your fate is sealed. The number is %d.", fate_number);
                break;
            case 2:
                sprintf(oracle_message, "Two cards have been drawn. The number is %d and %d.", fate_number, fate_number - 1);
                break;
            case 3:
                sprintf(oracle_message, "Three cards have been drawn. The number is %d, %d and %d.", fate_number, fate_number - 1, fate_number - 2);
                break;
            case 4:
                sprintf(oracle_message, "Four cards have been drawn. The number is %d, %d, %d and %d.", fate_number, fate_number - 1, fate_number - 2, fate_number - 3);
                break;
            case 5:
                sprintf(oracle_message, "Five cards have been drawn. The number is %d, %d, %d, %d and %d.", fate_number, fate_number - 1, fate_number - 2, fate_number - 3, fate_number - 4);
                break;
            default:
                sprintf(oracle_message, "Invalid number of cards. Please try again.");
                break;
        }

        printf("%s\n", oracle_message);
    }
    else
    {
        printf("Thank you for visiting the Enchanted Oracle of Zolander. Come again soon!\n");
    }

    return 0;
}