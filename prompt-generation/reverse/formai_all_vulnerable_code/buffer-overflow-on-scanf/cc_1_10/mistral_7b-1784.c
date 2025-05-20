//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>

void convert_f_to_c(float fahrenheit) {
    float celsius;

    celsius = (fahrenheit - 32.0) * 5.0 / 9.0;
    printf("%.2f°F is equivalent to %.2f°C.\n", fahrenheit, celsius);
}

void convert_c_to_f(float celsius) {
    float fahrenheit;

    fahrenheit = celsius * 9.0 / 5.0 + 32.0;
    printf("%.2f°C is equivalent to %.2f°F.\n", celsius, fahrenheit);
}

int main() {
    float temperature, user_choice;
    char unit;

    printf("Welcome to Temperature Converter!\n");
    printf("Press 1 to convert from Fahrenheit to Celsius.\n");
    printf("Press 2 to convert from Celsius to Fahrenheit.\n");
    printf("Enter your choice: ");
    scanf("%d", &user_choice);

    printf("Enter temperature: ");
    scanf("%c", &unit);
    if (unit != 'F' && unit != 'C') {
        printf("Invalid temperature unit.\n");
        return 1;
    }

    if (user_choice == 1) {
        if (unit == 'F') {
            scanf("%f", &temperature);
            convert_f_to_c(temperature);
        } else {
            scanf("%f", &temperature);
            printf("Invalid temperature value in Celsius.\n");
            return 1;
        }
    } else if (user_choice == 2) {
        if (unit == 'F') {
            scanf("%f", &temperature);
            convert_c_to_f(temperature);
        } else {
            scanf("%f", &temperature);
            convert_c_to_f(-(temperature * 1.8) + 32.0);
        }
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    return 0;
}