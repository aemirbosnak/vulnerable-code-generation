//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int n, i, j, sign;
    double x, y, z, sum = 0, prod = 1;
    char op;

    srand(time(NULL));
    n = rand() % 10 + 1; // generate a random number between 1 and 10

    for (i = 0; i < n; i++) {
        x = rand() % 100;
        y = rand() % 100;
        z = rand() % 100;

        op = rand() % 4; // randomly choose an operation

        switch (op) {
            case 0: // addition
                sum += x + y + z;
                break;
            case 1: // subtraction
                sign = rand() % 2;
                if (sign == 0) {
                    sum -= x - y - z;
                } else {
                    sum += x - y - z;
                }
                break;
            case 2: // multiplication
                prod *= x * y * z;
                break;
            case 3: // division
                sign = rand() % 2;
                if (sign == 0) {
                    sum += x / y / z;
                } else {
                    sum -= x / y / z;
                }
                break;
        }
    }

    printf("The result is: %.2f\n", sum);

    return 0;
}