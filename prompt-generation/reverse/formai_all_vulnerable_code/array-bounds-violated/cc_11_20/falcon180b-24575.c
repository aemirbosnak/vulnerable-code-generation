//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char hex[100], str[100];
    int len, i, j;

    // Check if user entered a hexadecimal string
    if (argc == 1) {
        printf("Enter a hexadecimal string: ");
        fgets(hex, sizeof(hex), stdin);
        len = strlen(hex);

        // Remove newline character from input
        hex[len - 1] = '\0';

        // Convert hexadecimal string to uppercase
        for (i = 0; i < len; i++) {
            hex[i] = toupper(hex[i]);
        }

        // Convert hexadecimal to decimal
        printf("Hexadecimal: %s\n", hex);
        printf("Decimal: ");
        for (i = 0; i < len; i++) {
            if (hex[i] >= '0' && hex[i] <= '9') {
                printf("%d", hex[i] - '0');
            } else if (hex[i] >= 'A' && hex[i] <= 'F') {
                printf("%d", hex[i] - 'A' + 10);
            }
        }
        printf("\n");
    } else {
        // Convert decimal to hexadecimal
        printf("Enter a decimal number: ");
        scanf("%s", str);
        len = strlen(str);

        // Remove newline character from input
        str[len - 1] = '\0';

        // Convert decimal to hexadecimal
        for (i = 0, j = 0; i < len; i++) {
            if (str[i] == '.') {
                continue;
            }
            if (isdigit(str[i])) {
                printf("%d", str[i] - '0');
            } else if (isalpha(str[i])) {
                printf("%c", toupper(str[i]));
            } else {
                printf("Error: Invalid input\n");
                return 1;
            }
        }
    }

    return 0;
}