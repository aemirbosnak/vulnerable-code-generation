//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room_num;
    int active;
} Ghost;

Ghost ghosts[MAX_GHOSTS];

void initializeGhosts() {
    for (int i = 0; i < MAX_GHOSTS; i++) {
        ghosts[i].active = 0;
    }
}

void spawnGhost() {
    int room_num = rand() % 5;
    char name[20];
    printf("Enter the name of the ghost: ");
    scanf("%s", name);
    ghosts[room_num].active = 1;
    strcpy(ghosts[room_num].name, name);
    ghosts[room_num].room_num = room_num;
}

void interactWithGhosts() {
    for (int i = 0; i < MAX_GHOSTS; i++) {
        if (ghosts[i].active) {
            printf("Ghost name: %s\n", ghosts[i].name);
            printf("Room number: %d\n", ghosts[i].room_num);
            printf("Do you want to interact with the ghost? (Y/N): ");
            char answer;
            scanf("%c", &answer);

            switch (answer) {
                case 'Y':
                    printf("What do you want to do with the ghost? (Talk/Poke/ scare): ");
                    char action;
                    scanf("%c", &action);

                    switch (action) {
                        case 'Talk':
                            printf("You talked to the ghost: %s\n", ghosts[i].name);
                            break;
                        case 'Poke':
                            printf("You poked the ghost: %s\n", ghosts[i].name);
                            break;
                        case 'Scare':
                            printf("You scared the ghost: %s\n", ghosts[i].name);
                            ghosts[i].active = 0;
                            break;
                        default:
                            printf("Invalid action.\n");
                            break;
                    }
                    break;
                case 'N':
                    printf("You did not interact with the ghost: %s\n", ghosts[i].name);
                    break;
                default:
                    printf("Invalid answer.\n");
                    break;
            }
        }
    }
}

int main() {
    initializeGhosts();
    spawnGhost();
    interactWithGhosts();

    return 0;
}