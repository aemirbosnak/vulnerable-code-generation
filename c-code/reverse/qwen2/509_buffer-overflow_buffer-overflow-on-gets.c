#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    int year, month, day;
    char code[100];
    char type[50];
    int strength;

    printf("Enter your name: ");
    gets(name);
    printf("Enter the date (YYYY MM DD): ");
    scanf("%d %d %d", &year, &month, &day);
    if (year < 2020 || year > 2025) {
        printf("Invalid date. Probability calculation aborted.\n");
        return 1;
    }
    printf("Enter the secret code: ");
    gets(code);
    printf("Enter the alien type: ");
    gets(type);
    printf("Enter the strength of the aliens: ");
    scanf("%d", &strength);

    float probability = 0.0;
    if (strcmp(type, "Klingon") == 0 && strength > 1000) {
        probability += 0.3;
    }
    if (strcmp(type, "Romulan") == 0 && strcmp(code, "Qo'noS") == 0) {
        probability += 0.2;
    }
    if (day == 25 && month == 12) {
        probability += 0.1;
    }

    printf("The probability of an alien invasion is %.2f\n", probability);

    return 0;
}
