//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 1000
#define BITS_IN_BYTE 8

typedef unsigned int uint;

void print_binary(uint num) {
    int i;
    for (i = BITS_IN_BYTE * sizeof(num); i--; ) {
        putchar(num & 1 ? '1' : '0');
        num >>= 1;
    }
    putchar('\n');
}

int main() {
    srand(time(NULL));
    uint a[MAX_SIZE], i, j, temp;

    for (i = 0; i < MAX_SIZE; i++)
        a[i] = rand() % (1 << BITS_IN_BYTE * sizeof(uint));

    for (i = 0; i < MAX_SIZE - 1; i++) {
        for (j = i + 1; j < MAX_SIZE; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    printf("Unsorted Array:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        print_binary(a[i]);
        printf("Decimal: %d\n", a[i]);
    }

    printf("\nSorted Array:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        print_binary(a[i]);
        printf("Decimal: %d\n", a[i]);
    }

    return 0;
}