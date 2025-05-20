//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000

int convert_hex(char *hex, char *decimal) {
    int i, j, k, length, base = 0;
    char *ptr;

    length = strlen(hex);
    for (i = 0; i < length; i++) {
        if (isdigit(hex[i])) {
            base = 10;
            break;
        } else if (isupper(hex[i])) {
            base = 16;
            break;
        } else if (islower(hex[i])) {
            base = 16;
            break;
        } else {
            printf("Invalid character %c\n", hex[i]);
            return 0;
        }
    }

    for (i = 0, j = 0; i < length; i++) {
        if (isdigit(hex[i])) {
            decimal[j++] = hex[i];
        } else {
            ptr = strchr("ABCDEF", hex[i]);
            if (ptr == NULL) {
                printf("Invalid character %c\n", hex[i]);
                return 0;
            }
            decimal[j++] = ptr - 'A' + 10;
        }
    }

    decimal[j] = '\0';

    if (base == 16) {
        for (i = strlen(decimal) - 1, j = 0; i >= 0; i--, j++) {
            k = 0;
            while (decimal[i] - '0' > 9) {
                decimal[i] -= 7;
                k++;
            }
            if (k > 0) {
                for (int l = 0; l < k; l++) {
                    decimal[i - l] += 'A' - '0' - 1;
                }
            }
        }
    }

    return 1;
}

int main() {
    char hex[MAX_LENGTH], decimal[MAX_LENGTH];

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    if (convert_hex(hex, decimal)) {
        printf("Decimal equivalent: %s\n", decimal);
    }

    return 0;
}