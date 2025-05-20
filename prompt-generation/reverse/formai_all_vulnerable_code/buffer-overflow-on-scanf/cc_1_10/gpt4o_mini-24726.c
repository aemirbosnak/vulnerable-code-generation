//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
    int x;
    int y;
} Position;

void displayPosition(Position pos) {
    printf("The vehicle glides to position (%d, %d) like a whisper on the evening breeze.\n", pos.x, pos.y);
}

void moveNorth(Position *pos) {
    pos->y += 1;
    displayPosition(*pos);
}

void moveSouth(Position *pos) {
    pos->y -= 1;
    displayPosition(*pos);
}

void moveEast(Position *pos) {
    pos->x += 1;
    displayPosition(*pos);
}

void moveWest(Position *pos) {
    pos->x -= 1;
    displayPosition(*pos);
}

void dance(Position *pos) {
    printf("The vehicle begins to dance in the moonlight...\n");
    for (int i = 0; i < 5; i++) {
        moveEast(pos);
        sleep(1);
        moveWest(pos);
        sleep(1);
    }
    printf("The dance has ended, leaving a trace of joy in the meadow.\n");
}

void showMenu() {
    printf("Romantic RC Vehicle Control Menu:\n");
    printf("1. Move North\n");
    printf("2. Move South\n");
    printf("3. Move East\n");
    printf("4. Move West\n");
    printf("5. Dance\n");
    printf("6. Exit\n");
}

int main() {
    Position vehicle = {0, 0};
    int choice;

    printf("As twilight descends, our remote control vehicle awaits your command...\n");

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                moveNorth(&vehicle);
                break;
            case 2:
                moveSouth(&vehicle);
                break;
            case 3:
                moveEast(&vehicle);
                break;
            case 4:
                moveWest(&vehicle);
                break;
            case 5:
                dance(&vehicle);
                break;
            case 6:
                printf("As the stars shimmer, our vehicle returns to rest. Goodnight!\n");
                return 0;
            default:
                printf("A moment of confusion, as the stars twinkle above... Please choose again.\n");
        }

        sleep(1); // A moment to reflect on the beauty of the evening.
    }

    return 0;
}