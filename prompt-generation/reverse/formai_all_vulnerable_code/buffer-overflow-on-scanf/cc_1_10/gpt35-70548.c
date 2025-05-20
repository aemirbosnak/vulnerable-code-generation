//FormAI DATASET v1.0 Category: Unit converter ; Style: Claude Shannon
#include <stdio.h>

/* Define a struct to represent the conversions */
typedef struct {
    const char* unitName;
    double scale;
} Conversion;

/* Create a function to convert between two units */
double convert(double value, Conversion from, Conversion to) {
    return (value * from.scale) / to.scale;
}

int main() {
    /* Define some unit conversions */
    Conversion meters = {"Meters", 1.0};
    Conversion feet = {"Feet", 0.3048};
    Conversion celsius = {"Celsius", 1.0};
    Conversion fahrenheit = {"Fahrenheit", 5.0/9.0};

    /* Get user input */
    double value;
    printf("Enter a value to convert: ");
    scanf("%lf", &value);

    /* Print a menu of conversion options */
    printf("1. Convert meters to feet\n");
    printf("2. Convert feet to meters\n");
    printf("3. Convert celsius to fahrenheit\n");
    printf("4. Convert fahrenheit to celsius\n");
    printf("Enter your choice: ");

    /* Get user selection */
    int choice;
    scanf("%d", &choice);

    /* Perform the selected conversion */
    switch(choice) {
        case 1:
            printf("%.2f meters = %.2f feet\n", value, convert(value, meters, feet));
            break;
        case 2:
            printf("%.2f feet = %.2f meters\n", value, convert(value, feet, meters));
            break;
        case 3:
            printf("%.2f celsius = %.2f fahrenheit\n", value, convert(value, celsius, fahrenheit));
            break;
        case 4:
            printf("%.2f fahrenheit = %.2f celsius\n", value, convert(value, fahrenheit, celsius));
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}