//GPT-4o-mini DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define NUM_ROOMS 5

typedef struct {
    int x, y;
} Position;

typedef struct {
    char name[50];
    char description[255];
    Position pos;
} Room;

Room rooms[NUM_ROOMS];

void generate_rooms() {
    srand(time(NULL));
    for (int i = 0; i < NUM_ROOMS; i++) {
        snprintf(rooms[i].name, sizeof(rooms[i].name), "Romantic Room %d", i+1);
        snprintf(rooms[i].description, sizeof(rooms[i].description), "This is a quaint room filled with love and warmth.");
        rooms[i].pos.x = rand() % MAP_WIDTH;
        rooms[i].pos.y = rand() % MAP_HEIGHT;
    }
}

void print_map() {
    char map[MAP_HEIGHT][MAP_WIDTH];

    // Initialize map with empty spaces
    for(int y = 0; y < MAP_HEIGHT; y++) {
        for(int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = '.';
        }
    }

    // Place rooms on map
    for (int i = 0; i < NUM_ROOMS; i++) {
        map[rooms[i].pos.y][rooms[i].pos.x] = 'R';
    }

    // Print map
    printf("\nYour Romantic Adventure Map:\n");
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            printf("%c ", map[y][x]);
        }
        printf("\n");
    }
}

void explore_room(int room_index) {
    if (room_index < 0 || room_index >= NUM_ROOMS) {
        printf("Room not found.\n");
        return;
    }
    printf("\nYou enter %s:\n", rooms[room_index].name);
    printf("%s\n", rooms[room_index].description);
    printf("The scent of roses fills the air, and the soft light creates an enchanting ambiance.\n");
}

int main() {
    generate_rooms();
    print_map();

    int choice;
    while (1) {
        printf("\nWhich room would you like to explore? (0 to %d or -1 to exit): ", NUM_ROOMS - 1);
        scanf("%d", &choice);
        if (choice == -1) {
            printf("Thank you for visiting this world of romance! Until next time...\n");
            break;
        }
        explore_room(choice);
    }

    return 0;
}