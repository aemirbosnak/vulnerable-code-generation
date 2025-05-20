//FormAI DATASET v1.0 Category: Unit converter ; Style: shocked
#include <stdio.h>

int main() {
    float input_value = 0;
    int input_type = 0, output_type = 0;

    printf("Welcome to Shocking Unit Converter!\n");

    printf("Enter the value to be converted: ");
    scanf("%f", &input_value);

    printf("Enter the input type:\n");
    printf("1: Feet\n");
    printf("2: Yards\n");
    printf("3: Miles\n");
    printf("4: Kilometers\n");
    printf("5: Meters\n");
    printf("Enter your choice: ");
    scanf("%d", &input_type);

    printf("Enter the output type:\n");
    printf("1: Feet\n");
    printf("2: Yards\n");
    printf("3: Miles\n");
    printf("4: Kilometers\n");
    printf("5: Meters\n");
    printf("Enter your choice: ");
    scanf("%d", &output_type);

    float output_value = 0;

    if (input_type == 1) {
        if (output_type == 1) {
            output_value = input_value;
        } else if (output_type == 2) {
            output_value = input_value / 3;
        } else if (output_type == 3) {
            output_value = input_value / 5280;
        } else if (output_type == 4) {
            output_value = input_value / 3280.84;
        } else if (output_type == 5) {
            output_value = input_value / 3.28084;
        }
    } else if (input_type == 2) {
        if (output_type == 1) {
            output_value = input_value * 3;
        } else if (output_type == 2) {
            output_value = input_value;
        } else if (output_type == 3) {
            output_value = input_value / 1760;
        } else if (output_type == 4) {
            output_value = input_value / 1093.61;
        } else if (output_type == 5) {
            output_value = input_value / 1.09361;
        }
    } else if (input_type == 3) {
        if (output_type == 1) {
            output_value = input_value * 5280;
        } else if (output_type == 2) {
            output_value = input_value * 1760;
        } else if (output_type == 3) {
            output_value = input_value;
        } else if (output_type == 4) {
            output_value = input_value * 1.60934;
        } else if (output_type == 5) {
            output_value = input_value * 1609.34;
        }
    } else if (input_type == 4) {
        if (output_type == 1) {
            output_value = input_value * 3280.84;
        } else if (output_type == 2) {
            output_value = input_value * 1093.61;
        } else if (output_type == 3) {
            output_value = input_value / 1.60934;
        } else if (output_type == 4) {
            output_value = input_value;
        } else if (output_type == 5) {
            output_value = input_value * 1000;
        }
    } else if (input_type == 5) {
        if (output_type == 1) {
            output_value = input_value * 3.28084;
        } else if (output_type == 2) {
            output_value = input_value * 1.09361;
        } else if (output_type == 3) {
            output_value = input_value / 1609.34;
        } else if (output_type == 4) {
            output_value = input_value / 1000;
        } else if (output_type == 5) {
            output_value = input_value;
        }
    }

    printf("The converted value is: %f", output_value);
    return 0;
}