//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    char unit[20];
    float conversion_factor;
} Unit;

Unit units[] = {
    {"Miles", 0.000189375},
    {"Kilometers", 1.60934},
    {"Pounds", 0.453592},
    {"Kilograms", 2.20462},
    {"Gallons", 3.78541},
    {"Liters", 0.264172},
    {"Fahrenheit", 1.8},
    {"Celsius", 1.0},
    {"Inches", 0.0254},
    {"Centimeters", 0.01},
    {"Seconds", 1.0}
};

void print_menu() {
    printf("\nUNIT CONVERTER MENU\n");
    printf("--------------------\n");
    printf("1. Miles to Kilometers\n");
    printf("2. Kilometers to Miles\n");
    printf("3. Pounds to Kilograms\n");
    printf("4. Kilograms to Pounds\n");
    printf("5. Gallons to Liters\n");
    printf("6. Liters to Gallons\n");
    printf("7. Fahrenheit to Celsius\n");
    printf("8. Celsius to Fahrenheit\n");
    printf("9. Inches to Centimeters\n");
    printf("10. Centimeters to Inches\n");
    printf("11. Seconds to minutes\n");
    printf("12. minutes to Seconds\n");
    printf("13. Exit\n");
}

int main() {
    int choice, source_index, target_index;
    float value;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 13) {
            printf("\nEnter the value to be converted: ");
            scanf("%f", &value);

            if (choice < 7) {
                source_index = choice - 1;
                target_index = 11;
            } else {
                source_index = 11;
                target_index = choice - 6;
            }

            printf("%.2f %s is equal to %.2f %s\n", value, units[source_index].unit, value * units[source_index].conversion_factor * units[target_index].conversion_factor, units[target_index].unit);
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}