//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    char binary[1000], decimal[1000];
    int i, j, k, n, p, q, r, s, t;

    printf("Enter a binary number: ");
    scanf("%s", binary);

    printf("Enter a decimal number: ");
    scanf("%s", decimal);

    n = strlen(decimal);
    p = strlen(binary);

    if (p == 0) {
        printf("Binary number cannot be empty.\n");
        return 0;
    }

    for (i = 0; i < p; i++) {
        if (!isdigit(binary[i])) {
            printf("Binary number can only contain 0s and 1s.\n");
            return 0;
        }
    }

    for (i = 0; i < n; i++) {
        if (!isdigit(decimal[i])) {
            printf("Decimal number can only contain digits.\n");
            return 0;
        }
    }

    k = 0;
    for (i = n - 1, j = 0; i >= 0; i--, j++) {
        q = decimal[i] - '0';
        r = binary[j] - '0';
        s = pow(2, k) * q + r;
        t = s % 10;
        k++;
        decimal[i] = t + '0';
    }

    printf("Decimal equivalent of binary number: %s\n", decimal);

    return 0;
}