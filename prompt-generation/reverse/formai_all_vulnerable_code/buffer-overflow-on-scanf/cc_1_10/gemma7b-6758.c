//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;
    char answer;
    int spooky_house_num = 13;

    // Setting the mood with a creepy soundtrack and flickering lights
    printf("A sinister tone fills the air, as you approach the imposing structure of the Haunted House of %d...  \n", spooky_house_num);

    // Choosing your path
    printf("Do you dare enter? (Y/N) ");
    scanf(" %c", &answer);

    // If you dare to enter...
    if (answer == 'Y' || answer == 'y')
    {
        // You hear a faint squeak and feel a cold hand brush against your back
        printf("Suddenly, you hear a squeak and feel a cold hand brush against your back. The hairs on your arms stand on end... \n");

        // You hear voices whispering your name...
        printf("Voices echo through the halls, whispering your name. You are overcome with terror and fear... \n");

        // You encounter a ghostly figure...
        printf("Suddenly, you encounter a ghostly figure standing in the middle of the hallway. Its eyes glow with an eerie light, and its cold hand reaches out to grab you... \n");

        // What will you do?
        printf("What do you do? Please enter your choice: ");
        scanf(" %d", &choice);

        // Depending on your choice, the outcome changes...
        switch (choice)
        {
            case 1:
                printf("You try to flee, but the ghostly figure is too fast. It grabs you and drags you into the haunted house, where you meet a gruesome end... \n");
                break;
            case 2:
                printf("You attempt to fight back, but the ghostly figure is too powerful. It overpowers you and throws you against a wall, causing severe injury... \n");
                break;
            case 3:
                printf("You try to call for help, but there is no one there to hear you. The ghostly figure feeds on your terror and leaves you to die... \n");
                break;
            default:
                printf("You have made an invalid choice. Please try again... \n");
                break;
        }
    }
    else
    {
        // You turn around and flee...
        printf("You turn around and flee, running as fast as you can... \n");
    }

    return 0;
}