//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 5

typedef struct {
    char *description;
    char *items[3];
    int num_items;
} Room;

Room createRoom(char *description, char *items[], int num_items) {
    Room room;
    room.description = description;
    room.num_items = num_items;
    for (int i = 0; i < num_items; i++) {
        room.items[i] = items[i];
    }
    return room;
}

void displayRoom(Room room) {
    printf("You have entered a room:\n");
    printf("%s\n", room.description);
    if (room.num_items > 0) {
        printf("You see the following items:\n");
        for (int i = 0; i < room.num_items; i++) {
            printf(" - %s\n", room.items[i]);
        }
    } else {
        printf("The room is empty.\n");
    }
}

int enterRoom() {
    srand(time(NULL));
    return rand() % NUM_ROOMS;
}

void playerChoice(Room room) {
    char choice;
    printf("Will you (e)xamine the items or (l)eave the room? ");
    scanf(" %c", &choice);
    
    if (choice == 'e') {
        if (room.num_items > 0) {
            printf("You examine the items...\n");
            int itemIndex = rand() % room.num_items;
            printf("You found a spooky %s!\n", room.items[itemIndex]);
            // Potential for more storytelling here.
        } else {
            printf("There's nothing to examine.\n");
        }
    } else if (choice == 'l') {
        printf("You leave the room cautiously.\n");
    } else {
        printf("Invalid choice! You stand frozen in fear.\n");
    }
}

int main() {
    char *items1[] = {"rusty key", "old torch", "cursed doll"};
    char *items2[] = {"ancient tome", "broken mirror", "haunted mask"};
    char *items3[] = {NULL};
    char *items4[] = {"ghostly figure", "twisted branches", "shattered glass"};
    char *items5[] = {"hidden trapdoor", "blood-stained carpet", "witch's broom"};
    
    Room rooms[NUM_ROOMS];
    rooms[0] = createRoom("A dimly lit room filled with cobwebs.", items1, 3);
    rooms[1] = createRoom("A library filled with dusty books and shadows.", items2, 3);
    rooms[2] = createRoom("A cold, empty cellar with a foul odor.", items3, 0);
    rooms[3] = createRoom("A garden overgrown with thorny vines and whispers.", items4, 3);
    rooms[4] = createRoom("An attic filled with forgotten memories and rust.", items5, 3);

    printf("Welcome to the Haunted House Simulator!\n\n");
    
    while (1) {
        int roomIndex = enterRoom();
        displayRoom(rooms[roomIndex]);
        playerChoice(rooms[roomIndex]);

        char continueChoice;
        printf("Do you want to explore another room? (y/n): ");
        scanf(" %c", &continueChoice);
        if (continueChoice != 'y') {
            printf("Thank you for exploring! Farewell...\n");
            break;
        }
    }

    return 0;
}