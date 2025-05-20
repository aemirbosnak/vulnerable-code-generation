//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int choice;
    int health = 100;
    int wealth = 100;
    int love = 50;
    int status = 1;

    printf("Welcome to the world of Romeo and Juliet!\n");
    printf("You are a young nobleman in Verona, seeking love and fortune.\n");
    printf("Your goal is to win the heart of Juliet and become the richest man in town.\n");
    printf("But beware, danger lurks around every corner!\n");
    printf("Are you ready to begin your adventure? (y/n)");
    scanf("%c", &choice);

    if (choice == 'n')
    {
        printf("Goodbye!\n");
        return 0;
    }

    while (status == 1)
    {
        printf("\n");
        printf("You wake up in your bedchamber. What do you want to do?\n");
        printf("1. Go to the market\n");
        printf("2. Visit the Capulet mansion\n");
        printf("3. Attend a party\n");
        printf("4. Go to church\n");
        printf("5. Take a walk in the park\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("You go to the market and buy some goods.\n");
                printf("You spend %d gold coins.\n", 10);
                wealth -= 10;
                break;
            case 2:
                printf("You visit the Capulet mansion and see Juliet.\n");
                printf("She smiles at you and your heart skips a beat.\n");
                love += 10;
                break;
            case 3:
                printf("You attend a party and have a great time.\n");
                printf("You meet new people and make some friends.\n");
                love += 5;
                wealth += 5;
                break;
            case 4:
                printf("You go to church and pray for good fortune.\n");
                printf("Your prayers are answered and you feel blessed.\n");
                health += 10;
                break;
            case 5:
                printf("You take a walk in the park and enjoy the scenery.\n");
                printf("You feel refreshed and energized.\n");
                health += 5;
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

        if (health <= 0 || wealth <= 0 || love <= 0)
        {
            printf("\n");
            printf("Game Over!\n");
            printf("You have lost your health, wealth, and love.\n");
            printf("Thanks for playing!\n");
            status = 0;
        }
    }

    return 0;
}