//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_FITNESS 1000
#define MIN_FITNESS 0
#define INITIAL_FITNESS 500
#define FITNESS_INCREMENT 10
#define FITNESS_DECREMENT 20
#define FOOD_INCREMENT 50
#define FOOD_DECREMENT 100
#define WATER_INCREMENT 25
#define WATER_DECREMENT 50
#define SLEEP_INCREMENT 75
#define SLEEP_DECREMENT 150

struct fitness_tracker {
    int fitness;
    int food;
    int water;
    int sleep;
};

void init_fitness_tracker(struct fitness_tracker *ft) {
    ft->fitness = INITIAL_FITNESS;
    ft->food = 0;
    ft->water = 0;
    ft->sleep = 0;
}

void print_fitness_tracker(struct fitness_tracker ft) {
    printf("Fitness: %d\n", ft.fitness);
    printf("Food: %d\n", ft.food);
    printf("Water: %d\n", ft.water);
    printf("Sleep: %d\n", ft.sleep);
}

int main() {
    struct fitness_tracker player;
    init_fitness_tracker(&player);

    srand(time(NULL));

    int choice;
    do {
        printf("What would you like to do?\n");
        printf("1. Hunt for food\n");
        printf("2. Search for water\n");
        printf("3. Rest\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                player.food += rand() % FOOD_INCREMENT + 1;
                player.fitness += rand() % FITNESS_INCREMENT + 1;
                break;
            case 2:
                player.water += rand() % WATER_INCREMENT + 1;
                player.fitness += rand() % FITNESS_INCREMENT + 1;
                break;
            case 3:
                player.sleep += rand() % SLEEP_INCREMENT + 1;
                player.fitness += rand() % FITNESS_INCREMENT + 1;
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        print_fitness_tracker(player);
    } while(choice!= 4);

    return 0;
}