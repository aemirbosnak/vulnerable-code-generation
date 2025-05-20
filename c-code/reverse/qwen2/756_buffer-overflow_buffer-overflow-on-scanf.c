#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void hex_to_dec(char *hex) {
    long dec = strtol(hex, NULL, 16);
    printf("Decimal: %ld\n", dec);
}

void dec_to_hex(long dec) {
    char hex[50];
    sprintf(hex, "%lx", dec);
    printf("Hexadecimal: %s\n", hex);
}

int main() {
    int choice;
    char input[100];

    while (1) {
        printf("Choose conversion:\n");
        printf("1. Hex to Dec\n");
        printf("2. Dec to Hex\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        if (choice == 3) break;

        printf("Enter value: ");
        scanf("%s", input);

        switch (choice) {
            case 1:
                hex_to_dec(input);
                break;
            case 2:
                dec_to_hex(atol(input));
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
