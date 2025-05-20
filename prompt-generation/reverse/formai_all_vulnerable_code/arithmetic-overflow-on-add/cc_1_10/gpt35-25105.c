//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(unsigned int ms) { // function to add delay (used for dramatic purposes)
    clock_t goal = ms + clock();
    while (goal > clock());
}

int main() {
    srand(time(NULL)); // initialize random number generator
    int health = 100; // player's health
    int fuel = 50; // spaceship's fuel level
    int distance = 0; // distance travelled
    int event; // random event generator

    printf("Welcome to the Space Adventure!\n\n");

    while (health > 0 && fuel > 0 && distance < 1000) { // main game loop
        delay(1000); // for dramatic purposes

        printf("Your spaceship is currently %d km from Earth.\n", distance);
        printf("Health: %d%% | Fuel: %d%%\n", health, fuel);

        event = rand() % 3; // generate random event (0, 1, or 2)

        switch (event) {
            case 0:
                printf("Smooth sailing. No unexpected events...\n\n");
                break;
            case 1:
                fuel -= 10; // decrease fuel level
                printf("Uh oh! Your spaceship's fuel level dropped by 10%%...\n\n");
                break;
            case 2:
                health -= 20; // decrease health level
                printf("Warning! Space debris has damaged your spaceship. Health dropped by 20%%...\n\n");
                break;
        }

        distance += 50; // increase distance travelled

        if (distance == 1000) { // reached the destination
            printf("Congratulations! You have reached the target destination successfully!\n");
            break;
        }

        if (health <= 0) { // player loses if health reaches 0 or below
            printf("Game Over! Your spaceship's health has reached critical levels...\n");
            break;
        }

        if (fuel <= 0) { // player loses if fuel runs out
            printf("Game Over! Your spaceship has run out of fuel...\n");
            break;
        }

        printf("Press any key to continue...\n");
        getchar();
    }

    return 0;
}