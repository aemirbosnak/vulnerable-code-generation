//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 5

typedef struct Ghost {
    char name[20];
    int room;
    int health;
    int attack;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
    {"Mr. Jones", 1, 100, 20},
    {"Ms. Smith", 2, 80, 15},
    {"Mr. Brown", 3, 60, 10},
    {"Mrs. Johnson", 4, 40, 5},
    {"Mr. Gray", 5, 20, 2}
};

void haunt(int room) {
    int i;
    for (i = 0; i < MAX_GHOSTS; i++) {
        if (ghosts[i].room == room) {
            printf("%s has appeared! Prepare for a fright!\n", ghosts[i].name);
            sleep(1);
            printf("BOO!\n");
            sleep(1);
            ghosts[i].health--;
            if (ghosts[i].health <= 0) {
                printf("%s has been defeated!\n", ghosts[i].name);
                ghosts[i].room = -1;
            }
        }
    }
}

int main() {
    int room;

    printf("Enter the room number you want to explore: ");
    scanf("%d", &room);

    haunt(room);

    printf("You have survived the haunted house!\n");

    return 0;
}