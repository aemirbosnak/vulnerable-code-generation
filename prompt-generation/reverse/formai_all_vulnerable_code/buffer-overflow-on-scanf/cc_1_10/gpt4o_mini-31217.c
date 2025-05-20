//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 5
#define MAX_EVENTS 3

typedef enum {
    EVENT_NONE,
    EVENT_GHOST,
    EVENT_TRAP,
    EVENT_CANDY
} Event;

const char *roomNames[MAX_ROOMS] = {
    "Entrance Hall",
    "Dining Room",
    "Library",
    "Bedroom",
    "Attic"
};

const char *eventMessages[MAX_EVENTS] = {
    "You've encountered a ghost! You lose 1 health point.",
    "You've fallen into a trap! You lose 2 health points.",
    "You've found some magical candy! You gain 1 health point."
};

typedef struct {
    int health;
} Player;

void printRoom(int roomIndex) {
    printf("\nYou are in the %s.\n", roomNames[roomIndex]);
}

Event generateRandomEvent() {
    return rand() % (MAX_EVENTS + 1); // 0 to 3 (0 = no event)
}

void encounterEvent(Player *player, Event event) {
    switch (event) {
        case EVENT_GHOST:
            player->health -= 1;
            printf("%s\n", eventMessages[0]);
            break;
        case EVENT_TRAP:
            player->health -= 2;
            printf("%s\n", eventMessages[1]);
            break;
        case EVENT_CANDY:
            player->health += 1;
            printf("%s\n", eventMessages[2]);
            break;
        default:
            printf("Nothing happens in this room.\n");
    }
}

void printStatus(Player *player) {
    printf("Current health: %d\n", player->health);
}

int main() {
    srand(time(NULL)); // Seed random number generator
    Player player = {5}; // Start with 5 health points
    int currentRoom = 0;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You start with %d health points.\n", player.health);

    while (player.health > 0) {
        printRoom(currentRoom);
        Event event = generateRandomEvent();
        encounterEvent(&player, event);
        printStatus(&player);

        if (currentRoom < MAX_ROOMS - 1) {
            printf("\nDo you want to go to the next room? (1 = yes, 0 = no): ");
            int choice;
            scanf("%d", &choice);
            if (choice == 1) {
                currentRoom++;
            } else {
                printf("You chose to stay in the current room. Game over!\n");
                break;
            }
        } else {
            printf("\nYou've reached the final room! The adventure ends here. Game over!\n");
            break;
        }

        printf("Press Enter to continue to the next room.\n");
        getchar(); // To consume the newline left by scanf
        getchar();
    }

    if (player.health <= 0) {
        printf("You have lost all your health! Game over!\n");
    }

    return 0;
}