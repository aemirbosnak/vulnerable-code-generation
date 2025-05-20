//FormAI DATASET v1.0 Category: QR code reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 1000

// Function to check if a character is valid hex
bool isValidHexChar(char c) {
    if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')) {
        return true;
    }
    return false;
}

// Function to check if a string is a valid hex string
bool isValidHexString(char str[]) {
    int len = strlen(str);
    if (len == 0 || len % 2 != 0) {
        return false;
    }
    for (int i = 0; i < len; i++) {
        if (!isValidHexChar(str[i])) {
            return false;
        }
    }
    return true;
}

// Function to convert a hex string to binary
void hexToBinary(char str[], char binary[]) {
    int len = strlen(str);
    for (int i = 0; i < len; i += 2) {
        int high = (isValidHexChar(str[i])) ? ((str[i] <= '9') ? str[i] - '0' : str[i] - 'a' + 10) : 0;
        int low = (isValidHexChar(str[i + 1])) ? ((str[i + 1] <= '9') ? str[i + 1] - '0' : str[i + 1] - 'a' + 10) : 0;
        binary[i/2] = (char) (high * 16 + low);
    }
}

// Main function to read a QR code from a file and output its content
int main() {
    char filename[MAX_LEN];
    printf("Enter the QR code filename: ");
    scanf("%s", filename);

    FILE *fp;
    char ch;
    char rawCode[MAX_LEN];
    int codeLen = 0;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }
    while ((ch = fgetc(fp)) != EOF) {
        rawCode[codeLen] = ch;
        codeLen++;
    }
    fclose(fp);

    // Convert raw code from file to binary
    char binaryCode[MAX_LEN];
    hexToBinary(rawCode, binaryCode);

    // Print the decoded message
    printf("Decoded message:\n");
    for (int i = 0; i < MAX_LEN && binaryCode[i] != '\0'; i++) {
        printf("%c", binaryCode[i]);
    }
    printf("\n");

    return 0;
}