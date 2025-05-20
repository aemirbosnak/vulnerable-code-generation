//GPT-4o-mini DATASET v1.0 Category: Unit converter ; Style: beginner-friendly
#include <stdio.h>

void displayMenu() {
    printf("Unit Converter\n");
    printf("Select the type of conversion:\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Meters to Miles\n");
    printf("3. Meters to Feet\n");
    printf("4. Kilometers to Meters\n");
    printf("5. Miles to Meters\n");
    printf("6. Feet to Meters\n");
    printf("7. Exit\n");
}

float metersToKilometers(float meters) {
    return meters / 1000.0;
}

float metersToMiles(float meters) {
    return meters / 1609.34;
}

float metersToFeet(float meters) {
    return meters * 3.28084;
}

float kilometersToMeters(float kilometers) {
    return kilometers * 1000.0;
}

float milesToMeters(float miles) {
    return miles * 1609.34;
}

float feetToMeters(float feet) {
    return feet / 3.28084;
}

int main() {
    int choice;
    float input, result;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        if (choice < 1 || choice > 7) {
            printf("Invalid choice, please try again.\n");
            continue;
        }
        
        switch (choice) {
            case 1:
                printf("Enter value in meters: ");
                scanf("%f", &input);
                result = metersToKilometers(input);
                printf("%.2f meters is %.2f kilometers\n", input, result);
                break;
            case 2:
                printf("Enter value in meters: ");
                scanf("%f", &input);
                result = metersToMiles(input);
                printf("%.2f meters is %.2f miles\n", input, result);
                break;
            case 3:
                printf("Enter value in meters: ");
                scanf("%f", &input);
                result = metersToFeet(input);
                printf("%.2f meters is %.2f feet\n", input, result);
                break;
            case 4:
                printf("Enter value in kilometers: ");
                scanf("%f", &input);
                result = kilometersToMeters(input);
                printf("%.2f kilometers is %.2f meters\n", input, result);
                break;
            case 5:
                printf("Enter value in miles: ");
                scanf("%f", &input);
                result = milesToMeters(input);
                printf("%.2f miles is %.2f meters\n", input, result);
                break;
            case 6:
                printf("Enter value in feet: ");
                scanf("%f", &input);
                result = feetToMeters(input);
                printf("%.2f feet is %.2f meters\n", input, result);
                break;
        }

        printf("\n");
    }

    return 0;
}