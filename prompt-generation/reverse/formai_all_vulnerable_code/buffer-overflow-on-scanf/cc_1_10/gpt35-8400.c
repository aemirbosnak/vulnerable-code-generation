//FormAI DATASET v1.0 Category: Unit converter ; Style: mind-bending
#include <stdio.h>

int main() {
    int option;
    float inputValue, convertedValue;

    // Prompt user to select conversion option
    printf("Welcome to the Mind-Bending Unit Converter!\n");
    printf("Please select a conversion option:\n");
    printf("1. Length\n");
    printf("2. Temperature\n");
    printf("3. Volume\n");
    scanf("%d", &option);

    switch (option) {
        // Length Conversion
        case 1:
            printf("You have selected Length conversion.\n");
            printf("Please enter the value in meters: ");
            scanf("%f", &inputValue);

            // Convert to light years
            convertedValue = inputValue / 9.461e+15;

            printf("%f meters is equivalent to %f light years.\n", inputValue, convertedValue);
            break;

        // Temperature Conversion
        case 2:
            printf("You have selected Temperature conversion.\n");
            printf("Please enter the temperature in Celsius: ");
            scanf("%f", &inputValue);

            // Convert to Kelvin
            convertedValue = inputValue + 273.15;

            printf("%f degrees Celsius is equivalent to %f Kelvin.\n", inputValue, convertedValue);
            break;

        // Volume Conversion
        case 3:
            printf("You have selected Volume conversion.\n");
            printf("Please enter the value in cubic meters: ");
            scanf("%f", &inputValue);

            // Convert to Olympic-sized swimming pools
            convertedValue = inputValue / 2500;

            printf("%f cubic meters is equivalent to %f Olympic-sized swimming pools.\n", inputValue, convertedValue);
            break;

        default:
            printf("Invalid option selected.\n");
            break;
    }

    return 0;
}