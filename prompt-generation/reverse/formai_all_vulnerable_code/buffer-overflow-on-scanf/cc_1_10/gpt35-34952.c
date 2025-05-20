//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20];
    int choice;
    
    srand(time(0)); // Initializes random seed
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("What is your name?\n");
    fgets(name, 20, stdin); // Reads user's input for their name
    
    printf("Nice to meet you, %s", name);
    printf("You are standing outside a mysterious, old mansion. Do you want to enter? (Enter 1 for yes, 2 for no)\n");
    scanf("%d", &choice); // Reads user's choice to enter or not
    
    if (choice == 2) // If user chooses not to enter, the program terminates 
    {
        printf("Goodbye, %s. Maybe next time!\n", name);
        return 0;
    }
    
    int ghost = rand() % 100; // Generates a random number from 0 to 99
    
    printf("You enter the mansion and start to explore...\n");
    printf("As you walk through the hallway, you suddenly hear a strange noise coming from behind a door. Do you want to investigate? (Enter 1 for yes, 2 for no)\n");
    scanf("%d", &choice); // Reads user's choice to investigate or not
    
    if (choice == 2) // If user chooses not to investigate, the program continues
    {
        printf("You decide to keep exploring the mansion...\n");
    }
    else // If user chooses to investigate, there's a chance of encountering a ghost
    {
        printf("You open the door and see...\n");
        
        if (ghost < 30) // There's a 30% chance of encountering a ghost
        {
            printf("A ghost! You flee the room in terror!\n");
            printf("You hear the ghost's manic laughter echoing through the hallway...\n");
            printf("Game Over, %s. Better luck next time!\n", name);
            return 0;
        }
        else // If there's no ghost, the user can continue exploring
        {
            printf("Nothing. Phew! You continue exploring...\n");
        }
    }
    
    printf("As you walk down the staircase, you notice a faint light emanating from the basement. Do you want to investigate? (Enter 1 for yes, 2 for no)\n");
    scanf("%d", &choice); // Reads user's choice to investigate or not
    
    if (choice == 2) // If user chooses not to investigate, the program continues
    {
        printf("You decide to keep exploring the mansion...\n");
    }
    else // If user chooses to investigate, there's a chance of encountering a ghost
    {
        printf("You make your way to the basement and see...\n");
        
        if (ghost < 50) // There's a 50% chance of encountering a ghost
        {
            printf("A ghost! You flee the basement in terror!\n");
            printf("You hear the ghost's manic laughter echoing through the mansion...\n");
            printf("Game Over, %s. Better luck next time!\n", name);
            return 0;
        }
        else // If there's no ghost, the user can continue exploring
        {
            printf("A treasure chest! You open it and find a valuable treasure!\n");
            printf("Congratulations, %s! You have found the treasure and completed the Haunted House Simulator!\n", name);
        }
    }
    
    return 0;
}