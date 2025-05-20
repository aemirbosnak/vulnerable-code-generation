#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int is_hex(char c) {
    return (isdigit(c) || (isalpha(c) && tolower(c) >= 'a' && tolower(c) <= 'f'));
}

int hex_to_dec(const char *hex) {
    int dec = 0;
    while (*hex) {
        if (!is_hex(*hex)) {
            fprintf(stderr, "Invalid hexadecimal character: %c\n", *hex);
            exit(EXIT_FAILURE);
        }
        dec *= 16;
        if (isdigit(*hex))
            dec += *hex - '0';
        else
            dec += tolower(*hex) - 'a' + 10;
        hex++;
    }
    return dec;
}

void dec_to_hex(int dec) {
    if (dec == 0) {
        printf("0");
        return;
    }
    const char *digits = "0123456789abcdef";
    while (dec > 0) {
        putchar(digits[dec % 16]);
        dec /= 16;
    }
    putchar('\n');
}

int main() {
    char input[100];
    printf("Enter a hexadecimal number: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from input
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    int dec = hex_to_dec(input);
    printf("Decimal representation: %d\n", dec);

    printf("Enter a decimal number: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove newline character from input
        len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        int num = atoi(input);
        printf("Hexadecimal representation: ");
        dec_to_hex(num);
    }

    return 0;
}
