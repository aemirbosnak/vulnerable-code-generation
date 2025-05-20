//GEMINI-pro DATASET v1.0 Category: Temperature Converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <math.h>

#define TEMP_CONV_MAGIC_NUMBER 0xdeadbeef
#define TEMP_CONV_EPSILON 1e-9

typedef struct {
    unsigned int magic_number;
    double celsius;
    double fahrenheit;
} temp_conv_t;

int temp_conv_init(temp_conv_t *tc) {
    if (tc == NULL) {
        return -1;
    }

    tc->magic_number = TEMP_CONV_MAGIC_NUMBER;
    tc->celsius = 0.0;
    tc->fahrenheit = 0.0;

    return 0;
}

int temp_conv_destroy(temp_conv_t *tc) {
    if (tc == NULL) {
        return -1;
    }

    if (tc->magic_number != TEMP_CONV_MAGIC_NUMBER) {
        return -1;
    }

    tc->magic_number = 0;
    tc->celsius = 0.0;
    tc->fahrenheit = 0.0;

    return 0;
}

int temp_conv_set_celsius(temp_conv_t *tc, double celsius) {
    if (tc == NULL) {
        return -1;
    }

    if (tc->magic_number != TEMP_CONV_MAGIC_NUMBER) {
        return -1;
    }

    if (isnan(celsius) || isinf(celsius)) {
        return -1;
    }

    tc->celsius = celsius;
    tc->fahrenheit = celsius * 9.0 / 5.0 + 32.0;

    return 0;
}

int temp_conv_set_fahrenheit(temp_conv_t *tc, double fahrenheit) {
    if (tc == NULL) {
        return -1;
    }

    if (tc->magic_number != TEMP_CONV_MAGIC_NUMBER) {
        return -1;
    }

    if (isnan(fahrenheit) || isinf(fahrenheit)) {
        return -1;
    }

    tc->fahrenheit = fahrenheit;
    tc->celsius = (fahrenheit - 32.0) * 5.0 / 9.0;

    return 0;
}

int temp_conv_get_celsius(temp_conv_t *tc, double *celsius) {
    if (tc == NULL) {
        return -1;
    }

    if (tc->magic_number != TEMP_CONV_MAGIC_NUMBER) {
        return -1;
    }

    if (celsius == NULL) {
        return -1;
    }

    *celsius = tc->celsius;

    return 0;
}

int temp_conv_get_fahrenheit(temp_conv_t *tc, double *fahrenheit) {
    if (tc == NULL) {
        return -1;
    }

    if (tc->magic_number != TEMP_CONV_MAGIC_NUMBER) {
        return -1;
    }

    if (fahrenheit == NULL) {
        return -1;
    }

    *fahrenheit = tc->fahrenheit;

    return 0;
}

int temp_conv_is_equal(temp_conv_t *tc1, temp_conv_t *tc2) {
    if (tc1 == NULL || tc2 == NULL) {
        return -1;
    }

    if (tc1->magic_number != TEMP_CONV_MAGIC_NUMBER || tc2->magic_number != TEMP_CONV_MAGIC_NUMBER) {
        return -1;
    }

    return fabs(tc1->celsius - tc2->celsius) < TEMP_CONV_EPSILON && fabs(tc1->fahrenheit - tc2->fahrenheit) < TEMP_CONV_EPSILON;
}

int main(int argc, char **argv) {
    temp_conv_t tc1, tc2;

    if (argc != 3) {
        printf("Usage: %s <celsius> <fahrenheit>\n", argv[0]);
        return -1;
    }

    if (temp_conv_init(&tc1) != 0) {
        fprintf(stderr, "Error: temp_conv_init() failed\n");
        return -1;
    }

    if (temp_conv_init(&tc2) != 0) {
        fprintf(stderr, "Error: temp_conv_init() failed\n");
        return -1;
    }

    if (temp_conv_set_celsius(&tc1, atof(argv[1])) != 0) {
        fprintf(stderr, "Error: temp_conv_set_celsius() failed\n");
        return -1;
    }

    if (temp_conv_set_fahrenheit(&tc2, atof(argv[2])) != 0) {
        fprintf(stderr, "Error: temp_conv_set_fahrenheit() failed\n");
        return -1;
    }

    if (temp_conv_is_equal(&tc1, &tc2) != 0) {
        fprintf(stderr, "Error: temp_conv_is_equal() failed\n");
        return -1;
    }

    printf("Celsius: %.2f\n", tc1.celsius);
    printf("Fahrenheit: %.2f\n", tc1.fahrenheit);

    temp_conv_destroy(&tc1);
    temp_conv_destroy(&tc2);

    return 0;
}