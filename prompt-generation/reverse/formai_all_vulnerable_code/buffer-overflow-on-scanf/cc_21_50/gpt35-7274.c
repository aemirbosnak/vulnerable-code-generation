//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to provide a random number within a given range
int randRange(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

int main()
{
    // Declare variables for player's name and answer
    char playerName[100];
    char answer;

    // Prompt the player for their name and store the input
    printf("Welcome to the Haunted House Simulator!\n");
    printf("What is your name?\n");
    scanf("%s", playerName);

    // Display a happy message to the player
    printf("\nWelcome, %s! Get ready for a spooky adventure!\n", playerName);

    // Set the seed for the random number generator
    srand(time(NULL));

    // Declare variables for the different rooms in the haunted house
    char *room1 = "Living Room";
    char *room2 = "Kitchen";
    char *room3 = "Bedroom";
    char *room4 = "Bathroom";
    char *room5 = "Attic";
    char *room6 = "Basement";

    // Declare variables for the different items in the haunted house
    char *item1 = "Candle";
    char *item2 = "Ouija Board";
    char *item3 = "Mirror";
    char *item4 = "Spider Web";
    char *item5 = "Skull";
    char *item6 = "Potion";
    
    // Declare variables for the different ghost names
    char *ghost1 = "Casper";
    char *ghost2 = "Slimer";
    char *ghost3 = "Poltergeist";
    char *ghost4 = "Boo";
    char *ghost5 = "Phantom";
    char *ghost6 = "Specter";

    // Declare and initialize variables for gameplay
    int currentRoom = 1;
    int hasItem1 = 0;
    int hasItem2 = 0;
    int hasItem3 = 0;
    int hasItem4 = 0;
    int hasItem5 = 0;
    int hasItem6 = 0;
    int hasGhost = 0;
    
    // Start the game
    printf("You find yourself in the %s.\n", room1);
    
    do 
    {
        // Prompt the player for their answer
        printf("What would you like to do?\n");
        printf("A) Move to a new room\n");
        printf("B) Search the room for an item\n");
        printf("C) Use an item\n");
        printf("D) Quit the game\n");
        scanf(" %c", &answer);
        printf("\n");
        
        // Handle the player's answer
        switch (answer) 
        {
            case 'A': // Move to a new room
                // Generate a random number between 1 and 6 to determine the new room
                currentRoom = randRange(1, 6);
                switch (currentRoom)
                {
                    case 1:
                        printf("You are now in the %s.\n", room1);
                        break;
                    case 2:
                        printf("You are now in the %s.\n", room2);
                        break;
                    case 3:
                        printf("You are now in the %s.\n", room3);
                        break;
                    case 4:
                        printf("You are now in the %s.\n", room4);
                        break;
                    case 5:
                        printf("You are now in the %s.\n", room5);
                        break;
                    case 6:
                        printf("You are now in the %s.\n", room6);
                        break;
                    default:
                        printf("Invalid room number!\n");
                        break;
                }
                // Roll a dice to determine if a ghost is in the room
                if (randRange(1, 6) == 6)
                {
                    hasGhost = 1;
                    printf("You have encountered a ghost named %s!\n", 
                       (randRange(1, 6) == 1) ? ghost1 :
                       (randRange(1, 6) == 2) ? ghost2 :
                       (randRange(1, 6) == 3) ? ghost3 :
                       (randRange(1, 6) == 4) ? ghost4 :
                       (randRange(1, 6) == 5) ? ghost5 :
                       ghost6);
                }
                break;
            case 'B': // Search the room for an item
                switch (currentRoom)
                {
                    case 1:
                        if (hasItem1 == 0)
                        {
                            hasItem1 = 1;
                            printf("You have found a %s!\n", item1);
                        }
                        else
                        {
                            printf("You have already searched this room for an item!\n");
                        }
                        break;
                    case 2:
                        if (hasItem2 == 0)
                        {
                            hasItem2 = 1;
                            printf("You have found an %s!\n", item2);
                        }
                        else
                        {
                            printf("You have already searched this room for an item!\n");
                        }
                        break;
                    case 3:
                        if (hasItem3 == 0)
                        {
                            hasItem3 = 1;
                            printf("You have found a %s!\n", item3);
                        }
                        else
                        {
                            printf("You have already searched this room for an item!\n");
                        }
                        break;
                    case 4:
                        if (hasItem4 == 0)
                        {
                            hasItem4 = 1;
                            printf("You have found a %s!\n", item4);
                        }
                        else
                        {
                            printf("You have already searched this room for an item!\n");
                        }
                        break;
                    case 5:
                        if (hasItem5 == 0)
                        {
                            hasItem5 = 1;
                            printf("You have found a %s!\n", item5);
                        }
                        else
                        {
                            printf("You have already searched this room for an item!\n");
                        }
                        break;
                    case 6:
                        if (hasItem6 == 0)
                        {
                            hasItem6 = 1;
                            printf("You have found a %s!\n", item6);
                        }
                        else
                        {
                            printf("You have already searched this room for an item!\n");
                        }
                        break;
                    default:
                        printf("Invalid room number!\n");
                        break;
                }
                break;
            case 'C': // Use an item
                if (hasGhost == 0)
                {
                    printf("There is no ghost in this room!\n");
                }
                else
                {
                    printf("Which item would you like to use?\n");
                    printf("1) %s\n", item1);
                    printf("2) %s\n", item2);
                    printf("3) %s\n", item3);
                    printf("4) %s\n", item4);
                    printf("5) %s\n", item5);
                    printf("6) %s\n", item6);
                    int choice;
                    scanf("%d", &choice);
                    switch (choice)
                    {
                        case 1:
                            if (hasItem1 == 0)
                            {
                                printf("You do not have that item!\n");
                            }
                            else
                            {
                                printf("You have used the %s and banished the ghost from the room!\n", item1);
                                hasGhost = 0;
                            }
                            break;
                        case 2:
                            if (hasItem2 == 0)
                            {
                                printf("You do not have that item!\n");
                            }
                            else
                            {
                                printf("You have used the %s and banished the ghost from the room!\n", item2);
                                hasGhost = 0;
                            }
                            break;
                        case 3:
                            if (hasItem3 == 0)
                            {
                                printf("You do not have that item!\n");
                            }
                            else
                            {
                                printf("You have used the %s and banished the ghost from the room!\n", item3);
                                hasGhost = 0;
                            }
                            break;
                        case 4:
                            if (hasItem4 == 0)
                            {
                                printf("You do not have that item!\n");
                            }
                            else
                            {
                                printf("You have used the %s and banished the ghost from the room!\n", item4);
                                hasGhost = 0;
                            }
                            break;
                        case 5:
                            if (hasItem5 == 0)
                            {
                                printf("You do not have that item!\n");
                            }
                            else
                            {
                                printf("You have used the %s and banished the ghost from the room!\n", item5);
                                hasGhost = 0;
                            }
                            break;
                        case 6:
                            if (hasItem6 == 0)
                            {
                                printf("You do not have that item!\n");
                            }
                            else
                            {
                                printf("You have used the %s and banished the ghost from the room!\n", item6);
                                hasGhost = 0;
                            }
                            break;
                        default:
                            printf("Invalid item number!\n");
                            break;
                    }
                }
                break;
            case 'D': // Quit the game
                printf("Thanks for playing, %s! Come back soon!\n", playerName);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
        
    } while (answer != 'D');
    
    return 0;
}