//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 100

typedef struct {
    char unit[10];
    float value;
} Temperature;

void fahrenheit_to_celsius(Temperature *temp) {
    temp->value = (temp->value - 32.0) * 5.0 / 9.0;
    strcpy(temp->unit, "Celsius");
}

void celsius_to_fahrenheit(Temperature *temp) {
    temp->value = temp->value * 9.0 / 5.0 + 32.0;
    strcpy(temp->unit, "Fahrenheit");
}

int validate_input(char *input) {
    int i, is_valid = 1;
    Temperature temp;

    sscanf(input, "%f%s", &temp.value, temp.unit);

    if (sscanf(input, "%f%s", &temp.value, temp.unit) != 2) {
        printf("Invalid input: %s\n", input);
        is_valid = 0;
    } else {
        if (strcmp(temp.unit, "Fahrenheit") == 0) {
            fahrenheit_to_celsius(&temp);
        } else if (strcmp(temp.unit, "Celsius") == 0) {
            celsius_to_fahrenheit(&temp);
        } else {
            printf("Unsupported unit: %s\n", temp.unit);
            is_valid = 0;
        }

        printf("%.2f %s\n", temp.value, temp.unit);
    }

    return is_valid;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    int is_valid = 0;

    while (!is_valid) {
        printf("Enter temperature value and unit (Fahrenheit or Celsius): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        is_valid = validate_input(input);
    }

    return 0;
}