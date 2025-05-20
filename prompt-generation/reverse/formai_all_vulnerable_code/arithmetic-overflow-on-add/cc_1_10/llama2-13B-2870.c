//LLAMA2-13B DATASET v1.0 Category: Modern Encryption ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MESSAGE_LENGTH 100
#define MAX_SHIFT 25

void encrypt_message(char *message, int shift);
void decrypt_message(char *message, int shift);

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int shift;

    // Ask the user for the message and shift
    printf("Enter a message (max %d characters): ", MAX_MESSAGE_LENGTH);
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    printf("Enter the shift (positive integer): ");
    scanf("%d", &shift);

    // Encrypt the message
    encrypt_message(message, shift);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message (just for fun)
    decrypt_message(message, shift);

    return 0;
}

void encrypt_message(char *message, int shift) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] + shift) % 26;
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] + shift - 'A') % 26;
        }
    }
}

void decrypt_message(char *message, int shift) {
    int i;
    for (i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = (message[i] - shift) % 26;
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = (message[i] - shift + 'A') % 26;
        }
    }
}