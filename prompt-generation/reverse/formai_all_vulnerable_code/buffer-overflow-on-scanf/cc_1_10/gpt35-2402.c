//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Function to generate random number within a range
int get_random(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    printf("Welcome to Procedural Space Adventure!\n");

    // Initializing variables
    int fuel_level = 100, distance = 0, aliens_defeated = 0;
    char command;

    // Game loop
    while (1) {
        printf("\nYour ship is currently %d miles from Earth.\n", distance);
        printf("Fuel level: %d%%\n", fuel_level);
        printf("Aliens defeated: %d\n", aliens_defeated);

        printf("Enter a command: ");
        scanf(" %c", &command);

        // Movement commands
        if (command == 'w') {
            int move_distance = get_random(1, 10);
            printf("You moved forward by %d miles.\n", move_distance);
            distance += move_distance;

            // Running out of fuel
            fuel_level -= get_random(5, 10);
            if (fuel_level <= 0) {
                printf("You have run out of fuel and your ship has exploded!\n");
                break;
            }
        } else if (command == 's') {
            int move_distance = get_random(1, 5);
            printf("You moved backward by %d miles.\n", move_distance);
            distance -= move_distance;

            // Running into an asteroid field
            if (get_random(1, 10) <= 3) {
                printf("You have flown into an asteroid field and your ship has been damaged!\n");
                fuel_level -= get_random(10, 20);
                if (fuel_level <= 0) {
                    printf("You have run out of fuel and your ship has exploded!\n");
                    break;
                }
            }
        } else if (command == 'a') {
            int move_distance = get_random(1, 3);
            printf("You moved left by %d miles.\n", move_distance);
            distance -= move_distance;

            // Finding a fuel depot
            if (get_random(1, 10) <= 3) {
                printf("You have discovered a fuel depot and refueled your ship!\n");
                fuel_level += get_random(20, 30);
                if (fuel_level > 100) {
                    fuel_level = 100;
                }
            }
        } else if (command == 'd') {
            int move_distance = get_random(1, 3);
            printf("You moved right by %d miles.\n", move_distance);
            distance += move_distance;

            // Encountering alien spaceship
            if (get_random(1, 10) <= 3) {
                printf("You have encountered an alien spaceship!\n");
                int alien_strength = get_random(50, 100);
                int your_strength = get_random(50, 100);
                if (your_strength >= alien_strength) {
                    printf("You have defeated the alien spaceship!\n");
                    aliens_defeated++;
                } else {
                    printf("Your ship has been destroyed by the alien spaceship!\n");
                    break;
                }
            }
        } else {
            printf("Invalid command. Please try again.\n");
        }

        // Winning the game
        if (distance >= 100) {
            printf("Congratulations, you have successfully reached your destination!\n");
            printf("Distance travelled: %d miles\n", distance);
            printf("Aliens defeated: %d\n", aliens_defeated);
            break;
        }
    }

    return 0;
}