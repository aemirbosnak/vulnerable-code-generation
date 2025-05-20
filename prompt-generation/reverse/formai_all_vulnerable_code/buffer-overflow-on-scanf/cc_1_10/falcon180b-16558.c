//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOMS 10
#define GHOST_ROOMS 5
#define DOOR_ROOMS 5
#define WINNING_ROOM 9

int room[ROOMS];
int player_room = 0;
int ghost_room = 0;
int door_room = 0;
int lives = 3;
int score = 0;

void init() {
    srand(time(NULL));
    for(int i = 0; i < ROOMS; i++) {
        room[i] = rand() % 3;
        if(room[i] == 0) {
            ghost_room = i;
        } else if(room[i] == 1) {
            door_room = i;
        }
    }
    player_room = 0;
    printf("You are in room %d\n", player_room);
}

void move(int direction) {
    int new_room = (player_room + direction + ROOMS) % ROOMS;
    if(new_room == door_room) {
        score++;
        if(score == DOOR_ROOMS) {
            printf("You won!\n");
            exit(0);
        }
    } else if(new_room == ghost_room) {
        lives--;
        if(lives == 0) {
            printf("You lost!\n");
            exit(0);
        }
    }
    player_room = new_room;
    printf("You are in room %d\n", player_room);
}

int main() {
    init();
    while(1) {
        printf("You have %d lives left.\n", lives);
        printf("Score: %d\n", score);
        int choice;
        scanf("%d", &choice);
        if(choice == 1) {
            move(1);
        } else if(choice == 2) {
            move(-1);
        } else if(choice == 3) {
            move(0);
        } else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}