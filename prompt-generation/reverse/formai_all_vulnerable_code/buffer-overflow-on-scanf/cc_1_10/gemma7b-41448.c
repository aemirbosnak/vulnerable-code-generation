//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunted_house(int);

int main()
{
    int choice;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Please select an option:\n");
    printf("1. Enter the house\n");
    printf("2. Exit\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            haunted_house(1);
            break;
        case 2:
            exit(0);
            break;
        default:
            printf("Invalid input.\n");
            break;
    }

    return 0;
}

void haunted_house(int mode)
{
    int i, j, k;
    int room_num = 1;
    int haunted_rooms[5] = {2, 3, 4, 5, 6};

    if (mode == 1)
    {
        system("clear");
        printf("You have entered the haunted house.\n");
        printf("You find yourself in room %d.\n", room_num);

        for (i = 0; i < 5; i++)
        {
            if (room_num == haunted_rooms[i])
            {
                printf("The room is haunted.\n");
                printf("You hear footsteps in the hallway.\n");
                printf("You feel a cold wind blowing through the house.\n");
                break;
            }
        }

        printf("You have escaped the haunted house.\n");
    }
}