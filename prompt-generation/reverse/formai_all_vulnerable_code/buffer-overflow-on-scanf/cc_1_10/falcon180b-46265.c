//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool isHex(char c) {
    if (c >= '0' && c <= '9')
        return true;
    else if (c >= 'A' && c <= 'F')
        return true;
    else if (c >= 'a' && c <= 'f')
        return true;
    else
        return false;
}

void toLowerCase(char* str) {
    int i = 0;
    while (str[i]) {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
        i++;
    }
}

int main() {
    char hex[MAX_SIZE];
    char dec[MAX_SIZE];
    printf("Enter a hexadecimal number: ");
    scanf("%s", hex);
    toLowerCase(hex);
    int i = 0;
    while (hex[i]) {
        if (!isHex(hex[i])) {
            printf("Invalid hexadecimal number!\n");
            return 1;
        }
        i++;
    }
    int len = strlen(hex);
    int j = 0;
    for (i = len - 1; i >= 0; i--) {
        char c = hex[i];
        if (c >= '0' && c <= '9') {
            dec[j] = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            dec[j] = c - 'A' + 10;
        } else {
            dec[j] = c - 'a' + 10;
        }
        j++;
    }
    printf("Decimal equivalent: %s\n", dec);
    return 0;
}