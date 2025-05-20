//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunt(int, char *);

int main()
{
    int choice, i, spooky_num = 0;
    char name[20];

    printf("Good evening, dear Watson. You have been summoned to a haunted house on Spooky Lane.\n");

    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Prepare for a chilling encounter, %s. We must investigate the eerie occurrences within the crumbling manor.\n", name);

    while (1)
    {
        printf("\nWhat would you like to do? (1) Search the house, (2) Speak to the ghosts, (3) Leave the premises:\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                haunt(spooky_num, name);
                break;
            case 2:
                printf("The ghosts have not spoken to you, %s. Perhaps they are waiting for a more opportune moment.\n", name);
                break;
            case 3:
                printf("Thank you for your time, %s. You have safely escaped the haunted house.\n", name);
                exit(0);
            default:
                printf("Invalid input, %s. Please try again.\n", name);
        }
    }
}

void haunt(int spooky_num, char *name)
{
    int spooky_encounter = rand() % 3;

    switch (spooky_encounter)
    {
        case 0:
            printf("A cold wind whips through the halls of the house, %s. You hear footsteps approaching, but they vanish into thin air.\n", name);
            break;
        case 1:
            printf("A disembodied voice whispers your name in the dead of night, %s. It is a chilling sound that sends shivers down your spine.\n", name);
            break;
        case 2:
            printf("A ghostly figure appears before you, %s. It is a terrifying sight, and you feel an overwhelming sense of dread.\n", name);
            break;
    }

    spooky_num++;

    printf("You have survived another encounter with the supernatural, %s. Be vigilant, for the ghosts may not be done with you.\n", name);
}