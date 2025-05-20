//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: optimized
#include <stdio.h>
#include <stdint.h>

typedef struct {
    uint32_t a:1;
    uint32_t b:1;
    uint32_t c:1;
    uint32_t d:1;
    uint32_t e:1;
    uint32_t f:1;
    uint32_t g:1;
    uint32_t h:1;
    uint32_t i:1;
    uint32_t j:1;
    uint32_t k:1;
    uint32_t l:1;
    uint32_t m:1;
    uint32_t n:1;
    uint32_t o:1;
    uint32_t p:1;
    uint32_t q:1;
    uint32_t r:1;
    uint32_t s:1;
    uint32_t t:1;
    uint32_t u:1;
    uint32_t v:1;
    uint32_t w:1;
    uint32_t x:1;
    uint32_t y:1;
    uint32_t z:1;
} mybits_t;

void set_bit(uint32_t *num, int bit_num) {
    (*num) |= (1 << bit_num);
}

void clear_bit(uint32_t *num, int bit_num) {
    (*num) &= ~(1 << bit_num);
}

void toggle_bit(uint32_t *num, int bit_num) {
    (*num) ^= (1 << bit_num);
}

void print_bits(uint32_t num) {
    mybits_t mybits;
    int i;

    for (i = 31; i >= 0; i--) {
        mybits.i = (num & (1 << i)) >> i;
        printf("%d", mybits.i);
    }

    printf("\n");
}

int main() {
    uint32_t num = 0;
    int i;

    for (i = 0; i < 32; i++) {
        set_bit(&num, i);
        printf("Setting bit %d: ", i);
        print_bits(num);

        clear_bit(&num, i);
        printf("Clearing bit %d: ", i);
        print_bits(num);

        toggle_bit(&num, i);
        printf("Toggling bit %d: ", i);
        print_bits(num);
    }

    return 0;
}