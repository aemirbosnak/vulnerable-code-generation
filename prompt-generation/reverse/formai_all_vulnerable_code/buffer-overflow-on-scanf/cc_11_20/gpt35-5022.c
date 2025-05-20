//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice, chance;
    srand(time(0)); // initialize the random seed
    printf("\nWelcome to the Haunted House Simulator!\n");
    
    do
    {
        printf("\nYou are standing in front of a big haunted house.");
        printf("\n1. Enter the house\n2. Run away\nEnter your choice (1/2): ");
        scanf("%d", &choice);
    } while(choice != 1 && choice != 2); // validate user input
    
    if(choice == 2)
    {
        printf("\nAs you turn around to run away, the door of the house opens on its own and you are pulled inside...");
    }
    
    printf("\nYou are now inside the house.");
    printf("\nYou have 5 chances to escape. Good Luck!");
    
    for(chance = 1; chance <= 5; chance++)
    {
        int random_number = rand() % 10 + 1; // generate a random number between 1 and 10
                
        printf("\n\nChance #%d", chance);
        printf("\nYou are standing in front of 3 doors - Red, Blue, and Green.");
        printf("\nEnter your choice (1/2/3): ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nYou open the Red door...");
                if(random_number < 4)
                {
                    printf("\nA ghost appears from behind the door and scares you to death. GAME OVER!");
                    return 0;
                }
                else
                {
                    printf("\nPhew! You are safe for now...");
                }
                break;
                
            case 2:
                printf("\nYou open the Blue door...");
                if(random_number < 5)
                {
                    printf("\nA monster jumps out from the door and eats you alive. GAME OVER!");
                    return 0;
                }
                else
                {
                    printf("\nYou dodge a close call and breathe a sigh of relief.");
                }
                break;
                
            case 3:
                printf("\nYou open the Green door...");
                if(random_number < 3)
                {
                    printf("\nA witch casts a spell and turns you into a frog. GAME OVER!");
                    return 0;
                }
                else
                {
                    printf("\nYou have made it to the next level...");
                }
                break;
                
            default:
                printf("\nInvalid choice! Please try again...");
                chance--;
                break;
        }
    }
    
    printf("\nCongratulations! You have made it out of the Haunted House...");
    return 0;
}