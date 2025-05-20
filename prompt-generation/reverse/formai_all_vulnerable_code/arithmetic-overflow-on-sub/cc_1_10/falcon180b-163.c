//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 100
#define MAX_LEN 10

struct num {
    char str[MAX_LEN];
    int bit;
    int len;
};

void set_bit(struct num *num, int pos) {
    int mask = 1 << pos;
    num->bit |= mask;
}

void clear_bit(struct num *num, int pos) {
    int mask = ~(1 << pos);
    num->bit &= mask;
}

void toggle_bit(struct num *num, int pos) {
    int mask = 1 << pos;
    num->bit ^= mask;
}

void set_bit_str(struct num *num, int pos) {
    int mask = 1 << pos;
    num->str[num->len++] = '1';
    num->bit |= mask;
}

void clear_bit_str(struct num *num, int pos) {
    int mask = ~(1 << pos);
    num->str[--num->len] = '0';
    num->bit &= mask;
}

void toggle_bit_str(struct num *num, int pos) {
    int mask = 1 << pos;
    if (num->str[num->len - 1] == '1') {
        num->str[--num->len] = '0';
        num->bit &= ~mask;
    } else {
        num->str[num->len++] = '1';
        num->bit |= mask;
    }
}

void print_num(struct num *num) {
    printf("Bit representation: %d\n", num->bit);
    printf("Binary string: %s\n", num->str);
}

int main() {
    struct num num;
    memset(&num, 0, sizeof(struct num));

    printf("Enter a binary number (up to %d bits):\n", MAX_NUM);
    scanf("%s", num.str);

    if (strlen(num.str) > MAX_NUM) {
        printf("Error: Input is too long\n");
        return 1;
    }

    printf("Number of bits: %d\n", strlen(num.str));
    printf("Bit representation: %d\n", num.bit);
    printf("Binary string: %s\n", num.str);

    set_bit_str(&num, 0);
    print_num(&num);

    clear_bit_str(&num, 0);
    print_num(&num);

    toggle_bit_str(&num, 0);
    print_num(&num);

    return 0;
}