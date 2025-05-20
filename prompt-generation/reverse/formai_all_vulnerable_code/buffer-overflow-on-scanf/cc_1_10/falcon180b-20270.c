//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: mathematical
#include<stdio.h>
#include<math.h>

int main() {
    double celsius, fahrenheit, kelvin;
    char choice;
    int valid_input = 0;

    printf("Enter temperature value: ");
    scanf("%lf", &celsius);

    while(!valid_input) {
        printf("\nSelect conversion option:\n");
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Celsius to Kelvin\n");
        printf("3. Fahrenheit to Celsius\n");
        printf("4. Fahrenheit to Kelvin\n");
        printf("5. Kelvin to Celsius\n");
        printf("6. Kelvin to Fahrenheit\n");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                fahrenheit = celsius * (9.0/5.0) + 32.0;
                printf("\n%lf degrees Celsius is equal to %lf degrees Fahrenheit.\n", celsius, fahrenheit);
                valid_input = 1;
                break;
            case '2':
                kelvin = celsius + 273.15;
                printf("\n%lf degrees Celsius is equal to %lf Kelvin.\n", celsius, kelvin);
                valid_input = 1;
                break;
            case '3':
                fahrenheit = (celsius * (9.0/5.0)) - 32.0;
                printf("\n%lf degrees Fahrenheit is equal to %lf degrees Celsius.\n", fahrenheit, celsius);
                valid_input = 1;
                break;
            case '4':
                celsius = (fahrenheit - 32.0) * (5.0/9.0);
                printf("\n%lf degrees Fahrenheit is equal to %lf degrees Celsius.\n", fahrenheit, celsius);
                valid_input = 1;
                break;
            case '5':
                celsius = kelvin - 273.15;
                printf("\n%lf Kelvin is equal to %lf degrees Celsius.\n", kelvin, celsius);
                valid_input = 1;
                break;
            case '6':
                fahrenheit = kelvin * (9.0/5.0) - 459.67;
                printf("\n%lf Kelvin is equal to %lf degrees Fahrenheit.\n", kelvin, fahrenheit);
                valid_input = 1;
                break;
            default:
                printf("\nInvalid input. Please try again.\n");
        }
    }

    return 0;
}