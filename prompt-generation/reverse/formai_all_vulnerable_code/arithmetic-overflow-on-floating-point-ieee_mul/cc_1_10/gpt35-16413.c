//FormAI DATASET v1.0 Category: Unit converter ; Style: careful
#include <stdio.h>

int menu();
double convert(int choice);

int main() {
    int choice;
    double result;

    printf("*** UNIT CONVERTER ***\n");
    choice = menu();

    result = convert(choice);
    printf("Result: %.2lf\n", result);

    return 0;
}

int menu() {
    int choice;

    printf("Select conversion type:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
    printf("5. Pounds to Kilograms\n");
    printf("6. Kilograms to Pounds\n");
    printf(">> ");
    scanf("%d", &choice);

    return choice;
}

double convert(int choice) {
    double input, output;

    switch(choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%lf", &input);
            output = (input * 9/5) + 32;
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%lf", &input);
            output = (input - 32) * 5/9;
            break;
        case 3:
            printf("Enter distance in Kilometers: ");
            scanf("%lf", &input);
            output = input * 0.621371;
            break;
        case 4:
            printf("Enter distance in Miles: ");
            scanf("%lf", &input);
            output = input * 1.60934;
            break;
        case 5:
            printf("Enter weight in Pounds: ");
            scanf("%lf", &input);
            output = input * 0.453592;
            break;
        case 6:
            printf("Enter weight in Kilograms: ");
            scanf("%lf", &input);
            output = input * 2.20462;
            break;
        default:
            printf("Invalid choice.\n");
            output = -1;
            break;
    }

    return output;
}