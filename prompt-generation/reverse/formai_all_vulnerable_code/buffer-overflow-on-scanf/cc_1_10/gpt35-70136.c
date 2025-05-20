//FormAI DATASET v1.0 Category: Benchmarking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define MAX_HUNGER 100
#define MAX_ENERGY 100
#define MAX_HAPPINESS 100
#define DECREASE_RATE 10
#define FILL_RATE 20

// Define functions
void print_stats(int hunger, int energy, int happiness);
void decrease_stats(int* hunger, int* energy, int* happiness);
void fill_stats(int* hunger, int* energy, int* happiness);

// Main function
int main() {
    srand(time(NULL));  // Seed random number generator
    int hunger = 50;  // Initialize stats
    int energy = 50;
    int happiness = 50;
    int turns = 0;  // Initialize turn counter

    while (hunger > 0 && energy > 0 && happiness > 0) {  // Game loop
        print_stats(hunger, energy, happiness);  // Print stats
        char action;
        printf("What would you like to do today? (f)eed, (p)lay, (s)leep: ");
        scanf(" %c", &action);  // Get user input

        if (action == 'f') {
            fill_stats(&hunger, &energy, &happiness);  // Feed pet
            printf("Yum! You filled up your pet's stats.\n");
        } else if (action == 'p') {
            decrease_stats(&hunger, &energy, &happiness);  // Play with pet
            printf("Yay! You played with your pet and decreased its stats.\n");
        } else if (action == 's') {
            energy = MAX_ENERGY;  // Put pet to sleep
            printf("Zzz... Your pet is all rested up.\n");
        } else {
            printf("Invalid action.\n");  // Handle invalid input
        }

        turns++;  // Increment turn counter
    }

    printf("Game over! You lasted %d turns.", turns);  // Print final score
    return 0;
}

// Function to print stats
void print_stats(int hunger, int energy, int happiness) {
    printf("Hunger: %d\nEnergy: %d\nHappiness: %d\n", hunger, energy, happiness);
}

// Function to decrease stats
void decrease_stats(int* hunger, int* energy, int* happiness) {
    *hunger -= DECREASE_RATE;
    *energy -= DECREASE_RATE;
    *happiness -= DECREASE_RATE;
    if (*hunger < 0) *hunger = 0;
    if (*energy < 0) *energy = 0;
    if (*happiness < 0) *happiness = 0;
}

// Function to fill stats
void fill_stats(int* hunger, int* energy, int* happiness) {
    *hunger += FILL_RATE;
    *energy += FILL_RATE;
    *happiness += FILL_RATE;
    if (*hunger > MAX_HUNGER) *hunger = MAX_HUNGER;
    if (*energy > MAX_ENERGY) *energy = MAX_ENERGY;
    if (*happiness > MAX_HAPPINESS) *happiness = MAX_HAPPINESS;
}