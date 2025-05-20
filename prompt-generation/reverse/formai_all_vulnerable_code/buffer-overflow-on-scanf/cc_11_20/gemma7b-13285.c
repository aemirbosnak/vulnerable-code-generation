//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    system("clear");
    srand(time(NULL));

    int haunted_house_num = rand() % 5 + 1;
    switch (haunted_house_num)
    {
        case 1:
            printf("You have entered the dilapidated Victorian Manor. The scent of decay and despair permeates the air. A chilling melody echoes through the halls.\n");
            break;
        case 2:
            printf("You have stumbled upon the crumbling Mayan Temple. The air is thick with the smell of ancient incense and decay. The echoes of chanting voices reverberate through the chambers.\n");
            break;
        case 3:
            printf("You have found yourself in the sinister Clock Tower. The clock strikes twelve, and the air crackles with the anticipation of something wicked.\n");
            break;
        case 4:
            printf("You have entered the haunted pirate ship. The salty air whips your face, and the smell of decay and blood fills your nostrils. The voices of the dead crew members resonate through the deck.\n");
            break;
        case 5:
            printf("You have wandered into the cursed asylum. The air is thick with the scent of madness and despair. The echoes of tormented screams echo through the corridors.\n");
            break;
    }

    printf("Suddenly, a cold wind blows through the halls, extinguishing the candles. The oppressive atmosphere thickens, and your senses are on high alert. You hear footsteps approaching, and your heart skips a beat.\n");

    int spooky_sound = rand() % 5;
    switch (spooky_sound)
    {
        case 0:
            printf("A soft, rustling sound.\n");
            break;
        case 1:
            printf("A chilling moan.\n");
            break;
        case 2:
            printf("A heavy, dragging sound.\n");
            break;
        case 3:
            printf("A ghostly groan.\n");
            break;
        case 4:
            printf("A piercing scream.\n");
            break;
    }

    printf("You turn around to flee, but the door has been boarded up. You are trapped in the haunted house. The only sound is your own breathing and the oppressive atmosphere. What will you do?\n");

    char answer;
    scanf(" %c", &answer);

    if (answer == 'f' || answer == 'F')
    {
        printf("You frantically flee from the haunted house, running for your life. You escape the clutches of the ghostly inhabitants.\n");
    }
    else
    {
        printf("You are consumed by the oppressive atmosphere and go mad. The voices of the dead echo through your mind forever.\n");
    }

    return 0;
}