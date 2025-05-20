//FormAI DATASET v1.0 Category: Table Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int dice1, dice2, option, gold = 50, goblin_gold = 0, thieves_gold = 0, bandit_gold = 0;
    char name[20];
    srand(time(NULL));
    printf("Welcome to Medieval Table Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("\n\n");
    printf("Hello, %s! Your starting gold is %d.\n", name, gold);
    printf("\n\n");
    while (gold > 0)
    {
        printf("Select option:\n");
        printf("1. Roll the dice\n");
        printf("2. Visit the goblin den\n");
        printf("3. Encounter thieves\n");
        printf("4. Fight bandits\n");
        printf("5. Quit game\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        printf("\n");
        switch (option)
        {
            case 1:
            dice1 = rand() % 6 + 1;
            dice2 = rand() % 6 + 1;
            printf("You rolled the dice: %d and %d\n", dice1, dice2);
            if (dice1 + dice2 >= 7)
            {
                printf("Congratulations! You won %d gold!\n", dice1 + dice2);
                gold += dice1 + dice2;
            }
            else
            {
                printf("Sorry, you lost %d gold.\n", dice1 + dice2);
                gold -= dice1 + dice2;
            }
            printf("Your current gold is: %d\n", gold);
            break;
            case 2:
            printf("You have encountered a goblin den!\n");
            printf("The goblins demand tribute of 10 gold before you can leave.\n");
            if (gold >= 10)
            {
                printf("You give the goblins 10 gold and leave unharmed.\n");
                gold -= 10;
                goblin_gold += 10; 

            }
            else
            {
                printf("You don't have enough gold to pay the tribute!\n");
                printf("The goblins attack you and steal 5 gold.\n");
                gold -= 5;
                goblin_gold += 5;
            }
            printf("Your current gold is: %d\n", gold);
            break;
            case 3:
            printf("You have encountered a group of thieves!\n");
            printf("The thieves demand all your gold before they'll let you pass.\n");
            if (gold > 0)
            {
                printf("You give the thieves all your gold and continue unharmed.\n");
                thieves_gold += gold;
                gold = 0;

            }
            else
            {
                printf("You have nothing to give the thieves!\n");
                printf("The thieves attack you but you manage to escape.\n");
            }
            printf("Your current gold is: %d\n", gold);
            break;
            case 4:
            printf("You have encountered a group of bandits!\n");
            printf("The bandits challenge you to a fight.\n");
            if (gold >= 20)
            {
                printf("You pay the bandits 20 gold to let you pass.\n");
                gold -= 20;
                bandit_gold += 20;
            }
            else
            {
                printf("You don't have enough gold to pay the bandits!\n");
                printf("You fight the bandits with all your might but they overpower you.\n");
                printf("You lose 10 gold to the bandits.\n");
                gold -= 10;
                bandit_gold += 10;
            }
            printf("Your current gold is: %d\n", gold);
            break;
            case 5:
            printf("Thanks for playing Medieval Table Game!\n");
            printf("Your total gold is: %d\n", gold);
            printf("Your gold from goblins: %d\n", goblin_gold);
            printf("Your gold from thieves: %d\n", thieves_gold);
            printf("Your gold from bandits: %d\n", bandit_gold);
            exit(0);
            default:
            printf("Invalid option! Please try again.\n");
            break;
        }
    }
    printf("You have run out of gold!\n");
    printf("Thanks for playing Medieval Table Game!\n");
    return 0;
}