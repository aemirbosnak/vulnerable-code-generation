//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_CHARS 1000
#define ASCII_VALUE_OF_A 65
#define ASCII_VALUE_OF_Z 90
#define ASCII_VALUE_OF_a 97
#define ASCII_VALUE_OF_z 122
#define ASCII_VALUE_OF_0 48
#define ASCII_VALUE_OF_9 57

// Function to convert a character to its ASCII value
int characterToAscii(char c) {
    if (c >= ASCII_VALUE_OF_A && c <= ASCII_VALUE_OF_Z) {
        return c - ASCII_VALUE_OF_A + 1;
    } else if (c >= ASCII_VALUE_OF_a && c <= ASCII_VALUE_OF_z) {
        return c - ASCII_VALUE_OF_a + 1;
    } else if (c >= ASCII_VALUE_OF_0 && c <= ASCII_VALUE_OF_9) {
        return c - ASCII_VALUE_OF_0 + 1;
    } else {
        return 0;
    }
}

// Function to calculate the checksum of a given string
int calculateChecksum(char* string) {
    int sum = 0;
    int length = strlen(string);

    for (int i = 0; i < length; i++) {
        sum += characterToAscii(string[i]);
    }

    return sum % 10;
}

int main() {
    char string[MAX_CHARS];
    printf("Enter a string: ");
    scanf("%s", string);

    int checksum = calculateChecksum(string);

    if (checksum == 0) {
        printf("The string has a valid checksum.\n");
    } else {
        printf("The string has an invalid checksum.\n");
    }

    return 0;
}