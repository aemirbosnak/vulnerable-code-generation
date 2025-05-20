#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    char hex[100];
    int dec;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    dec = (int)strtol(hex, NULL, 16);
    printf("Decimal equivalent: %d\n", dec);

    return 0;
}
