#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[20];
    char date[11];
    int secret_code;
    char alien_type;
    int alien_strength;

    // Get user input
    printf("Enter your name: ");
    gets(name);

    printf("Enter the date (YYYY-MM-DD): ");
    gets(date);

    printf("Enter your secret code: ");
    scanf("%d", &secret_code);

    printf("Enter the alien type (A, B, C): ");
    scanf(" %c", &alien_type);

    printf("Enter the alien strength (1-10): ");
    scanf("%d", &alien_strength);

    // Calculate probability of alien invasion
    int probability = 0;
    if (date >= "2020-01-01" && date <= "2025-12-31")
    {
        if (secret_code % 3 == 0)
        {
            probability = alien_strength * 2;
        }
        else
        {
            probability = alien_strength / 2;
        }
    }

    // Print the probability
    printf("The probability of an alien invasion is: %.2f%%", probability);

    return 0;
}
