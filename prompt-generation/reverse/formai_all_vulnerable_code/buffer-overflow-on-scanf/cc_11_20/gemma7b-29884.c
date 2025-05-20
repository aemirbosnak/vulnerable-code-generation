//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    printf("Please enter your name: ");
    scanf("%s", name);

    int room_num = 1;
    char current_room[20];

    switch (room_num)
    {
        case 1:
            strcpy(current_room, "The Foyer");
            break;
        case 2:
            strcpy(current_room, "The Living Room");
            break;
        case 3:
            strcpy(current_room, "The Kitchen");
            break;
        case 4:
            strcpy(current_room, "The Bedroom");
            break;
    }

    printf("You are in the %s.\n", current_room);

    int choice;
    printf("Please enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            room_num++;
            break;
        case 2:
            room_num--;
            break;
        case 3:
            printf("You have chosen to stay in the current room.\n");
            break;
        case 4:
            printf("You have chosen to leave the house.\n");
            exit(0);
            break;
    }

    switch (room_num)
    {
        case 1:
            strcpy(current_room, "The Foyer");
            break;
        case 2:
            strcpy(current_room, "The Living Room");
            break;
        case 3:
            strcpy(current_room, "The Kitchen");
            break;
        case 4:
            strcpy(current_room, "The Bedroom");
            break;
    }

    printf("You are now in the %s.\n", current_room);

    return 0;
}