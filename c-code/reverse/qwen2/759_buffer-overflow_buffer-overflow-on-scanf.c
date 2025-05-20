#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice, num;
    printf("Enter 1 for Hex to Dec, 2 for Dec to Hex: ");
    scanf("%d", &choice);
    printf("Enter number: ");
    scanf("%x", &num);

    if (choice == 1) {
        printf("Decimal: %d\n", num);
    } else if (choice == 2) {
        printf("Hexadecimal: %X\n", num);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
