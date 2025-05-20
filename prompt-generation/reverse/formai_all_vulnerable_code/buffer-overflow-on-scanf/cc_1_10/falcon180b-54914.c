//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void print_intro();
int get_user_input();
int calculate_probability(int num_planets, int num_civilizations);
void print_result(int probability);

int main() {
    srand(time(NULL)); // Seed the random number generator with current time
    print_intro();
    int num_planets = get_user_input();
    int num_civilizations = get_user_input();
    int probability = calculate_probability(num_planets, num_civilizations);
    print_result(probability);
    return 0;
}

void print_intro() {
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("This program will help you determine the probability of an alien invasion based on the number of planets and civilizations in the universe.\n");
    printf("Please enter the number of planets and civilizations when prompted.\n");
}

int get_user_input() {
    int input;
    printf("Enter the number of planets: ");
    scanf("%d", &input);
    printf("Enter the number of civilizations: ");
    scanf("%d", &input);
    return input;
}

int calculate_probability(int num_planets, int num_civilizations) {
    int probability = 0;
    int i;
    for (i = 0; i < num_planets; i++) {
        if (rand() % 2 == 1) { // Randomly determine if a planet has life
            probability++;
        }
    }
    probability *= num_civilizations; // Multiply by the number of civilizations to get the total probability
    return probability;
}

void print_result(int probability) {
    printf("The probability of an alien invasion is %d%.\n", probability);
}