//FormAI DATASET v1.0 Category: Unit converter ; Style: relaxed
#include <stdio.h>

int main() {
    /* Displaying the available conversion options for the user */
    printf("Welcome to Unit Converter!\n");
    printf("Please select the conversion you want to perform:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Kilometers to Miles\n");
    printf("4. Miles to Kilometers\n");
    printf("Enter the option number: ");

    int option;
    scanf("%d", &option);

    double temp, result;
    switch (option) {
        case 1:
            /* Converting Celsius to Fahrenheit */
            printf("Enter the temperature in Celsius: ");
            scanf("%lf", &temp);
            result = (temp * 1.8) + 32;
            printf("%.2lf Celsius is equal to %.2lf Fahrenheit\n", temp, result);
            break;
        case 2:
            /* Converting Fahrenheit to Celsius */
            printf("Enter the temperature in Fahrenheit: ");
            scanf("%lf", &temp);
            result = (temp - 32) / 1.8;
            printf("%.2lf Fahrenheit is equal to %.2lf Celsius\n", temp, result);
            break;
        case 3:
            /* Converting Kilometers to Miles */
            printf("Enter the distance in kilometers: ");
            scanf("%lf", &temp);
            result = temp / 1.609;
            printf("%.2lf kilometers is equal to %.2lf miles\n", temp, result);
            break;
        case 4:
            /* Converting Miles to Kilometers */
            printf("Enter the distance in miles: ");
            scanf("%lf", &temp);
            result = temp * 1.609;
            printf("%.2lf miles is equal to %.2lf kilometers\n", temp, result);
            break;
        default:
            printf("Invalid option. Please enter a valid option.\n");
            break;
    }

    return 0;
}