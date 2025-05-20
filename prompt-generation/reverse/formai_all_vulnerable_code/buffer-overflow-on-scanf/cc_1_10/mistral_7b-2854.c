//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: ultraprecise
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define FXP_BITS 16
#define FXP_ONE ((1 << FXP_BITS) - 1)
#define FXP_EPSILON (1 << (FXP_BITS - 2))

typedef struct {
    int32_t integer;
    uint16_t fraction;
} fixed_point_t;

fixed_point_t sqrt_fixed(fixed_point_t x) {
    fixed_point_t x2, y, t;

    if (x.integer < 0) {
        fprintf(stderr, "Error: Negative input\n");
        x.integer = 0;
        x.fraction = 0;
    }

    x2.integer = x.integer * x.integer;
    x2.fraction = x.fraction * x.fraction;

    y.integer = 0;
    y.fraction = FXP_ONE >> 1;

    do {
        t = x2;
        x.integer = (x.integer + y.integer) >> 1;
        x.fraction = (x2.integer * x.fraction + x.integer * t.fraction) >> (FXP_BITS + 1);
        x2 = t;
    } while (x2.integer != x.integer || x.integer < y.integer);

    return x;
}

int main() {
    fixed_point_t num, result;

    printf("Enter a number: ");
    scanf("%d", &num.integer);
    num.fraction = 0;

    result = sqrt_fixed(num);

    printf("The square root of %d is %d.%04d\n", num.integer, result.integer, result.fraction);

    return 0;
}