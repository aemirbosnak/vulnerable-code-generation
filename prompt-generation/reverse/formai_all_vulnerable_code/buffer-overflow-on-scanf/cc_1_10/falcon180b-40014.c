//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

struct Unit {
    char name[MAX_LENGTH];
    double factor;
    double offset;
};

struct Unit units[] = {
    {"Celsius", 1.0, 0.0},
    {"Fahrenheit", 1.8, 32.0},
    {"Kelvin", 1.0, 273.15}
};

int main() {
    int num_units = sizeof(units) / sizeof(units[0]);
    int choice;
    double value, result;
    char input[MAX_LENGTH];

    printf("Temperature Converter\n");
    printf("=====================\n");

    for (int i = 0; i < num_units; i++) {
        printf("%d. %s\n", i + 1, units[i].name);
    }

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    printf("\nEnter the temperature: ");
    scanf("%s", input);

    result = atof(input);

    switch (choice) {
        case 1:
            value = (result - 32) / 1.8;
            printf("%s is %.2f Celsius\n", input, value);
            break;
        case 2:
            value = (result + 32) * 5.0 / 9.0;
            printf("%s is %.2f Celsius\n", input, value);
            break;
        case 3:
            value = result + 273.15;
            printf("%s is %.2f Celsius\n", input, value);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}