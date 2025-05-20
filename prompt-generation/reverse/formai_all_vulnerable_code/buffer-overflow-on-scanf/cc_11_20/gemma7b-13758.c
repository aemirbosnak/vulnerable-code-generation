//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost {
    char name[20];
    int room;
    float fear_level;
} Ghost;

Ghost ghosts[MAX_GHOULS] = {
    {"Sarah", 1, 0.8},
    {"Jack", 2, 0.6},
    {"Mary", 3, 0.7},
    {"Thomas", 4, 0.5},
    {"Anna", 5, 0.9}
};

int main() {
    int i, j, r, current_room = 1;
    char input;

    srand(time(NULL));

    for (i = 0; i < MAX_GHOULS; i++) {
        ghosts[i].room = rand() % 5 + 1;
    }

    printf("You wake up in an abandoned building in a post-apocalyptic world.\n");
    printf("You have no memory of how you ended up here, only a sense of dread.\n");
    printf("The only sound is your breathing and the ticking of a clock.\n");

    while (1) {
        r = rand() % 2;
        if (r == 0) {
            printf("You hear a shuffling sound in the hallway.\n");
        } else {
            printf("You see a flickering light in the distance.\n");
        }

        printf("What do you want to do? (q/w/a/s/d): ");
        scanf("%c", &input);

        switch (input) {
            case 'q':
                printf("You decide to quit. The house fades away, and you are left with nothing.\n");
                exit(0);
            case 'w':
                current_room++;
                printf("You cautiously move forward, exploring the next room.\n");
                break;
            case 'a':
                current_room--;
                printf("You cautiously move back, exploring the previous room.\n");
                break;
            case 's':
                printf("You search the room for clues. You find a hidden key.\n");
                break;
            case 'd':
                printf("You try to flee, but the door is locked. You are trapped.\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }

        for (j = 0; j < MAX_GHOULS; j++) {
            if (ghosts[j].room == current_room && ghosts[j].fear_level > 0) {
                printf("Suddenly, you hear a scream. A ghost has appeared!\n");
                printf("What do you want to do? (f/p/r): ");
                scanf("%c", &input);

                switch (input) {
                    case 'f':
                        printf("You fight the ghost. A battle ensues.\n");
                        break;
                    case 'p':
                        printf("You plead with the ghost. It disappears.\n");
                        break;
                    case 'r':
                        printf("You run from the ghost. You flee the room.\n");
                        break;
                    default:
                        printf("Invalid input. Please try again.\n");
                        break;
                }
            }
        }
    }

    return 0;
}