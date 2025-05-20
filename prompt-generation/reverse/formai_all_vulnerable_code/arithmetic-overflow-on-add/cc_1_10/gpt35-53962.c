//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ASTEROIDS 10
#define MAX_FUEL 1000

int playerFuel = MAX_FUEL;
int playerMoney = 0;
int playerLocation = 0;
int asteroidLocations[MAX_ASTEROIDS];

void generateAsteroids() {
    srand((unsigned) time(NULL));
    int count = 0;
    while (count < MAX_ASTEROIDS) {
        int location = rand() % 100;
        if (location != playerLocation) {
            asteroidLocations[count] = location;
            count++;
        }
    }
}

void movePlayer(int distance) {
    playerLocation += distance;
    playerFuel -= distance;
}

void collectMoney() {
    int money = rand() % 100;
    playerMoney += money;
    printf("\nYou collected %d money from an asteroid!\n", money);
}

int main() {

    generateAsteroids();

    printf("***SPACESHIP ADVENTURE***\n\n");
    printf("You are on a mission to collect as much money as possible by exploring asteroids in space.\n");
    printf("You have 1000 units of fuel, and each unit allows you to travel one unit of distance.\n");
    printf("Be careful, crashing into an asteroid will cause you to lose all of your money!\n\n");

    while (playerFuel > 0) {
        printf("Current location: %d. Fuel remaining: %d units. Money collected: %d\n", playerLocation, playerFuel, playerMoney);
        printf("Enter the distance you want to travel (maximum %d): ", playerFuel);
        int distance;
        scanf("%d", &distance);
        if (distance <= playerFuel) {
            movePlayer(distance);
            for (int i = 0; i < MAX_ASTEROIDS; i++) {
                if (asteroidLocations[i] == playerLocation) {
                    printf("\nOh no! You crashed into an asteroid and lost all of your money.\n");
                    playerMoney = 0;
                    break;
                }
            }
            if (playerLocation == 100) {
                printf("\nCongratulations! You made it to the end of your journey with %d money.\n", playerMoney);
                break;
            }
            if (playerLocation == asteroidLocations[0]) {
                collectMoney();
            }
        } else {
            printf("You don't have enough fuel to travel that distance. Please enter a smaller distance.\n");
        }
    }

    printf("\nGAME OVER\n");

    return 0;
}