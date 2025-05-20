//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NUMBERS 1000
#define MAX_DIGITS 10

typedef struct {
    int value;
    int digits;
} Number;

void generate_random_number(Number *number) {
    int i;
    for (i = 0; i < MAX_DIGITS; i++) {
        number->value = number->value * 10 + rand() % 10;
        number->digits++;
    }
}

int compare_numbers(const void *a, const void *b) {
    const Number *num1 = a;
    const Number *num2 = b;
    if (num1->value < num2->value) {
        return -1;
    } else if (num1->value > num2->value) {
        return 1;
    } else {
        return 0;
    }
}

void print_number(const Number *number) {
    int i;
    for (i = number->digits - 1; i >= 0; i--) {
        printf("%d", number->value / (int)pow(10, i) % 10);
    }
}

int main() {
    srand(time(NULL));
    Number numbers[MAX_NUMBERS];
    int i;
    for (i = 0; i < MAX_NUMBERS; i++) {
        generate_random_number(&numbers[i]);
    }
    qsort(numbers, MAX_NUMBERS, sizeof(Number), compare_numbers);
    printf("Sorted numbers:\n");
    for (i = 0; i < MAX_NUMBERS; i++) {
        print_number(&numbers[i]);
        printf("\n");
    }
    return 0;
}