//FormAI DATASET v1.0 Category: Unit converter ; Style: Linus Torvalds
/*
 * Unit Converter Program by [Your Name]
 * Released under the GNU General Public License
 */

#include <stdio.h>

int main() {
    float value;
    int option;

    printf("Welcome to the Unit Converter!\n\n");
    printf("Please select an option:\n");
    printf("1. Kilometers to Miles\n");
    printf("2. Miles to Kilometers\n");
    printf("3. Celsius to Fahrenheit\n");
    printf("4. Fahrenheit to Celsius\n");
    printf("5. Meters to Feet\n");
    printf("6. Feet to Meters\n");
    printf("7. Kilograms to Pounds\n");
    printf("8. Pounds to Kilograms\n");
    printf("9. Quit\n\n");

    do {
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter value in kilometers: ");
                scanf("%f", &value);
                printf("%.2f kilometers = %.2f miles\n", value, value / 1.609);
                break;
            case 2:
                printf("Enter value in miles: ");
                scanf("%f", &value);
                printf("%.2f miles = %.2f kilometers\n", value, value * 1.609);
                break;
            case 3:
                printf("Enter value in Celsius: ");
                scanf("%f", &value);
                printf("%.2f Celsius = %.2f Fahrenheit\n", value, (value * 1.8) + 32);
                break;
            case 4:
                printf("Enter value in Fahrenheit: ");
                scanf("%f", &value);
                printf("%.2f Fahrenheit = %.2f Celsius\n", value, (value - 32) / 1.8);
                break;
            case 5:
                printf("Enter value in meters: ");
                scanf("%f", &value);
                printf("%.2f meters = %.2f feet\n", value, value / 0.3048);
                break;
            case 6:
                printf("Enter value in feet: ");
                scanf("%f", &value);
                printf("%.2f feet = %.2f meters\n", value, value * 0.3048);
                break;
            case 7:
                printf("Enter value in kilograms: ");
                scanf("%f", &value);
                printf("%.2f kilograms = %.2f pounds\n", value, value * 2.2046);
                break;
            case 8:
                printf("Enter value in pounds: ");
                scanf("%f", &value);
                printf("%.2f pounds = %.2f kilograms\n", value, value / 2.2046);
                break;
            case 9:
                printf("Quitting program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n\n");
                break;
        }

    } while (option != 9);

    return 0;
}