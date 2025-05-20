//FormAI DATASET v1.0 Category: Unit converter ; Style: paranoid
#include <stdio.h>

int main() {
    int choice = 0, val = 0;
    float convertedVal = 0.0;

    printf("Welcome to the paranoid C Unit Converter!\n");
    printf("Please select an option to convert:\n");
    printf("1. Feet to meters\n2. Miles to kilometers\n3. Gallons to liters\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter a value in feet: ");
            scanf("%d", &val);
            
            if (val <= 0) {
                printf("Invalid input! Value must be greater than 0.\n");
                return 0;
            }

            convertedVal = val * 0.3048;
            printf("%d feet is equal to %.2f meters.\n", val, convertedVal);
            break;

        case 2:
            printf("Enter a value in miles: ");
            scanf("%d", &val);
            
            if (val <= 0) {
                printf("Invalid input! Value must be greater than 0.\n");
                return 0;
            }

            convertedVal = val * 1.60934;
            printf("%d miles is equal to %.2f kilometers.\n", val, convertedVal);
            break;

        case 3:
            printf("Enter a value in gallons: ");
            scanf("%d", &val);
            
            if (val <= 0) {
                printf("Invalid input! Value must be greater than 0.\n");
                return 0;
            }

            convertedVal = val * 3.78541;
            printf("%d gallons is equal to %.2f liters.\n", val, convertedVal);
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }
    
    return 0;
}