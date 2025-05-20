//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

int isQRCode(char* str); // function to check if string is QR code
int countPatterns(char* str); // function to count number of QR code patterns
int getModuleValue(char* str, int i); // function to get module value at position i
void printQRCode(char* str); // function to print QR code

int main() {
    char input[MAX_SIZE];
    printf("Enter QR code: ");
    scanf("%s", input);

    if (isQRCode(input)) {
        printf("Valid QR code.\n");
        countPatterns(input);
        printQRCode(input);
    } else {
        printf("Invalid QR code.\n");
    }

    return 0;
}

int isQRCode(char* str) {
    int len = strlen(str);
    if (len < 1 || len > MAX_SIZE) { // check for valid length
        return 0;
    }
    for (int i = 0; i < len; i++) {
        if (!isxdigit(str[i])) { // check for valid characters
            return 0;
        }
    }
    return 1; // QR code is valid
}

int countPatterns(char* str) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '1') {
            count++;
        }
    }
    return count;
}

int getModuleValue(char* str, int i) {
    int value = 0;
    for (int j = i; j < i + 3; j++) {
        if (str[j] == '1') {
            value += pow(2, 2 - j % 3);
        }
    }
    return value;
}

void printQRCode(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i += 3) {
        int moduleValue = getModuleValue(str, i);
        for (int j = 0; j < moduleValue; j++) {
            printf("  ");
        }
        for (int j = 0; j < 6 - moduleValue; j++) {
            printf("██");
        }
        printf("\n");
    }
}