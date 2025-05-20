//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    char input[100];
    int decimal = 0;
    int binary[100];
    int i = 0;
    int j = 0;
    int k = 0;
    int n;
    int flag = 0;
    int count = 0;
    char ch;

    printf("Enter a decimal number: ");
    scanf("%s", input);

    n = strlen(input);

    for (i = 0; i < n; i++) {
        ch = toupper(input[i]);
        if (ch < '0' || ch > '9') {
            printf("Invalid input. Please enter a valid decimal number.\n");
            exit(1);
        }
    }

    for (i = n - 1; i >= 0; i--) {
        ch = toupper(input[i]);
        decimal += (ch - '0') * pow(2, count);
        count++;
    }

    for (i = 0; i < 8; i++) {
        binary[i] = 0;
    }

    k = 0;
    for (j = 7; j >= 0; j--) {
        if (decimal % 2 == 1) {
            binary[j] = 1;
            decimal = decimal - 1;
        } else {
            binary[j] = 0;
        }
        k++;
        if (k == 4) {
            printf(" ");
            k = 0;
        }
    }

    printf("\nBinary equivalent: ");
    for (i = 0; i < 8; i++) {
        printf("%d ", binary[i]);
    }

    return 0;
}