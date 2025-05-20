//FormAI DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>

int main() {
    int choice = 0;
    float value, result;
    
    printf("Welcome to the Happy Unit Converter!\n");
    
    while (1) { // Loop until the user chooses to exit
        printf("\nPlease select an option:\n");
        printf("1. Meters to Feet\n");
        printf("2. Feet to Meters\n");
        printf("3. Kilograms to Pounds\n");
        printf("4. Pounds to Kilograms\n");
        printf("5. Celcius to Fahrenheit\n");
        printf("6. Fahrenheit to Celcius\n");
        printf("7. Exit\n");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter meters: ");
                scanf("%f", &value);
                result = value * 3.28084;
                printf("%.2f meters is equal to %.2f feet\n", value, result);
                break;
            case 2:
                printf("Enter feet: ");
                scanf("%f", &value);
                result = value * 0.3048;
                printf("%.2f feet is equal to %.2f meters\n", value, result);
                break;
            case 3:
                printf("Enter kilograms: ");
                scanf("%f", &value);
                result = value * 2.20462;
                printf("%.2f kilograms is equal to %.2f pounds\n", value, result);
                break;
            case 4:
                printf("Enter pounds: ");
                scanf("%f", &value);
                result = value * 0.453592;
                printf("%.2f pounds is equal to %.2f kilograms\n", value, result);
                break;
            case 5:
                printf("Enter Celsius: ");
                scanf("%f", &value);
                result = (value * 1.8) + 32;
                printf("%.2f degrees Celsius is equal to %.2f degrees Fahrenheit\n", value, result);
                break;
            case 6:
                printf("Enter Fahrenheit: ");
                scanf("%f", &value);
                result = (value - 32) * 0.555556;
                printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius\n", value, result);
                break;
            case 7:
                printf("\nThank you for using the Happy Unit Converter!\n");
                return 0;
            default:
                printf("\nInvalid option, please try again!\n");
        }
    }
}