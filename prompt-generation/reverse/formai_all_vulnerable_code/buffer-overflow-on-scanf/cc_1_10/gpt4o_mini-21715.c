//GPT-4o-mini DATASET v1.0 Category: Haunted House Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_ROOMS 5
#define ROOM_NAME_LENGTH 20

typedef struct {
    char name[ROOM_NAME_LENGTH];
    int danger_level;
} Room;

Room haunted_house[MAX_ROOMS];

void* explore_room(void* arg) {
    Room* room = (Room*)arg;

    printf("Entering the %s...\n", room->name);
    sleep(2); // Simulate the delay of exploring the room

    if (room->danger_level > 5) {
        printf("You encounter a ghost in the %s!\n", room->name);
        printf("It's too scary! You shout and run away!\n");
    } else {
        printf("It's safe! You find some hidden treasures in the %s!\n", room->name);
    }

    return NULL;
}

void init_haunted_house() {
    strcpy(haunted_house[0].name, "Library");
    haunted_house[0].danger_level = 3;

    strcpy(haunted_house[1].name, "Kitchen");
    haunted_house[1].danger_level = 6;

    strcpy(haunted_house[2].name, "Basement");
    haunted_house[2].danger_level = 7;

    strcpy(haunted_house[3].name, "Attic");
    haunted_house[3].danger_level = 4;

    strcpy(haunted_house[4].name, "Garden");
    haunted_house[4].danger_level = 2;
}

void feel_the_fright() {
    printf("Welcome to the Haunted House Simulator!\n");
    printf("Which room do you want to explore?\n");
    
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("%d. %s (Danger Level: %d)\n", i+1, haunted_house[i].name, haunted_house[i].danger_level);
    }
    
    int choice;
    printf("Enter the room number (1-%d): ", MAX_ROOMS);
    scanf("%d", &choice);

    if (choice < 1 || choice > MAX_ROOMS) {
        printf("Invalid choice!\n");
        return;
    }

    pthread_t thread;
    pthread_create(&thread, NULL, explore_room, (void*)&haunted_house[choice - 1]);
    pthread_join(thread, NULL);
}

int main() {
    init_haunted_house();
    feel_the_fright();

    printf("Thank you for playing the Haunted House Simulator. Goodbye!\n");
    return 0;
}