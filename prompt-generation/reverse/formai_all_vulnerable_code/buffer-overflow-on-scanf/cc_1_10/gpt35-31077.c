//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// define constants
#define MAX_DISTANCE 1000
#define MAX_RESOURCES 5
#define MAX_ENEMIES 3

// function prototypes
void print_intro();
int get_valid_input(int min, int max);
void generate_resources(int resources[]);
bool encounter_enemy();
void enter_wormhole(int *distance, int *resources);

// main function
int main() {
    srand(time(NULL));  // seed the random number generator
    int distance = 0;  // current distance from Earth
    int resources[MAX_RESOURCES];  // array to store the available resources
    int enemies_encountered = 0;

    // print the game intro
    print_intro();

    // generate initial resources
    generate_resources(resources);

    while (distance < MAX_DISTANCE) {
        int choice = -1;
        printf("\nCurrent distance from Earth: %d\n", distance);
        printf("Resources: ");
        for (int i = 0; i < MAX_RESOURCES; i++) {
            printf("%d ", resources[i]);
        }
        printf("\n");

        // show available options
        printf("Select an action:\n");
        printf("1. Travel a certain distance\n");
        printf("2. Check resources\n");
        printf("3. Enter a wormhole\n");
        printf("Choice: ");
        choice = get_valid_input(1, 3);

        if (choice == 1) {
            int distance_to_travel = 0;
            printf("\nEnter distance to travel: ");
            distance_to_travel = get_valid_input(1, MAX_DISTANCE - distance);
            distance += distance_to_travel;
            printf("\nTraveled %d distance.\n", distance_to_travel);
            bool enemy_encountered = encounter_enemy();
            if (enemy_encountered) {
                printf("\nYou encountered an enemy! Prepare for battle.\n");
                enemies_encountered++;
                if (enemies_encountered > MAX_ENEMIES) {
                    printf("\nYou have encountered too many enemies. Game over.\n");
                    break;
                }
                // Simulate battle here
            }
        } else if (choice == 2) {
            printf("\nResources: ");
            for (int i = 0; i < MAX_RESOURCES; i++) {
                printf("%d ", resources[i]);
            }
            printf("\n");
        } else if (choice == 3) {
            enter_wormhole(&distance, resources);
        }
    }

    printf("\nCongratulations! You have successfully traveled %d distance from Earth and returned safely.\n", distance);
    return 0;
}

// function definitions

void print_intro() {
    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are on a peaceful mission to explore the vast reaches of space and collect resources for Earth.\n");
    printf("Your mission is to travel as far from Earth as possible and return safely.\n\n");
}

int get_valid_input(int min, int max) {
    int choice = -1;
    while (choice < min || choice > max) {
        scanf("%d", &choice);
        if (choice < min || choice > max) {
            printf("\nInvalid choice. Please choose again: ");
        }
    }
    return choice;
}

void generate_resources(int resources[]) {
    for (int i = 0; i < MAX_RESOURCES; i++) {
        resources[i] = rand() % 11; // assign a random value from 0 to 10
    }
}

bool encounter_enemy() {
    int chance = rand() % 11;
    if (chance >= 8) {
        return true;
    }
    return false;
}

void enter_wormhole(int *distance, int *resources) {
    printf("\nEntering a wormhole...\n");
    *distance = rand() % MAX_DISTANCE;
    printf("Congratulations! You have traveled %d distance teleporting through the wormhole.\n", *distance);
    for (int i = 0; i < MAX_RESOURCES; i++) {
        resources[i] = rand() % 11; // assign a new random value from 0 to 10
    }
}