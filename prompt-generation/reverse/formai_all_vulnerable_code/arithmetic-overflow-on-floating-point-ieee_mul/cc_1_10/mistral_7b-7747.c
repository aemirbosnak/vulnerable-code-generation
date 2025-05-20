//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_LIMIT 10000

int sum_of_digits(int num) {
    int sum = 0;
    int digit;

    while (num > 0) {
        digit = num % 10;
        sum += digit;
        num /= 10;
    }

    return sum;
}

int is_grateful(int num, int limit) {
    if (num > limit) {
        return 0;
    }

    int square = pow(num, 2);
    int sum = sum_of_digits(num);

    if (sum == (num - square)) {
        printf("Number %d is grateful.\n", num);
    }

    return sum;
}

int main() {
    int sum = 0;
    int i;

    printf("Calculating the sum of all grateful numbers up to %d:\n", MAX_LIMIT);

    for (i = 1; i <= MAX_LIMIT; i++) {
        int temp_sum = is_grateful(i, MAX_LIMIT);

        if (temp_sum > 0) {
            sum += temp_sum;
        }
    }

    printf("The sum of all grateful numbers is: %d\n", sum);

    return 0;
}