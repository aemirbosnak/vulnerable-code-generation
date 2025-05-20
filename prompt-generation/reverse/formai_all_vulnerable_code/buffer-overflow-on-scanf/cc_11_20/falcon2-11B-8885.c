//Falcon2-11B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Location;

Location start_location;
Location current_location;

int main() {
    srand(time(NULL));
    start_location.x = 1;
    start_location.y = 1;
    current_location = start_location;

    int choice;

    printf("Welcome to the Rogue-like Game!n");
    printf("You start at location (%d, %d)\n", start_location.x, start_location.y);
    printf("What would you like to do? (move, attack, or quit)\n");

    while (1) {
        scanf("%d", &choice);

        if (choice == 1) {
            if (current_location.x == 1 && current_location.y == 1) {
                printf("You can't move from the starting location.\n");
            } else {
                int new_x = current_location.x + (rand() % 2);
                int new_y = current_location.y + (rand() % 2);

                Location new_location = {new_x, new_y};

                if (new_location.x > 10 || new_location.y > 10) {
                    printf("You fell off the map.\n");
                } else {
                    current_location = new_location;
                    printf("You moved to location (%d, %d)\n", current_location.x, current_location.y);
                }
            }
        } else if (choice == 2) {
            if (current_location.x == 1 && current_location.y == 1) {
                printf("You can't attack from the starting location.\n");
            } else {
                printf("You attacked the monster at location (%d, %d)\n", current_location.x, current_location.y);
            }
        } else if (choice == 3) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}