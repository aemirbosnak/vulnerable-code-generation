//Gemma-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, lucky_num, i, fate_score, answer, yes_no;
    char name[20];
    printf("Welcome to the Crystal Ball, %s!\n", name);
    printf("Please choose a number between 1 and 10: ");
    scanf("%d", &lucky_num);
    printf("You have chosen number %d. Now, let's see what the stars have in store for you...\n", lucky_num);

    // Predicting the future using oracle crystals
    for (i = 0; i < 3; i++)
    {
        fate_score = rand() % 10;
        switch (fate_score)
        {
            case 0:
                printf("The stars align in your favor, bringing prosperity and love.\n");
                break;
            case 1:
                printf("A hidden treasure awaits you, but beware of treacherous paths.\n");
                break;
            case 2:
                printf("A new relationship blooms, but be cautious of hidden agendas.\n");
                break;
            case 3:
                printf("An opportunity for growth and learning looms, but don't be afraid to take risks.\n");
                break;
            case 4:
                printf("Beware of gossip and manipulation, they can lead you astray.\n");
                break;
            case 5:
                printf("A journey awaits you, filled with adventure and mystery.\n");
                break;
            case 6:
                printf("Your creativity blossoms, bring new ideas and express yourself freely.\n");
                break;
            case 7:
                printf("A hidden talent emerges, discover your hidden abilities.\n");
                break;
            case 8:
                printf("Love and happiness find you, cherish these precious gifts.\n");
                break;
            case 9:
                printf("Strength and resilience guide you through challenges, you will overcome.\n");
                break;
            case 10:
                printf("The stars dance in your favor, bring joy and prosperity.\n");
                break;
        }
    }

    // Asking for confirmation
    printf("Do you want to hear your future more? (Y/N): ");
    scanf("%c", &yes_no);

    if (yes_no == 'Y')
    {
        // Repeating the oracle's predictions
        for (i = 0; i < 3; i++)
        {
            fate_score = rand() % 10;
            switch (fate_score)
            {
                case 0:
                    printf("The stars align in your favor, bringing prosperity and love.\n");
                    break;
                case 1:
                    printf("A hidden treasure awaits you, but beware of treacherous paths.\n");
                    break;
                case 2:
                    printf("A new relationship blooms, but be cautious of hidden agendas.\n");
                    break;
                case 3:
                    printf("An opportunity for growth and learning looms, but don't be afraid to take risks.\n");
                    break;
                case 4:
                    printf("Beware of gossip and manipulation, they can lead you astray.\n");
                    break;
                case 5:
                    printf("A journey awaits you, filled with adventure and mystery.\n");
                    break;
                case 6:
                    printf("Your creativity blossoms, bring new ideas and express yourself freely.\n");
                    break;
                case 7:
                    printf("A hidden talent emerges, discover your hidden abilities.\n");
                    break;
                case 8:
                    printf("Love and happiness find you, cherish these precious gifts.\n");
                    break;
                case 9:
                    printf("Strength and resilience guide you through challenges, you will overcome.\n");
                    break;
                case 10:
                    printf("The stars dance in your favor, bring joy and prosperity.\n");
                    break;
            }
        }
    }

    // Closing the crystal ball
    printf("Thank you for visiting the Crystal Ball, %s. May your future be bright.\n", name);

    return 0;
}