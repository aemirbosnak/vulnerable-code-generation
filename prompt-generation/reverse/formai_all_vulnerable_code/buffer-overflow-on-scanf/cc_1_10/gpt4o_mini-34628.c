//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: synchronous
#include <stdio.h>

void display_menu() {
    printf("Unit Converter\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Meters to Feet\n");
    printf("3. Meters to Inches\n");
    printf("4. Kilometers to Meters\n");
    printf("5. Feet to Meters\n");
    printf("6. Inches to Meters\n");
    printf("0. Exit\n");
    printf("Select an option: ");
}

double convert_length(double value, int option) {
    switch(option) {
        case 1: // Meters to Kilometers
            return value / 1000.0;
        case 2: // Meters to Feet
            return value * 3.28084;
        case 3: // Meters to Inches
            return value * 39.3701;
        case 4: // Kilometers to Meters
            return value * 1000.0;
        case 5: // Feet to Meters
            return value / 3.28084;
        case 6: // Inches to Meters
            return value / 39.3701;
        default:
            return 0; // Unknown option
    }
}

void handle_conversion() {
    double value;
    int option;
    
    printf("Enter the value to convert: ");
    scanf("%lf", &value);
    
    display_menu();
    scanf("%d", &option);
    
    if (option == 0) {
        printf("Exiting...\n");
        return;
    }

    double converted_value = convert_length(value, option);

    switch(option) {
        case 1:
            printf("%.2lf Meters is %.2lf Kilometers\n", value, converted_value);
            break;
        case 2:
            printf("%.2lf Meters is %.2lf Feet\n", value, converted_value);
            break;
        case 3:
            printf("%.2lf Meters is %.2lf Inches\n", value, converted_value);
            break;
        case 4:
            printf("%.2lf Kilometers is %.2lf Meters\n", value, converted_value);
            break;
        case 5:
            printf("%.2lf Feet is %.2lf Meters\n", value, converted_value);
            break;
        case 6:
            printf("%.2lf Inches is %.2lf Meters\n", value, converted_value);
            break;
        default:
            printf("Invalid option selected!\n");
            break;
    }
}

int main() {
    int continue_conversion = 1;

    while (continue_conversion) {
        handle_conversion();
        printf("\nDo you want to perform another conversion? (1 for Yes, 0 for No): ");
        scanf("%d", &continue_conversion);
    }

    printf("Thank you for using the unit converter. Goodbye!\n");
    return 0;
}