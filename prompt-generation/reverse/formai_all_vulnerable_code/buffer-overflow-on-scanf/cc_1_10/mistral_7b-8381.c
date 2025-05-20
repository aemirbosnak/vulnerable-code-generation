//MISTRAL-7B DATASET v1.0 Category: Hexadecimal Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_HEX_STRING_SIZE 256
#define MAX_NUM_DIGITS 16

void decodeHexString(char hexString[]) {
    int hex, i, j;
    unsigned char decNumber[MAX_NUM_DIGITS];
    int index = 0;

    for (i = 0; i < strlen(hexString); i += 2) {
        if ((hex = strxtoi(hexString + i, NULL, 16)) >= 0x10)
            hex -= 0x0A;

        decNumber[index++] = (unsigned char)hex;
    }

    for (i = 0; i < index; i++)
        printf("%X", decNumber[i]);
    printf("\n");
}

int strxtoi(const char *string, char **endptr, int base) {
    int number = 0, i = 0, sign = 1;

    if (base < 2 || base > 36)
        return -1;

    if (*string == '+' || *string == '-') {
        if (*(string++) == '-')
            sign = -1;
    }

    while (isxdigit(*(string + i))) {
        number = number * base +
            (isdigit(*(string + i)) ? *(string + i) - '0' :
             *(string + i) - 'A' + 10);
        i++;
    }

    if (endptr)
        *endptr = string;

    return sign * number;
}

int main() {
    char hexString[MAX_HEX_STRING_SIZE] = "";

    printf("Enter hexadecimal string: ");
    scanf("%s", hexString);

    decodeHexString(hexString);

    return 0;
}