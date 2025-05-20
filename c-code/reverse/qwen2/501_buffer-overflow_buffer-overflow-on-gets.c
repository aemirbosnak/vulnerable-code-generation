#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    char name[100], date[20], alienType[50];
    int strength;
    long code;

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter the date: ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = '\0';

    printf("Enter the alien type: ");
    fgets(alienType, sizeof(alienType), stdin);
    alienType[strcspn(alienType, "\n")] = '\0';

    printf("Enter the strength of the aliens: ");
    scanf("%d", &strength);

    printf("Enter the top-secret code: ");
    scanf("%ld", &code);

    int randomValue = rand() % 101; // Generates a random number between 0 and 100

    if (randomValue <= strength && code == 12345) {
        printf("The probability of an alien invasion is high.\n");
    } else {
        printf("The probability of an alien invasion is low.\n");
    }

    return 0;
}
