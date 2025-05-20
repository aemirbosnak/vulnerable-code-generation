//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Constants
#define MAX_HEALTH 100
#define MAX_ENERGY 100
#define MIN_ENERGY 0
#define MAX_FOOD 10
#define MIN_FOOD 0
#define MAX_WATER 10
#define MIN_WATER 0
#define ENERGY_LOSS_RATE 1
#define HEALTH_LOSS_RATE 2
#define FOOD_LOSS_RATE 1
#define WATER_LOSS_RATE 1
#define HEALTH_GAIN_RATE 5
#define ENERGY_GAIN_RATE 10

// Global variables
int health = MAX_HEALTH;
int energy = MAX_ENERGY;
int food = MAX_FOOD;
int water = MAX_WATER;
int day = 1;

// Function prototypes
void printStatus();
void spendEnergy(int);
void loseHealth(int);
void eatFood(int);
void drinkWater(int);
void nextDay();

int main() {
    srand(time(NULL));
    printf("Welcome to the post-apocalyptic survival game!\n");
    while (health > 0) {
        printStatus();
        printf("What would you like to do?\n");
        printf("1. Rest\n");
        printf("2. Scavenge for food and water\n");
        printf("3. Eat food\n");
        printf("4. Drink water\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                spendEnergy(20);
                printf("You rested and regained some energy.\n");
                break;
            case 2:
                loseHealth(10);
                printf("You went scavenging and got injured.\n");
                int foodFound = rand() % (MAX_FOOD - MIN_FOOD + 1) + MIN_FOOD;
                int waterFound = rand() % (MAX_WATER - MIN_WATER + 1) + MIN_WATER;
                printf("You found %d food and %d water.\n", foodFound, waterFound);
                food += foodFound;
                water += waterFound;
                break;
            case 3:
                if (food > 0) {
                    eatFood(1);
                    printf("You ate some food and regained some health.\n");
                } else {
                    printf("You don't have any food!\n");
                }
                break;
            case 4:
                if (water > 0) {
                    drinkWater(1);
                    printf("You drank some water and regained some energy.\n");
                } else {
                    printf("You don't have any water!\n");
                }
                break;
            default:
                printf("Invalid choice!\n");
        }
        nextDay();
    }
    printf("Game over! You survived for %d days.\n", day - 1);
    return 0;
}

void printStatus() {
    printf("Day: %d\n", day);
    printf("Health: %d\n", health);
    printf("Energy: %d\n", energy);
    printf("Food: %d\n", food);
    printf("Water: %d\n", water);
}

void spendEnergy(int amount) {
    energy -= amount;
    if (energy < MIN_ENERGY) {
        energy = MIN_ENERGY;
        loseHealth(HEALTH_LOSS_RATE);
    }
}

void loseHealth(int amount) {
    health -= amount;
    if (health < 0) {
        health = 0;
    }
}

void eatFood(int amount) {
    food -= amount;
    if (food < MIN_FOOD) {
        food = MIN_FOOD;
    }
    health += HEALTH_GAIN_RATE;
    if (health > MAX_HEALTH) {
        health = MAX_HEALTH;
    }
}

void drinkWater(int amount) {
    water -= amount;
    if (water < MIN_WATER) {
        water = MIN_WATER;
    }
    energy += ENERGY_GAIN_RATE;
    if (energy > MAX_ENERGY) {
        energy = MAX_ENERGY;
    }
}

void nextDay() {
    energy -= ENERGY_LOSS_RATE;
    if (energy < MIN_ENERGY) {
        energy = MIN_ENERGY;
        loseHealth(HEALTH_LOSS_RATE);
    }
    food -= FOOD_LOSS_RATE;
    if (food < MIN_FOOD) {
        food = MIN_FOOD;
        loseHealth(HEALTH_LOSS_RATE);
    }
    water -= WATER_LOSS_RATE;
    if (water < MIN_WATER) {
        water = MIN_WATER;
        loseHealth(HEALTH_LOSS_RATE);
    }
    day++;
    usleep(500000);
}