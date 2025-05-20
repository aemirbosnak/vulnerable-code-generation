//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1000 // maximum length of input string

int is_valid_hex(char c) {
    if (c >= '0' && c <= '9')
        return 1;
    else if (c >= 'A' && c <= 'F')
        return 1;
    else if (c >= 'a' && c <= 'f')
        return 1;
    else
        return 0;
}

void convert_hex_to_dec(char* hex_str, long long* dec_num) {
    int len = strlen(hex_str);
    int i = 0;
    int j = 0;
    int num = 0;
    int power = 0;

    while (i < len) {
        if (is_valid_hex(hex_str[i])) {
            num = hex_str[i] - '0';
            if (num > 9) {
                num = num - 7;
            }
            num *= (int)pow(16, power);
            *dec_num += num;
            power++;
            i++;
        } else {
            printf("Invalid hexadecimal character: %c\n", hex_str[i]);
            exit(1);
        }
    }
}

int main() {
    char hex_str[MAX_LEN];
    long long dec_num;

    printf("Enter a hexadecimal number: ");
    if (fgets(hex_str, MAX_LEN, stdin) == NULL) {
        printf("Error reading input.\n");
        exit(1);
    }

    convert_hex_to_dec(hex_str, &dec_num);

    printf("The decimal equivalent of %s is %lld.\n", hex_str, dec_num);

    return 0;
}