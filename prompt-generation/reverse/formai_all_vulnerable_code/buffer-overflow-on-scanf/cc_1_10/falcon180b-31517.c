//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_ROOMS 5
#define NUM_GHOSTS 3
#define GHOST_SPEED 1000 // In milliseconds

typedef struct {
    int room;
    int direction;
    int speed;
} Ghost;

Ghost ghosts[NUM_GHOSTS];
pthread_t ghost_threads[NUM_GHOSTS];

void *ghost_move(void *arg) {
    int i = *((int *) arg);
    while (1) {
        printf("Ghost %d is moving from room %d to room %d.\n", i, ghosts[i].room, (ghosts[i].room + ghosts[i].direction) % NUM_ROOMS);
        sleep(ghosts[i].speed);
        ghosts[i].room = (ghosts[i].room + ghosts[i].direction) % NUM_ROOMS;
    }
    return NULL;
}

int main() {
    int i;
    srand(time(NULL));
    for (i = 0; i < NUM_GHOSTS; i++) {
        ghosts[i].room = rand() % NUM_ROOMS;
        ghosts[i].direction = rand() % 2? 1 : -1;
        ghosts[i].speed = GHOST_SPEED + rand() % 500;
        pthread_create(&ghost_threads[i], NULL, ghost_move, &i);
    }

    while (1) {
        printf("You are in room 0. What do you want to do?\n");
        printf("1. Move to the next room.\n");
        printf("2. Move to the previous room.\n");
        printf("3. Quit.\n");
        scanf("%d", &i);
        if (i == 1) {
            printf("You moved to room 1.\n");
        } else if (i == 2) {
            printf("You moved to room %d.\n", NUM_ROOMS - 1);
        } else if (i == 3) {
            break;
        }
    }

    for (i = 0; i < NUM_GHOSTS; i++) {
        pthread_join(ghost_threads[i], NULL);
    }

    return 0;
}