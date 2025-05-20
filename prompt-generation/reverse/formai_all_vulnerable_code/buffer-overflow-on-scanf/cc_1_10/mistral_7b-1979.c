//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct Temperature {
    float celsius;
    float fahrenheit;
} Temp;

void futuristic_print(const char* message) {
    printf("\033[1;31m[ FutureTech ]\033[0m %s\n", message);
}

void convert_celsius_to_fahrenheit(Temp* temp) {
    temp->fahrenheit = (temp->celsius * 9.0 / 5.0) + 32.0;
}

void convert_fahrenheit_to_celsius(Temp* temp) {
    temp->celsius = (temp->fahrenheit - 32.0) * 5.0 / 9.0;
}

void display_temperature(Temp temp) {
    const char* unit;

    if (temp.celsius == temp.fahrenheit) {
        unit = "°C";
    } else {
        unit = temp.celsius > temp.fahrenheit ? "°F" : "°C";
    }

    futuristic_print("Input Temperature:");
    printf("\033[1;34m[ Input ]\033[0m %0.1f%s\n", temp.celsius, unit);

    temp.celsius = temp.fahrenheit;
    convert_celsius_to_fahrenheit(&temp);

    futuristic_print("Output Temperature:");
    printf("\033[1;31m[ Output ]\033[0m %0.1f%s\n", temp.fahrenheit, unit);
}

int main() {
    Temp temp;
    char input;

    while (1) {
        futuristic_print("Welcome to FutureTech Temperature Converter!");
        printf("\nEnter temperature value in Celsius (C) or Fahrenheit (F) and press Enter: ");
        scanf("%c", &input);

        if (input == 'C' || input == 'c') {
            printf("Enter temperature value in Celsius: ");
            scanf("%f", &temp.celsius);
        } else if (input == 'F' || input == 'f') {
            printf("Enter temperature value in Fahrenheit: ");
            scanf("%f", &temp.fahrenheit);
            convert_fahrenheit_to_celsius(&temp);
        } else {
            printf("Invalid input. Please enter C or F and press Enter.\n");
            continue;
        }

        display_temperature(temp);

        printf("\nDo you want to convert another temperature? (Y/N): ");
        scanf("%c", &input);

        if (input == 'N' || input == 'n') {
            break;
        }
    }

    return 0;
}