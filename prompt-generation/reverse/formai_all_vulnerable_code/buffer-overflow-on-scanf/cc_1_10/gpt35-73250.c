//FormAI DATASET v1.0 Category: Unit converter ; Style: ultraprecise
#include <stdio.h>

int main() {
    int option;
    float value, result;

    printf("Unit conversion tool\n");
    printf("--------------------\n");

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Feet to meters\n");
        printf("2. Miles to kilometers\n");
        printf("3. Pounds to kilograms\n");
        printf("4. Fahrenheit to Celsius\n");
        printf("5. Quit\n");
        printf("Option: ");
        scanf("%d", &option);

        if (option == 5) {
            printf("Goodbye!\n");
            break;
        } else if (option < 1 || option > 5) {
            printf("Invalid option.\n");
            continue;
        }

        printf("Value to convert: ");
        scanf("%f", &value);

        switch (option) {
            case 1:
                result = value / 3.2808;
                printf("%0.2f feet = %0.2f meters\n", value, result);
                break;

            case 2:
                result = value * 1.6093;
                printf("%0.2f miles = %0.2f kilometers\n", value, result);
                break;

            case 3:
                result = value / 2.2046;
                printf("%0.2f pounds = %0.2f kilograms\n", value, result);
                break;

            case 4:
                result = (value - 32) * 5 / 9;
                printf("%0.2f degrees Fahrenheit = %0.2f degrees Celsius\n", value, result);
                break;
        }
    }

    return 0;
}