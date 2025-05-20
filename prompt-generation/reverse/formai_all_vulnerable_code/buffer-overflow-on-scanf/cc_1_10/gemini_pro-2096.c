//GEMINI-pro DATASET v1.0 Category: Bitwise operations ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

// 128 bit integer type
typedef uint64_t uint128_t;

// 128 bit integer constants
#define UINT128_C(hi, lo) (((uint128_t)(hi) << 64) | (uint128_t)(lo))
#define UINT128_MAX UINT128_C(0xFFFFFFFFFFFFFFFF, 0xFFFFFFFFFFFFFFFF)
#define UINT128_MIN UINT128_C(0x0000000000000000, 0x0000000000000000)

// 128 bit integer operations
uint128_t uint128_add(uint128_t a, uint128_t b) {
    uint128_t sum = a + b;
    return sum < a || sum < b ? UINT128_MAX : sum;
}

uint128_t uint128_sub(uint128_t a, uint128_t b) {
    uint128_t diff = a - b;
    return diff > a ? UINT128_MIN : diff;
}

uint128_t uint128_mul(uint128_t a, uint128_t b) {
    uint128_t lo = a * b;
    uint128_t hi = ((a >> 64) * b + (lo >> 64)) >> 64;
    return hi ? UINT128_MAX : lo;
}

uint128_t uint128_div(uint128_t a, uint128_t b) {
    assert(b != 0);
    uint128_t q = 0;
    uint128_t r = a;
    for (int i = 127; i >= 0; i--) {
        r <<= 1;
        q <<= 1;
        uint128_t t = b << (127 - i);
        if (r >= t) {
            r -= t;
            q |= 1;
        }
    }
    return q;
}

uint128_t uint128_mod(uint128_t a, uint128_t b) {
    assert(b != 0);
    uint128_t q = uint128_div(a, b);
    return uint128_sub(a, uint128_mul(q, b));
}

// 128 bit integer input and output
void uint128_input(uint128_t *a) {
    char buf[33];
    scanf("%s", buf);
    int len = strlen(buf);
    assert(len <= 32);
    *a = 0;
    for (int i = 0; i < len; i++) {
        *a <<= 4;
        if (buf[i] >= '0' && buf[i] <= '9') {
            *a |= buf[i] - '0';
        } else if (buf[i] >= 'A' && buf[i] <= 'F') {
            *a |= buf[i] - 'A' + 10;
        } else if (buf[i] >= 'a' && buf[i] <= 'f') {
            *a |= buf[i] - 'a' + 10;
        } else {
            assert(0);
        }
    }
}

void uint128_output(uint128_t a) {
    char buf[33];
    int len = 0;
    do {
        int d = a & 0xF;
        a >>= 4;
        buf[len++] = d < 10 ? d + '0' : d + 'A' - 10;
    } while (a != 0);
    buf[len] = '\0';
    printf("%s\n", buf);
}

// Main function
int main() {
    uint128_t a, b;
    uint128_input(&a);
    uint128_input(&b);
    uint128_output(uint128_add(a, b));
    uint128_output(uint128_sub(a, b));
    uint128_output(uint128_mul(a, b));
    uint128_output(uint128_div(a, b));
    uint128_output(uint128_mod(a, b));
    return 0;
}