//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10000 // maximum size of input binary number

void reverse(char *str, int start, int end) {
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char binary[MAX_SIZE];
    char decimal[MAX_SIZE];
    int i, j, len, value = 0;

    printf("Enter a binary number: ");
    scanf("%s", binary);
    len = strlen(binary);

    if (len == 0) {
        printf("Error: Empty input\n");
        exit(1);
    }

    for (i = 0; i < len; i++) {
        if (binary[i]!= '0' && binary[i]!= '1') {
            printf("Error: Invalid input\n");
            exit(1);
        }
    }

    reverse(binary, 0, len - 1); // reverse the binary number

    i = 0;
    while (binary[i] == '0') {
        i++;
    }

    j = i;
    while (j < len) {
        value = value * 2 + binary[j] - '0';
        j++;
    }

    sprintf(decimal, "%d", value); // convert binary to decimal

    printf("Binary: %s\n", binary);
    printf("Decimal: %s\n", decimal);

    return 0;
}