//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: retro
#include <stdio.h>

int main()
{
    int choice, room, treasure;
    char name[20];

    // Welcome to the Cave of Wonders!
    printf("Welcome, traveler, to the Cave of Wonders!\n");
    printf("Please tell me your name: ");
    scanf("%s", name);

    // Choose your adventure path...
    printf("\nYou find yourself in a mysterious cave. Three doors stand before you:\n");
    printf("Door 1: It is glowing red and has a sinister feel.\n");
    printf("Door 2: It is glowing blue and has a sense of mystery.\n");
    printf("Door 3: It is glowing green and has a peaceful aura.\n");

    printf("Please choose a door number: ");
    scanf("%d", &choice);

    // Depending on your choice, you enter a different room...
    switch (choice)
    {
        case 1:
            room = 1;
            break;
        case 2:
            room = 2;
            break;
        case 3:
            room = 3;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            return 0;
    }

    // In each room, you search for a treasure...
    switch (room)
    {
        case 1:
            treasure = 1;
            break;
        case 2:
            treasure = 2;
            break;
        case 3:
            treasure = 3;
            break;
        default:
            printf("No treasure found.\n");
            return 0;
    }

    // If you found the treasure, congratulations!
    printf("\nCongratulations, %s! You have found the treasure!", name);
    printf("The treasure is a(n) %d.", treasure);

    return 0;
}