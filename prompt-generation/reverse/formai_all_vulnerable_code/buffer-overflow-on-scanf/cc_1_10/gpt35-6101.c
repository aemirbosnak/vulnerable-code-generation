//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM_ROOMS 6
#define NUM_GHOSTS 3

int main()
{
    srand(time(NULL));

    char rooms[NUM_ROOMS] = {'e','e','e','e','e','e'}; // 'e' means empty room
    int ghost_locations[NUM_GHOSTS];

    // randomly placing ghosts in 3 different rooms
    for(int i=0; i<NUM_GHOSTS; i++)
    {
        int location;
        do{
            location = rand()%NUM_ROOMS;
        }while(rooms[location] == 'g'); // 'g' means ghost already present in the room

        ghost_locations[i] = location;
        rooms[location] = 'g'; // placing ghost in the room
    }

    printf("\n\nWelcome to the Haunted House Simulator. You will enter a house with 6 rooms.\n");
    printf("You will have to search for the ghosts and banish them. But beware, they might try to scare you.\nGood Luck!\n\n");

    int current_room = 0;
    int banished_ghosts = 0;

    while(banished_ghosts < NUM_GHOSTS)
    {
        printf("You are currently in room %d\n",current_room+1);
        printf("Do you want to (1) search the room or (2) move to another room?\n");

        int choice;
        scanf("%d",&choice);

        if(choice == 1) // searching the current room
        {
            if(rooms[current_room] == 'g') // ghost present in the room
            {
                printf("Oh no!! You have encountered a ghost in the room.\n");
                printf("The ghost tries to scare you, but you bravely banish it.\n");
                rooms[current_room] = 'e'; // banishing the ghost
                banished_ghosts++;
            }
            else // no ghost present in the current room
            {
                printf("You search the room, but find nothing unusual.\n");
            }
        }
        else if(choice == 2) // moving to another room
        {
            printf("Which room do you want to move to? Enter room number (1-6).\n");

            int room_number;
            scanf("%d",&room_number);
            room_number--; // converting to 0-based index

            if(room_number < 0 || room_number >= NUM_ROOMS) // invalid room number
            {
                printf("Invalid room number. Please try again.\n");
            }
            else
            {
                current_room = room_number;
                if(rooms[current_room] == 'g') // ghost present in the new room
                {
                    printf("Oh no!! You have encountered a ghost in the room.\n");
                    printf("The ghost tries to scare you, but you bravely banish it.\n");
                    rooms[current_room] = 'e'; // banishing the ghost
                    banished_ghosts++;
                }
            }
        }
        else // invalid choice
        {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("\n\nCongratulations!!! You have banished all %d ghosts from the haunted house.\n",NUM_GHOSTS);

    return 0;
}