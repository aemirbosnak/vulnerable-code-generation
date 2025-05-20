//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void introduction() {
    printf("In fair Verona, where we set our scene,\n");
    printf("Two star-crossed lovers, of haunted dreams,\n");
    printf("Enter a house of doom and gloom, it seems,\n");
    printf("Oh love, embark we on this eerie night,\n");
    printf("To face our fates by flash of candlelight.\n\n");
}

void hauntedChoice() {
    printf("Choose thy path, dear lovers, with hearts entwined:\n");
    printf("1. Enter the dark hallway, filled with whispers.\n");
    printf("2. Venture down to the basement, where shadows linger.\n");
    printf("3. Ascend the staircase to the attic, where secrets are kept.\n");
}

void respondChoice(int choice) {
    switch (choice) {
        case 1:
            printf("With trembling hearts, they tread the darkened way,\n");
            printf("Where echoes of the past in silence play.\n");
            printf("A ghostly figure appears, and speaks with fright:\n");
            printf("Stay ye but a moment, or taketh to flight!\n");
            break;
        case 2:
            printf("Into the basement, they bravely venture down,\n");
            printf("Upon the dusted floor, secrets swirl around.\n");
            printf("A hollow howl speaks forth, breaks the eerie calm:\n");
            printf("Two foolish souls, doth ye seek a care or balm?\n");
            break;
        case 3:
            printf("The attic beckons, with spirits from the past,\n");
            printf("Amidst the cobwebs, riddles wisely cast.\n");
            printf("An apparition whispers soft and low:\n");
            printf("Unlock thy heart, for love is but a show.\n");
            break;
        default:
            printf("Alas, in darkness thy choice was lost,\n");
            printf("Retreat from whence you came, at perilous cost.\n");
            break;
    }
}

int gameFlow() {
    srand(time(0));
    int choice;

    introduction();
    hauntedChoice();

    // Get user input
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    respondChoice(choice);
    
    // Random chance outcome
    int randomEvent = rand() % 2; // 0 or 1 for simplicity
    if (randomEvent == 0) {
        printf("The spirits are pleased, love shall prevail!\n");
        printf("Together they escape, telling the tale.\n");
    } else {
        printf("In terror, they flee, the hauntings do swell,\n");
        printf("By fate's cruel hand, trapped in this shell.\n");
    }

    return 0;
}

int main() {
    gameFlow();
    printf("Thanks for joining this ethereal soirée,\n");
    printf("In shadows, we danced, where spirits lay.\n");
    return 0;
}