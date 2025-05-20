//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: puzzling
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost {
    char name[20];
    int room_num;
    int health;
    int is_alive;
} Ghost;

Ghost ghosts[MAX_GHOULS];

void initializeGhosts() {
    for (int i = 0; i < MAX_GHOULS; i++) {
        ghosts[i].is_alive = 1;
        sprintf(ghosts[i].name, "Ghost %d", i + 1);
        ghosts[i].room_num = rand() % 5 + 1;
        ghosts[i].health = rand() % 10 + 1;
    }
}

void scarePlayer(Ghost *ghost) {
    if (ghost->is_alive) {
        printf("Suddenly, a %s appears out of nowhere, its cold, dead eyes searching for you. You feel a chilling presence in the air.\n", ghost->name);
        printf("A wave of fear washes over you as the %s approaches, its sharp claws glinting in the dim light. You hear its raspy breathing and feel its icy hand brush against your skin.\n", ghost->name);
        printf("Do you flee or confront the %s? (F/C): ", ghost->name);
        char answer;
        scanf(" %c", &answer);

        switch (answer) {
            case 'F':
                printf("You flee in terror, but the %s is close behind, its cold hand reaching out to grab you.\n", ghost->name);
                break;
            case 'C':
                printf("You confront the %s, but its powerful attack sends you reeling back. You feel your sanity slipping as the %s feeds on your fear.\n", ghost->name);
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    }
}

void main() {
    initializeGhosts();

    for (int i = 0; i < MAX_GHOULS; i++) {
        scarePlayer(&ghosts[i]);
    }

    printf("You have survived the night. Congratulations!\n");
}