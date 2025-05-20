//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_haunted_house(int difficulty) {
    // Set the mood
    srand(time(NULL));
    int spooky_sound = rand() % 2;
    int creepy_light = rand() % 2;
    int creepy_music = rand() % 2;
    int ghostly_presence = rand() % 2;

    // Create the haunted house
    int house_layout = rand() % 3;
    switch (house_layout) {
        case 0:
            // Simple linear hallway
            printf("You enter a dimly lit hallway. The only sound is your own breathing and the ticking clock.\n");
            break;
        case 1:
            // Twisted labyrinth
            printf("You find yourself trapped in a tangled labyrinth of corridors. The walls seem to warp and twist around you, and the only sound is your own frantic breathing.\n");
            break;
        case 2:
            // Haunted ballroom
            printf("You enter a grand ballroom, filled with ghostly whispers and dripping blood. The only sound is the echo of your own footsteps and the ominous music playing on repeat.\n");
            break;
    }

    // Add spooky elements
    if (spooky_sound) {
        printf("Suddenly, a disembodied scream echoes through the halls.\n");
    }
    if (creepy_light) {
        printf("The flickering lights dim and cast long, ominous shadows on the walls.\n");
    }
    if (creepy_music) {
        printf("A sinister melody begins to play, and the hairs on your neck stand on end.\n");
    }
    if (ghostly_presence) {
        printf("You feel a cold hand brush against your skin, and the hairs on your arms stand on end.\n");
    }

    // Create a sense of urgency
    printf("You must find a way out of the haunted house. Do you want to explore further (Y/N)? ");
    char answer;
    scanf("%c", &answer);

    // Check if the player escaped
    if (answer == 'Y') {
        printf("You bravely escape the haunted house. You are safe... for now.\n");
    } else {
        printf("You are trapped in the haunted house forever. The only sound is your own screams.\n");
    }
}

int main() {
    play_haunted_house(3);
    return 0;
}