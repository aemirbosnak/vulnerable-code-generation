//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char name[20];
    printf("Please tell me your name: ");
    scanf("%s", name);

    int room_num = 1;
    char current_room[20];
    strcpy(current_room, "The Foyer");

    // The adventure begins!
    while (1)
    {
        // Display the current room information
        printf("You are currently in %s.\n", current_room);

        // List the available actions
        printf("What would you like to do? (help, go, examine, interact): ");

        // Get the user's input
        char input[20];
        scanf("%s", input);

        // Process the user's input
        if (strcmp(input, "help") == 0)
        {
            // Display a list of available actions
            printf("Available actions:\n");
            printf("  - go [direction]\n");
            printf("  - examine [object]\n");
            printf("  - interact with [person]\n");
            printf("  - help\n");
        }
        else if (strcmp(input, "go") == 0)
        {
            // Get the direction the user wants to go
            char direction[20];
            printf("Please tell me the direction you want to go: ");
            scanf("%s", direction);

            // Check if the direction is valid
            if (strcmp(direction, "north") == 0 || strcmp(direction, "south") == 0 || strcmp(direction, "east") == 0 || strcmp(direction, "west") == 0)
            {
                // Update the room number and current room
                if (strcmp(direction, "north") == 0)
                {
                    room_num++;
                    strcpy(current_room, "The Living Room");
                }
                else if (strcmp(direction, "south") == 0)
                {
                    room_num--;
                    strcpy(current_room, "The Entrance Hall");
                }
                else if (strcmp(direction, "east") == 0)
                {
                    room_num++;
                    strcpy(current_room, "The Dining Room");
                }
                else if (strcmp(direction, "west") == 0)
                {
                    room_num--;
                    strcpy(current_room, "The Kitchen");
                }

                // Display a message confirming the move
                printf("You have successfully traveled to the %s.\n", current_room);
            }
            else
            {
                printf("Invalid direction.\n");
            }
        }
        else if (strcmp(input, "examine") == 0)
        {
            // Get the object the user wants to examine
            char object[20];
            printf("Please tell me the object you want to examine: ");
            scanf("%s", object);

            // Check if the object is valid
            if (strcmp(object, "the painting") == 0 || strcmp(object, "the bookshelf") == 0 || strcmp(object, "the table") == 0)
            {
                // Describe the object
                if (strcmp(object, "the painting") == 0)
                {
                    printf("The painting is a beautiful portrait of a woman.\n");
                }
                else if (strcmp(object, "the bookshelf") == 0)
                {
                    printf("The bookshelf is full of books.\n");
                }
                else if (strcmp(object, "the table") == 0)
                {
                    printf("The table is made of wood.\n");
                }
            }
            else
            {
                printf("Invalid object.\n");
            }
        }
        else if (strcmp(input, "interact") == 0)
        {
            // Get the person the user wants to interact with
            char person[20];
            printf("Please tell me the person you want to interact with: ");
            scanf("%s", person);

            // Check if the person is valid
            if (strcmp(person, "the butler") == 0 || strcmp(person, "the maid") == 0 || strcmp(person, "the chef") == 0)
            {
                // Interact with the person
                if (strcmp(person, "the butler") == 0)
                {
                    printf("The butler is a polite and efficient servant.\n");
                }
                else if (strcmp(person, "the maid") == 0)
                {
                    printf("The maid is a hard-working and efficient employee.\n");
                }
                else if (strcmp(person, "the chef") == 0)
                {
                    printf("The chef is a skilled and creative cook.\n");
                }
            }
            else
            {
                printf("Invalid person.\n");
            }
        }
        else
        {
            printf("Invalid input.\n");
        }

        // Check if the user wants to continue the adventure
        printf("Do you want to continue your adventure? (yes/no): ");

        // Get the user's answer
        char answer[20];
        scanf("%s", answer);

        // If the user wants to continue, start the adventure again
        if (strcmp(answer, "yes") == 0)
        {
            // Reset the current room and room number
            strcpy(current_room, "The Foyer");
            room_num = 1;
        }
        else
        {
            // End the adventure
            printf("Thank you for playing! Goodbye.\n");
            break;
        }
    }
}