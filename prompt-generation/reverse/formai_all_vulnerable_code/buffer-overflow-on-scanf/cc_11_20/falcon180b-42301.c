//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main() {
    char binary[100], decimal[100], *endptr;
    int i, j, n, sign;
    printf("Enter a decimal number: ");
    scanf("%s", decimal);
    n = strlen(decimal);
    sign = 1;
    if (decimal[0] == '-') {
        sign = -1;
        strcpy(decimal, decimal+1);
        n--;
    }
    if (n > 0 && decimal[n-1] == '.') {
        decimal[n-1] = '\0';
        n--;
    }
    if (n == 0 || decimal[0]!= '0') {
        printf("Invalid input!\n");
        return 0;
    }
    i = 0;
    while (n > 0) {
        if (n == 1 && decimal[0] == '0') {
            binary[i] = '0';
            i++;
            break;
        }
        j = 0;
        while (n > 0 && isdigit(decimal[j])) {
            binary[i] = decimal[j] - '0';
            i++;
            j++;
            n--;
        }
        if (n > 0 && decimal[j] == '.') {
            decimal[j] = '\0';
            j++;
            n--;
        }
        if (n > 0) {
            printf("Invalid input!\n");
            return 0;
        }
    }
    if (sign == -1) {
        for (i = 0; i < strlen(binary); i++) {
            binary[i] = ~binary[i];
        }
    }
    printf("Binary: %s\n", binary);
    return 0;
}