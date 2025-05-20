//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define ASCII_MIN 0
#define ASCII_MAX 127
#define KEY 3

void encodeMessage(char *message, int key);
void decodeMessage(char *message, int key);

int main() {
    char originalMessage[MAX_LEN];
    char encodedMessage[MAX_LEN];
    char decodedMessage[MAX_LEN];

    printf("Enter the original message: ");
    scanf("%s", originalMessage);

    encodeMessage(originalMessage, KEY);

    printf("Encoded message: %s\n", encodedMessage);

    decodeMessage(encodedMessage, KEY);

    printf("Decoded message: %s\n", decodedMessage);

    return 0;
}

void encodeMessage(char *message, int key) {
    int i = 0;

    while (message[i] != '\0') {
        if (message[i] >= ASCII_MIN && message[i] <= ASCII_MAX) {
            message[i] += key;
            if (message[i] > ASCII_MAX)
                message[i] -= (ASCII_MAX - ASCII_MIN);
        }
        i++;
    }
}

void decodeMessage(char *message, int key) {
    int i = 0;

    while (message[i] != '\0') {
        if (message[i] >= ASCII_MIN && message[i] <= ASCII_MAX) {
            message[i] -= key;
            if (message[i] < ASCII_MIN)
                message[i] += (ASCII_MAX - ASCII_MIN);
        }
        i++;
    }
}