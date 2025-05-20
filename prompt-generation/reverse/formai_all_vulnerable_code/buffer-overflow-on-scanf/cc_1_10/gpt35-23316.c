//FormAI DATASET v1.0 Category: Unit converter ; Style: ephemeral
#include <stdio.h>

int main() {
    int choice;
    float input, result;
    
    printf("Welcome to the Unit Convertor!\n\n");
    
    while(1) {
        printf("Please select an option:\n");
        printf("1. Fahrenheit to Celsius\n");
        printf("2. Celsius to Fahrenheit\n");
        printf("3. Feet to Meters\n");
        printf("4. Meters to Feet\n");
        printf("5. Pounds to Kilograms\n");
        printf("6. Kilograms to Pounds\n");
        printf("0. Exit\n");
        printf("Your choice: ");
        
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &input);
                result = (input - 32) * 5/9;
                printf("%.2f°F is equal to %.2f°C\n\n", input, result);
                break;
            case 2:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &input);
                result = (input * 9/5) + 32;
                printf("%.2f°C is equal to %.2f°F\n\n", input, result);
                break;
            case 3:
                printf("Enter distance in feet: ");
                scanf("%f", &input);
                result = input / 3.2808;
                printf("%.2f feet is equal to %.2f meters\n\n", input, result);
                break;
            case 4:
                printf("Enter distance in meters: ");
                scanf("%f", &input);
                result = input * 3.2808;
                printf("%.2f meters is equal to %.2f feet\n\n", input, result);
                break;
            case 5:
                printf("Enter weight in pounds: ");
                scanf("%f", &input);
                result = input / 2.2046;
                printf("%.2f pounds is equal to %.2f kilograms\n\n", input, result);
                break;
            case 6:
                printf("Enter weight in kilograms: ");
                scanf("%f", &input);
                result = input * 2.2046;
                printf("%.2f kilograms is equal to %.2f pounds\n\n", input, result);
                break;
            case 0:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n\n");
                break;
        }
    }
}