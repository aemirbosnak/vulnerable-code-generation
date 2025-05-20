//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random numbers
int random_num(int min, int max) {
    return (rand() % (max - min + 1) + min);
}

int main() {
    // initialize variables
    int asteroid_distance = 500;
    int spaceship_speed = 100;
    int space_duration = 0;
    int asteroids_hit = 0;
    int fuel_level = 100;
    int asteroid_size, asteroid_speed, asteroid_difficulty;
    char play_again = 'y';

    srand(time(0)); // set seed for random number generation

    while (play_again == 'y') { // main game loop
        printf("\nWELCOME TO INTERGALACTIC ASTEROID FIELD!\n");
        printf("Your mission is to navigate through the asteroid field and reach the other side.\n");

        while (asteroid_distance > 0) {
            printf("\nYou are currently %d km away from the end of the asteroid field.\n", asteroid_distance);
            printf("Your fuel level is %d%%.\n", fuel_level);

            // generate asteroid properties
            asteroid_size = random_num(1, 10);
            asteroid_speed = random_num(50, 150);
            if (asteroid_size <= 5) {
                asteroid_difficulty = 1;
            } else if (asteroid_size > 5 && asteroid_size <= 8) {
                asteroid_difficulty = 2;
            } else {
                asteroid_difficulty = 3;
            }

            printf("\nAsteroid incoming!\n");
            printf("Size: %d, Speed: %d, Difficulty: %d\n", asteroid_size, asteroid_speed, asteroid_difficulty);

            // calculate spaceship speed based on asteroid difficulty
            if (asteroid_difficulty == 1) {
                spaceship_speed += 20;
            } else if (asteroid_difficulty == 2) {
                spaceship_speed += 10;
            }

            space_duration = asteroid_distance / spaceship_speed; // calculate travel time
            asteroid_distance -= asteroid_speed * space_duration; // update asteroid distance

            // calculate damage from asteroid collision
            if (asteroid_size <= 5) {
                fuel_level -= 20;
            } else if (asteroid_size > 5 && asteroid_size <= 8) {
                fuel_level -= 40;
                asteroids_hit++;
            } else {
                fuel_level -= 60;
                asteroids_hit++;
                spaceship_speed -= 20;
                printf("Your speed decreased due to a direct collision with a large asteroid!\n");
            }

            // check if game over
            if (fuel_level <= 0) {
                printf("\nYour spaceship ran out of fuel and crashed into an asteroid. GAME OVER.\n");
                break;
            } else if (asteroids_hit >= 3) {
                printf("\nYour spaceship was hit by too many asteroids. GAME OVER.\n");
                break;
            } else if (asteroid_distance <= 0) {
                printf("\nCONGRATULATIONS, you made it through the asteroid field!\n");
                break;
            }
        }

        printf("\nYou hit %d asteroids during your journey.\n", asteroids_hit);
        printf("Would you like to play again? (y/n) ");
        scanf(" %c", &play_again);
    }

    return 0;
}