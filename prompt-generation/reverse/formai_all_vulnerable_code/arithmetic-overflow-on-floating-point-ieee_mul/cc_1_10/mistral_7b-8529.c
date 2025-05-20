//MISTRAL-7B DATASET v1.0 Category: Unit converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define INCH_TO_CM_RATIO 2.54f
#define CM_TO_INCH_RATIO 0.393701f

void print_instructions() {
    printf("\nWelcome to the Unit Converter!\n");
    printf("This program converts units of length between inches and centimeters.\n");
    printf("Enter 'i' to convert inches to centimeters.\n");
    printf("Enter 'c' to convert centimeters to inches.\n");
    printf("Enter 'q' to quit.\n");
}

float convert_inches_to_centimeters(float inches) {
    return inches * INCH_TO_CM_RATIO;
}

float convert_centimeters_to_inches(float centimeters) {
    return centimeters * CM_TO_INCH_RATIO;
}

int main() {
    float user_input;
    char user_choice;
    int valid_input = 0;

    do {
        print_instructions();

        scanf("%f %c", &user_input, &user_choice);

        switch (user_choice) {
            case 'i':
                printf("You entered %f inches.\n", user_input);
                printf("%f inches is equal to %f centimeters.\n", user_input, convert_inches_to_centimeters(user_input));
                valid_input = 1;
                break;

            case 'c':
                printf("You entered %f centimeters.\n", user_input);
                printf("%f centimeters is equal to %f inches.\n", user_input, convert_centimeters_to_inches(user_input));
                valid_input = 1;
                break;

            case 'q':
                printf("Goodbye! Thanks for using the Unit Converter.\n");
                return 0;

            default:
                printf("Invalid input. Please try again.\n");
                break;
        }

        if (!valid_input) {
            printf("Invalid input. Please enter a valid option.\n");
            valid_input = 0;
        }

    } while (1);

    return 0;
}