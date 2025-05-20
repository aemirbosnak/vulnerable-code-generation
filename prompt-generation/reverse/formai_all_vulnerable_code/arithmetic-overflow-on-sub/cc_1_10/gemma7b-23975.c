//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Cyberpunk
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int health;
    int location[2];
    int movement_direction;
} Ghost;

Ghost ghosts[MAX_GHOSTS];

void initialize_ghosts() {
    for (int i = 0; i < MAX_GHOSTS; i++) {
        ghosts[i].name[0] = '\0';
        ghosts[i].health = 100;
        ghosts[i].location[0] = -1;
        ghosts[i].location[1] = -1;
        ghosts[i].movement_direction = 0;
    }
}

void move_ghosts() {
    for (int i = 0; i < MAX_GHOSTS; i++) {
        switch (ghosts[i].movement_direction) {
            case 0:
                ghosts[i].location[0]++;
                break;
            case 1:
                ghosts[i].location[1]++;
                break;
            case 2:
                ghosts[i].location[0]--;
                break;
            case 3:
                ghosts[i].location[1]--;
                break;
        }
    }
}

int main() {
    initialize_ghosts();

    time_t start_time = time(NULL);
    while (time(NULL) - start_time < 60) {
        move_ghosts();
        sleep(1);
    }

    return 0;
}