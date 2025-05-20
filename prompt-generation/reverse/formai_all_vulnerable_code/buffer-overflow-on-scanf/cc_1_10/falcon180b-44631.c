//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NUMBERS 100

typedef struct {
    double value;
    int index;
} number_t;

int compare_numbers(const void *a, const void *b) {
    const number_t *num1 = a;
    const number_t *num2 = b;

    if (num1->value > num2->value) {
        return 1;
    } else if (num1->value < num2->value) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    number_t numbers[MAX_NUMBERS];
    int num_count = 0;
    double sum = 0.0;
    double average;
    int mode_count = 0;
    int mode_index = -1;

    printf("Enter up to %d numbers (enter a non-numeric value to stop):\n", MAX_NUMBERS - 1);

    while (num_count < MAX_NUMBERS && scanf("%lf", &numbers[num_count].value) == 1) {
        num_count++;
    }

    qsort(numbers, num_count, sizeof(number_t), compare_numbers);

    for (int i = 0; i < num_count; i++) {
        sum += numbers[i].value;
        if (numbers[i].value == numbers[0].value) {
            mode_count++;
        }
    }

    average = sum / num_count;

    if (mode_count > 1) {
        printf("There is no mode.\n");
    } else {
        printf("Mode: %.2lf\n", numbers[0].value);
    }

    printf("Average: %.2lf\n", average);

    return 0;
}