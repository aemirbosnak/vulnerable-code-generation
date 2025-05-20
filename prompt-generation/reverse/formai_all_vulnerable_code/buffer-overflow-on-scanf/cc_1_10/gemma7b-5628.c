//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: Cryptic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_GHOULS 5

typedef struct Ghost {
    char name[20];
    int room_num;
    int spectral_power;
} Ghost;

Ghost ghosts[MAX_GHOULS] = {
    {"Mortimer", 1, 3},
    {"Victoria", 2, 2},
    {"Alfred", 3, 1},
    {"Samantha", 4, 4},
    {"Jasper", 5, 2}
};

void haunt_house(int room_num) {
    int i;
    for (i = 0; i < MAX_GHOULS; i++) {
        if (ghosts[i].room_num == room_num) {
            printf("The spirit of %s appears!\n", ghosts[i].name);
            switch (ghosts[i].spectral_power) {
                case 1:
                    printf("It whispers secrets...\n");
                    break;
                case 2:
                    printf("It moves objects...\n");
                    break;
                case 3:
                    printf("It brings illusions...\n");
                    break;
            }
        }
    }
}

int main() {
    int room_num;

    printf("Enter the room number:");
    scanf("%d", &room_num);

    haunt_house(room_num);

    return 0;
}