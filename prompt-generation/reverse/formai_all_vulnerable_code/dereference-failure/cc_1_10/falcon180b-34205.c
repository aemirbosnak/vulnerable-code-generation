//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define MAX_LENGTH 1000
#define CHARSET "0123456789abcdef"

// Function prototypes
void generateRandomString(char* str, int length);
int calculateChecksum(char* str);
int validateChecksum(char* str);

int main() {
    char inputString[MAX_LENGTH];
    int length;
    int checksum;

    printf("Enter a string to calculate checksum: ");
    fgets(inputString, MAX_LENGTH, stdin);
    length = strlen(inputString);

    if (length > MAX_LENGTH) {
        printf("Error: Input string is too long.\n");
        return 1;
    }

    checksum = calculateChecksum(inputString);
    printf("Checksum: %d\n", checksum);

    if (validateChecksum(inputString)) {
        printf("Input string is valid.\n");
    } else {
        printf("Input string is invalid.\n");
    }

    return 0;
}

void generateRandomString(char* str, int length) {
    for (int i = 0; i < length; i++) {
        str[i] = CHARSET[rand() % strlen(CHARSET)];
    }
    str[length] = '\0';
}

int calculateChecksum(char* str) {
    int sum = 0;
    for (int i = 0; i < strlen(str); i++) {
        sum += (int)str[i];
    }
    return sum % 10;
}

int validateChecksum(char* str) {
    int checksum = calculateChecksum(str);
    int lastChar = (int)str[strlen(str) - 1];

    if (checksum == lastChar) {
        return true;
    } else {
        return false;
    }
}