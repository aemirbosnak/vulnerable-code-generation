//GPT-4o-mini DATASET v1.0 Category: Temperature Converter ; Style: puzzling
#include <stdio.h>

void print_welcome() {
    printf("*************************************\n");
    printf("*                                   *\n");
    printf("*         Welcome to Temp          *\n");
    printf("*         Converter Wizard!        *\n");
    printf("*                                   *\n");
    printf("*************************************\n");
}

void print_menu() {
    printf("\nChoose the conversion option:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
}

float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

void get_celsius_input() {
    float celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    printf("%.2f Celsius is %.2f Fahrenheit\n", celsius, celsius_to_fahrenheit(celsius));
}

void get_fahrenheit_input() {
    float fahrenheit;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    printf("%.2f Fahrenheit is %.2f Celsius\n", fahrenheit, fahrenheit_to_celsius(fahrenheit));
}

int main() {
    int choice;
    
    print_welcome();

    do {
        print_menu();
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                get_celsius_input();
                break;
            case 2:
                get_fahrenheit_input();
                break;
            case 3:
                printf("Exiting the converter. Stay warm or cool!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 3);

    return 0;
}