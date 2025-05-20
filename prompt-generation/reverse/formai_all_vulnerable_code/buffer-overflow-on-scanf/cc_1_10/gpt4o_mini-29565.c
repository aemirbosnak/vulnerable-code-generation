//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 5
#define MAX_ITEMS 3

typedef struct {
    char *name;
    char *description;
    int treasures;
} Room;

typedef struct {
    char *name;
    char *description;
} Item;

void explore(Room rooms[], Item items[], int *totalTreasures);
void showCurrentRoom(Room *room);
void interactWithRoom(Room *room);

int main() {
    srand(time(NULL));  // Seed the random number generator

    Room rooms[MAX_ROOMS] = {
        {"The Spooky Living Room", "You enter a dimly lit room with cobwebs hanging from the ceiling. There's an eerie feeling in the air.", 3},
        {"The Creepy Kitchen", "The kitchen smells of something rotten. You hear strange noises coming from the pantry.", 2},
        {"The Haunted Library", "Books float eerily in the air. Shadows dance around you as whispers fill the room.", 5},
        {"The Ghostly Bedroom", "You see a bed covered with dust. A chilling breeze makes you shiver.", 1},
        {"The Mysterious Attic", "Old trunks and forgotten memories await you. A ghost seems to linger here.", 4}
    };

    Item items[MAX_ITEMS] = {
        {"Shiny Necklace", "A sparkling necklace that seems to lure you closer."},
        {"Ancient Coin", "A rusty coin that glimmers with hidden treasures."},
        {"Crystal Ball", "A crystal ball that reveals glimpses of otherworldly secrets."}
    };

    int totalTreasures = 0;

    printf("Welcome to the Cheerful Haunted House Simulator!\n");
    printf("Are you ready for a delightful and spooky adventure? Let's go!\n\n");

    explore(rooms, items, &totalTreasures);

    printf("\nYou've collected a total of %d treasures! What a fantastic adventure!\n", totalTreasures);
    printf("Thank you for visiting the Cheerful Haunted House! Until next time!\n");

    return 0;
}

void explore(Room rooms[], Item items[], int *totalTreasures) {
    int choice;
    
    for (int i = 0; i < MAX_ROOMS; i++) {
        showCurrentRoom(&rooms[i]);
        interactWithRoom(&rooms[i]);
        *totalTreasures += rooms[i].treasures;
        
        if (i < MAX_ROOMS - 1) {
            printf("\nWould you like to move to the next room? (1 for YES, 0 for NO): ");
            scanf("%d", &choice);
            if (choice == 0) {
                printf("Leaving the haunted house... Thank you for visiting!\n");
                break;
            }
        }

        printf("\n");
    }
}

void showCurrentRoom(Room *room) {
    printf("You are now in: %s\n", room->name);
    printf("Description: %s\n", room->description);
    printf("Treasures to collect in this room: %d\n", room->treasures);
}

void interactWithRoom(Room *room) {
    printf("What a delightful place! Would you like to inspect it further? (1 for YES, 0 for NO): ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You found some treasures! Collecting them...\n");
        printf("You've collected %d treasures from this room!\n", room->treasures);
        room->treasures = 0;  // All treasures are collected
    } else {
        printf("You decided to leave the treasures behind. Spooky!\n");
    }
}