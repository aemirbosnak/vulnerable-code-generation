//FormAI DATASET v1.0 Category: Unit converter ; Style: sophisticated
#include <stdio.h>

void print_menu();
double convert_length(double, int, int);
double convert_temperature(double, int, int);
double convert_weight(double, int, int);

int main() {

    int choice, from_unit, to_unit;
    double value, result;

    printf("Welcome to the Unit Converter App!\n");

    do {
        print_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the length value: ");
                scanf("%lf", &value);

                printf("\nChoose the conversion unit:\n");
                printf("1. meters\n");
                printf("2. feet\n");
                printf("3. inches\n");

                printf("\nConvert from: ");
                scanf("%d", &from_unit);

                printf("Convert to: ");
                scanf("%d", &to_unit);

                result = convert_length(value, from_unit, to_unit);
                printf("\nResult: %.2lf\n", result);
                break;

            case 2:
                printf("\nEnter the temperature value: ");
                scanf("%lf", &value);

                printf("\nChoose the conversion unit:\n");
                printf("1. Celsius\n");
                printf("2. Fahrenheit\n");

                printf("\nConvert from: ");
                scanf("%d", &from_unit);

                printf("Convert to: ");
                scanf("%d", &to_unit);

                result = convert_temperature(value,from_unit,to_unit);
                printf("\nResult: %.2lf\n", result);
                break;

            case 3:
                printf("\nEnter the weight value: ");
                scanf("%lf", &value);

                printf("\nChoose the conversion unit:\n");
                printf("1. kilograms\n");
                printf("2. pounds\n");
                printf("3. grams\n");

                printf("\nConvert from: ");
                scanf("%d", &from_unit);

                printf("Convert to: ");
                scanf("%d", &to_unit);

                result = convert_weight(value,from_unit,to_unit);
                printf("\nResult: %.2lf\n", result);
                break;

            case 4:
                printf("\nThank you for using the Unit Converter App!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void print_menu() {

    printf("\nChoose an option:\n");
    printf("1. Length converter\n");
    printf("2. Temperature converter\n");
    printf("3. Weight converter\n");
    printf("4. Exit\n");

}

double convert_length(double value, int from_unit, int to_unit) {

    double result;

    if (from_unit == 1 && to_unit == 2) { // from meters to feet
        result = value * 3.28084;
    }
    else if (from_unit == 1 && to_unit == 3) { // from meters to inches
        result = value * 39.3701;
    }
    else if (from_unit == 2 && to_unit == 1) { // from feet to meters
        result = value * 0.3048;
    }
    else if (from_unit == 2 && to_unit == 3) { // from feet to inches
        result = value * 12;
    }
    else if (from_unit == 3 && to_unit == 1) { // from inches to meters
        result = value * 0.0254;
    }
    else if (from_unit == 3 && to_unit == 2) { // from inches to feet
        result = value * 0.0833333;
    }
    else {
        result = value;
    }

    return result;
}

double convert_temperature(double value, int from_unit, int to_unit) {

    double result;

    if (from_unit == 1 && to_unit == 2) { // from Celsius to Fahrenheit
        result = (value * 9/5) + 32;
    }
    else if (from_unit == 2 && to_unit == 1) { // from Fahrenheit to Celsius
        result = (value - 32) * 5/9;
    }
    else {
        result = value;
    }

    return result;
}

double convert_weight(double value, int from_unit, int to_unit) {

    double result;

    if (from_unit == 1 && to_unit == 2) { // from kilograms to pounds 
        result = value * 2.20462;
    }
    else if (from_unit == 1 && to_unit == 3) { // from kilograms to grams
        result = value * 1000;
    }
    else if (from_unit == 2 && to_unit == 1) { // from pounds to kilograms
        result = value * 0.453592;
    }
    else if (from_unit == 2 && to_unit == 3) { // from pounds to grams
        result = value * 453.592;
    }
    else if (from_unit == 3 && to_unit == 1) { // from grams to kilograms
        result = value * 0.001;
    }
    else if (from_unit == 3 && to_unit == 2) { // from grams to pounds
        result = value * 0.00220462;
    }
    else {
        result = value;
    }

    return result;
}