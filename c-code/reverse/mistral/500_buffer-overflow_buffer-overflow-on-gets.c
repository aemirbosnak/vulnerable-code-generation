#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    char secretCode[5];
    int date, alienType, strength;

    printf("Enter your name: ");
    gets(name);

    printf("Enter the secret code (4 digits): ");
    scanf("%s", secretCode);

    printf("Enter the date (MM/DD/YYYY): ");
    scanf("%d%*c%d%*c%d", &date, &date, &date);

    printf("Enter the alien type (1: peaceful, 2: aggressive, 3: unknown): ");
    scanf("%d", &alienType);

    printf("Enter the alien strength (1-10): ");
    scanf("%d", &strength);

    int probability = 0;

    if (strcmp(secretCode, "1234") == 0) {
        probability += 10;
    }

    if (date >= 1201 && date <= 1231) {
        probability += 5;
    }

    if (alienType == 1) {
        probability += 20;
    } else if (alienType == 2) {
        probability -= 10;
    } else {
        probability += 5;
    }

    if (strength > 5) {
        probability += 15;
    } else {
        probability -= 5;
    }

    printf("Probability of alien invasion: %d%%\n", probability);

    return 0;
}
