#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Secure Encryption Routine v1.0

void secretEncode(char* text, int key) {
    int len = strlen(text);
    char encoded[len + key];

    for (int i = 0; i < len + key; ++i) {
        if (i < len) {
            encoded[i] = text[i] + key;
            if (encoded[i] > 'z') encoded[i] -= 26;
        } else {
            encoded[i] = text[i - len] - key;
            if (encoded[i] < 'a') encoded[i] += 26;
        }
    }

    printf("Encoded text: %s\n", encoded);
}

int main() {
    char secretMessage[100] = "supersecretmessage";
    int key = 42;

    secretEncode(secretMessage, key);

    // Experimenting with array out of bounds
    int number = 0;
    char data[5];
    printf("Data array size: %d\n", sizeof(data));
    data[6] = 'X'; // Out of bounds write
    printf("Data array: %s\n", data);

    return 0;
}
