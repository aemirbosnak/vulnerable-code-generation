//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int playerHealth = 100; // starting health
    int monsterHealth = 100; // starting health
    int random;

    printf("Welcome to the Haunted House Simulator!\n\n");

    while(playerHealth > 0 && monsterHealth > 0) // game loop
    {
        printf("Your current health: %d\n", playerHealth);
        printf("Monster's current health: %d\n\n", monsterHealth);

        printf("Press 1 to attack the monster.\n");
        printf("Press 2 to heal yourself.\n");
        printf("Enter your choice (1 or 2): ");
        int choice;
        scanf("%d", &choice);
        printf("\n");

        if(choice == 1) // attack
        {
            random = rand() % 10 + 1; // random number between 1 - 10
            monsterHealth -= random;
            printf("You attacked the monster and dealt %d damage.\n", random);

            if(monsterHealth <= 0) // monster dead
            {
                printf("You have defeated the monster!\n");
            }
            else // monster still alive
            {
                random = rand() % 10 + 1; // monster attacks
                playerHealth -= random;
                printf("The monster counter-attacked and dealt %d damage.\n", random);
            }
        }
        else if(choice == 2) // heal
        {
            random = rand() % 20 + 1; // random number between 1 - 20
            playerHealth += random;
            printf("You have healed yourself by %d points.\n", random);

            random = rand() % 10 + 1; // monster attacks
            playerHealth -= random;
            printf("The monster attacked you and dealt %d damage.\n", random);
        }
        else // invalid input
        {
            printf("Invalid input. Please try again.\n\n");
        }
    }

    if(playerHealth <= 0) // player dead
    {
        printf("You have been defeated by the monster. Game Over!\n");
    }

    return 0;
}