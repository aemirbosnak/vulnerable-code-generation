#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[20];
    int date, secret_code, alien_type, alien_strength;
    float probability;

    // Get user input
    printf("Enter your name: ");
    gets(name);

    printf("Enter the date (MM/DD): ");
    scanf("%d", &date);

    printf("Enter your secret code: ");
    scanf("%d", &secret_code);

    printf("Select alien type (1 for small, 2 for medium, 3 for large): ");
    scanf("%d", &alien_type);

    printf("Enter alien strength (1-10): ");
    scanf("%d", &alien_strength);

    // Calculate probability
    if (date >= 10 && secret_code % 3 == 0) {
        probability = 0.8;
    } else if (alien_type == 2 && alien_strength > 5) {
        probability = 0.6;
    } else if (name[0] == 'A' && alien_type == 1) {
        probability = 0.4;
    } else {
        probability = 0.2;
    }

    // Display probability
    printf("Your probability of alien invasion is: %.2f", probability);

    return 0;
}
