//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

typedef enum { FAHRENHEIT, CELSIUS } TemperatureUnit;

struct TemperatureConversion {
    float value;
    TemperatureUnit unit;
};

void print_temperature(struct TemperatureConversion temp) {
    switch (temp.unit) {
        case FAHRENHEIT:
            printf("%.2f°F\n", temp.value);
            break;
        case CELSIUS:
            printf("%.2f°C\n", temp.value);
            break;
        default:
            printf("Invalid Temperature Unit!\n");
            exit(EXIT_FAILURE);
    }
}

void convert_fahrenheit_to_celsius(struct TemperatureConversion *temp) {
    (*temp).value = ((*temp).value - 32) * 5.0/9.0;
    (*temp).unit = CELSIUS;
}

void convert_celsius_to_fahrenheit(struct TemperatureConversion *temp) {
    (*temp).value = (*temp).value * 9.0/5.0 + 32;
    (*temp).unit = FAHRENHEIT;
}

int main() {
    int user_choice;
    struct TemperatureConversion user_temp, result;

    printf("\n\t===°TEMPERATURE CONVERTER===°===\n");
    printf("\t1. Convert Fahrenheit to Celsius\n");
    printf("\t2. Convert Celsius to Fahrenheit\n");
    printf("\tChoose an option: ");
    scanf("%d", &user_choice);

    printf("\nEnter Temperature: ");
    scanf("%f", &user_temp.value);
    user_temp.unit = FAHRENHEIT;

    if (user_choice == 1) {
        convert_fahrenheit_to_celsius(&user_temp);
        print_temperature(user_temp);
    } else if (user_choice == 2) {
        convert_celsius_to_fahrenheit(&user_temp);
        print_temperature(user_temp);
    } else {
        printf("\nInvalid choice! Exiting...\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}