//GPT-4o-mini DATASET v1.0 Category: Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define NUM_ROOMS 5
#define MONSTER_DELAY 5

typedef struct {
    int room_id;
    int has_item;
    int is_monster_present;
} Room;

Room dungeon[NUM_ROOMS];

void *check_monsters(void *arg) {
    int room_id = (int)(long)arg;
    while (1) {
        sleep(MONSTER_DELAY);
        dungeon[room_id].is_monster_present = rand() % 2; // 50% chance of monster appearing
        if (dungeon[room_id].is_monster_present) {
            printf("A monster has appeared in room %d!\n", room_id);
        } else {
            printf("Room %d is safe.\n", room_id);
        }
    }
    return NULL;
}

void initialize_dungeon() {
    for (int i = 0; i < NUM_ROOMS; i++) {
        dungeon[i].room_id = i;
        dungeon[i].has_item = rand() % 2; // 50% chance of having an item
        dungeon[i].is_monster_present = 0;
    }
}

void explore_room(int room_id) {
    if (dungeon[room_id].has_item) {
        printf("You found an item in room %d!\n", room_id);
        dungeon[room_id].has_item = 0; // The item is now taken
    } else {
        printf("Room %d is empty.\n", room_id);
    }
    
    if (dungeon[room_id].is_monster_present) {
        printf("You encountered a monster in room %d! You have been defeated!\n", room_id);
        exit(0); // Exit the game on defeat
    }
}

void *player_action(void *arg) {
    int *current_room = (int *)arg;
    char input;
    
    while (1) {
        printf("You are in room %d. (e: explore / q: quit): ", *current_room);
        scanf(" %c", &input);
        
        if (input == 'e') {
            explore_room(*current_room);
        } else if (input == 'q') {
            printf("Thanks for playing!\n");
            exit(0);
        } else {
            printf("Invalid input! Please try again.\n");
        }
    }
    
    return NULL;
}

int main() {
    srand(time(NULL));
    initialize_dungeon();
    
    pthread_t monster_threads[NUM_ROOMS];
    int room_ids[NUM_ROOMS];
    
    // Create threads for monster presence in each room
    for (int i = 0; i < NUM_ROOMS; i++) {
        room_ids[i] = i;
        pthread_create(&monster_threads[i], NULL, check_monsters, (void *)(long)i);
    }

    // Player action handling
    int current_room = 0; // Start in room 0
    player_action(&current_room);

    // Cleanup and wait for threads if needed (not reached due to exit)
    for (int i = 0; i < NUM_ROOMS; i++) {
        pthread_cancel(monster_threads[i]); // Cancel threads on exit
    }

    return 0;
}