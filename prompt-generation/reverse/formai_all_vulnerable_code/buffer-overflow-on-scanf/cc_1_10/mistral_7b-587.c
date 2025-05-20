//MISTRAL-7B DATASET v1.0 Category: Prime Number Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

typedef uint64_t ulong;

bool is_prime(ulong num) {
    if (num <= 1) return false;
    if (num <= 3) return true;

    bool is_prime_num = true;

    for (ulong i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            is_prime_num = false;
            break;
        }
    }

    return is_prime_num;
}

void print_prime_numbers(ulong start, ulong end) {
    if (start > end) {
        ulong temp = start;
        start = end;
        end = temp;
    }

    for (ulong i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%llu ", i);
        }
    }

    printf("\n");
}

int main() {
    ulong start, end;

    printf("Enter the range (start-end): ");
    scanf("%llu%llu", &start, &end);

    printf("Prime Numbers between %llu and %llu:\n", start, end);
    print_prime_numbers(start, end);

    return 0;
}