//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MESSAGE_LENGTH 1024
#define MAX_SHIFT 26

void encrypt(char *message, int shift);
void decrypt(char *message, int shift);

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int shift;

    // Ask the user for the message and shift
    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    printf("Enter a shift (1-26): ");
    scanf("%d", &shift);

    // Encrypt the message
    encrypt(message, shift);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}

void encrypt(char *message, int shift) {
    int i, j;
    char c;

    // Shift each letter in the message by the given number of positions
    for (i = 0; i < strlen(message); i++) {
        c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = (c + shift) % 26;
            message[i] = c;
        }
    }
}

void decrypt(char *message, int shift) {
    int i, j;
    char c;

    // Shift each letter in the message by the given number of positions in the reverse direction
    for (i = 0; i < strlen(message); i++) {
        c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = (c - shift) % 26;
            message[i] = c;
        }
    }
}