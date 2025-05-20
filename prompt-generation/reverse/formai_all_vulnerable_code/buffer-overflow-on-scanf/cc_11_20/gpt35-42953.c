//FormAI DATASET v1.0 Category: Unit converter ; Style: post-apocalyptic
#include <stdio.h>

int main() {
    float value;
    char from_unit[10], to_unit[10];

    printf("Welcome to the Post-Apocalyptic Unit Converter\n");
    printf("Enter value to convert: ");
    scanf("%f", &value);
    printf("Enter unit to convert from (e.g. mm, cm, m): ");
    scanf("%s", from_unit);
    printf("Enter unit to convert to (e.g. mm, cm, m): ");
    scanf("%s", to_unit);

    if (strcmp(from_unit, "mm") == 0) {
        if (strcmp(to_unit, "mm") == 0) {
            printf("%.2f mm is %.2f mm\n", value, value);
        } else if (strcmp(to_unit, "cm") == 0) {
            printf("%.2f mm is %.2f cm\n", value, value / 10);
        } else if (strcmp(to_unit, "m") == 0) {
            printf("%.2f mm is %.2f m\n", value, value / 1000);
        } else {
            printf("Invalid unit entered\n");
        }
    } else if (strcmp(from_unit, "cm") == 0) {
        if (strcmp(to_unit, "mm") == 0) {
            printf("%.2f cm is %.2f mm\n", value, value * 10);
        } else if (strcmp(to_unit, "cm") == 0) {
            printf("%.2f cm is %.2f cm\n", value, value);
        } else if (strcmp(to_unit, "m") == 0) {
            printf("%.2f cm is %.2f m\n", value, value / 100);
        } else {
            printf("Invalid unit entered\n");
        }
    } else if (strcmp(from_unit, "m") == 0) {
        if (strcmp(to_unit, "mm") == 0) {
            printf("%.2f m is %.2f mm\n", value, value * 1000);
        } else if (strcmp(to_unit, "cm") == 0) {
            printf("%.2f m is %.2f cm\n", value, value * 100);
        } else if (strcmp(to_unit, "m") == 0) {
            printf("%.2f m is %.2f m\n", value, value);
        } else {
            printf("Invalid unit entered\n");
        }
    } else {
        printf("Invalid unit entered\n");
    }

    return 0;
}