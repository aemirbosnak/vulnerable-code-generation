//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, health = 100, is_alive = 1;
    char name[20];

    // Introduction
    printf("Welcome to the feuding families of Montague and Capulet.\n");
    printf("You are %s, a young member of the Montague family.\n", name);

    // Main Loop
    while (is_alive)
    {
        // Present options
        printf("What would you like to do?\n");
        printf("1. Fight\n");
        printf("2. Negotiate\n");
        printf("3. Retreat\n");

        // Get user input
        scanf("%d", &choice);

        // Process user input
        switch (choice)
        {
            case 1:
                // Fight
                printf("You engage in a fierce battle with a Capulet warrior.\n");
                health -= 20;
                break;
            case 2:
                // Negotiate
                printf("You attempt to mediate between your family and the Capulets.\n");
                health += 10;
                break;
            case 3:
                // Retreat
                printf("You decide to flee the conflict.\n");
                is_alive = 0;
                break;
            default:
                printf("Invalid input.\n");
                break;
        }

        // Check if player is still alive
        if (health <= 0)
        {
            printf("You have succumbed to your injuries.\n");
            is_alive = 0;
        }

        // Print current health
        printf("Your health: %d\n", health);
    }

    return 0;
}