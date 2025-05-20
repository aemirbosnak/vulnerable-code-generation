//Code Llama-13B DATASET v1.0 Category: Unit converter ; Style: puzzling
#include <stdio.h>

int main() {
    int unit = 1;
    char input;
    char output;
    double value;
    double result;

    printf("Enter a unit (e.g. cm, m, km): ");
    scanf("%c", &input);
    printf("Enter a value: ");
    scanf("%lf", &value);
    printf("Enter a unit to convert to (e.g. m, km): ");
    scanf("%c", &output);

    switch (input) {
        case 'c':
            unit = 1;
            break;
        case 'm':
            unit = 1000;
            break;
        case 'km':
            unit = 1000000;
            break;
        default:
            printf("Invalid unit\n");
            return 1;
    }

    switch (output) {
        case 'c':
            result = value * unit;
            break;
        case 'm':
            result = value / unit;
            break;
        case 'km':
            result = value / (unit * 1000);
            break;
        default:
            printf("Invalid unit\n");
            return 1;
    }

    printf("%.2f %c = %.2f %c\n", value, input, result, output);

    return 0;
}