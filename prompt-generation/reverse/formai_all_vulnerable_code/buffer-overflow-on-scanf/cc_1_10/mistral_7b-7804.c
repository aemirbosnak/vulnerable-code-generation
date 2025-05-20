//MISTRAL-7B DATASET v1.0 Category: Temperature Converter ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 50
#define MIN_TEMP_VALUE -32767
#define MAX_TEMP_VALUE 32767
#define F_TO_C_CONVERSION_FACTOR 1.8
#define C_TO_F_CONVERSION_FACTOR 32.0

void print_welcome_message() {
    printf("\nWelcome to Temperature Converter v1.0\n");
    printf("------------------------------------\n");
}

void print_conversion_instructions() {
    printf("\nInstructions:\n");
    printf("--------------\n");
    printf("Enter the temperature value in either Fahrenheit or Celsius.\n");
    printf("Press 'f' for Fahrenheit to Celsius conversion.\n");
    printf("Press 'c' for Celsius to Fahrenheit conversion.\n");
}

void get_user_input(char temperatureType, float *temperatureValue) {
    char input[MAX_INPUT_LENGTH];
    float inputValue;

    printf("\nEnter temperature value: ");
    scanf("%s", input);

    if (temperatureType == 'f') {
        inputValue = atof(input);
        *temperatureValue = inputValue;
    } else {
        inputValue = atof(input) * C_TO_F_CONVERSION_FACTOR;
        *temperatureValue = inputValue;
    }
}

void print_conversion_result(char temperatureType, float temperatureValue) {
    float convertedValue;

    if (temperatureType == 'f') {
        convertedValue = temperatureValue * F_TO_C_CONVERSION_FACTOR;
        printf("\n%0.2f degrees Fahrenheit is equal to %0.2f degrees Celsius.\n", temperatureValue, convertedValue);
    } else {
        convertedValue = temperatureValue / F_TO_C_CONVERSION_FACTOR;
        printf("\n%0.2f degrees Celsius is equal to %0.2f degrees Fahrenheit.\n", temperatureValue, convertedValue);
    }
}

int main() {
    char temperatureType;
    float temperatureValue;

    print_welcome_message();
    print_conversion_instructions();

    while (1) {
        scanf("%c", &temperatureType);

        if (temperatureType == 'f' || temperatureType == 'c') {
            get_user_input(temperatureType, &temperatureValue);

            if (temperatureValue < MIN_TEMP_VALUE || temperatureValue > MAX_TEMP_VALUE) {
                printf("\nInvalid temperature value. Please try again.\n");
                continue;
            }

            print_conversion_result(temperatureType, temperatureValue);
            break;
        } else {
            printf("\nInvalid input. Please press 'f' or 'c' and try again.\n");
        }
    }

    return 0;
}