//FormAI DATASET v1.0 Category: Unit converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main() {
    float input_value;
    int choice;
    float output_value;
    
    printf("------------------------------------\n");
    printf("         Unit Converter             \n");
    printf("------------------------------------\n");
    printf("Enter the value to be converted: ");
    scanf("%f", &input_value);
    
    printf("\nPlease select the type of conversion:\n");
    printf("1. Feet to Meters\n");
    printf("2. Meters to Feet\n");
    printf("3. Inches to Centimeters\n");
    printf("4. Centimeters to Inches\n");
    printf("5. Pounds to Kilograms\n");
    printf("6. Kilograms to Pounds\n");
    printf("7. Minutes to Hours\n");
    printf("8. Hours to Minutes\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            output_value = input_value / 3.281f;
            printf("%.2f feet = %.2f meters\n", input_value, output_value);
            break;
        case 2:
            output_value = input_value * 3.281f;
            printf("%.2f meters = %.2f feet\n", input_value, output_value);
            break;
        case 3:
            output_value = input_value * 2.54f;
            printf("%.2f inches = %.2f centimeters\n", input_value, output_value);
            break;
        case 4:
            output_value = input_value / 2.54f;
            printf("%.2f centimeters = %.2f inches\n", input_value, output_value);
            break;
        case 5:
            output_value = input_value / 2.205f;
            printf("%.2f pounds = %.2f kilograms\n", input_value, output_value);
            break;
        case 6:
            output_value = input_value * 2.205f;
            printf("%.2f kilograms = %.2f pounds\n", input_value, output_value);
            break;
        case 7:
            output_value = input_value / 60.0f;
            printf("%.2f minutes = %.2f hours\n", input_value, output_value);
            break;
        case 8:
            output_value = input_value * 60.0f;
            printf("%.2f hours = %.2f minutes\n", input_value, output_value);
            break;
        default:
            printf("Invalid choice\n");
    }
    
    return 0;
}