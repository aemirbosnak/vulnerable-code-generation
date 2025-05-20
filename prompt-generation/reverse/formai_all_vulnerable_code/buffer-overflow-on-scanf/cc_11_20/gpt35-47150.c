//FormAI DATASET v1.0 Category: Unit converter ; Style: all-encompassing
#include <stdio.h>

int main() {
    float input_value;
    char input_unit[15], output_unit[15];
    float output_value;

    printf("Enter the value: ");
    scanf("%f", &input_value);

    printf("Enter the input unit: ");
    scanf("%s", input_unit);

    printf("Enter the output unit: ");
    scanf("%s", output_unit);

    if (strcmp(input_unit, "mm") == 0 && strcmp(output_unit, "cm") == 0) {
        output_value = input_value / 10;
        printf("%f mm = %f cm", input_value, output_value);
    }
    else if (strcmp(input_unit, "cm") == 0 && strcmp(output_unit, "mm") == 0) {
        output_value = input_value * 10;
        printf("%f cm = %f mm", input_value, output_value);
    }
    else if (strcmp(input_unit, "cm") == 0 && strcmp(output_unit, "m") == 0) {
        output_value = input_value / 100;
        printf("%f cm = %f m", input_value, output_value);
    }
    else if (strcmp(input_unit, "m") == 0 && strcmp(output_unit, "cm") == 0) {
        output_value = input_value * 100;
        printf("%f m = %f cm", input_value, output_value);
    }
    else if (strcmp(input_unit, "m") == 0 && strcmp(output_unit, "km") == 0) {
        output_value = input_value / 1000;
        printf("%f m = %f km", input_value, output_value);
    }
    else if (strcmp(input_unit, "km") == 0 && strcmp(output_unit, "m") == 0) {
        output_value = input_value * 1000;
        printf("%f km = %f m", input_value, output_value);
    }
    else if (strcmp(input_unit, "kg") == 0 && strcmp(output_unit, "lb") == 0) {
        output_value = input_value * 2.20462;
        printf("%f kg = %f lb", input_value, output_value);
    }
    else if (strcmp(input_unit, "lb") == 0 && strcmp(output_unit, "kg") == 0) {
        output_value = input_value / 2.20462;
        printf("%f lb = %f kg", input_value, output_value);
    }
    else {
        printf("Invalid conversion!\n");
    }

    return 0;
}