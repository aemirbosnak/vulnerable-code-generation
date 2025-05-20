//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //seeding random function with current time

    int roomNumber = 1; //start in room 1
    int ghostLocation = rand() % 10 + 1; //generate random ghost room

    printf("Welcome to the Haunted House Simulator! You are currently in Room 1. \n");

    while (roomNumber <= 10) //loop through all 10 rooms
    {
        printf("Enter 1 to move to the next room: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) //user chooses to move to next room
        {
            roomNumber++;

            if (roomNumber == ghostLocation) //ghost is in current room
            {
                printf("Oh no! You have encountered a ghost in Room %d!\n", roomNumber);
                printf("GAME OVER\n");
                return 0;
            }
            else if (roomNumber == 10) //user has reached the end
            {
                printf("Congratulations! You have successfully escaped the haunted house.\n");
                return 0;
            }
            else //user moves to next room
            {
                printf("You have entered Room %d. ", roomNumber);

                //randomly generate spooky event
                int eventChance = rand() % 4;

                if (eventChance == 0) //monster growls
                {
                    printf("You hear a loud growling noise. It seems to be coming from the next room.\n");
                }
                else if (eventChance == 1) //door slams shut
                {
                    printf("The door slams shut behind you. You can't open it again.\n");
                }
                else if (eventChance == 2) //floorboards creak
                {
                    printf("The floorboards creak loudly underfoot. It's as if someone or something is watching you.\n");
                }
                else if (eventChance == 3) //cold wind blows
                {
                    printf("A sudden cold wind blows through the room. You shiver involuntarily.\n");
                }
            }
        }
        else //user did not enter 1
        {
            printf("Invalid choice. Please enter 1 to move to the next room.\n");
        }
    }

    return 0;
}