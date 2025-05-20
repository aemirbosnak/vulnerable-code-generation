#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

int main() {
    char name[MAX_NAME_LENGTH];
    int day, month, year;
    int alienType, alienStrength;
    float probability;

    printf("Enter your name: ");
    gets(name);
    printf("Enter the date (DD MM YYYY): ");
    scanf("%d %d %d", &day, &month, &year);
    printf("Select alien type (1-3): ");
    scanf("%d", &alienType);
    printf("Enter alien strength: ");
    scanf("%d", &alienStrength);

    if (alienType == 1) {
        probability = 0.1 * alienStrength;
    } else if (alienType == 2) {
        probability = 0.2 * alienStrength;
    } else if (alienType == 3) {
        probability = 0.3 * alienStrength;
    } else {
        probability = 0.0;
    }

    printf("Alien invasion probability for %s on %d/%d/%d with type %d and strength %d is %.2f\n", name, day, month, year, alienType, alienStrength, probability);

    return 0;
}
