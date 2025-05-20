//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Function prototypes
void print_binary(int num);
int is_binary(char *str);
int main(int argc, char *argv[]) {
    char input[100];
    int decimal, binary[33];
    int i, j, k, len;
    printf("Enter a decimal number: ");
    scanf("%s", input);
    len = strlen(input);
    for (i = 0; i < len; i++) {
        if (!isdigit(input[i])) {
            printf("Error: Invalid input.\n");
            return 1;
        }
    }
    decimal = atoi(input);
    if (decimal == 0) {
        printf("0\n");
        return 0;
    }
    for (i = 0; i < 32; i++) {
        binary[i] = 0;
    }
    k = 0;
    while (decimal > 0) {
        binary[k] = decimal % 2;
        decimal /= 2;
        k++;
    }
    for (j = k - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
    return 0;
}

void print_binary(int num) {
    int i, rem;
    for (i = 31; i >= 0; i--) {
        rem = num % 2;
        printf("%d", rem);
        num /= 2;
    }
}

int is_binary(char *str) {
    int i, len;
    len = strlen(str);
    for (i = 0; i < len; i++) {
        if (str[i]!= '0' && str[i]!= '1') {
            return 0;
        }
    }
    return 1;
}