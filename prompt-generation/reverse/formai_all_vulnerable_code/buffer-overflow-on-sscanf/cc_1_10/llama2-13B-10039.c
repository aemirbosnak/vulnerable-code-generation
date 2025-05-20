//LLAMA2-13B DATASET v1.0 Category: Binary Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_BASES 16

typedef struct {
    int base;
    char *str;
} conversion_t;

static conversion_t convert(int num, int from_base, int to_base) {
    conversion_t res;
    char temp[32];
    int i, j;

    res.base = to_base;
    res.str = malloc(32);

    // Convert the number to the target base
    for (i = 0, j = 0; i < sizeof(temp); i++) {
        temp[j++] = num % 10 + '0';
        num /= 10;
    }

    // Reverse the string
    for (i = 0, j = (int)strlen(temp) - 1; i < j; i++, j--) {
        res.str[j] = temp[i];
    }

    return res;
}

int main() {
    int num, from_base, to_base;
    char input[MAX_INPUT_LENGTH];
    conversion_t conversion;

    printf("Enter a number and two bases (separated by a space): ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    sscanf(input, "%d%c%d", &num, &from_base, &to_base);

    conversion = convert(num, from_base, to_base);

    printf("Input number in base %c: %s\n", from_base, conversion.str);
    printf("Output number in base %c: %s\n", to_base, conversion.str);

    free(conversion.str);

    return 0;
}