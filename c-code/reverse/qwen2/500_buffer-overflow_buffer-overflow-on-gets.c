#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    int day, month, year;
    char code[20];
    char type[50];
    int strength;
    float probability = 0.0;

    printf("Enter your name: ");
    gets(name);
    printf("Enter the date (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);
    printf("Enter the secret code: ");
    scanf("%s", code);
    printf("Enter the alien type: ");
    scanf("%s", type);
    printf("Enter the strength of the aliens: ");
    scanf("%d", &strength);

    if (strcmp(type, "Klingon") == 0) {
        probability += 0.3;
    }
    if (strength > 1000) {
        probability += 0.2;
    }
    if (day == 1 && month == 1) {
        probability += 0.1;
    }
    if (strlen(code) > 10) {
        probability += 0.15;
    }
    if (strcmp(name, "Picard") == 0) {
        probability -= 0.4;
    }

    if (probability > 1.0) {
        probability = 1.0;
    } else if (probability < 0.0) {
        probability = 0.0;
    }

    printf("The probability of an alien invasion is: %.2f\n", probability);

    return 0;
}
