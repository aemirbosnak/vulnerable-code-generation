//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    srand(time(NULL)); //set random seed
    int door_number = rand() % 3 + 1; //randomly choose a door number
    int player_choice; //player's choice of door
    int reveal_door; //door that is revealed
    int remaining_door; //door that is left unopened
    int switch_choice; //player's choice after reveal

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are standing in front of three doors.\n");
    printf("Behind one of the doors, is a ghost waiting to scare you!\n");
    printf("Choose a door (1, 2, or 3): ");
    scanf("%d", &player_choice); //take player's choice as input

    printf("You have chosen door number %d.\n", player_choice);

    //reveal a door that does not have the ghost
    if(door_number == player_choice) 
    {
        reveal_door = (rand() % 2 == 0) ? player_choice + 1 : player_choice - 1;
        reveal_door = (reveal_door > 3) ? 1 : reveal_door;
    }
    else
    {
        for(int i = 1; i <= 3; i++)
        {
            if(i != player_choice && i != door_number)
            {
                reveal_door = i;
                break;
            }
        }
    }

    printf("I will now reveal one of the other doors that does not have the ghost.\n");
    printf("Door number %d is empty.\n", reveal_door);

    //player has the option to switch their choice
    printf("Do you want to switch your choice to the remaining door? (1 = Yes, 0 = No): ");
    scanf("%d", &switch_choice);

    if(switch_choice == 1)
    {
        for(int i = 1; i <= 3; i++)
        {
            if(i != player_choice && i != reveal_door)
            {
                remaining_door = i;
                break;
            }
        }
        printf("You have switched your choice to door number %d.\n", remaining_door);
        if(remaining_door == door_number)
        {
            printf("Congratulations! You have escaped the haunted house unharmed.\n");
        }
        else
        {
            printf("Oh no! You have been scared by the ghost behind the door.\n");
        }
    }
    else
    {
        printf("You have stayed with your original choice of door number %d.\n", player_choice);
        if(player_choice == door_number)
        {
            printf("Congratulations! You have escaped the haunted house unharmed.\n");
        }
        else
        {
            printf("Oh no! You have been scared by the ghost behind the door.\n");
        }
    }

    return 0;
}