//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get a random number within a range
int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {

    // Seed the random number generator with current timestamp
    srand(time(NULL));

    // Initializing game variables
    int fuel = 100;
    int x = 0;
    int y = 0;
    int z = 0;
    int distance_left = 1000;

    printf("Welcome to our space adventure game!\n");
    printf("You are currently stranded in space with limited fuel and you need to reach your base which is 1000 km away.\n");
    printf("Good Luck!\n");

    // Game loop
    while (distance_left > 0 && fuel > 0) {

        printf("--------------------------------------------------------\n");

        // Getting user input
        char direction;
        printf("Enter the direction you want to move (N, S, E, W): ");
        scanf(" %c", &direction);

        // Random events can occur during the spaceship journey
        int event = getRandomNumber(1, 3);

        switch(event) {
            case 1: // Nothing Happened
                printf("You looked out the window and nothing interesting happened.\n");
                break;
            case 2: // Asteroid attack
                printf("Oh no, an asteroid attack has damaged your spaceship!\n");
                int damage = getRandomNumber(10, 20);
                fuel -= damage;
                printf("You lost %d fuel during the attack.\n", damage);
                break;
            case 3: // Fuel tank leak
                printf("Uh oh, your fuel tank is leaking!\n");
                int leak = getRandomNumber(5, 15);
                fuel -= leak;
                printf("You lost %d fuel due to the leak.\n", leak);
                break;
        }

        // Moving the spaceship to the desired direction
        switch(direction) {
            case 'N':
                y += getRandomNumber(1, 10);
                break;
            case 'S':
                y -= getRandomNumber(1, 10);
                break;
            case 'E':
                x += getRandomNumber(1, 10);
                break;
            case 'W':
                x -= getRandomNumber(1, 10);
                break;
        }

        // Updating distance left
        distance_left = abs(x) + abs(y) + abs(z);
        printf("Distance left to reach the base: %d km\n", distance_left);

        // Printing spaceship location
        printf("Your spaceship is at location (%d, %d, %d)\n", x, y, z);

        // Printing fuel remaining
        printf("Fuel remaining: %d\n", fuel);
    }

    // Checking if the player won or lost
    if (distance_left == 0) {
        printf("Congratulations! You have successfully reached your base!\n");
    } else {
        printf("Oh no! You ran out of fuel and lost the game.\n");
    }

    printf("Thanks for playing our space adventure game!\n");
    return 0;
}