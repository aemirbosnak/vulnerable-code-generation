//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_haunted_house()
{
    // Setting the mood
    srand(time(NULL));
    int mood = rand() % 3;
    switch (mood)
    {
        case 0:
            printf("The air is thick with the scent of decaying roses and damp earth. The wind whistles through the trees, creating a mournful hum.\n");
            break;
        case 1:
            printf("A cold wind whips through your hair, carrying the scent of burning incense and desperation. The hairs on your neck stand on end.\n");
            break;
        case 2:
            printf("The smell of fresh bread and burning oil fills your senses. The air is thick with the sound of voices, both living and dead.\n");
            break;
    }

    // Building the haunted house
    printf("You find yourself in a dilapidated Victorian mansion. The front door swings open as you approach, and a cold wind rushes out, carrying with it the scent of decay and despair.\n");

    // The haunted house experience
    int choice;
    printf("What do you do? (1) Enter, (2) Turn around, (3) Leave\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            // Exploring the house
            printf("You cautiously enter the house, your footsteps echoing through the halls. You hear a rustle in the shadows and feel a cold hand brush against your back.\n");
            break;
        case 2:
            // Leaving the house
            printf("You turn around and flee from the house, running back into the wind.\n");
            break;
        case 3:
            // Leaving the house
            printf("You leave the house, feeling a sense of relief and dread. You hear a scream from within the house, and you swear you see a ghostly figure standing in the doorway.\n");
            break;
    }

    // Conclusion
    printf("The haunted house has been destroyed, but the memories of your experience linger on. You have escaped the clutches of the ghostly inhabitants, but you will never forget your night in the haunted Victorian mansion.\n");
}

int main()
{
    play_haunted_house();
    return 0;
}