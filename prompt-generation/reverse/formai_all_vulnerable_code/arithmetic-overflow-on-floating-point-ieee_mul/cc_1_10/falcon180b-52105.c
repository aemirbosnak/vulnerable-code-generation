//Falcon-180B DATASET v1.0 Category: Unit converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int choice;
    double num, result;
    
    printf("Enter the number to be converted:\n");
    scanf("%lf", &num);
    
    printf("Select the unit to convert to:\n");
    printf("1. Kilometers\n");
    printf("2. Meters\n");
    printf("3. Centimeters\n");
    printf("4. Millimeters\n");
    printf("5. Miles\n");
    printf("6. Yards\n");
    printf("7. Feet\n");
    printf("8. Inches\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            result = num * 1000;
            printf("%.2lf meters is equal to %.2lf kilometers.\n", num, result);
            break;
        case 2:
            result = num;
            printf("%.2lf meters is equal to %.2lf meters.\n", num, result);
            break;
        case 3:
            result = num / 100;
            printf("%.2lf meters is equal to %.2lf centimeters.\n", num, result);
            break;
        case 4:
            result = num / 1000;
            printf("%.2lf meters is equal to %.2lf millimeters.\n", num, result);
            break;
        case 5:
            result = num * 1609.34;
            printf("%.2lf meters is equal to %.2lf miles.\n", num, result);
            break;
        case 6:
            result = num * 3.28084;
            printf("%.2lf meters is equal to %.2lf yards.\n", num, result);
            break;
        case 7:
            result = num * 3.28084;
            printf("%.2lf meters is equal to %.2lf feet.\n", num, result);
            break;
        case 8:
            result = num * 39.3701;
            printf("%.2lf meters is equal to %.2lf inches.\n", num, result);
            break;
        default:
            printf("Invalid choice.\n");
    }
    
    return 0;
}