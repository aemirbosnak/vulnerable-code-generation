//FormAI DATASET v1.0 Category: Unit converter ; Style: authentic
#include <stdio.h>

// Function prototypes
void printInstructions();
void convertLength();
void convertWeight();
void convertTemperature();

int main() {
    printf("Welcome to the Unit Converter!\n");
    printInstructions();
    
    int choice;
    do {
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                convertLength();
                break;
            case 2:
                convertWeight();
                break;
            case 3:
                convertTemperature();
                break;
            case 4:
                printf("Thank you for using the Unit Converter!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
    } while (choice != 4);
    
    return 0;
}

// Function to print the instructions
void printInstructions() {
    printf("Please select an option:\n");
    printf("1. Convert length\n");
    printf("2. Convert weight\n");
    printf("3. Convert temperature\n");
    printf("4. Quit the program\n");
}

// Function to convert length
void convertLength() {
    printf("You have chosen to convert length.\n");
    printf("Please select the unit you would like to convert from:\n");
    printf("1. Meters\n");
    printf("2. Centimeters\n");
    printf("3. Kilometers\n");
    printf("4. Feet\n");
    printf("5. Inches\n");
    printf("6. Miles\n");
    
    int fromUnit;
    printf("Enter your choice (1-6): ");
    scanf("%d", &fromUnit);
    
    double amount;
    printf("Enter the amount of length to convert: ");
    scanf("%lf", &amount);
    
    double result;
    char* toUnit;
    
    switch (fromUnit) {
        case 1:
            // Meters to other units
            printf("Please select the unit you would like to convert to:\n");
            printf("1. Centimeters\n");
            printf("2. Kilometers\n");
            printf("3. Feet\n");
            printf("4. Inches\n");
            printf("5. Miles\n");
            printf("Enter your choice (1-5): ");
            int toUnitNum;
            scanf("%d", &toUnitNum);
            switch (toUnitNum) {
                case 1:
                    result = amount * 100;
                    toUnit = "centimeters";
                    break;
                case 2:
                    result = amount / 1000;
                    toUnit = "kilometers";
                    break;
                case 3:
                    result = amount * 3.28084;
                    toUnit = "feet";
                    break;
                case 4:
                    result = amount * 39.3701;
                    toUnit = "inches";
                    break;
                case 5:
                    result = amount * 0.000621371;
                    toUnit = "miles";
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    return;
            }
            break;
        case 2:
            // Centimeters to other units
            printf("Please select the unit you would like to convert to:\n");
            printf("1. Meters\n");
            printf("2. Kilometers\n");
            printf("3. Feet\n");
            printf("4. Inches\n");
            printf("5. Miles\n");
            printf("Enter your choice (1-5): ");
            scanf("%d", &toUnitNum);
            switch (toUnitNum) {
                case 1:
                    result = amount / 100;
                    toUnit = "meters";
                    break;
                case 2:
                    result = amount / 100000;
                    toUnit = "kilometers";
                    break;
                case 3:
                    result = amount * 0.0328084;
                    toUnit = "feet";
                    break;
                case 4:
                    result = amount * 0.393701;
                    toUnit = "inches";
                    break;
                case 5:
                    result = amount * 0.00000621371;
                    toUnit = "miles";
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    return;
            }
            break;
        case 3:
            // Kilometers to other units
            printf("Please select the unit you would like to convert to:\n");
            printf("1. Meters\n");
            printf("2. Centimeters\n");
            printf("3. Feet\n");
            printf("4. Inches\n");
            printf("5. Miles\n");
            printf("Enter your choice (1-5): ");
            scanf("%d", &toUnitNum);
            switch (toUnitNum) {
                case 1:
                    result = amount * 1000;
                    toUnit = "meters";
                    break;
                case 2:
                    result = amount * 100000;
                    toUnit = "centimeters";
                    break;
                case 3:
                    result = amount * 3280.84;
                    toUnit = "feet";
                    break;
                case 4:
                    result = amount * 39370.1;
                    toUnit = "inches";
                    break;
                case 5:
                    result = amount * 0.621371;
                    toUnit = "miles";
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    return;
            }
            break;
        case 4:
            // Feet to other units
            printf("Please select the unit you would like to convert to:\n");
            printf("1. Meters\n");
            printf("2. Centimeters\n");
            printf("3. Kilometers\n");
            printf("4. Inches\n");
            printf("5. Miles\n");
            printf("Enter your choice (1-5): ");
            scanf("%d", &toUnitNum);
            switch (toUnitNum) {
                case 1:
                    result = amount / 3.28084;
                    toUnit = "meters";
                    break;
                case 2:
                    result = amount * 30.48;
                    toUnit = "centimeters";
                    break;
                case 3:
                    result = amount / 3280.84;
                    toUnit = "kilometers";
                    break;
                case 4:
                    result = amount * 12;
                    toUnit = "inches";
                    break;
                case 5:
                    result = amount * 0.000189394;
                    toUnit = "miles";
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    return;
            }
            break;
        case 5:
            // Inches to other units
            printf("Please select the unit you would like to convert to:\n");
            printf("1. Meters\n");
            printf("2. Centimeters\n");
            printf("3. Kilometers\n");
            printf("4. Feet\n");
            printf("5. Miles\n");
            printf("Enter your choice (1-5): ");
            scanf("%d", &toUnitNum);
            switch (toUnitNum) {
                case 1:
                    result = amount / 39.3701;
                    toUnit = "meters";
                    break;
                case 2:
                    result = amount * 2.54;
                    toUnit = "centimeters";
                    break;
                case 3:
                    result = amount / 39370.1;
                    toUnit = "kilometers";
                    break;
                case 4:
                    result = amount * 0.0833333;
                    toUnit = "feet";
                    break;
                case 5:
                    result = amount * 0.0000157828;
                    toUnit = "miles";
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    return;
            }
            break;
        case 6:
            // Miles to other units
            printf("Please select the unit you would like to convert to:\n");
            printf("1. Meters\n");
            printf("2. Centimeters\n");
            printf("3. Kilometers\n");
            printf("4. Feet\n");
            printf("5. Inches\n");
            printf("Enter your choice (1-5): ");
            scanf("%d", &toUnitNum);
            switch (toUnitNum) {
                case 1:
                    result = amount / 0.000621371;
                    toUnit = "meters";
                    break;
                case 2:
                    result = amount * 160934;
                    toUnit = "centimeters";
                    break;
                case 3:
                    result = amount * 1.60934;
                    toUnit = "kilometers";
                    break;
                case 4:
                    result = amount * 5280;
                    toUnit = "feet";
                    break;
                case 5:
                    result = amount * 63360;
                    toUnit = "inches";
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    return;
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            return;
    }
    
    printf("%.2f %s is equal to %.2f %s.\n", amount, (fromUnit == 1 || fromUnit == 2 || fromUnit == 3) ? "meters" : "feet", result, toUnit);
}

// Function to convert weight
void convertWeight() {
    printf("You have chosen to convert weight.\n");
    printf("Please select the unit you would like to convert from:\n");
    printf("1. Kilograms\n");
    printf("2. Grams\n");
    printf("3. Pounds\n");
    printf("4. Ounces\n");

    int fromUnit;
    printf("Enter your choice (1-4): ");
    scanf("%d", &fromUnit);

    double amount;
    printf("Enter the amount of weight to convert: ");
    scanf("%lf", &amount);

    double result;
    char* toUnit;

    switch (fromUnit) {
        case 1:
            // Kilograms to other units
            printf("Please select the unit you would like to convert to:\n");
            printf("1. Grams\n");
            printf("2. Pounds\n");
            printf("3. Ounces\n");
            printf("Enter your choice (1-3): ");
            int toUnitNum;
            scanf("%d", &toUnitNum);
            switch (toUnitNum) {
                case 1:
                    result = amount * 1000;
                    toUnit = "grams";
                    break;
                case 2:
                    result = amount * 2.20462;
                    toUnit = "pounds";
                    break;
                case 3:
                    result = amount * 35.274;
                    toUnit = "ounces";
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    return;
            }
            break;
        case 2:
            // Grams to other units
            printf("Please select the unit you would like to convert to:\n");
            printf("1. Kilograms\n");
            printf("2. Pounds\n");
            printf("3. Ounces\n");
            printf("Enter your choice (1-3): ");
            scanf("%d", &toUnitNum);
            switch (toUnitNum) {
                case 1:
                    result = amount / 1000;
                    toUnit = "kilograms";
                    break;
                case 2:
                    result = amount * 0.00220462;
                    toUnit = "pounds";
                    break;
                case 3:
                    result = amount * 0.035274;
                    toUnit = "ounces";
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    return;
            }
            break;
        case 3:
            // Pounds to other units
            printf("Please select the unit you would like to convert to:\n");
            printf("1. Kilograms\n");
            printf("2. Grams\n");
            printf("3. Ounces\n");
            printf("Enter your choice (1-3): ");
            scanf("%d", &toUnitNum);
            switch (toUnitNum) {
                case 1:
                    result = amount * 0.453592;
                    toUnit = "kilograms";
                    break;
                case 2:
                    result = amount * 453.592;
                    toUnit = "grams";
                    break;
                case 3:
                    result = amount * 16;
                    toUnit = "ounces";
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    return;
            }
            break;
        case 4:
            // Ounces to other units
            printf("Please select the unit you would like to convert to:\n");
            printf("1. Kilograms\n");
            printf("2. Grams\n");
            printf("3. Pounds\n");
            printf("Enter your choice (1-3): ");
            scanf("%d", &toUnitNum);
            switch (toUnitNum) {
                case 1:
                    result = amount * 0.0283495;
                    toUnit = "kilograms";
                    break;
                case 2:
                    result = amount * 28.3495;
                    toUnit = "grams";
                    break;
                case 3:
                    result = amount * 0.0625;
                    toUnit = "pounds";
                    break;
                default:
                    printf("Invalid choice. Please try again.\n");
                    return;
            }
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            return;
    }

    printf("%.2f %s is equal to %.2f %s.\n", amount, (fromUnit == 1) ? "kilograms" : (fromUnit == 2) ? "grams" : (fromUnit == 3) ? "pounds" : "ounces", result, toUnit);
}

// Function to convert temperature
void convertTemperature() {
    printf("You have chosen to convert temperature.\n");
    printf("Please select the scale you would like to convert from:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");

    int fromScale;
    printf("Enter your choice (1-2): ");
    scanf("%d", &fromScale);

    double amount;
    printf("Enter the temperature to convert: ");
    scanf("%lf", &amount);

    double result;
    char* toScale;

    switch (fromScale) {
        case 1:
            // Celsius to Fahrenheit
            result = (amount * 1.8) + 32;
            toScale = "degrees Fahrenheit";
            break;
        case 2:
            // Fahrenheit to Celsius
            result = (amount - 32) / 1.8;
            toScale = "degrees Celsius";
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            return;
    }

    printf("%.2f degrees %s is equal to %.2f %s.\n", amount, (fromScale == 1) ? "Celsius" : "Fahrenheit", result, toScale);
}