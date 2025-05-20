//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the introduction of the game
void printIntro()
{
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are lost in a haunted house and need to find your way out.\n");
    printf("Be careful though, there are ghosts and other eerie creatures lurking around.\n");
    printf("Press any key to continue...\n");
    getchar();
    system("cls");
}

// Function to generate a random number
int generateRandom(int min, int max)
{
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

// Function to simulate a room in the haunted house
void simulateRoom()
{
    int ghostChance = generateRandom(1, 100);
    printf("You enter a room...\n");

    if (ghostChance <= 30)
    {
        printf("Oh no! There's a ghost in this room!\n");
        printf("You run out as fast as you can...\n");
    }
    else if (ghostChance > 30 && ghostChance <= 70)
    {
        printf("This room seems to be safe...\n");
        printf("You continue on your way...\n");
    }
    else
    {
        printf("You hear some strange noises, but don't see anything...\n");
        printf("You cautiously leave the room...\n");
    }
}

// Function to simulate a hallway in the haunted house
void simulateHallway()
{
    int creatureChance = generateRandom(1, 100);
    printf("You enter a dark hallway...\n");

    if (creatureChance <= 50)
    {
        printf("You encounter a creepy creature...\n");
        printf("You try to keep your composure and slowly walk past it...\n");
    }
    else
    {
        printf("The hallway seems to be clear...\n");
        printf("You continue on your way...\n");
    }
}

// Function to simulate the escape from the haunted house
void simulateEscape(int steps)
{
    printf("You make your way through the dark and spooky house...\n");
    printf("After %d steps, you finally see a glimmer of light...\n", steps);
    printf("You rush to the door and finally escape the haunted house!\n");
}

// Main function to run the game
int main()
{
    printIntro();

    int steps = 0;
    char choice;

    do
    {
        int roomOrHall = generateRandom(1, 2);

        if (roomOrHall == 1)
        {
            simulateRoom();
        }
        else
        {
            simulateHallway();
        }

        steps++;

        printf("Would you like to continue exploring? (y/n)\n");
        scanf(" %c", &choice);
        system("cls");

    } while (choice == 'y' || choice == 'Y');

    simulateEscape(steps);

    return 0;
}