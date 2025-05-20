//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Game Variables
    int health = 100;
    int strength = 50;
    char current_room = 'A';

    // Game Loop
    while (health > 0)
    {
        // Display current room and status
        printf("You are in room %c.\n", current_room);
        printf("Health: %d, Strength: %d\n", health, strength);

        // Get user input
        char input;
        printf("Enter your command: ");
        scanf("%c", &input);

        // Process user input
        switch (input)
        {
            case 'f':
                // Fight
                strength += 10;
                printf("You fought a monster and gained strength.\n");
                break;
            case 'h':
                // Heal
                health += 20;
                printf("You healed your wounds.\n");
                break;
            case 'm':
                // Move
                current_room++;
                printf("You moved to the next room.\n");
                break;
            default:
                // Invalid input
                printf("Invalid input.\n");
                break;
        }

        // Check if the game is over
        if (health <= 0)
        {
            printf("Game over.\n");
        }
    }

    return 0;
}