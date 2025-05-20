//FormAI DATASET v1.0 Category: Unit converter ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    printf("Welcome to the Unit Converter, my dear Watson! Please choose an option:\n\n");
    printf("1. Fahrenheit to Celsius\n");
    printf("2. Miles to Kilometers\n");
    printf("3. Inches to Centimeters\n");
    printf("4. Pounds to Kilograms\n\n");

    int option;
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Ah, Fahrenheit to Celsius, a classic case! Please enter the temperature in Fahrenheit:\n");
            double fahrenheit;
            scanf("%lf", &fahrenheit);
            double celsius = (fahrenheit - 32) * 5 / 9;
            printf("%.2lf degrees Fahrenheit is equivalent to %.2lf degrees Celsius.\n", fahrenheit, celsius);
            break;

        case 2:
            printf("Miles to Kilometers, an interesting challenge! Please enter the distance in miles:\n");
            double miles;
            scanf("%lf", &miles);
            double kilometers = miles * 1.60934;
            printf("%.2lf miles is equivalent to %.2lf kilometers.\n", miles, kilometers);
            break;

        case 3:
            printf("Inches to Centimeters, a curious case! Please enter the length in inches:\n");
            double inches;
            scanf("%lf", &inches);
            double centimeters = inches * 2.54;
            printf("%.2lf inches is equivalent to %.2lf centimeters.\n", inches, centimeters);
            break;

        case 4:
            printf("Pounds to Kilograms, an intriguing mystery! Please enter the weight in pounds:\n");
            double pounds;
            scanf("%lf", &pounds);
            double kilograms = pounds * 0.453592;
            printf("%.2lf pounds is equivalent to %.2lf kilograms.\n", pounds, kilograms);
            break;

        default:
            printf("I am sorry, my dear Watson, but that option is not available at the moment!\n");
            break;
    }

    return 0;
}