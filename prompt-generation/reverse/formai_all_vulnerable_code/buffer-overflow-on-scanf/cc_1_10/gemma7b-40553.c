//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>

void main()
{
    char ch;
    int room = 1;
    int inventory[] = {0, 0, 0, 0};

    printf("Welcome to the Mysterious Manor!\n");
    printf("You wake up in a dimly lit room. You have no recollection of how you ended up here.\n");
    printf("Three doors stand before you:\n");
    printf("Door 1: It is shrouded in an eerie red glow.\n");
    printf("Door 2: It emanates a calming blue glow.\n");
    printf("Door 3: It pulsates with a vibrant green glow.\n");
    printf("Door 4: It radiates a mysterious purple glow.\n");

    printf("Please choose a door number: ");
    scanf("%c", &ch);

    switch (ch)
    {
        case '1':
            room = 2;
            inventory[0] = 1;
            printf("You enter the red door and find yourself in a dusty library.\n");
            break;
        case '2':
            room = 3;
            inventory[1] = 1;
            printf("You enter the blue door and find yourself in a cozy parlor.\n");
            break;
        case '3':
            room = 4;
            inventory[2] = 1;
            printf("You enter the green door and find yourself in a secret laboratory.\n");
            break;
        case '4':
            room = 5;
            inventory[3] = 1;
            printf("You enter the purple door and find yourself in a mysterious attic.\n");
            break;
        default:
            printf("Invalid input. Please try again.\n");
    }

    if (room == 2)
    {
        printf("You find a book in the library. It is a diary that belonged to the former owner of the manor.\n");
    }
    else if (room == 3)
    {
        printf("You find a silver key in the parlor. It is the key to unlocking a secret room.\n");
    }
    else if (room == 4)
    {
        printf("You find a hidden map in the laboratory. It leads you to a secret chamber.\n");
    }
    else if (room == 5)
    {
        printf("You find a hidden treasure in the attic. It is a priceless jewel.\n");
    }

    printf("Thank you for playing the game!\n");

    return;
}