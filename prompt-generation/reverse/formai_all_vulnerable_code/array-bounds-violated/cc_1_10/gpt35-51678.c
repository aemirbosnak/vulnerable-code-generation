//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Sherlock Holmes
#include <stdio.h>
#include <ctype.h>

int main()
{
    char hex[17];
    long decimal, place;
    int i = 0, digit, invalid = 0;

    printf("Enter a hexadecimal number: ");
    fgets(hex, sizeof(hex), stdin);

    if (hex[0] == '\n') {
        printf("You entered nothing!\n");
        return 1;
    }

    if (hex[strlen(hex) - 1] != '\n') {
        scanf("%*[^\n]");
        scanf("%*c");
    }

    if (hex[0] == '0' && tolower(hex[1]) == 'x') {
        i = 2;
    }

    decimal = 0;
    place = 1;

    for (; i < strlen(hex); i++) {
        if (isxdigit(hex[i])) {
            if (isdigit(hex[i])) {
                digit = hex[i] - '0';
            }
            else {
                digit = tolower(hex[i]) - 'a' + 10;
            }

            decimal += digit * place;
            place *= 16;
        }
        else {
            printf("Invalid hexadecimal digit '%c' detected at position %d!\n", hex[i], i + 1);
            invalid = 1;
            break;
        }
    }

    if (!invalid) {
        printf("The decimal equivalent of hexadecimal number '%s' is: %ld\n", hex, decimal);
    }

    return 0;
}