//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    printf("Welcome to the C Scientific Calculator!\n");
    printf("Enter your equation: ");

    char equation[100];
    scanf("%s", equation);

    float result = 0;
    float power = 0;
    int sign = 1;
    int decimalPlaces = 0;

    int i = 0;
    while (i < strlen(equation) && equation[i]!= '\0') {
        if (equation[i] == '-') {
            sign *= -1;
        } else if (equation[i] == '+') {
            sign *= 1;
        } else if (equation[i] == '*') {
            power *= 10;
            if (decimalPlaces == 0) {
                decimalPlaces = 1;
            }
        } else if (equation[i] == '/') {
            power /= 10;
            if (decimalPlaces == 1) {
                decimalPlaces = 0;
            }
        } else if (equation[i] == '.') {
            decimalPlaces += 1;
        } else if (isdigit(equation[i]) || equation[i] == 'E') {
            if (i == 0) {
                result = strtod(equation, NULL);
                i++;
            } else {
                result += pow(10, power) * (equation[i] - '0');
                power = 0;
            }
        }
        i++;
    }

    printf("Result: %.2f\n", result * sign);

    return 0;
}