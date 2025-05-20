//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char binary[MAX_SIZE];
    int decimal;
} BinaryConverter;

void initialize(BinaryConverter *bc) {
    memset(bc->binary, 0, MAX_SIZE);
    bc->decimal = 0;
}

void convert(BinaryConverter *bc, int decimal) {
    char *binary = bc->binary;
    int i = 0;

    while (decimal > 0) {
        if (decimal & 1) {
            *binary++ = '1';
        } else {
            *binary++ = '0';
        }
        decimal >>= 1;
        i++;
    }

    while (i < MAX_SIZE) {
        *binary++ = '0';
        i++;
    }

    *binary = '\0';
    bc->decimal = decimal;
}

void display(BinaryConverter *bc) {
    printf("Binary: %s\n", bc->binary);
    printf("Decimal: %d\n", bc->decimal);
}

int main() {
    BinaryConverter bc;
    initialize(&bc);

    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    convert(&bc, decimal);
    display(&bc);

    return 0;
}