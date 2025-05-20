//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: Cryptic
#include <stdio.h>

void intro();
void menu();
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
void conversion(float temperature, char type);

int main() {
    float temperature;
    char type;
    intro();
    
    while (1) {
        menu();
        printf("\nChoose conversion type (C/F): ");
        scanf(" %c", &type);
        
        if (type != 'C' && type != 'F') {
            printf("Invalid choice. Please select C or F.\n");
            continue;
        }

        printf("Enter the temperature to convert: ");
        scanf("%f", &temperature);
        
        conversion(temperature, type);

        printf("\nDo you want to perform another conversion? (y/n): ");
        char again;
        scanf(" %c", &again);
        if (again != 'y') {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
    }
    return 0;
}

void intro() {
    printf("=====================================\n");
    printf("       Temperature Converter         \n");
    printf("       Journey through Celsius       \n");
    printf("       and Fahrenheit realms!       \n");
    printf("=====================================\n");
}

void menu() {
    printf("\nConversion Menu:\n");
    printf("1. Celsius to Fahrenheit (C)\n");
    printf("2. Fahrenheit to Celsius (F)\n");
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 1.8) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) / 1.8;
}

void conversion(float temperature, char type) {
    float result;
    if (type == 'C') {
        result = celsius_to_fahrenheit(temperature);
        printf("Celsius %.2f is Fahrenheit %.2f\n", temperature, result);
    } else {
        result = fahrenheit_to_celsius(temperature);
        printf("Fahrenheit %.2f is Celsius %.2f\n", temperature, result);
    }
    printf("=====================================\n");
}