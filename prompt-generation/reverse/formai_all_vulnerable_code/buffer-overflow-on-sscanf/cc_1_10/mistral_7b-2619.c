//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 50

void print_menu();
int data_validation(char* str);
void inches_to_centimeters(double inches);
void print_result(char* unit, double value);

int main() {
    char input[MAX_INPUT_LENGTH];
    double inches;

    while (1) {
        print_menu();
        fgets(input, MAX_INPUT_LENGTH, stdin);

        input[strcspn(input, "\n")] = '\0';

        if (data_validation(input) == 1) {
            sscanf(input, "%lf", &inches);
            inches_to_centimeters(inches);
            break;
        } else {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}

void print_menu() {
    printf("\nUnit Converter Menu\n");
    printf("----------------------\n");
    printf("Enter the length value in inches: ");
    printf("(Type 'quit' to exit)\n");
}

int data_validation(char* str) {
    int i, valid = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            valid = 1;
        } else if (str[i] == '.') {
            if (valid == 0) {
                valid = -1;
                break;
            }
        } else if (str[i] != '.' && str[i] != ' ') {
            valid = -1;
            break;
        }
    }

    if (valid >= 0) {
        return valid;
    } else {
        return -1;
    }
}

void inches_to_centimeters(double inches) {
    double centimeters = inches * 2.54;

    print_result("centimeters", centimeters);
}

void print_result(char* unit, double value) {
    printf("\nThe equivalent %s is: %.2f\n", unit, value);
}