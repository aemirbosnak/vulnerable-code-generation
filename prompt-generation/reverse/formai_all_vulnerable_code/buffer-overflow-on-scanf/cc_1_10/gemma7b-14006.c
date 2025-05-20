//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_sound(char *sound)
{
    system(sound);
}

void scare(int scare_level)
{
    switch (scare_level)
    {
        case 1:
            play_sound("sound/screams_1.wav");
            break;
        case 2:
            play_sound("sound/screams_2.wav");
            break;
        case 3:
            play_sound("sound/screams_3.wav");
            break;
        case 4:
            play_sound("sound/screams_4.wav");
            break;
        case 5:
            play_sound("sound/screams_5.wav");
            break;
    }
}

int main()
{
    int choice, scare_level;
    char *sound_file;

    // Set the seed for random number generator
    srand(time(NULL));

    // Choose a haunted house scenario
    printf("Enter the number of the haunted house scenario you want to experience (1-5): ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            sound_file = "sound/haunted_house_1.wav";
            scare_level = rand() % 5 + 1;
            break;
        case 2:
            sound_file = "sound/haunted_house_2.wav";
            scare_level = rand() % 5 + 1;
            break;
        case 3:
            sound_file = "sound/haunted_house_3.wav";
            scare_level = rand() % 5 + 1;
            break;
        case 4:
            sound_file = "sound/haunted_house_4.wav";
            scare_level = rand() % 5 + 1;
            break;
        case 5:
            sound_file = "sound/haunted_house_5.wav";
            scare_level = rand() % 5 + 1;
            break;
    }

    // Play the haunted house sound
    play_sound(sound_file);

    // Scares the player
    scare(scare_level);

    // End the game
    printf("Thank you for playing the haunted house simulator. Goodbye.\n");

    return 0;
}