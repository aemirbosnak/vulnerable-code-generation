#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    double meters = 1.0;
    double kilometers = 0.001;
    double miles = 0.000621371;
    double feet = 3.28084;
    double inches = 39.3701;

    double value, result;
    int choice, repeat = 1;

    while (repeat) {
        printf("Enter a distance: ");
        scanf("%lf", &value);

        printf("Choose unit to convert from:\n");
        printf("1. Meters\n2. Kilometers\n3. Miles\n4. Feet\n5. Inches\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                result = value * meters;
                break;
            case 2:
                result = value * kilometers;
                break;
            case 3:
                result = value * miles;
                break;
            case 4:
                result = value * feet;
                break;
            case 5:
                result = value * inches;
                break;
            default:
                printf("Invalid choice.\n");
                continue;
        }

        printf("Choose unit to convert to:\n");
        printf("1. Meters\n2. Kilometers\n3. Miles\n4. Feet\n5. Inches\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                result /= meters;
                break;
            case 2:
                result /= kilometers;
                break;
            case 3:
                result /= miles;
                break;
            case 4:
                result /= feet;
                break;
            case 5:
                result /= inches;
                break;
            default:
                printf("Invalid choice.\n");
                continue;
        }

        printf("%.2f converted is %.2f\n", value, result);

        printf("Convert another? (1 for yes, 0 for no): ");
        scanf("%d", &repeat);
    }

    return 0;
}
