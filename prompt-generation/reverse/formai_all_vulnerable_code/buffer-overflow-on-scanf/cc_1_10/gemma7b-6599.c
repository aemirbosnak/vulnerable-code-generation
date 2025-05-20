//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void spooky_sounds(void);

int main()
{
    int choice;
    char name[20];
    time_t t;

    printf("Welcome to Spooky Manor! Please enter your name: ");
    scanf("%s", name);

    printf("Hello, %s. Prepare for a spooky journey!\n", name);

    t = time(NULL);
    srand(t);

    // Choose your haunted experience
    printf("What would you like to do?\n");
    printf("1. Enter the Haunted Hallway\n");
    printf("2. Explore the Spooky Attic\n");
    printf("3. Peek at the Witch's Brew\n");

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            spooky_sounds();
            printf("You cautiously enter the Haunted Hallway. The air is thick with the scent of decay and desperation. As you move through the dimly lit hallway, you hear whispers and footsteps echoing through the halls. Suddenly, a cold wind blows through the room, and you feel a presence lurking nearby.\n");
            break;
        case 2:
            spooky_sounds();
            printf("You cautiously explore the Spooky Attic. The smell of mothballs and decay permeates the air. As you venture deeper into the attic, you hear voices chanting and footsteps running up the stairs. The feeling of being watched intensifies, and you sense a ghostly presence surrounding you.\n");
            break;
        case 3:
            spooky_sounds();
            printf("You peek at the Witch's Brew. The stench of incense and blood fills your senses. As you examine the bubbling brew, you hear a cackling laugh and feel a cold hand brush against your back. The atmosphere is thick with anticipation, and you sense the presence of a wicked witch.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    printf("Thank you for visiting Spooky Manor. Please come again soon.\n");

    return 0;
}

void spooky_sounds(void)
{
    int sound_num;

    sound_num = rand() % 3;

    switch (sound_num)
    {
        case 0:
            printf("Footsteps\n");
            break;
        case 1:
            printf("Whispers\n");
            break;
        case 2:
            printf("Screams\n");
            break;
    }
}