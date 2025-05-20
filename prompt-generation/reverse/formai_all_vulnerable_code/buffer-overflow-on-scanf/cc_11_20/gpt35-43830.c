//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // seed random function
    
    // initialize game variables
    int health = 100;
    int fuel = 100;
    int distance = 0;
    int alien_count = 0;
    int asteroid_count = 0;
    int round = 1;
    char choice;
    
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are the captain of a spaceship traveling through deep space.\n");
    printf("Your mission is to reach the other side of the galaxy.\n");
    
    while (health > 0 && fuel > 0 && distance < 1000) {
        printf("------------------------------------------------------------\n");
        printf("Round %d: Distance traveled = %d light years, Health = %d%%, Fuel = %d%%\n", round, distance, health, fuel);
        printf("------------------------------------------------------------\n");
        printf("Select an action: [M]ove forward, [S]can for alien life, [A]void asteroids\n");
        scanf(" %c", &choice); // get user input
        
        // handle user choices
        switch (choice) {
            case 'M':
            case 'm':
                fuel -= rand() % 10 + 5; // use up fuel
                distance += rand() % 25 + 50; // travel random distance
                printf("Traveling through deep space...\n");
                break;
            case 'S':
            case 's':
                health -= rand() % 10 + 5; // expose crew to radiation
                alien_count = rand() % 3 + 1; // find random number of aliens
                printf("Scanning for alien life...\n");
                if (alien_count > 0) {
                    printf("Alien life detected! %d hostile aliens detected. Prepare for battle!\n", alien_count);
                    health -= alien_count * 10; // lose health in battle
                    if (health <= 0) {
                        printf("Your spaceship was destroyed by the aliens. Game over!\n");
                        return 0; // end game
                    }
                    printf("You defeated the aliens and continue your journey through space.\n");
                } else {
                    printf("No alien life detected. Continue your journey through space.\n");
                }
                break;
            case 'A':
            case 'a':
                fuel -= rand() % 10 + 5; // use up fuel
                asteroid_count = rand() % 3 + 1; // find random number of asteroids
                printf("Avoiding asteroids...\n");
                if (asteroid_count > 0) {
                    printf("%d asteroids detected! Maneuvering through them...\n", asteroid_count);
                    health -= asteroid_count * 5; // lose health in asteroid field
                    if (health <= 0) {
                        printf("Your spaceship was destroyed in an asteroid field. Game over!\n");
                        return 0; // end game
                    }
                    printf("You made it safely through the asteroid field and continue your journey through space.\n");
                } else {
                    printf("No asteroids detected. Continue your journey through space.\n");
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        
        // handle end of round
        if (distance >= 1000) {
            printf("Congratulations! You have successfully completed your journey through space.\n");
        } else if (fuel <= 0) {
            printf("Your spaceship has run out of fuel. Game over!\n");
            return 0; // end game
        }
        
        round++; // increment round number
    }
    
    return 0;
}