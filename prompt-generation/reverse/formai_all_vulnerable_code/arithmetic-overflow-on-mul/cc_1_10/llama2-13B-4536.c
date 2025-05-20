//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

void arithmetic_adventure(int *numbers, int num_numbers) {
    int current_number = 0;
    int previous_number = 0;
    int sum = 0;
    int product = 1;
    int square = 0;
    int power = 0;
    int factorial = 1;

    srand(time(NULL));

    for (int i = 0; i < num_numbers; i++) {
        current_number = rand() % 100 + 1;

        if (i == 0) {
            previous_number = current_number;
        } else {
            sum += current_number;
            product *= current_number;
            square += current_number * current_number;
            power *= current_number;
            factorial *= current_number;
        }

        printf("%d + %d = %d\n", previous_number, current_number, sum);
        printf("%d x %d = %d\n", previous_number, current_number, product);
        printf("%d^2 = %d\n", previous_number, square);
        printf("%d^%d = %d\n", previous_number, power, factorial);
    }
}

int main() {
    int numbers[10];
    int num_numbers = 10;

    for (int i = 0; i < num_numbers; i++) {
        numbers[i] = MAGIC_NUMBER;
    }

    arithmetic_adventure(numbers, num_numbers);

    return 0;
}