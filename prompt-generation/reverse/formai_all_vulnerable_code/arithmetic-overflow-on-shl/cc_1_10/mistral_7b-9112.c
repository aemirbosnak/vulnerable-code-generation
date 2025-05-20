//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define MASK 0x0F

typedef struct {
    int data[SIZE];
} MyArray;

void printBinary(int number) {
    int i;
    for (i = 7; i >= 0; i--) {
        printf("%d", (number >> i) & 1);
    }
    printf("\n");
}

void performBitwise(MyArray *arr) {
    int i, j, temp, bitPos;
    for (i = 0; i < SIZE; i++) {
        printBinary(arr->data[i]);
        for (j = 0; j < 4; j++) {
            bitPos = i * 4 + j;
            temp = arr->data[i] << j;
            arr->data[i] = arr->data[i] | (arr->data[i] & ~(MASK << bitPos));
            arr->data[i] = arr->data[i] | (temp >> (32 - (j + 1)));
            printBinary(arr->data[i]);
            printf(" -> ");
        }
        printf("Done with array index %d\n", i);
    }
}

int main() {
    MyArray arr;
    int i;

    for (i = 0; i < SIZE; i++) {
        arr.data[i] = i;
    }

    printf("Initial Array:\n");
    for (i = 0; i < SIZE; i++) {
        printBinary(arr.data[i]);
        printf("\n");
    }

    printf("\nPerforming Bitwise Operations...\n");
    performBitwise(&arr);

    printf("\nFinal Array:\n");
    for (i = 0; i < SIZE; i++) {
        printBinary(arr.data[i]);
        printf("\n");
    }

    return 0;
}