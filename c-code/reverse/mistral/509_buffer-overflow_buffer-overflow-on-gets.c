#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[100];
    int year, month, day, alienType, strength, secretCode;
    double probability;

    printf("Enter your name: ");
    gets(name);

    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%d%*c%d%*c%d", &year, &month, &day);

    if (year < 2020 || year > 2025) {
        printf("Invalid date. Please enter a date between 2020 and 2025.\n");
        return 1;
    }

    printf("Enter the alien type (1 for Zorgons, 2 for Morglax, 3 for Xenon): ");
    scanf("%d", &alienType);

    printf("Enter the alien strength (1-10): ");
    scanf("%d", &strength);

    printf("Enter the secret code (1234): ");
    scanf("%d", &secretCode);

    if (secretCode != 1234) {
        printf("Invalid secret code.\n");
        return 1;
    }

    if (alienType == 1 && strength > 7) {
        probability = 0.9;
    } else if (alienType == 2 && strength > 5) {
        probability = 0.7;
    } else if (alienType == 3 && strength > 3) {
        probability = 0.3;
    } else {
        probability = 0;
    }

    printf("The probability of an alien invasion is %.2f\n", probability);

    return 0;
}
