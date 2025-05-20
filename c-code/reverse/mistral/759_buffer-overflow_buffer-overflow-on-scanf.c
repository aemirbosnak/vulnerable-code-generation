#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    char choice;
    unsigned long long num, hex_or_dec;
    char hex[33];

    printf("Enter conversion choice (H for Hex to Dec, D for Dec to Hex): ");
    scanf(" %c", &choice);

    if (choice == 'H' || choice == 'h') {
        printf("Enter hexadecimal number: ");
        scanf("%s", hex);
        sscanf(hex, "%llx", &hex_or_dec);
        printf("Decimal equivalent: %llu\n", (unsigned long long)strtoull(hex, NULL, 16));
    } else if (choice == 'D' || choice == 'd') {
        printf("Enter decimal number: ");
        scanf("%llu", &num);
        printf("Hexadecimal equivalent: %llx\n", num);
    } else {
        printf("Invalid choice. Please enter H for Hex to Dec or D for Dec to Hex.\n");
    }

    return 0;
}
