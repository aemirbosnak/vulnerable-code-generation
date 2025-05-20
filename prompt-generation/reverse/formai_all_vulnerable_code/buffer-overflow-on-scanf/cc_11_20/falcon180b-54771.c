//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: shape shifting
#include <stdio.h>
#include <string.h>

int main() {
    char hex[100] = {0};
    char decimal[100] = {0};
    int i, j, len, choice;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    printf("\nChoose an option:\n1. Convert hexadecimal to decimal\n2. Convert decimal to hexadecimal\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            len = strlen(hex);

            for (i = 0, j = 0; i < len; i++) {
                if (hex[i] >= '0' && hex[i] <= '9') {
                    decimal[j++] = hex[i];
                } else if (hex[i] >= 'A' && hex[i] <= 'F') {
                    decimal[j++] = hex[i] - 'A' + 10;
                } else if (hex[i] >= 'a' && hex[i] <= 'f') {
                    decimal[j++] = hex[i] - 'a' + 10;
                } else {
                    printf("Invalid character in hexadecimal number.\n");
                    return 0;
                }
            }

            decimal[j] = '\0';

            printf("\nDecimal equivalent: %s\n", decimal);

            break;

        case 2:
            len = strlen(decimal);

            for (i = 0, j = 0; i < len; i++) {
                if (decimal[i] >= '0' && decimal[i] <= '9') {
                    sprintf(&hex[j], "%c", decimal[i]);
                    j += 1;
                } else {
                    printf("Invalid character in decimal number.\n");
                    return 0;
                }
            }

            hex[j] = '\0';

            printf("\nHexadecimal equivalent: %s\n", hex);

            break;

        default:
            printf("Invalid choice.\n");
            return 0;
    }

    return 0;
}