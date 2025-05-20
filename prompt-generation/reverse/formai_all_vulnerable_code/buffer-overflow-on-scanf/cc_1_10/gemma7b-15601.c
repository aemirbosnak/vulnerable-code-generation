//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost {
    char name[20];
    int room;
    int mood;
    int action;
} Ghost;

Ghost ghosts[MAX_GHOULS] = {
    {"Mary", 1, 0, 0},
    {"John", 2, 1, 1},
    {"Alice", 3, 2, 2},
    {"Bob", 4, 3, 3},
    {"Tom", 5, 4, 4}
};

void haunt(int room) {
    int i;
    for (i = 0; i < MAX_GHOULS; i++) {
        if (ghosts[i].room == room) {
            switch (ghosts[i].mood) {
                case 0:
                    printf("You hear a soft whisper.\n");
                    break;
                case 1:
                    printf("You feel a cold hand brush against you.\n");
                    break;
                case 2:
                    printf("You hear footsteps behind you.\n");
                    break;
                case 3:
                    printf("You see a ghostly figure.\n");
                    break;
            }
            ghosts[i].action++;
        }
    }
}

int main() {
    int room;

    printf("Enter the room number: ");
    scanf("%d", &room);

    haunt(room);

    printf("The ghost has moved on.\n");

    return 0;
}