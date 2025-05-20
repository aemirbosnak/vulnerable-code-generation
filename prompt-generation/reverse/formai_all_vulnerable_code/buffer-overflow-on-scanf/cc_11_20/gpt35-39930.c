//FormAI DATASET v1.0 Category: Unit converter ; Style: happy
#include <stdio.h>

int main() {
    printf("Welcome to my happy unit converter!\n");
    
    int choice;
    float value, result;
    
    printf("Choose the unit you want to convert from: \n");
    printf("1. Meter\n2. Kilometer\n3. Centimeter\n4. Millimeter\n");
    scanf("%d", &choice);
    
    printf("Enter the value you want to convert: ");
    scanf("%f", &value);
    
    switch(choice) {
        case 1:
            printf("You chose meter as your unit.\n");
            printf("Choose the unit you want to convert to: \n");
            printf("1. Kilometer\n2. Centimeter\n3. Millimeter\n");
            scanf("%d", &choice);
            
            switch(choice) {
                case 1:
                    result = value / 1000;
                    printf("%.2f meters is equal to %.2f kilometers.\n", value, result);
                    break;
                case 2:
                    result = value * 100;
                    printf("%.2f meters is equal to %.2f centimeters.\n", value, result);
                    break;
                case 3:
                    result = value * 1000;
                    printf("%.2f meters is equal to %.2f millimeters.\n", value, result);
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
            }
            break;
        case 2:
            printf("You chose kilometer as your unit.\n");
            printf("Choose the unit you want to convert to: \n");
            printf("1. Meter\n2. Centimeter\n3. Millimeter\n");
            scanf("%d", &choice);
            
            switch(choice) {
                case 1:
                    result = value * 1000;
                    printf("%.2f kilometers is equal to %.2f meters.\n", value, result);
                    break;
                case 2:
                    result = value * 100000;
                    printf("%.2f kilometers is equal to %.2f centimeters.\n", value, result);
                    break;
                case 3:
                    result = value * 1000000;
                    printf("%.2f kilometers is equal to %.2f millimeters.\n", value, result);
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
            }
            break;
        case 3:
            printf("You chose centimeter as your unit.\n");
            printf("Choose the unit you want to convert to: \n");
            printf("1. Meter\n2. Kilometer\n3. Millimeter\n");
            scanf("%d", &choice);
            
            switch(choice) {
                case 1:
                    result = value / 100;
                    printf("%.2f centimeters is equal to %.2f meters.\n", value, result);
                    break;
                case 2:
                    result = value / 100000;
                    printf("%.2f centimeters is equal to %.2f kilometers.\n", value, result);
                    break;
                case 3:
                    result = value * 10;
                    printf("%.2f centimeters is equal to %.2f millimeters.\n", value, result);
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
            }
            break;
        case 4:
            printf("You chose millimeter as your unit.\n");
            printf("Choose the unit you want to convert to: \n");
            printf("1. Meter\n2. Kilometer\n3. Centimeter\n");
            scanf("%d", &choice);
            
            switch(choice) {
                case 1:
                    result = value / 1000;
                    printf("%.2f millimeters is equal to %.2f meters.\n", value, result);
                    break;
                case 2:
                    result = value / 1000000;
                    printf("%.2f millimeters is equal to %.2f kilometers.\n", value, result);
                    break;
                case 3:
                    result = value / 10;
                    printf("%.2f millimeters is equal to %.2f centimeters.\n", value, result);
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
            }
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    
    printf("Thank you for using my happy unit converter! :)");
    
    return 0;
}