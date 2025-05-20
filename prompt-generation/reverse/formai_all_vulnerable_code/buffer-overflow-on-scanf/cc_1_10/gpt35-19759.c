//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Setting up seed for random number generator
    srand(time(NULL));
    
    // Initializing variables
    int health = 100;
    int scare = 0;
    int room = 1;
    char choice;
    
    // Introduction
    printf("Welcome to the Haunted House simulator\n");
    printf("You have woken up in a dark and spooky mansion\n");
    printf("Your goal is to escape from the haunted house\n");
    printf("You have 100 health points, but beware, the house is full of scares\n");
    printf("Good luck!\n\n");
    
    // Game loop
    while(health > 0 && room != 6)
    {
        // Display info and options
        printf("You are in room %d\n", room);
        printf("Health: %d\n", health);
        printf("Scare level: %d\n\n", scare);
        printf("Choose your action:\n");
        printf("a) Move to the next room\n");
        printf("b) Search the room for clues\n");
        printf("c) Rest for a while to regain health\n");
        printf("Your choice: ");
        scanf(" %c", &choice);
        
        // Process input
        switch(choice)
        {
            case 'a':
                // Move to next room
                room++;
                break;
                
            case 'b':
                // Search the room
                printf("You search the room and find nothing useful\n");
                break;
                
            case 'c':
                // Rest to regain some health
                printf("You rest for a while and regain 10 health points\n");
                health += 10;
                break;
                
            default:
                printf("Invalid choice. Try again\n");
                break;
        }
        
        // Random scare event
        if(rand() % 3 == 0)
        {
            int scareAmount = rand() % 30 + 10;
            scare += scareAmount;
            health -= scareAmount;
            printf("You have been scared by a ghost! Your scare level increases by %d and you lose %d health points\n", scareAmount, scareAmount);
        }
    }
    
    // Game over message
    if(health <= 0)
    {
        printf("You were too scared and your health reached 0. You have failed to escape from the haunted house\n");
    }
    else
    {
        printf("Congratulations! You have escaped from the haunted house with %d health and a scare level of %d\n", health, scare);
    }
    
    return 0;
}