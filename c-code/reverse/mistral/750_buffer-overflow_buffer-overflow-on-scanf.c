#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char hex[7];
    int decimal;

    printf("Enter a hexadecimal number (up to 6 characters): ");
    scanf("%s", hex);

    if (strlen(hex) > 6) {
        printf("Buffer overflow vulnerability detected.\n");
        return 1;
    }

    decimal = strtol(hex, NULL, 16);
    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}
