//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char hex[1024];
    char ascii[1024];
    int i, j;
    int len = 0;
    int is_hex = 0;
    int is_ascii = 0;
    int is_binary = 0;
    int is_decimal = 0;
    int is_octal = 0;
    int is_uppercase = 0;
    int is_lowercase = 0;
    int is_invalid = 0;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);

    for (i = 0; i < strlen(hex); i++) {
        if (isdigit(hex[i])) {
            is_decimal = 1;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            is_uppercase = 1;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            is_lowercase = 1;
        } else {
            is_invalid = 1;
            break;
        }
    }

    if (is_decimal) {
        printf("Decimal: %d\n", atoi(hex));
    } else if (is_uppercase) {
        printf("ASCII: %c\n", hex[0]);
    } else if (is_lowercase) {
        printf("ASCII: %c\n", hex[0]);
    } else if (is_invalid) {
        printf("Invalid input\n");
    } else {
        for (i = 0; i < strlen(hex); i++) {
            if (isdigit(hex[i])) {
                ascii[len++] = hex[i];
            } else if (hex[i] >= 'A' && hex[i] <= 'F') {
                ascii[len++] = hex[i] - 'A' + 10;
            } else if (hex[i] >= 'a' && hex[i] <= 'f') {
                ascii[len++] = hex[i] - 'a' + 10;
            } else {
                is_invalid = 1;
                break;
            }
        }

        if (is_invalid) {
            printf("Invalid input\n");
        } else {
            ascii[len] = '\0';
            printf("ASCII: %s\n", ascii);
        }
    }

    return 0;
}