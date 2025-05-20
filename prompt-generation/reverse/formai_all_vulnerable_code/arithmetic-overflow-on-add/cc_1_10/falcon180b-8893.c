//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBERS 1000
#define MAX_DIGITS 6

int main() {
    int numbers[MAX_NUMBERS];
    int num_digits[MAX_NUMBERS];
    int i, j, k;
    int sum = 0;
    int count = 0;
    int max_num_digits = 0;
    int max_count = 0;
    int max_sum = 0;

    srand(time(NULL));

    for (i = 0; i < MAX_NUMBERS; i++) {
        numbers[i] = rand() % 1000000;
        num_digits[i] = (int)log10(numbers[i]) + 1;
    }

    for (i = 0; i < MAX_NUMBERS; i++) {
        for (j = 0; j < num_digits[i]; j++) {
            sum += (numbers[i] / (int)pow(10, j)) % 10;
        }
        count++;
    }

    for (i = 0; i < MAX_NUMBERS; i++) {
        if (num_digits[i] > max_num_digits) {
            max_num_digits = num_digits[i];
        }
    }

    for (i = 0; i < MAX_NUMBERS; i++) {
        if (num_digits[i] == max_num_digits) {
            if (count > max_count) {
                max_count = count;
                max_sum = sum;
            }
        }
    }

    printf("The maximum sum of digits is %d.\n", max_sum);

    return 0;
}