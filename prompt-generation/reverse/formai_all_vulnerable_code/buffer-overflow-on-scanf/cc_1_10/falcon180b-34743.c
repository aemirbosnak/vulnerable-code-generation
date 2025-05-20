//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

int hex_to_dec(char *hex, int hex_len, int *dec_num, int *dec_len) {
    int i, j, k, sign = 1;
    char *dec = (char *)malloc((hex_len * 3) + 1);
    if (dec == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    for (i = 0, j = 0; i < hex_len; i++) {
        if (isxdigit(hex[i])) {
            dec[j++] = hex[i];
        } else {
            printf("Invalid hexadecimal character: %c\n", hex[i]);
            free(dec);
            return -1;
        }
    }
    *dec_num = strtol(dec, NULL, 10);
    *dec_len = strlen(dec);
    free(dec);
    return 0;
}

int dec_to_hex(int dec_num, char *hex, int hex_len) {
    char *dec = (char *)malloc((dec_num + 1) * sizeof(char));
    if (dec == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    sprintf(dec, "%d", dec_num);
    int i, j, k;
    for (i = strlen(dec) - 1, j = 0; i >= 0; i--, j++) {
        k = dec[i] - '0';
        if (k < 0 || k > 9) {
            printf("Invalid decimal number: %s\n", dec);
            free(dec);
            return -1;
        }
        hex[j] = k + '0';
    }
    free(dec);
    return 0;
}

int main() {
    char hex[100], dec[100];
    int hex_len, dec_len;
    int dec_num;
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    hex_len = strlen(hex);
    if (hex_to_dec(hex, hex_len, &dec_num, &dec_len) == -1) {
        return 1;
    }
    printf("The decimal equivalent is: ");
    dec_to_hex(dec_num, dec, dec_len);
    printf("%s\n", dec);
    return 0;
}