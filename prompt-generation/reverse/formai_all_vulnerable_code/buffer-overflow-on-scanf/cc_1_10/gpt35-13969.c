//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_MESSAGE_LENGTH 1000

char encrypt(char letter, int shift);
void decrypt(char message[], int shift);

int main () {
    char message[MAX_MESSAGE_LENGTH];
    int shift;
    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    printf("Enter shift amount (0-25): ");
    scanf("%d", &shift);
    getchar(); // consume the trailing newline after scanf
    printf("Encrypting message...\n");
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = encrypt(message[i], shift);
        }
    }
    printf("Your encrypted message is: %s\n", message);
    printf("Decrypting message...\n");
    decrypt(message, shift);
    printf("Your decrypted message is: %s\n", message);
    return 0;
}

char encrypt(char letter, int shift) {
    char encrypted_letter = letter;
    if (isupper(letter)) {
        encrypted_letter = (letter - 'A' + shift) % 26 + 'A';
    } else {
        encrypted_letter = (letter - 'a' + shift) % 26 + 'a';
    }
    return encrypted_letter;
}

void decrypt(char message[], int shift) {
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            char decrypted_letter = message[i];
            if (isupper(message[i])) {
                decrypted_letter = (message[i] - 'A' - shift + 26) % 26 + 'A';
            } else {
                decrypted_letter = (message[i] - 'a' - shift + 26) % 26 + 'a';
            }
            message[i] = decrypted_letter;
        }
    }
}