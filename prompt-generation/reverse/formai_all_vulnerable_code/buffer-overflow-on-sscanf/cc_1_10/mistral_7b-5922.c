//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_LEN 32
#define MAX_BIN_LEN 64

void reverse(char* str, int start, int end) {
    int temp;
    for (; start < end; start++, end--) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
    }
}

void decToBin(int num, char* bin, int* bin_len) {
    int i = 0;
    while (num > 0) {
        bin[i++] = num % 2 + '0';
        num /= 2;
    }
    reverse(bin, 0, i - 1);
    *bin_len = i;
}

void binToDec(char* bin, int bin_len, int* dec) {
    int dec_val = 0;
    int pow = 0;
    for (int i = bin_len - 1; i >= 0; i--) {
        if (bin[i] == '1')
            dec_val += pow > 0 ? pow * 1 + dec_val : dec_val << pow + 1;
        pow++;
    }
    *dec = dec_val;
}

int main() {
    char decStr[MAX_NUM_LEN];
    char binStr[MAX_BIN_LEN];
    int decVal = 0, binVal = 0;
    int decLen = 0, binLen = 0;

    printf("Enter decimal number: ");
    fgets(decStr, sizeof(decStr), stdin);
    decStr[strcspn(decStr, "\n")] = '\0';

    sscanf(decStr, "%d", &decVal);

    decToBin(decVal, binStr, &binLen);
    printf("\nBinary representation of %d: %s\n", decVal, binStr);

    strcpy(decStr, binStr);

    binToDec(decStr, binLen, &binVal);
    printf("\nDecimal representation of %s: %d\n", binStr, binVal);

    return 0;
}