//Falcon2-11B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_aliens, num_ships;
    int success_rate;
    int current_ship;
    int total_ships_left;
    int total_ships_destroyed;
    int alien_ships_left;
    int alien_ships_destroyed;

    printf("Number of Alien Ships: ");
    scanf("%d", &num_aliens);

    printf("Number of Ships: ");
    scanf("%d", &num_ships);

    srand(time(NULL));

    success_rate = rand() % 100;

    for (current_ship = 1; current_ship <= num_ships; current_ship++) {
        total_ships_left = num_ships - current_ship;
        total_ships_destroyed = 0;

        alien_ships_left = num_aliens - (rand() % num_aliens);
        alien_ships_destroyed = 0;

        printf("Ship %d of %d\n", current_ship, num_ships);

        while (alien_ships_left > 0) {
            if (rand() % 100 <= success_rate) {
                printf("Ship destroyed %d alien ship(s)!\n", current_ship);
                alien_ships_destroyed += 1;
                alien_ships_left -= 1;
            } else {
                printf("Ship failed to destroy any alien ship(s).\n");
            }
        }

        printf("Total ships destroyed: %d\n", total_ships_destroyed);
        printf("Total alien ships destroyed: %d\n", alien_ships_destroyed);

        total_ships_destroyed += alien_ships_destroyed;

        printf("Alien ships left: %d\n", alien_ships_left);

        if (alien_ships_left == 0) {
            break;
        }
    }

    if (alien_ships_left > 0) {
        printf("Alien Invasion Successful!\n");
    } else {
        printf("Alien Invasion Defeated!\n");
    }

    return 0;
}