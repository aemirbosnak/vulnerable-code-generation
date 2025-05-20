//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert a character to its ASCII value
int charToAscii(char c) {
    return (int)c;
}

// Function to convert an integer to its ASCII value
char intToAscii(int num) {
    return (char)num;
}

// Function to center a string within a given width
void centerString(char* str, int width) {
    int len = strlen(str);
    int padding = (width - len) / 2;
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
    printf("%s", str);
    for (int i = 0; i < padding; i++) {
        printf(" ");
    }
}

// Function to print an ASCII art banner
void printBanner(char* message) {
    int messageLen = strlen(message);
    int bannerLen = messageLen + 10; // Add 10 for padding on each side
    char banner[bannerLen];
    memset(banner, '=', bannerLen);
    centerString(message, bannerLen);
    printf("\n%s\n", banner);
}

// Function to convert a string to ASCII art
void stringToAscii(char* inputStr) {
    int len = strlen(inputStr);
    for (int i = 0; i < len; i++) {
        char currChar = tolower(inputStr[i]);
        if (currChar >= 'a' && currChar <= 'z') {
            int asciiVal = charToAscii(currChar);
            printf("%c", asciiVal);
        } else {
            printf("%c", currChar);
        }
    }
}

int main() {
    char inputStr[100];
    printf("Enter a string (max 100 characters): ");
    scanf("%s", inputStr);

    // Check if input string is empty or contains only whitespace
    if (strlen(inputStr) == 0 || strspn(inputStr, " \t\r\n") == strlen(inputStr)) {
        printf("Error: Input string cannot be empty or contain only whitespace.\n");
        return 1;
    }

    // Convert input string to ASCII art and print result
    printBanner("ASCII Art");
    printf("\n");
    stringToAscii(inputStr);
    printf("\n");

    return 0;
}