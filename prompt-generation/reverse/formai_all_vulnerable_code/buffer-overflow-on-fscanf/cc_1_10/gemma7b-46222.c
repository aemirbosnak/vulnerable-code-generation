//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_GHOSTS 5
#define GHOST_SOUNDS_FILE "ghost_sounds.wav"
#define GHOST_MOVEMENT_FILE "ghost_movement.txt"

typedef struct Ghost {
    char name[20];
    int room_num;
    int sound_num;
    int movement_num;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
    {"Mr. Jones", 1, 1, 1},
    {"Mrs. Smith", 2, 2, 2},
    {"Mr. Brown", 3, 3, 3},
    {"Ms. Green", 4, 4, 4},
    {"Mr. White", 5, 5, 5}
};

void play_ghost_sound(int sound_num) {
    char sound_path[100];
    sprintf(sound_path, "sounds/%d.wav", sound_num);
    system(sound_path);
}

void move_ghost(Ghost *ghost) {
    FILE *fp = fopen(GHOST_MOVEMENT_FILE, "r");
    char line[100];
    fscanf(fp, "%s", line);
    fclose(fp);

    char *movement = strstr(line, ghost->name);
    if (movement) {
        switch (movement[0]) {
            case 'N':
                ghost->room_num++;
                break;
            case 'S':
                ghost->room_num--;
                break;
            case 'E':
                ghost->room_num++;
                break;
            case 'W':
                ghost->room_num--;
                break;
        }
    }
}

void simulate_haunted_house() {
    srand(time(NULL));
    for (int i = 0; i < MAX_GHOSTS; i++) {
        move_ghost(&ghosts[i]);
        play_ghost_sound(ghosts[i].sound_num);
    }
}

int main() {
    simulate_haunted_house();
    return 0;
}