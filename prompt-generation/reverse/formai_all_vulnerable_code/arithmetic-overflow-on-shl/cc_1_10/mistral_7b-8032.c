//MISTRAL-7B DATASET v1.0 Category: Bitwise operations ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct {
    int data;
    int flag;
} BitElement;

void setBit(BitElement *element, int bitIndex) {
    element->flag |= 1 << bitIndex;
}

void clearBit(BitElement *element, int bitIndex) {
    element->flag &= ~(1 << bitIndex);
}

int checkBit(BitElement element, int bitIndex) {
    return (element.flag & (1 << bitIndex)) != 0;
}

int main() {
    BitElement elements[SIZE];
    int i, index, bitIndex;

    for (i = 0; i < SIZE; i++) {
        elements[i].data = i;
        elements[i].flag = 0;
    }

    for (i = 0; i < SIZE; i++) {
        printf("Element %d: Data = %d, Flags = %05d\n", i, elements[i].data, elements[i].flag);

        printf("Enter index and bit index to set bit: ");
        scanf("%d%d", &index, &bitIndex);

        if (index >= 0 && index < SIZE && bitIndex >= 0 && bitIndex < 32) {
            setBit(&elements[index], bitIndex);
            printf("Bit %d of Element %d set to 1.\n", bitIndex, index);
        } else {
            printf("Invalid index or bit index.\n");
        }

        printf("Enter index to clear bit: ");
        scanf("%d", &index);

        if (index >= 0 && index < SIZE) {
            printf("Enter bit index to clear: ");
            scanf("%d", &bitIndex);

            if (bitIndex >= 0 && bitIndex < 32) {
                clearBit(&elements[index], bitIndex);
                printf("Bit %d of Element %d cleared.\n", bitIndex, index);
            } else {
                printf("Invalid bit index.\n");
            }
        } else {
            printf("Invalid index.\n");
        }

        printf("Element %d: Data = %d, Flags = %05d\n", i, elements[i].data, elements[i].flag);
    }

    return 0;
}