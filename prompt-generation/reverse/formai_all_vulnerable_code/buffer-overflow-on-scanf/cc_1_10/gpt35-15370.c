//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayInstructions();
void playGame();
void enterRoom();
void shapeShift();

// Global variables
int currentRoom = 1;
int previousRoom = 0;
int shapeShiftCount = 0;

int main()
{
    // Set seed for random number generation
    srand(time(NULL));

    printf("Welcome to the Haunted House Simulator\n\n");

    // Display instructions
    displayInstructions();

    // Play the game
    playGame();

    printf("\nGoodbye! Thanks for playing.\n");

    return 0;
}

void displayInstructions()
{
    printf("You have entered a haunted house and your goal is to find your way out.\n");
    printf("There are four rooms in the house and four exits.\n");
    printf("Each time you enter a room, there is a chance that it will shape shift into a different room.\n");
    printf("You have a limited number of shape shifts you can use to navigate the house.\n");
    printf("Type \"enter\" to enter a room, \"shift\" to shape shift, or \"quit\" to exit the game.\n\n");
}

void playGame()
{
    char input[6];

    while (1)
    {
        printf("You are in room %d.\n", currentRoom);

        // Check if current room is the exit
        if (currentRoom == 4)
        {
            printf("You have found the exit! Congratulations!\n");
            break;
        }

        printf("What would you like to do? ");
        scanf("%s", input);

        if (strcmp(input, "enter") == 0)
        {
            enterRoom();
        }
        else if (strcmp(input, "shift") == 0)
        {
            shapeShift();
        }
        else if (strcmp(input, "quit") == 0)
        {
            break;
        }
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    }
}

void enterRoom()
{
    // Set previous room as current room
    previousRoom = currentRoom;

    // Randomly generate new room
    currentRoom = rand() % 4 + 1;

    // Check if shape shift occurred
    if (currentRoom != previousRoom)
    {
        printf("You have entered room %d, but it has shape shifted from room %d!\n", currentRoom, previousRoom);
    }
    else
    {
        printf("You have entered room %d.\n", currentRoom);
    }
}

void shapeShift()
{
    // Check if there are shape shifts remaining
    if (shapeShiftCount < 3)
    {
        // Set previous room as current room
        previousRoom = currentRoom;

        // Randomly generate new room
        currentRoom = rand() % 4 + 1;

        // Increment shape shift count
        shapeShiftCount++;

        // Check if shape shift occurred
        if (currentRoom != previousRoom)
        {
            printf("You have shape shifted to room %d from room %d!\n", currentRoom, previousRoom);
        }
        else
        {
            printf("You have shape shifted to room %d.\n", currentRoom);
        }
    }
    else
    {
        printf("You have used all your shape shifts. Please enter a room instead.\n");
    }
}