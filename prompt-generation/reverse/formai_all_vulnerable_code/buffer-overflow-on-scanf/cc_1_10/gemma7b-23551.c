//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_GHOULS 10

typedef struct Ghost {
    char name[20];
    int room;
    int haunt_frequency;
    int scare_factor;
} Ghost;

Ghost ghouls[MAX_GHOULS] = {
    {"Mortimer", 1, 5, 8},
    {"Agatha", 2, 3, 6},
    {" Bartholomew", 3, 2, 4},
    {"Helena", 4, 4, 7},
    {"Abraham", 5, 3, 5},
    {"Catherine", 6, 2, 3},
    {"Elijah", 7, 4, 6},
    {"Frances", 8, 3, 5},
    {"Gertrude", 9, 2, 4},
    {"Henry", 10, 4, 7}
};

void haunt_house(int room) {
    int i;
    for (i = 0; i < MAX_GHOULS; i++) {
        if (ghouls[i].room == room) {
            printf("Suddenly, you hear a whisper in your ear: '%s'\n", ghouls[i].name);
            printf("A cold wind blows through the halls, and you feel a presence watching you.\n");
            printf("Suddenly, the hairs on your neck stand up, and you feel a chill down your spine.\n");
            printf("You hear a sound behind you, and turn around to see a ghostly figure standing there.\n");
            printf("The figure's eyes glow, and its voice is dripping with despair.\n");
            printf("The figure's hand reaches out to you, and you feel a wave of terror.\n");
            printf("You flee in terror, and the figure fades into the night.\n");
        }
    }
}

int main() {
    int room;

    printf("Enter the room number you want to explore: ");
    scanf("%d", &room);

    haunt_house(room);

    return 0;
}