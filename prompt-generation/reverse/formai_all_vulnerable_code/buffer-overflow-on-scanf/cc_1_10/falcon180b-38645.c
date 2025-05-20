//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int encode(char *string);
int decode(char *string);

int main() {
    char string[100];
    int choice;

    // Get user input
    printf("Enter a string: ");
    scanf("%s", string);

    // Get user choice
    printf("\nEnter your choice:\n");
    printf("1. Encode\n2. Decode\n");
    scanf("%d", &choice);

    // Encode or decode string
    if (choice == 1) {
        encode(string);
    } else if (choice == 2) {
        decode(string);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

// Encodes the given string using a custom algorithm
int encode(char *string) {
    int length = strlen(string);
    char encoded[length * 2];
    int i = 0, j = 0;

    // Encode the string
    for (i = 0; i < length; i++) {
        if (i % 2 == 0) {
            encoded[j++] = string[i];
        } else {
            encoded[j++] = '0';
        }
    }

    // Output the encoded string
    printf("Encoded string: %s\n", encoded);

    return 0;
}

// Decodes the given string using the custom algorithm
int decode(char *string) {
    int length = strlen(string);
    char decoded[length / 2];
    int i = 0, j = 0;

    // Decode the string
    for (i = 0; i < length; i++) {
        if (i % 2 == 0) {
            decoded[j++] = string[i];
        }
    }

    // Output the decoded string
    printf("Decoded string: %s\n", decoded);

    return 0;
}