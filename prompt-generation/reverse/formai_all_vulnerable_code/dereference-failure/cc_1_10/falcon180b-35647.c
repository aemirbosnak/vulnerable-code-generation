//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_NUM_LENGTH 100
#define MAX_HEX_LENGTH 3
#define MAX_INPUT_LENGTH 1000

int isHex(const char* str);

int main() {
    char input[MAX_INPUT_LENGTH] = {0};
    char hex[MAX_HEX_LENGTH] = {0};
    int decimal = 0;
    int i = 0;
    int j = 0;
    int len = 0;
    int isNegative = 0;

    printf("Enter a decimal number: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    len = strlen(input);

    // Check if input is negative
    if (input[0] == '-') {
        isNegative = 1;
        i++;
    }

    // Convert input to hexadecimal
    for (; i < len; i++) {
        if (isdigit(input[i])) {
            decimal = decimal * 10 + (input[i] - '0');
        } else if (isHex(input[i])) {
            hex[j++] = input[i];
        } else {
            printf("Invalid input\n");
            return 1;
        }
    }

    // Check if input is negative
    if (isNegative) {
        printf("-");
        i++;
    }

    // Print hexadecimal representation
    for (; j < MAX_HEX_LENGTH; j++) {
        printf("%c", hex[j]);
    }

    return 0;
}

int isHex(const char* str) {
    if (strlen(str)!= 1) {
        return 0;
    }
    if (isdigit(str[0])) {
        return 1;
    } else if (str[0] >= 'A' && str[0] <= 'F') {
        return 1;
    } else if (str[0] >= 'a' && str[0] <= 'f') {
        return 1;
    }
    return 0;
}