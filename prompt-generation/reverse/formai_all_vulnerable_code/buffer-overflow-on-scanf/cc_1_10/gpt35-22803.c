//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Cryptic
# include <stdio.h>
# include <stdlib.h>

/* Define constants */
#define CELSIUS 'C'
#define FAHRENHEIT 'F'

/* Function prototypes */
void print_menu();
double celsius_to_fahrenheit(double celsius);
double fahrenheit_to_celsius(double fahrenheit);
double get_temperature();
char get_scale();
void clear_screen();


int main() {
    char input;
    double temperature, result;
    clear_screen();

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%c", &input);

        switch (input) {
            case '1':
                temperature = get_temperature();
                result = celsius_to_fahrenheit(temperature);
                printf("%.2fC is equal to %.2fF\n", temperature, result);
                break;
            case '2':
                temperature = get_temperature();
                result = fahrenheit_to_celsius(temperature);
                printf("%.2fF is equal to %.2fC\n", temperature, result);
                break;
            case '3':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }

        clear_screen();

    } while (input != '3');

    return 0;
}

void print_menu() {
    printf("Temperature Converter\n");
    printf("----------------------\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Quit\n");
}

double celsius_to_fahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double fahrenheit_to_celsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double get_temperature() {
    double temperature;
    printf("Enter temperature: ");
    scanf("%lf", &temperature);

    return temperature;
}

char get_scale() {
    char scale;
    do {
        printf("Enter scale (C/F): ");
    } while (scanf("%c", &scale) == 0 && scale != CELSIUS && scale != FAHRENHEIT);

    return scale;
}

void clear_screen() {
    system("cls || clear");
}