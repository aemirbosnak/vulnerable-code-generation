//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 5
#define MAX_OPTIONS 3

typedef struct {
    char *description;
    char *options[MAX_OPTIONS];
    int haunt_type;
} Room;

void introduce();
void enterRoom(Room *room);
void encounter(int haunt_type);
int randomNumber(int max);
void delay(int seconds);

int main() {
    srand(time(NULL));

    Room rooms[NUM_ROOMS] = {
        {"You stand in a dimly lit corridor filled with flickering neon lights.", {"Go to the control room", "Head to the server bay", "Exit to the Neon Alley"}, 1},
        {"The control room buzzes with static, screens flickering ominously.", {"Investigate the screens", "Check the terminal", "Leave to the corridor"}, 2},
        {"In the server bay, the hum of machinery surrounds you, shadows dance on the walls.", {"Search the shelves", "Tamper with the servers", "Return to the corridor"}, 3},
        {"Neon Alley is alive with the sounds of techno music, but eerie shadows stalk the night.", {"Explore the alley", "Look for a hidden path", "Head to the abandoned skyscraper"}, 4},
        {"Abandoned skyscraper looms ominously, legends of ghosts haunt its corridors.", {"Enter the building", "Cower outside", "Find another entrance"}, 5}
    };

    introduce();

    for (int i = 0; i < NUM_ROOMS; i++) {
        enterRoom(&rooms[i]);
    }

    printf("You've reached the end of your journey. The haunted house remains. What lies beyond?\n");
    return 0;
}

void introduce() {
    printf("Welcome to the Cyberpunk Haunted House Simulator!\n");
    printf("Prepare for an adventure full of technological horror and neon lights.\n");
    delay(2);
}

void enterRoom(Room *room) {
    printf("\n%s\n", room->description);
    printf("Options:\n");
    for (int i = 0; i < MAX_OPTIONS; i++) {
        if (room->options[i] != NULL) {
            printf("%d. %s\n", i + 1, room->options[i]);
        }
    }

    int choice;
    printf("Choose an option (1-%d): ", MAX_OPTIONS);
    scanf("%d", &choice);

    if (choice >= 1 && choice <= MAX_OPTIONS) {
        printf("\nYou chose: %s\n", room->options[choice - 1]);
        encounter(room->haunt_type);
    } else {
        printf("Invalid choice, you stumble and fall backward into darkness...\n");
        delay(1);
    }
}

void encounter(int haunt_type) {
    printf("Suddenly, you encounter a haunting...\n");
    switch (haunt_type) {
        case 1:
            printf("An abandoned holographic figure flickers in front of you, pleading for help!\n");
            break;
        case 2:
            printf("The screens burst to life, displaying terrifying visions of your darkest fears!\n");
            break;
        case 3:
            printf("A shadowy figure emerges from the servers, its face a featureless void, reaching out to you...\n");
            break;
        case 4:
            printf("Ghostly whispers fill the air, echoing secrets of the Neon Alley...\n");
            break;
        case 5:
            printf("The skyscraper groans as if alive, each floor riddled with specters of the past...\n");
            break;
        default:
            printf("Nothing happens. You breathe a sigh of relief.\n");
            break;
    }
    delay(2);
}

int randomNumber(int max) {
    return rand() % max;
}

void delay(int seconds) {
    for (int i = 0; i < seconds; i++) {
        sleep(1);
    }
}