//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunted_house(int spooky_level) {
    int i, j;
    char sound[10] = {"Boo!"};
    time_t t;

    // Spooky sound effects
    switch (spooky_level) {
        case 1:
            sound[0] = 'C';
            break;
        case 2:
            sound[0] = 'H';
            break;
        case 3:
            sound[0] = 'M';
            break;
    }

    // Flashing lights
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("\n");
            sleep(1);
            printf("%c", 247);
            sleep(1);
        }
    }

    // Ghostly whispers
    t = time(NULL);
    while (time(NULL) - t < 3) {
        printf("Shhh... hear the voices...\n");
        sleep(rand() % 2);
    }

    // Spooky music
    system("play spooky_music.wav");

    // Final scream
    printf("%s\n", sound);
}

int main() {
    haunted_house(3);
    return 0;
}