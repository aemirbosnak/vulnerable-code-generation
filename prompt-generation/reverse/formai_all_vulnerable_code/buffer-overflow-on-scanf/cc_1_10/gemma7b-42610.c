//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room_num;
    int health;
    int is_active;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
    {"Sarah", 1, 100, 1},
    {"Jack", 2, 80, 1},
    {"Mary", 3, 60, 1},
    {"Peter", 4, 40, 1},
    {"Alice", 5, 20, 1}
};

void initialize_ghosts() {
    for (int i = 0; i < MAX_GHOSTS; i++) {
        ghosts[i].is_active = 1;
    }
}

void move_ghosts() {
    for (int i = 0; i < MAX_GHOSTS; i++) {
        if (ghosts[i].is_active) {
            ghosts[i].room_num = rand() % 5 + 1;
        }
    }
}

void interact_with_ghosts() {
    for (int i = 0; i < MAX_GHOSTS; i++) {
        if (ghosts[i].is_active) {
            printf("You encounter %s in room %d.\n", ghosts[i].name, ghosts[i].room_num);
            printf("What do you want to do? (fight, flee, talk)\n");
            char input[20];
            scanf("%s", input);

            switch (input[0]) {
                case 'f':
                    ghosts[i].health -= 20;
                    printf("You fought %s and damaged them.\n", ghosts[i].name);
                    break;
                case 'F':
                    ghosts[i].is_active = 0;
                    printf("You fled from %s.\n", ghosts[i].name);
                    break;
                case 't':
                    printf("You talked to %s.\n", ghosts[i].name);
                    break;
                default:
                    printf("Invalid input.\n");
                    break;
            }
        }
    }
}

int main() {
    initialize_ghosts();
    move_ghosts();
    interact_with_ghosts();

    return 0;
}