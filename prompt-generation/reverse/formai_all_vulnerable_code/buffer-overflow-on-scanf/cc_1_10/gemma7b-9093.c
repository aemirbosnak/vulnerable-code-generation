//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: mathematical
#include <stdlib.h>
#include <time.h>

#define MAX_GHOSTS 10

typedef struct Ghost {
    char name[20];
    int room_num;
    int scare_factor;
} Ghost;

Ghost ghosts[MAX_GHOSTS] = {
    {"Mary", 1, 5},
    {"Jack", 2, 3},
    {"Alice", 3, 4},
    {"Tom", 4, 2},
    {"Sarah", 5, 3},
    {"Peter", 6, 4},
    {"Anna", 7, 2},
    {"John", 8, 3},
    {"Emily", 9, 5},
    {"David", 10, 4}
};

int main() {
    srand(time(NULL));

    int i, r, n, ghosts_num = MAX_GHOSTS;

    printf("Welcome to the Haunted House Simulator!\n");

    printf("Please select a room number: ");
    scanf("%d", &r);

    for (i = 0; i < ghosts_num; i++) {
        if (ghosts[i].room_num == r) {
            printf("Hello, %s. You have entered their room.\n", ghosts[i].name);

            n = rand() % ghosts[i].scare_factor;

            switch (n) {
                case 0:
                    printf("You hear a soft whisper in the hallway.\n");
                    break;
                case 1:
                    printf("A cold wind blows through the room.\n");
                    break;
                case 2:
                    printf("You see a ghostly figure moving in the shadows.\n");
                    break;
                case 3:
                    printf("You hear a scream from the next room.\n");
                    break;
                case 4:
                    printf("You feel a presence watching you.\n");
                    break;
                default:
                    printf("You experience a terrifying sensation.\n");
                    break;
            }
        }
    }

    return 0;
}