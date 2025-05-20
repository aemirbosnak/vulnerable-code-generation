//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room;
    int type;
    float fear_factor;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
    {"Mr. Bartholomew", 1, 1, 3.5},
    {"Ms. Sophia", 2, 2, 2.8},
    {"The Disembodied", 3, 3, 4.2},
    {"The Blood Countess", 4, 2, 3.2},
    {"The Rag Doll", 5, 1, 2.6}
};

void haunt_house(int room) {
    int i;
    for (i = 0; i < MAX_GHOSTS; i++) {
        if (ghosts[i].room == room) {
            switch (ghosts[i].type) {
                case 1:
                    printf("You hear a disembodied moan.\n");
                    break;
                case 2:
                    printf("You smell a faint, decaying odor.\n");
                    break;
                case 3:
                    printf("You feel a cold wind blowing through the room.\n");
                    break;
            }
            printf("A chilling feeling washes over you.\n");
        }
    }
}

int main() {
    int room;

    printf("Enter the room number: ");
    scanf("%d", &room);

    haunt_house(room);

    return 0;
}