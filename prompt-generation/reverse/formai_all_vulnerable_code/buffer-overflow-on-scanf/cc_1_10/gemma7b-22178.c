//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

void play_game()
{
    int choice, inventory[] = {0, 0, 0}, location = 1;

    system("clear");
    printf("You are in a mysterious cave.\n");
    printf("There are three doors before you.\n");
    printf("Door 1 is red and has a glowing handle.\n");
    printf("Door 2 is blue and has a cracked handle.\n");
    printf("Door 3 is green and has a twisted handle.\n");

    printf("Please choose a door number: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            inventory[0] = 1;
            location = 2;
            break;
        case 2:
            inventory[1] = 1;
            location = 3;
            break;
        case 3:
            inventory[2] = 1;
            location = 4;
            break;
        default:
            printf("Invalid choice.\n");
    }

    system("clear");

    switch (location)
    {
        case 2:
            printf("You have entered a room with a lot of gold coins.\n");
            break;
        case 3:
            printf("You have entered a room with a powerful sword.\n");
            break;
        case 4:
            printf("You have entered a room with a healing potion.\n");
            break;
    }

    play_game();
}

int main()
{
    play_game();

    return 0;
}