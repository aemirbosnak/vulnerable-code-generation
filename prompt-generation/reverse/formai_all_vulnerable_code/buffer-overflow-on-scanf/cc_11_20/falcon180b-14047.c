//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int choice;
    int flag = 0;
    int room = 1;
    int key = 0;
    int door;
    int i;

    printf("Welcome to the Haunted House!\n");
    printf("You are in room %d.\n", room);
    printf("There is a door in front of you.\n");

    srand(time(0));
    door = rand() % 3;

    if(door == 1)
    {
        printf("The door is locked.\n");
    }
    else if(door == 2)
    {
        printf("The door is unlocked.\n");
        key = 1;
    }
    else
    {
        printf("There is no door.\n");
    }

    while(flag == 0)
    {
        printf("\nWhat would you like to do?\n");
        printf("1. Try to open the door.\n");
        printf("2. Search the room.\n");
        printf("3. Give up.\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(door == 1 && key == 0)
                {
                    printf("The door is locked and you don't have the key.\n");
                }
                else if(door == 1 && key == 1)
                {
                    printf("You open the door and enter the next room.\n");
                    room++;
                }
                else if(door == 2 && key == 0)
                {
                    printf("You open the door and enter the next room.\n");
                    room++;
                    key = 1;
                }
                else if(door == 2 && key == 1)
                {
                    printf("The door is already unlocked.\n");
                }
                break;

            case 2:
                printf("You search the room and find a key.\n");
                key = 1;
                break;

            case 3:
                printf("You give up and remain trapped in the haunted house forever.\n");
                flag = 1;
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}