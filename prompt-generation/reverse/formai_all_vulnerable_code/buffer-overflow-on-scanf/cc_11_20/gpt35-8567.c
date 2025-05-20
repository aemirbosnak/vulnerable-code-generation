//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[30];
    int choice;
    int ghosts_found = 0;
    int turns = 20;
    
    // Set random seed to current time
    srand(time(0));
    
    // Ask for name of player
    printf("Welcome to the Haunted House Simulator Game!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    
    // Explain game rules
    printf("Hello %s, you have been dared to spend a night in this haunted house.\n", name);
    printf("Your objective is to find all the ghosts in the house within 20 turns.\n");
    printf("You can move from room to room and if you encounter a ghost, you'll have to fight it!\n");

    // Initialize starting position and ghosts
    int current_room = 1 + rand() % 10;
    int ghost1 = 1 + rand() % 10;
    int ghost2 = 1 + rand() % 10;
    int ghost3 = 1 + rand() % 10;

    // Game loop
    while(turns > 0 && ghosts_found < 3)
    {
        printf("You are in room %d.\n", current_room);
        printf("You have %d turns left.\n", turns);
        
        printf("Choose a direction to move:\n");
        printf("1. North\n");
        printf("2. South\n");
        printf("3. East\n");
        printf("4. West\n");
        printf("5. Stay Still\n");
        scanf("%d", &choice);

        // Move player to new room based on choice
        switch(choice)
        {
            case 1:
                current_room -= 3;
                break;
            case 2:
                current_room += 3;
                break;
            case 3:
                current_room += 1;
                break;
            case 4:
                current_room -= 1;
                break;
            case 5:
                // Do nothing
                break;
            default:
                printf("Invalid choice. Choose again.\n");
                break;
        }
        
        // Check if player has found a ghost
        if(current_room == ghost1 || current_room == ghost2 || current_room == ghost3)
        {
            printf("You have encountered a ghost!\n");
            printf("Choose how you want to fight it:\n");
            printf("1. Use a cross\n");
            printf("2. Use a mirror\n");
            scanf("%d", &choice);
            
            // Randomly determine if player defeats ghost or not
            if(choice == 1 && rand() % 2 == 0)
            {
                printf("The ghost has been defeated!\n");
                ghosts_found++;
            }
            else if(choice == 2 && rand() % 2 == 1)
            {
                printf("The ghost has been defeated!\n");
                ghosts_found++;
            }
            else
            {
                printf("The ghost has won the fight!\n");
                turns--;
            }
        }
        
        turns--;
    }
    
    // Determine if player has won or lost
    if(ghosts_found == 3)
    {
        printf("Congratulations, %s! You have found all the ghosts!\n", name);
    }
    else
    {
        printf("Sorry, %s. You did not find all the ghosts within time.\n", name);
    }
    
    return 0;
}