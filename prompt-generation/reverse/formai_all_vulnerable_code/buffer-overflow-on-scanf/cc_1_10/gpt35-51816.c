//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    printf("Please enter the number of spaceships the aliens have (up to 100): ");
    int num_spaceships;
    scanf("%d", &num_spaceships);

    if (num_spaceships <= 0 || num_spaceships > 100) {
        printf("\nInvalid number of spaceships entered. Please try again.\n");
        return 1;
    }

    printf("\nPlease enter the number of weapons the aliens have (up to 100): ");
    int num_weapons;
    scanf("%d", &num_weapons);

    if (num_weapons <= 0 || num_weapons > 100) {
        printf("\nInvalid number of weapons entered. Please try again.\n");
        return 1;
    }

    printf("\nPlease enter the number of days until the invasion (up to 30): ");
    int num_days;
    scanf("%d", &num_days);

    if (num_days <= 0 || num_days > 30) {
        printf("\nInvalid number of days entered. Please try again.\n");
        return 1;
    }

    int spaceship_roll = rand() % 100 + 1;
    int weapon_roll = rand() % 100 + 1;
    int days_roll = rand() % 30 + 1;

    float probability = ((float) num_spaceships/spaceship_roll) * ((float) num_weapons/weapon_roll) * ((float) num_days/days_roll) * 100;

    printf("\nCalculating invasion probability...\n\n");
    printf("Number of spaceships: %d\n", num_spaceships);
    printf("Spaceship roll: %d/100\n", spaceship_roll);
    printf("Number of weapons: %d\n", num_weapons);
    printf("Weapon roll: %d/100\n", weapon_roll);
    printf("Number of days: %d\n", num_days);
    printf("Days roll: %d/30\n\n", days_roll);
    printf("Probability of invasion: %.2f%%\n", probability);

    return 0;
}