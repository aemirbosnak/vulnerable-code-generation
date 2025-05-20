//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int choice;
    int minFuel = 5;
    int maxFuel = 10;
    int fuel = generateRandomNumber(minFuel, maxFuel);
    int distance = generateRandomNumber(50, 500);
    int maxSpeed = 100;
    int speed = 0;
    int time = 0;
    int fuelConsumptionRate = 2;
    int fuelLimit = 30;
    int meteorHit = 0;
    int gameOver = 0;

    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are on a mission to reach the next planet, which is %d km away.\n", distance);

    while (!gameOver) {
        printf("Your current speed is %d km/hr.\n", speed);
        printf("You have %d litres of fuel left.\n", fuel);

        // ask user for action
        printf("What do you want to do?\n");
        printf("1. Accelerate\n");
        printf("2. Decelerate\n");
        printf("3. Refuel\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You accelerated!\n");
                speed += generateRandomNumber(10, 20);
                if (speed > maxSpeed) {
                    speed = maxSpeed;
                }
                break;
            case 2:
                printf("You decelerated!\n");
                speed -= generateRandomNumber(5, 15);
                if (speed < 0) {
                    speed = 0;
                }
                break;
            case 3:
                printf("You refueled!\n");
                fuel += generateRandomNumber(5, 10);
                if (fuel > fuelLimit) {
                    fuel = fuelLimit;
                }
                break;
            case 4:
                printf("You quit the game! Bye!\n");
                gameOver = 1;
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        // update time and distance
        time++;
        distance -= speed;

        // check fuel
        if (fuel < 0) {
            printf("You ran out of fuel! Game over!\n");
            gameOver = 1;
        }
        else {
            fuel -= fuelConsumptionRate * speed;
        }

        // check meteor hits
        if (generateRandomNumber(0, 100) < 10) {
            meteorHit = 1;
        }
        else {
            meteorHit = 0;
        }

        if (meteorHit) {
            printf("Oh no! A meteor hit your spaceship!\n");
            printf("You lost some fuel and time to repair the damage.\n");
            fuel -= generateRandomNumber(5, 10);
            time += generateRandomNumber(1, 5);
        }

        // check distance
        if (distance <= 0) {
            printf("Congratulations! You have reached the planet!\n");
            printf("It took you %d hours and %d litres of fuel.\n", time, fuel);
            gameOver = 1;
        }
    }

    return 0;
}