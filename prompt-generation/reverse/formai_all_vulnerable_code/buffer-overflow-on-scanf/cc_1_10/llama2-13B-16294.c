//LLAMA2-13B DATASET v1.0 Category: Terminal Based Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_OBSTACLES 5
#define MAX_ENEMIES 3

// Structure to store room data
struct room {
    char name[50];
    char description[100];
    int obstacles[MAX_OBSTACLES];
    int enemies[MAX_ENEMIES];
    int exits[2];
};

// Global variables
int current_room = 0;
struct room rooms[MAX_ROOMS];

// Function to generate a random room
void generate_room() {
    int i, j;
    char name[50];
    char description[100];
    int obstacles[MAX_OBSTACLES];
    int enemies[MAX_ENEMIES];
    int exits[2];

    // Generate random name and description
    sprintf(name, "Room %d", current_room);
    description[0] = '\0';
    for (i = 0; i < 50; i++) {
        description[i] = 'a' + (rand() % 26);
    }

    // Generate random obstacles and enemies
    for (i = 0; i < MAX_OBSTACLES; i++) {
        obstacles[i] = rand() % 3;
    }
    for (i = 0; i < MAX_ENEMIES; i++) {
        enemies[i] = rand() % 3;
    }

    // Generate random exits
    exits[0] = rand() % 2;
    exits[1] = rand() % 2;

    // Add room to the list of rooms
    rooms[current_room] = (struct room) {
        .name = name,
        .description = description,
        .obstacles = obstacles,
        .enemies = enemies,
        .exits = exits,
    };
    current_room++;
}

// Function to print room information
void print_room() {
    printf("You are in %s\n", rooms[current_room - 1].name);
    printf("Description: %s\n", rooms[current_room - 1].description);
    printf("Obstacles: ");
    for (int i = 0; i < MAX_OBSTACLES; i++) {
        printf("%d ", rooms[current_room - 1].obstacles[i]);
    }
    printf("\nEnemies: ");
    for (int i = 0; i < MAX_ENEMIES; i++) {
        printf("%d ", rooms[current_room - 1].enemies[i]);
    }
    printf("\nExits: ");
    printf("%d, %d\n", rooms[current_room - 1].exits[0], rooms[current_room - 1].exits[1]);
}

// Function to move around the cave
void move() {
    int direction;
    printf("Where do you want to go? (n, s, e, w, up, down)\n");
    scanf("%c", &direction);

    // Handle invalid input
    if (direction < 'n' || direction > 'd') {
        printf("Invalid input. You are stuck in the cave.\n");
        return;
    }

    // Move to the corresponding room
    switch (direction) {
        case 'n':
            current_room -= 1;
            break;
        case 's':
            current_room += 1;
            break;
        case 'e':
            current_room += 1;
            break;
        case 'w':
            current_room -= 1;
            break;
        case 'u':
            current_room = 0;
            break;
        case 'd':
            current_room = MAX_ROOMS - 1;
            break;
    }
    print_room();
}

int main() {
    srand(time(NULL));
    generate_room();
    print_room();

    while (1) {
        move();
    }

    return 0;
}