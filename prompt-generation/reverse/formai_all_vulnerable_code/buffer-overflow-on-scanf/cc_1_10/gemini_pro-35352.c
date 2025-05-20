//GEMINI-pro DATASET v1.0 Category: Unit converter ; Style: retro
// ** Pontius's Imperial-Metric Converter **

// Greetings, weary traveler! Welcome to Pontius's Imperial-Metric Converter, a wondrous contraption that will transmute ye olde imperial units into their metric counterparts with ease.

#include <stdio.h>

// ** Enumerations **

// Lo, the units of length:
typedef enum {INCH, FOOT, YARD, MILE} LengthUnit;

// And the units of mass:
typedef enum {OUNCE, POUND, TON} MassUnit;

// ** Function Prototypes **

// Converts a length from imperial to metric:
float ImperialToMetricLength(float imperialLength, LengthUnit unit);

// Converts a mass from imperial to metric:
float ImperialToMetricMass(float imperialMass, MassUnit unit);

// Prints the conversion result:
void PrintResult(float result, char *unit);

// ** Main Function **

int main() {
    // Declare variables:
    float imperialValue;
    LengthUnit lengthUnit;
    MassUnit massUnit;
    int choice;
    char resultUnit[10];
    
    // Greet the user:
    printf("Welcome to Pontius's Imperial-Metric Converter!\n");
    printf("What units dost thou wish to convert?\n");
    printf("1. Length (inches, feet, yards, miles)\n");
    printf("2. Mass (ounces, pounds, tons)\n");
    printf("Enter thy choice (1 or 2): ");
    scanf("%d", &choice);
    printf("\n");
    
    switch (choice) {
        case 1:
            // Length conversion:

            // Get the imperial value:
            printf("Enter the imperial length value: ");
            scanf("%f", &imperialValue);
            printf("\n");

            // Get the imperial unit:
            printf("Enter the imperial unit (inch, foot, yard, mile): ");
            scanf("%s", resultUnit);
            printf("\n");

            // Convert the value:
            float metricLength = ImperialToMetricLength(imperialValue, lengthUnit);

            // Print the result:
            PrintResult(metricLength, "meter");

            break;

        case 2:
            // Mass conversion:

            // Get the imperial value:
            printf("Enter the imperial mass value: ");
            scanf("%f", &imperialValue);
            printf("\n");

            // Get the imperial unit:
            printf("Enter the imperial unit (ounce, pound, ton): ");
            scanf("%s", resultUnit);
            printf("\n");

            // Convert the value:
            float metricMass = ImperialToMetricMass(imperialValue, massUnit);

            // Print the result:
            PrintResult(metricMass, "kilogram");

            break;

        default:
            printf("Invalid choice. Please enter 1 or 2.\n");
            break;
    }

    // Bid farewell:
    printf("\nMay this conversion serve thee well, traveler. Fare thee well!\n");

    return 0;
}

// ** Function Definitions **

// Converts a length from imperial to metric:
float ImperialToMetricLength(float imperialLength, LengthUnit unit) {
    float metricLength;
    
    switch (unit) {
        case INCH:
            metricLength = imperialLength * 0.0254;
            break;
        case FOOT:
            metricLength = imperialLength * 0.3048;
            break;
        case YARD:
            metricLength = imperialLength * 0.9144;
            break;
        case MILE:
            metricLength = imperialLength * 1609.34;
            break;
    }
    
    return metricLength;
}

// Converts a mass from imperial to metric:
float ImperialToMetricMass(float imperialMass, MassUnit unit) {
    float metricMass;
    
    switch (unit) {
        case OUNCE:
            metricMass = imperialMass * 0.0283495;
            break;
        case POUND:
            metricMass = imperialMass * 0.453592;
            break;
        case TON:
            metricMass = imperialMass * 907.185;
            break;
    }

    return metricMass;
}

// Prints the conversion result:
void PrintResult(float result, char *unit) {
    printf("The converted value is: %.2f %s\n", result, unit);
}