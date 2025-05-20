//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GHOST_ROOM_COUNT 5
#define GHOST_SOUND_COUNT 3

typedef struct Ghost {
    char name[20];
    int room_num;
    int sound_num;
    int is_active;
} Ghost;

Ghost ghosts[GHOST_ROOM_COUNT];

void init_ghosts() {
    int i;
    for (i = 0; i < GHOST_ROOM_COUNT; i++) {
        ghosts[i].is_active = 0;
    }
}

void activate_ghost(int room_num) {
    int i;
    for (i = 0; i < GHOST_ROOM_COUNT; i++) {
        if (ghosts[i].room_num == room_num) {
            ghosts[i].is_active = 1;
        }
    }
}

void generate_sound() {
    int sound_num = ghosts[0].sound_num;
    switch (sound_num) {
        case 0:
            printf("A creepy moan.\n");
            break;
        case 1:
            printf("A disembodied groan.\n");
            break;
        case 2:
            printf("A ghostly whine.\n");
            break;
    }
}

int main() {
    int room_num;

    init_ghosts();

    printf("Enter the room number: ");
    scanf("%d", &room_num);

    activate_ghost(room_num);

    if (ghosts[0].is_active) {
        generate_sound();
    } else {
        printf("No ghost activity.\n");
    }

    return 0;
}