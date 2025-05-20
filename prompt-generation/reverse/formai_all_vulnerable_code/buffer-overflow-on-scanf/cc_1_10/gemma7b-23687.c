//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    printf("Welcome to the Galactic Battleground!\n");

    // Player's ship name
    char shipName[20];
    printf("Please enter the name of your ship: ");
    scanf("%s", shipName);

    // Create a random enemy ship name
    char enemyShipName[20];
    enemyShipName[0] = 'E';
    enemyShipName[1] = 'S';
    enemyShipName[2] = 'C';
    enemyShipName[3] = 'H';
    enemyShipName[4] = '\0';

    // Game loop
    int turn = 0;
    while (1)
    {
        // Display game information
        printf("Turn: %d\n", turn);
        printf("Your ship: %s\n", shipName);
        printf("Enemy ship: %s\n", enemyShipName);

        // Player's move
        int move = 0;
        printf("Enter your move (1-5): ");
        scanf("%d", &move);

        // Check if the move is valid
        if (move < 1 || move > 5)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Simulate battle damage
        int damage = rand() % 5;
        printf("You inflicted %d damage on the enemy ship.\n", damage);

        // Check if the enemy ship is destroyed
        if (damage >= 3)
        {
            printf("Congratulations! You have destroyed the enemy ship!\n");
            break;
        }

        // Enemy's turn
        move = rand() % 5;
        damage = rand() % 5;
        printf("The enemy has inflicted %d damage on your ship.\n", damage);

        // Check if the player's ship is destroyed
        if (damage >= 3)
        {
            printf("Game over. You have been destroyed.\n");
            break;
        }

        // Increment the turn counter
        turn++;
    }

    return 0;
}