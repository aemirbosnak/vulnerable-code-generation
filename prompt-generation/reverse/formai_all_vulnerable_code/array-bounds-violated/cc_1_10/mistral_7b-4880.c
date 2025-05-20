//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char hex[17] = "0123456789ABCDEF"; /* hexadecimal digits */
int bin[32]; /* binary digits */
int i, j, k, m, n;
char str[MAX];

void itob(int dec) {
    for (i = 31; dec && i >= 0; dec--) {
        bin[i] = dec % 2;
        dec /= 2;
    }
}

void ibt(void) {
    for (i = 31, j = 0; i >= 0; i--)
        if (bin[i])
            putchar(hex[j++]);
    putchar('\n');
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hexadecimal string>\n", argv[0]);
        return 1;
    }

    for (i = 0; argv[1][i]; i++) {
        if (isdigit(argv[1][i]))
            n = argv[1][i] - '0';
        else if (isalpha(argv[1][i]))
            n = hex[toupper(argv[1][i]) - 'A'] * 10 + (argv[1][i] == 'A' ? 0 : 10);
        else {
            printf("Invalid character '%c' in hexadecimal string\n", argv[1][i]);
            return 1;
        }
        itob(n);
    }

    ibt();

    for (i = 0; i < 32; i++)
        str[i] = bin[i] + '0';

    for (i = 0, j = 31; i <= 31 && j >= 0; i++, j--)
        str[i] = str[i] == '0' ? str[j] : str[i];

    puts(str);

    return 0;
}