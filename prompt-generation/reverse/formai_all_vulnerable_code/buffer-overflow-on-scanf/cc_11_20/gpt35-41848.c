//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int room = 1;
    char answer;
    printf("Welcome to the Haunted House Simulator!\n");
    while(1) {
        if (room == 1) {
            printf("You enter into a dark room with spider webs hanging from the ceiling. You hear creaking noises coming from the floorboards. Do you want to move forward? (y/n) ");
            scanf(" %c", &answer);
            if (answer == 'y') {
                room = 2;
            } else {
                printf("Thanks for playing!\n");
                return 0;
            }
        } else if (room == 2) {
            printf("You enter into a room with a fireplace, the flames glowing a deep red. You smell a faint odor of burnt wood. Do you want to move forward? (y/n) ");
            scanf(" %c", &answer);
            if (answer == 'y') {
                room = 3;
            } else {
                printf("Thanks for playing!\n");
                return 0;
            }
        } else if (room == 3) {
            printf("You enter into a hallway with paintings of unknown faces hanging from the walls. You hear footsteps coming towards you from the other end of the hallway. Do you want to move forward? (y/n) ");
            scanf(" %c", &answer);
            if (answer == 'y') {
                int randomness = rand() % 2;
                if (randomness == 0) {
                    room = 4;
                } else {
                    printf("You are suddenly pushed to the ground, knocking you unconscious...\n");
                    return 0;
                }
            } else {
                printf("Thanks for playing!\n");
                return 0;
            }
        } else if (room == 4) {
            printf("You enter into a room with a single window. The glass is shattered and the wind is howling. You see a shadowy figure in the corner of the room. Do you want to move forward? (y/n) ");
            scanf(" %c", &answer);
            if (answer == 'y') {
                room = 5;
            } else {
                printf("Thanks for playing!\n");
                return 0;
            }
        } else if (room == 5) {
            printf("You enter into the final room with a large mirror. You see the reflection of the shadowy figure behind you. Do you want to turn around? (y/n) ");
            scanf(" %c", &answer);
            if (answer == 'y') {
                printf("You turn around to see the shadowy figure slowly approaching you. Suddenly, the room goes dark...\n");
                return 0;
            } else {
                printf("Thanks for playing!\n");
                return 0;
            }
        }
    }
    return 0;
}