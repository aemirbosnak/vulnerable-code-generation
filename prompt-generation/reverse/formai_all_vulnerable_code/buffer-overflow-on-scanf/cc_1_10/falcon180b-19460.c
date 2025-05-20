//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000
#define MAX_LENGTH 1000000

int countOccurrences(char *string, int length, char character);
void encodeString(char *string, int *length, char *encodedString);
void decodeString(char *encodedString, int *length, char *decodedString);

int main() {
    char inputString[MAX_SIZE];
    int inputLength, encodedLength;
    char encodedString[MAX_SIZE];
    char decodedString[MAX_SIZE];

    printf("Enter a string: ");
    scanf("%s", inputString);
    inputLength = strlen(inputString);

    printf("Original string: %s\n", inputString);
    printf("Length: %d\n", inputLength);

    encodeString(inputString, &encodedLength, encodedString);

    printf("Encoded string: %s\n", encodedString);
    printf("Encoded length: %d\n", encodedLength);

    decodeString(encodedString, &encodedLength, decodedString);

    printf("Decoded string: %s\n", decodedString);
    printf("Decoded length: %d\n", encodedLength);

    return 0;
}

int countOccurrences(char *string, int length, char character) {
    int count = 0;

    for (int i = 0; i < length; i++) {
        if (string[i] == character) {
            count++;
        }
    }

    return count;
}

void encodeString(char *string, int *length, char *encodedString) {
    int inputLength = strlen(string);
    int encodedLength = 0;
    char *currentPosition = encodedString;

    while (inputLength > 0) {
        int count = countOccurrences(string, inputLength, *string);
        sprintf(currentPosition, "%d%c", count, *string);
        currentPosition += strlen(currentPosition);
        inputLength--;
        string++;
    }

    *length = strlen(encodedString);
}

void decodeString(char *encodedString, int *length, char *decodedString) {
    int encodedLength = strlen(encodedString);
    int decodedLength = 0;
    char *currentPosition = decodedString;

    while (encodedLength > 0) {
        int count = 0;
        sscanf(encodedString, "%d%c", &count, *currentPosition);
        strcat(decodedString, currentPosition);
        currentPosition += strlen(currentPosition);
        while (count > 0) {
            strcat(decodedString, currentPosition);
            count--;
        }
        encodedLength -= strlen(currentPosition);
        currentPosition++;
    }

    *length = strlen(decodedString);
}