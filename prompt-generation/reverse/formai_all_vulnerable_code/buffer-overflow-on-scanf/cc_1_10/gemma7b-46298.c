//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room;
    int strength;
} Ghost;

Ghost ghosts[NUM_GHOSTS] = {
    {"Mr. Jones", 1, 3},
    {"Mrs. Smith", 2, 2},
    {"Mr. Brown", 3, 4},
    {"Ms. Green", 4, 3},
    {"Mr. Gray", 5, 2}
};

int main()
{
    int i, j, room, choice;
    char name[20];

    srand(time(NULL));

    // Welcome the visitor
    printf("Welcome to the Haunted House of Terror!\n");

    // Get the visitor's name
    printf("What is your name? ");
    scanf("%s", name);

    // Choose a room
    printf("Which room do you want to enter? (1-5) ");
    scanf("%d", &room);

    // Check if the room is haunted
    for (i = 0; i < NUM_GHOSTS; i++)
    {
        if (ghosts[i].room == room)
        {
            // The room is haunted!
            printf("The room is haunted by %s. Prepare for a fright!\n", ghosts[i].name);

            // Play a spooky sound effect
            system("play spooky.wav");

            // Have the ghost speak to the visitor
            switch (ghosts[i].strength)
            {
                case 1:
                    printf("Boo! I'm %s. Come say hi.\n", ghosts[i].name);
                    break;
                case 2:
                    printf("Beware, %s is lurking nearby. Prepare for a scare.\n", ghosts[i].name);
                    break;
                case 3:
                    printf("Get out of here, %s wants to play with you.\n", ghosts[i].name);
                    break;
                case 4:
                    printf("Prepare for a haunting, %s is on your way.\n", ghosts[i].name);
                    break;
            }

            // Ask the visitor if they want to leave
            printf("Do you want to leave the room? (Y/N) ");
            scanf("%c", &choice);

            // If the visitor chooses to leave, they are transported to safety
            if (choice == 'Y')
            {
                printf("You have escaped the Haunted House of Terror.\n");
            }
            else
            {
                printf("Oh no, you're trapped in the haunted house! Prepare for a nightmarish stay.\n");
            }

            break;
        }
    }

    // If the visitor has not found a ghost, they are safe
    if (i == NUM_GHOSTS)
    {
        printf("You have safely exited the Haunted House of Terror.\n");
    }

    return 0;
}