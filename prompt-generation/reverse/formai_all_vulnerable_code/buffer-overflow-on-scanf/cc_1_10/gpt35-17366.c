//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int aliens_appear = 0; // Probability that aliens will appear

    srand(time(NULL)); // Setting seed for random number generator

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    printf("Please enter the following probabilities between 0-100:\n\n");

    printf("Probability that aliens already exist and are en route to Earth: ");
    int existing_alien_probability;
    scanf("%d", &existing_alien_probability);

    printf("Probability that aliens possess advanced technology: ");
    int tech_probability;
    scanf("%d", &tech_probability);

    printf("Probability that aliens are hostile towards humans: ");
    int hostile_probability;
    scanf("%d", &hostile_probability);

    printf("\nCalculating probability of alien invasion...\n");

    int random_num1 = rand() % 101; // Generating random number between 0-100
    int random_num2 = rand() % 101;
    int random_num3 = rand() % 101;

    int total_probability = existing_alien_probability + tech_probability + hostile_probability;

    if (total_probability >= 200) {
        aliens_appear = 100; // If total probability is greater than or equal to 200, aliens must exist and will appear
    }
    else {
        aliens_appear = random_num1;
    }

    int tech_advantage = random_num2;
    int hostile_factor = random_num3;

    printf("\nAlien Invasion Probability Results:\n\n");

    printf("Probability aliens exist and will appear: %d%%\n", aliens_appear);
    printf("Probability aliens possess advanced technology: %d%%\n", tech_advantage);
    printf("Probability aliens are hostile towards humans: %d%%\n", hostile_factor);

    printf("\nBased on these probabilities, the likelihood of an alien invasion is: ");

    if (aliens_appear > 0 && tech_advantage > 50 && hostile_factor > 50) {
        printf("HIGH\n");
    }
    else if (aliens_appear > 0 && (tech_advantage > 50 || hostile_factor > 50)) {
        printf("MEDIUM\n");
    }
    else {
        printf("LOW\n");
    }

    printf("\nThank you for using the Alien Invasion Probability Calculator. Stay safe!\n");

    return 0;
}