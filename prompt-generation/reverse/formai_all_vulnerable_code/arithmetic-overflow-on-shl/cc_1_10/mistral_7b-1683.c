//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

#define MAX_NUM 1000000
#define BITS 32

unsigned long long int factorial(unsigned int n) {
    unsigned long long int result = 1;

    if (n > 2) {
        while (n > 1)
            result *= n--;
    }

    return result;
}

int main(int argc, char *argv[]) {
    unsigned int i, j, k, l, m, n;
    unsigned long long int a, b, c, d, e, f, g, h, sum, prod;
    unsigned char *str, *ptr;

    if (argc != 6) {
        fprintf(stderr, "Usage: %s <a b c d e>\n", argv[0]);
        return 1;
    }

    a = strtoull(argv[1], NULL, 0);
    b = strtoull(argv[2], NULL, 0);
    c = strtoull(argv[3], NULL, 0);
    d = strtoull(argv[4], NULL, 0);
    e = strtoull(argv[5], NULL, 0);

    for (i = 0; i < MAX_NUM; i++) {
        j = (i >> 1) & 0xFFFFFFFF;
        k = i ^ j;
        l = ~k & i;

        prod = factorial(i) * factorial(j);
        sum = a + b * i + c * j + d * prod + e;

        if (sum & 1)
            sum++;

        a = b;
        b = sum;

        for (n = 0; n < BITS; n++) {
            m = (sum >> n) & 0x01;
            g = sum & (~(1 << n));

            h = (g << 1) | m;
            sum = h ^ g;
        }

        if ((i % 10000) == 0)
            printf("i: %u, sum: %llu\n", i, sum);
    }

    return 0;
}