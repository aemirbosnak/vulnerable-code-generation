//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number
int rand_num() {
    return rand() % 100;
}

// Function to simulate alien invasion
void alien_invasion() {
    printf("The aliens have arrived!\n");
    printf("Their ships are hovering over the city.\n");
    printf("The sky is turning green!\n");
    printf("People are running for their lives!\n");
    printf("The fate of the city is in your hands!\n");
}

// Function to calculate probability of alien invasion
int calculate_probability(int age, int gender, int location) {
    int probability = 0;

    // Calculate probability based on age
    if (age < 20) {
        probability += 20;
    } else if (age >= 20 && age < 30) {
        probability += 15;
    } else if (age >= 30 && age < 40) {
        probability += 10;
    } else if (age >= 40 && age < 50) {
        probability += 5;
    } else if (age >= 50) {
        probability -= 10;
    }

    // Calculate probability based on gender
    if (gender == 1) {
        probability += 10;
    } else if (gender == 2) {
        probability -= 10;
    }

    // Calculate probability based on location
    if (location == 1) {
        probability += 20;
    } else if (location == 2) {
        probability += 15;
    } else if (location == 3) {
        probability -= 5;
    } else if (location == 4) {
        probability -= 10;
    }

    return probability;
}

int main() {
    int age, gender, location, probability;
    srand(time(NULL));

    // Get user input
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your gender (1 for male, 2 for female): ");
    scanf("%d", &gender);

    printf("Enter your location (1 for city, 2 for suburbs, 3 for rural, 4 for wilderness): ");
    scanf("%d", &location);

    // Calculate probability of alien invasion
    probability = calculate_probability(age, gender, location);

    // Simulate alien invasion
    if (probability >= 0) {
        printf("The probability of an alien invasion is %d%%\n", probability);
        printf("You are safe for now.\n");
    } else {
        printf("The probability of an alien invasion is -%d%%\n", probability);
        alien_invasion();
    }

    return 0;
}