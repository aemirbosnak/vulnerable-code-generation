#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
    char name[50];
    int day, month, year;
    char code[20];
    char type[20];
    int strength;

    printf("Enter your name: ");
    gets(name);
    printf("Enter the date (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);
    getchar();
    printf("Enter the secret code: ");
    gets(code);
    printf("Enter the alien type: ");
    gets(type);
    printf("Enter the strength of the aliens: ");
    scanf("%d", &strength);

    int probability = 0;

    if (strcmp(name, "Dr. Smith") == 0) {
        probability += 10;
    }
    if (day == 1 && month == 1 && year == 2023) {
        probability += 5;
    }
    if (strcmp(code, "Xylophone") == 0) {
        probability += 8;
    }
    if (strcmp(type, "Klingon") == 0) {
        probability += 7;
    }
    if (strength > 1000) {
        probability += 6;
    }

    if (probability >= 30) {
        printf("The probability of an alien invasion is high.\n");
    } else {
        printf("The probability of an alien invasion is low.\n");
    }

    return 0;
}
