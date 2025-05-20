//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printArr(char arr[][50], int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%s\n", arr[i]);
    }
}

int main()
{
    // Initialize variables
    char roomsArr[6][50] = {"Living Room", "Dining Room", "Kitchen", "Bedroom", "Bathroom", "Attic"};
    char objectsArr[6][50] = {"Mirror", "Chair", "Table", "Candle", "Book", "Painting"};
    int roomIndex = 0;
    int objectIndex = 0;

    // Seed the random number generator
    srand(time(0));

    // Welcome message
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are now inside the house.\n");

    // Start game loop
    while(1)
    {
        // Print current room and objects
        printf("You are in the %s.\n", roomsArr[roomIndex]);
        printf("You see a %s in the room.\n", objectsArr[objectIndex]);

        // Ask user for input
        printf("Enter a command: ");
        char input[50];
        scanf("%s", input);

        // Check user input
        if(strcmp(input, "quit") == 0)
        {
            printf("Thanks for playing!\n");
            break;
        }
        else if(strcmp(input, "help") == 0)
        {
            // Print available commands
            printf("\nCommands:\n");
            printf("  quit - Exit the game.\n");
            printf("  help - Display this help menu.\n");
            printf("  next - Move to the next room.\n");
            printf("  search - Search the room.\n");
            printf("\n");
        }
        else if(strcmp(input, "next") == 0)
        {
            // Move to the next room
            roomIndex = (roomIndex + 1) % 6;
            printf("You move to the %s.\n", roomsArr[roomIndex]);

            // Choose a new object
            objectIndex = rand() % 6;
        }
        else if(strcmp(input, "search") == 0)
        {
            // Search the room
            printf("You search the room and find nothing of interest...\n");
        }
        else
        {
            printf("Invalid command. Type 'help' to see available commands.\n");
        }
    }

    return 0;
}