//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunted_house();

int main()
{
    srand(time(NULL));
    haunted_house();
    return 0;
}

void haunted_house()
{
    int choice;
    printf("Welcome to the Haunted House!\n");
    printf("You find yourself standing in front of a large, ominous-looking mansion.\n");
    printf("The air is thick with fog and the only sound you can hear is the distant howling of wolves.\n");
    printf("Do you dare enter the house? (y/n)\n");
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        int door_choice;
        printf("You slowly push open the creaky door and step inside.\n");
        printf("The room is dark and dusty, with cobwebs covering every surface.\n");
        printf("There are three doors leading out of the room. Which one do you choose?\n");
        printf("1. The door on the left\n");
        printf("2. The door in the middle\n");
        printf("3. The door on the right\n");
        scanf("%d", &door_choice);

        switch (door_choice)
        {
            case 1:
                printf("You open the door on the left and find yourself in a long hallway.\n");
                printf("The walls are lined with portraits of eerie-looking people who seem to follow you with their eyes as you walk past.\n");
                printf("Suddenly, you hear a loud scream coming from one of the rooms at the end of the hallway!\n");
                break;

            case 2:
                printf("You open the door in the middle and find yourself in a large, dimly-lit room.\n");
                printf("In the center of the room is a dusty old book lying on a pedestal.\n");
                printf("As you approach the book, it suddenly springs to life and starts flipping pages on its own!\n");
                break;

            case 3:
                printf("You open the door on the right and find yourself in a small, cramped room.\n");
                printf("The walls are covered in strange symbols and there is a single candle burning in the center of the room.\n");
                printf("Suddenly, the candle goes out and you are plunged into darkness!\n");
                break;

            default:
                printf("Invalid choice. You must choose a door.\n");
        }
    }
    else
    {
        printf("You decide not to enter the house and quickly leave.\n");
    }
}