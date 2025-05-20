//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("*** Welcome to the End of the World! ***\n");
    printf("Get ready to embark on a perilous journey\n");
    
    // Initialize game variables
    int health = 100;
    int food = 3;
    int distance = 0;
    bool gameOver = false;
    
    // Set random seed
    srand(time(NULL));
    
    while(!gameOver)
    {
        // Print current status
        printf("\nCurrent Status\n--------------\n");
        printf("Health: %d\n", health);
        printf("Food: %d\n", food);
        printf("Distance: %d miles\n", distance);
        
        // Prompt user for action
        printf("\nWhat would you like to do?\n");
        printf("1. Travel 10 miles\n");
        printf("2. Rest\n");
        printf("3. Hunt for food\n");
        printf("4. Quit game\n");
        int choice;
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: // Travel
                printf("\nTravelling 10 miles...\n");
                
                // Random event occurs
                int event = rand() % 3;
                if(event == 0)
                {
                    printf("You encountered a group of bandits!\n");
                    printf("They stole 20 health from you and 1 food!\n");
                    health -= 20;
                    food--;
                    if(health <= 0)
                    {
                        printf("You died of your injuries. Game over.\n");
                        gameOver = true;
                    }
                }
                else if(event == 1)
                {
                    printf("You came across a river!\n");
                    printf("You managed to cross it safely using 1 food.\n");
                    food--;
                }
                else
                {
                    printf("The journey was uneventful.\n");
                }
                
                // Increment distance
                distance += 10;
                break;
                
            case 2: // Rest
                printf("\nResting...\n");
                
                // Random event occurs
                int restEvent = rand() % 3;
                if(restEvent == 0)
                {
                    printf("A wild animal attacked you while you were resting!\n");
                    printf("You lost 30 health!\n");
                    health -= 30;
                    if(health <= 0)
                    {
                        printf("You died of your injuries. Game over.\n");
                        gameOver = true;
                    }
                }
                else if(restEvent == 1)
                {
                    printf("You found a small village while resting!\n");
                    printf("The villagers gave you 2 food and 50 health.\n");
                    food += 2;
                    health += 50;
                }
                else
                {
                    printf("You rested peacefully.\n");
                }
                
                // Restore health
                health += 20;
                if(health > 100)
                {
                    health = 100;
                }
                break;
                
            case 3: // Hunt for food
                printf("\nHunting for food...\n");
                
                // Random event occurs
                int huntEvent = rand() % 3;
                if(huntEvent == 0)
                {
                    printf("You were attacked by a wild animal while hunting!\n");
                    printf("You lost 20 health!\n");
                    health -= 20;
                    if(health <= 0)
                    {
                        printf("You died of your injuries. Game over.\n");
                        gameOver = true;
                    }
                }
                else if(huntEvent == 1)
                {
                    printf("You managed to hunt and gather 2 food!\n");
                    food += 2;
                }
                else
                {
                    printf("You were unable to find any food.\n");
                }
                break;
                
            case 4: // Quit game
                printf("\nQuitting game...\n");
                gameOver = true;
                break;
                
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
        
        // Check win condition
        if(distance >= 100)
        {
            printf("\nCongratulations! You made it to the safe zone and survived the end of the world!\n");
            printf("Your final stats:\n");
            printf("Health: %d\n", health);
            printf("Food: %d\n", food);
            printf("Distance: %d miles\n", distance);
            gameOver = true;
        }
        
        // Check game over condition
        if(food <= 0)
        {
            printf("You ran out of food and starved to death. Game over.\n");
            gameOver = true;
        }
    }
    
    return 0;
}