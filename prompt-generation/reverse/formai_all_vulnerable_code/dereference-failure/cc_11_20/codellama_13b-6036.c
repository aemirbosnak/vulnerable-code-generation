//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: lively
/*
 * Scientific Calculator Implementation
 *
 * A program to perform scientific calculations using a
 * command-line interface.
 *
 * Usage:
 *      ./calc <command> <arguments>
 *
 * Commands:
 *      sin <number>     - Calculate the sine of a number
 *      cos <number>     - Calculate the cosine of a number
 *      tan <number>     - Calculate the tangent of a number
 *      log <number>     - Calculate the natural logarithm of a number
 *      log10 <number>   - Calculate the base 10 logarithm of a number
 *      sqrt <number>    - Calculate the square root of a number
 *      pow <number> <power> - Calculate the number raised to the power
 *
 * Examples:
 *      ./calc sin 0.5
 *      ./calc cos 3.14
 *      ./calc tan 0.25
 *      ./calc log 100
 *      ./calc log10 1000
 *      ./calc sqrt 16
 *      ./calc pow 2 8
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command> <arguments>\n", argv[0]);
        return 1;
    }

    char *command = argv[1];
    double number;
    double result;

    if (strcmp(command, "sin") == 0) {
        if (argc < 3) {
            printf("Usage: %s sin <number>\n", argv[0]);
            return 1;
        }

        number = atof(argv[2]);
        result = sin(number);
    } else if (strcmp(command, "cos") == 0) {
        if (argc < 3) {
            printf("Usage: %s cos <number>\n", argv[0]);
            return 1;
        }

        number = atof(argv[2]);
        result = cos(number);
    } else if (strcmp(command, "tan") == 0) {
        if (argc < 3) {
            printf("Usage: %s tan <number>\n", argv[0]);
            return 1;
        }

        number = atof(argv[2]);
        result = tan(number);
    } else if (strcmp(command, "log") == 0) {
        if (argc < 3) {
            printf("Usage: %s log <number>\n", argv[0]);
            return 1;
        }

        number = atof(argv[2]);
        result = log(number);
    } else if (strcmp(command, "log10") == 0) {
        if (argc < 3) {
            printf("Usage: %s log10 <number>\n", argv[0]);
            return 1;
        }

        number = atof(argv[2]);
        result = log10(number);
    } else if (strcmp(command, "sqrt") == 0) {
        if (argc < 3) {
            printf("Usage: %s sqrt <number>\n", argv[0]);
            return 1;
        }

        number = atof(argv[2]);
        result = sqrt(number);
    } else if (strcmp(command, "pow") == 0) {
        if (argc < 4) {
            printf("Usage: %s pow <number> <power>\n", argv[0]);
            return 1;
        }

        number = atof(argv[2]);
        double power = atof(argv[3]);
        result = pow(number, power);
    } else {
        printf("Invalid command: %s\n", command);
        return 1;
    }

    printf("%s(%f) = %f\n", command, number, result);

    return 0;
}