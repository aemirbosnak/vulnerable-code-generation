//Falcon2-11B DATASET v1.0 Category: Haunted House Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10
#define MAX_OBSTACLES 5
#define MAX_CANDLES 100

struct Room {
    int id;
    char name[50];
    int occupied;
    int light;
    int candles;
};

struct Obstacle {
    int id;
    char name[50];
    int x;
    int y;
};

struct House {
    struct Room rooms[MAX_ROOMS];
    struct Obstacle obstacles[MAX_OBSTACLES];
};

int main(void) {
    struct House house;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Enter the number of rooms in the house: ");
    scanf("%d", &house.rooms[0].id);
    printf("Enter the name of the room: ");
    scanf("%s", house.rooms[0].name);
    printf("Enter the number of obstacles in the room: ");
    scanf("%d", &house.rooms[0].occupied);
    printf("Enter the light level of the room: ");
    scanf("%d", &house.rooms[0].light);
    printf("Enter the number of candles in the room: ");
    scanf("%d", &house.rooms[0].candles);

    for (int i = 1; i < MAX_ROOMS; i++) {
        printf("Enter the name of the room: ");
        scanf("%s", house.rooms[i].name);
        printf("Enter the number of obstacles in the room: ");
        scanf("%d", &house.rooms[i].occupied);
        printf("Enter the light level of the room: ");
        scanf("%d", &house.rooms[i].light);
        printf("Enter the number of candles in the room: ");
        scanf("%d", &house.rooms[i].candles);
    }

    for (int i = 0; i < MAX_OBSTACLES; i++) {
        printf("Enter the name of the obstacle: ");
        scanf("%s", house.obstacles[i].name);
        printf("Enter the x coordinate of the obstacle: ");
        scanf("%d", &house.obstacles[i].x);
        printf("Enter the y coordinate of the obstacle: ");
        scanf("%d", &house.obstacles[i].y);
    }

    printf("\nYour haunted house has been created!\n");
    printf("Rooms: ");
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("%d: %s\n", i + 1, house.rooms[i].name);
    }
    printf("Obstacles: ");
    for (int i = 0; i < MAX_OBSTACLES; i++) {
        printf("%d: %s (%d, %d)\n", i + 1, house.obstacles[i].name, house.obstacles[i].x, house.obstacles[i].y);
    }

    return 0;
}