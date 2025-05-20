//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100
#define NUM_ROOMS 10
#define NUM_OBJECTS 20

typedef struct {
    int x, y;
    char symbol;
} Room;

typedef struct {
    int x, y;
    char symbol;
} Object;

Room rooms[NUM_ROOMS];
Object objects[NUM_OBJECTS];

void generate_maze(int seed) {
    srand(seed);
    for (int i = 0; i < NUM_ROOMS; i++) {
        rooms[i].x = rand() % WIDTH;
        rooms[i].y = rand() % HEIGHT;
        rooms[i].symbol = rand() % 2? '.' : '#';
    }
    for (int i = 0; i < NUM_OBJECTS; i++) {
        objects[i].x = rand() % WIDTH;
        objects[i].y = rand() % HEIGHT;
        objects[i].symbol = rand() % 2? '.' : '#';
    }
}

void print_room(int room_num) {
    printf("Room %d:\n", room_num + 1);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (rooms[room_num].x == j && rooms[room_num].y == i) {
                printf("@");
            } else {
                printf("%c", rooms[room_num].symbol);
            }
        }
        printf("\n");
    }
}

void print_object(int obj_num) {
    printf("Object %d:\n", obj_num + 1);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (objects[obj_num].x == j && objects[obj_num].y == i) {
                printf("@");
            } else {
                printf("%c", objects[obj_num].symbol);
            }
        }
        printf("\n");
    }
}

int main() {
    int seed;
    printf("Enter a seed value: ");
    scanf("%d", &seed);
    generate_maze(seed);
    for (int i = 0; i < NUM_ROOMS; i++) {
        print_room(i);
    }
    for (int i = 0; i < NUM_OBJECTS; i++) {
        print_object(i);
    }
    return 0;
}