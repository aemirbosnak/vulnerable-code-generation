//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GHOULS 10

typedef struct Ghost {
    char name[20];
    int room;
    int haunt_frequency;
    int scare_factor;
} Ghost;

Ghost ghosts[MAX_GHOULS] = {
    {"Mr. Bartholomew", 1, 3, 8},
    {"Ms. Constance", 2, 5, 6},
    {"Mr. Edward", 3, 2, 7},
    {"Ms. Flora", 4, 4, 5},
    {"Mr. George", 5, 1, 9},
    {"Mrs. Harriet", 6, 3, 6},
    {"Mr. Henry", 7, 2, 8},
    {"Ms. Irene", 8, 4, 5},
    {"Mr. Jack", 9, 1, 9},
    {"Mrs. Jane", 10, 3, 6}
};

void haunt_house(int room) {
    int i;
    for (i = 0; i < MAX_GHOULS; i++) {
        if (ghosts[i].room == room) {
            printf("%s has been spotted in room %d!\n", ghosts[i].name, room);
            printf("Prepare for a scare...\n");
            sleep(ghosts[i].haunt_frequency);
            printf("BOO!\n");
            sleep(ghosts[i].scare_factor);
        }
    }
}

int main() {
    int room_number;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("Please enter the room number you want to explore: ");
    scanf("%d", &room_number);

    haunt_house(room_number);

    return 0;
}