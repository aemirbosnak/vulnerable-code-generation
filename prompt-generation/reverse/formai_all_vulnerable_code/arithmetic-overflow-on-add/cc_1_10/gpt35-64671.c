//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int milliseconds);

int main()
{
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Define the variables for the game
    int health = 100;
    int num_rooms = 10;
    int curr_room = 1;
    int ghost_room = rand() % num_rooms + 1;
    
    // Display the introduction
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have %d health points.\n", health);
    printf("There are %d rooms in the house.\n", num_rooms);
    printf("You must find and defeat the ghost hiding in one of the rooms.\n\n");
    
    // Start the game loop
    while (health > 0 && curr_room <= num_rooms)
    {
        // Display the current status
        printf("You are in room %d.\n", curr_room);
        if (curr_room == ghost_room)
        {
            printf("A spooky ghost appears in front of you!\n");
            printf("You must defeat the ghost to win the game.\n\n");
            delay(3000);
            
            // Fight the ghost
            int ghost_health = 50;
            while (ghost_health > 0 && health > 0)
            {
                int damage = rand() % 10 + 1;
                printf("You attack the ghost for %d damage.\n", damage);
                ghost_health -= damage;
                
                if (ghost_health <= 0)
                {
                    printf("Congratulations! You have defeated the ghost and won the game!\n");
                    printf("Your final health is %d.\n", health);
                    return 0;
                }
                
                damage = rand() % 10 + 1;
                printf("The ghost attacks you for %d damage.\n", damage);
                health -= damage;
                
                if (health <= 0)
                {
                    printf("You have lost the game!\n");
                    return 0;
                }
            }
        }
        else
        {
            printf("This room is empty. You move on to the next one.\n\n");
            delay(1000);
        }
        
        curr_room++;
    }
    
    // If we get here, the player has reached the end of the house
    printf("You have searched all %d rooms in the house but did not find the ghost.\n", num_rooms);
    printf("Your final health is %d.\n", health);
    
    return 0;
}

// A simple delay function
void delay(int milliseconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}