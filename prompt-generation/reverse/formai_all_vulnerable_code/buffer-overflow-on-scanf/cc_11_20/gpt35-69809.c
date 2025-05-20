//FormAI DATASET v1.0 Category: Unit converter ; Style: complete
#include <stdio.h>

int main() {

    float input_value;
    char input_unit;
    char output_unit;

    printf("Enter a value you want to convert: ");
    scanf("%f", &input_value);

    printf("Select input unit (c for Celsius, f for Fahrenheit, m for miles, h for hours): ");
    scanf(" %c", &input_unit);

    printf("Select output unit (c for Celsius, f for Fahrenheit, m for miles, h for hours): ");
    scanf(" %c", &output_unit);

    float output_value;

    // Celsius to Fahrenheit
    if (input_unit == 'c' && output_unit == 'f') {
        output_value = (input_value * 1.8) + 32;
        printf("%.2f Celsius is equal to %.2f Fahrenheit", input_value, output_value);
    }

    // Fahrenheit to Celsius
    else if (input_unit == 'f' && output_unit == 'c') {
        output_value = (input_value - 32) / 1.8;
        printf("%.2f Fahrenheit is equal to %.2f Celsius", input_value, output_value);
    }

    // Miles to Kilometers
    else if (input_unit == 'm' && output_unit == 'k') {
        output_value = input_value * 1.60934;
        printf("%.2f Miles is equal to %.2f Kilometers", input_value, output_value);
    }

    // Kilometers to Miles
    else if (input_unit == 'k' && output_unit == 'm') {
        output_value = input_value / 1.60934;
        printf("%.2f Kilometers is equal to %.2f Miles", input_value, output_value);
    }

    // Hours to Minutes
    else if (input_unit == 'h' && output_unit == 'm') {
        output_value = input_value * 60;
        printf("%.2f Hours is equal to %.2f Minutes", input_value, output_value);
    }

    // Minutes to Hours
    else if (input_unit == 'm' && output_unit == 'h') {
        output_value = input_value / 60;
        printf("%.2f Minutes is equal to %.2f Hours", input_value, output_value);
    }

    // Unsupported conversion
    else {
        printf("Unsupported conversion");
    }

    return 0;
}