//FormAI DATASET v1.0 Category: Unit converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    float input_value, output_value;
    char ch;

    printf("Welcome to the Unit Converter\n");

    do {
        printf("\nConvert from: \n");
        printf("(f) Fahrenheit\n");
        printf("(c) Celsius\n");
        printf("(i) Inches\n");
        printf("(m) Meters\n");
        printf("(q) Quit\n");
        printf("Enter your choice: ");

        ch = getchar();
        clear_input_buffer();

        switch (ch) {
            case 'f':
                printf("Enter temperature in Fahrenheit: ");
                scanf("%f", &input_value);
                clear_input_buffer();
                output_value = (input_value - 32) * 5 / 9;
                printf("%.2f Fahrenheit is equal to %.2f Celsius.\n", input_value, output_value);
                break;
            case 'c':
                printf("Enter temperature in Celsius: ");
                scanf("%f", &input_value);
                clear_input_buffer();
                output_value = input_value * 9 / 5 + 32;
                printf("%.2f Celsius is equal to %.2f Fahrenheit.\n", input_value, output_value);
                break;
            case 'i':
                printf("Enter length in inches: ");
                scanf("%f", &input_value);
                clear_input_buffer();
                output_value = input_value / 39.37;
                printf("%.2f inches is equal to %.2f meters.\n", input_value, output_value);
                break;
            case 'm':
                printf("Enter length in meters: ");
                scanf("%f", &input_value);
                clear_input_buffer();
                output_value = input_value * 39.37;
                printf("%.2f meters is equal to %.2f inches.\n", input_value, output_value);
                break;
            case 'q':
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
        }
    } while (ch != 'q');

    return 0;
}