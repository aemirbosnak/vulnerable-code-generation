//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NUM 1000000
#define MAX_NUM_DIGITS 6

int main() {
    srand(time(NULL));
    int num1, num2, num3, num4;
    int num1_digits, num2_digits, num3_digits, num4_digits;
    int i, j, k, l, m;
    int sum;

    num1 = rand() % MAX_NUM;
    num2 = rand() % MAX_NUM;
    num3 = rand() % MAX_NUM;
    num4 = rand() % MAX_NUM;

    num1_digits = (int)log10(num1) + 1;
    num2_digits = (int)log10(num2) + 1;
    num3_digits = (int)log10(num3) + 1;
    num4_digits = (int)log10(num4) + 1;

    if (num1_digits > MAX_NUM_DIGITS) {
        num1 = rand() % MAX_NUM;
        num1_digits = (int)log10(num1) + 1;
    }

    if (num2_digits > MAX_NUM_DIGITS) {
        num2 = rand() % MAX_NUM;
        num2_digits = (int)log10(num2) + 1;
    }

    if (num3_digits > MAX_NUM_DIGITS) {
        num3 = rand() % MAX_NUM;
        num3_digits = (int)log10(num3) + 1;
    }

    if (num4_digits > MAX_NUM_DIGITS) {
        num4 = rand() % MAX_NUM;
        num4_digits = (int)log10(num4) + 1;
    }

    printf("Number 1: %d (%d digits)\n", num1, num1_digits);
    printf("Number 2: %d (%d digits)\n", num2, num2_digits);
    printf("Number 3: %d (%d digits)\n", num3, num3_digits);
    printf("Number 4: %d (%d digits)\n", num4, num4_digits);

    sum = num1 + num2 + num3 + num4;

    printf("\nSum: %d\n", sum);

    return 0;
}