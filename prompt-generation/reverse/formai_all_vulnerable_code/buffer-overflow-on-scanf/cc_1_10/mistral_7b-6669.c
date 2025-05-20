//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: statistical
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_INT32 (INT32_MAX / 2)
#define MIN_INT32 (-(INT32_MAX / 2) - 1)

typedef struct {
    int32_t num;
    int32_t sum_bits;
    int32_t prod_bits;
    int32_t count;
} bitwise_stat;

void initialize_bitwise_stat(bitwise_stat* stat) {
    stat->sum_bits = 0;
    stat->prod_bits = 1;
    stat->count = 0;
}

void process_number(bitwise_stat* stat, int32_t num) {
    stat->num = num;
    int32_t temp = num;
    int32_t sum = 0;
    int32_t prod = 1;

    for (int i = 0; i < CHAR_BIT * sizeof(int32_t); i++) {
        sum += (num & 1) << i;
        prod *= (num & 1);
        num >>= 1;
    }

    stat->sum_bits += sum;
    stat->prod_bits *= prod;
    stat->count++;
}

void print_statistics(const bitwise_stat* stat) {
    printf("Number: %d\n", stat->num);
    printf("Sum of bits: %d\n", stat->sum_bits);
    printf("Product of bits: %d\n", stat->prod_bits);
    printf("Average bits per number: %.2f\n", (float)stat->sum_bits / stat->count);
}

int main() {
    bitwise_stat stats[10];
    for (int i = 0; i < 10; i++) {
        int32_t num;
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);

        if (num < MIN_INT32 || num > MAX_INT32) {
            printf("Invalid number. Please enter a 32-bit integer.\n");
            continue;
        }

        process_number(&stats[i], num);
    }

    printf("\nStatistics for the entered numbers:\n");
    for (int i = 0; i < 10; i++) {
        print_statistics(&stats[i]);
        printf("\n");
    }

    return 0;
}