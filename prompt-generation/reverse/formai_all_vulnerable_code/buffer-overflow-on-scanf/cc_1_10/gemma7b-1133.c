//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void main()
{
    char name[20];
    printf("Please enter your name: ");
    scanf("%s", name);

    int room_num = 1;
    char current_room[20];
    current_room[0] = '\0';

    while (1)
    {
        system("clear");
        printf("You are in room %d: %s\n", room_num, current_room);

        char command[20];
        printf("What do you want to do? (help, go, interact, quit) ");
        scanf("%s", command);

        if (strcmp(command, "help") == 0)
        {
            printf("Available commands:\n");
            printf("help - Displays this message\n");
            printf("go - Goes to another room\n");
            printf("interact - Interacts with objects in the current room\n");
            printf("quit - Ends the game\n");
        }
        else if (strcmp(command, "go") == 0)
        {
            int next_room = rand() % 3 + 1;
            current_room[0] = '\0';
            room_num = next_room;
            printf("You have moved to room %d: %s\n", room_num, current_room);
        }
        else if (strcmp(command, "interact") == 0)
        {
            // Interact with objects in the current room
        }
        else if (strcmp(command, "quit") == 0)
        {
            printf("Thank you for playing, %s. See you next time!\n", name);
            exit(0);
        }
        else
        {
            printf("Invalid command.\n");
        }
    }
}