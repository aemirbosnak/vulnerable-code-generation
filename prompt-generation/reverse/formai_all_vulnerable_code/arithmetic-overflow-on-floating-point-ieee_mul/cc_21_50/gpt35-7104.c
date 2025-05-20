//FormAI DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>

int main() {
    float value, result;
    int choice;

    printf("Welcome to the Length Unit Converter!\n");
    printf("Enter the value you want to convert: ");
    scanf("%f", &value);
    printf("Select the unit you want to convert:\n");
    printf("1. Meter\n2. Centimeter\n3. Millimeter\n4. Kilometer\n5. Foot\n6. Inch\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1: // conversion from meter
            printf("You selected meter. Choose the unit you want to convert to:\n");
            printf("1. Centimeter\n2. Millimeter\n3. Kilometer\n4. Foot\n5. Inch\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1: // meter to centimeter
                    result = value * 100;
                    printf("%.2f meter is equal to %.2f centimeters.\n", value, result);
                    break;
                case 2: // meter to millimeter
                    result = value * 1000;
                    printf("%.2f meter is equal to %.2f millimeters.\n", value, result);
                    break;
                case 3: // meter to kilometer
                    result = value / 1000;
                    printf("%.2f meter is equal to %.2f kilometers.\n", value, result);
                    break;
                case 4: // meter to foot
                    result = value * 3.281;
                    printf("%.2f meter is equal to %.2f feet.\n", value, result);
                    break;
                case 5: // meter to inch
                    result = value * 39.37;
                    printf("%.2f meter is equal to %.2f inches.\n", value, result);
                    break;
                default:
                    printf("Invalid input. Please try again.\n");
            }
            break;
        case 2: // conversion from centimeter
            printf("You selected centimeter. Choose the unit you want to convert to:\n");
            printf("1. Meter\n2. Millimeter\n3. Kilometer\n4. Foot\n5. Inch\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1: // centimeter to meter
                    result = value / 100;
                    printf("%.2f centimeter is equal to %.2f meters.\n", value, result);
                    break;
                case 2: // centimeter to millimeter
                    result = value * 10;
                    printf("%.2f centimeter is equal to %.2f millimeters.\n", value, result);
                    break;
                case 3: // centimeter to kilometer
                    result = value / 100000;
                    printf("%.2f centimeter is equal to %.2f kilometers.\n", value, result);
                    break;
                case 4: // centimeter to foot
                    result = value / 30.48;
                    printf("%.2f centimeter is equal to %.2f feet.\n", value, result);
                    break;
                case 5: // centimeter to inch
                    result = value / 2.54;
                    printf("%.2f centimeter is equal to %.2f inches.\n", value, result);
                    break;
                default:
                    printf("Invalid input. Please try again.\n");
            }
            break;
        case 3: // conversion from millimeter
            printf("You selected millimeter. Choose the unit you want to convert to:\n");
            printf("1. Meter\n2. Centimeter\n3. Kilometer\n4. Foot\n5. Inch\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1: // millimeter to meter
                    result = value / 1000;
                    printf("%.2f millimeter is equal to %.2f meters.\n", value, result);
                    break;
                case 2: // millimeter to centimeter
                    result = value / 10;
                    printf("%.2f millimeter is equal to %.2f centimeters.\n", value, result);
                    break;
                case 3: // millimeter to kilometer
                    result = value / 1000000;
                    printf("%.2f millimeter is equal to %.2f kilometers.\n", value, result);
                    break;
                case 4: // millimeter to foot
                    result = value / 304.8;
                    printf("%.2f millimeter is equal to %.2f feet.\n", value, result);
                    break;
                case 5: // millimeter to inch
                    result = value / 25.4;
                    printf("%.2f millimeter is equal to %.2f inches.\n", value, result);
                    break;
                default:
                    printf("Invalid input. Please try again.\n");
            }
            break;
        case 4: // conversion from kilometer
            printf("You selected kilometer. Choose the unit you want to convert to:\n");
            printf("1. Meter\n2. Centimeter\n3. Millimeter\n4. Foot\n5. Inch\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1: // kilometer to meter
                    result = value * 1000;
                    printf("%.2f kilometer is equal to %.2f meters.\n", value, result);
                    break;
                case 2: // kilometer to centimeter
                    result = value * 100000;
                    printf("%.2f kilometer is equal to %.2f centimeters.\n", value, result);
                    break;
                case 3: // kilometer to millimeter
                    result = value * 1000000;
                    printf("%.2f kilometer is equal to %.2f millimeters.\n", value, result);
                    break;
                case 4: // kilometer to foot
                    result = value * 3281;
                    printf("%.2f kilometer is equal to %.2f feet.\n", value, result);
                    break;
                case 5: // kilometer to inch
                    result = value * 39370;
                    printf("%.2f kilometer is equal to %.2f inches.\n", value, result);
                    break;
                default:
                    printf("Invalid input. Please try again.\n");
            }
            break;
        case 5: // conversion from foot
            printf("You selected foot. Choose the unit you want to convert to:\n");
            printf("1. Meter\n2. Centimeter\n3. Millimeter\n4. Kilometer\n5. Inch\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1: // foot to meter
                    result = value / 3.281;
                    printf("%.2f foot is equal to %.2f meters.\n", value, result);
                    break;
                case 2: // foot to centimeter
                    result = value * 30.48;
                    printf("%.2f foot is equal to %.2f centimeters.\n", value, result);
                    break;
                case 3: // foot to millimeter
                    result = value * 304.8;
                    printf("%.2f foot is equal to %.2f millimeters.\n", value, result);
                    break;
                case 4: // foot to kilometer
                    result = value / 3281;
                    printf("%.2f foot is equal to %.2f kilometers.\n", value, result);
                    break;
                case 5: // foot to inch
                    result = value * 12;
                    printf("%.2f foot is equal to %.2f inches.\n", value, result);
                    break;
                default:
                    printf("Invalid input. Please try again.\n");
            }
            break;
        case 6: // conversion from inch
            printf("You selected inch. Choose the unit you want to convert to:\n");
            printf("1. Meter\n2. Centimeter\n3. Millimeter\n4. Kilometer\n5. Foot\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1: // inch to meter
                    result = value / 39.37;
                    printf("%.2f inch is equal to %.2f meters.\n", value, result);
                    break;
                case 2: // inch to centimeter
                    result = value * 2.54;
                    printf("%.2f inch is equal to %.2f centimeters.\n", value, result);
                    break;
                case 3: // inch to millimeter
                    result = value * 25.4;
                    printf("%.2f inch is equal to %.2f millimeters.\n", value, result);
                    break;
                case 4: // inch to kilometer
                    result = value / 39370;
                    printf("%.2f inch is equal to %.2f kilometers.\n", value, result);
                    break;
                case 5: // inch to foot
                    result = value / 12;
                    printf("%.2f inch is equal to %.2f feet.\n", value, result);
                    break;
                default:
                    printf("Invalid input. Please try again.\n");
            }
            break;
        default:
            printf("Invalid input. Please try again.\n");
    }

    return 0;
}