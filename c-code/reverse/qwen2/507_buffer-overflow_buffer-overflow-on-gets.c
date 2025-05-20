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

    printf("Enter your name: ");
    gets(name);
    printf("Enter the date (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);
    getchar(); // Consume newline left-over
    printf("Enter the secret code: ");
    gets(code);
    printf("Enter the alien type: ");
    gets(type);
    printf("Enter the strength of the aliens: ");
    scanf("%d", &strength);

    float probability = 0.0;

    if (strcmp(type, "Klingon") == 0) {
        probability += 0.3;
    }
    if (strength > 1000) {
        probability += 0.2;
    }
    if (year > 2020) {
        probability += 0.1;
    }
    if (strcmp(code, "Vulcan") == 0) {
        probability += 0.4;
    }
    if (day == 7 && month == 11) {
        probability += 0.1;
    }

    if (probability >= 0.8) {
        printf("The probability of an alien invasion is very high.\n");
    } else if (probability >= 0.5) {
        printf("The probability of an alien invasion is moderate.\n");
    } else {
        printf("The probability of an alien invasion is low.\n");
    }

    return 0;
}
