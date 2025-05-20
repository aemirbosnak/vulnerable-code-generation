//Falcon-180B DATASET v1.0 Category: Encryption ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY 256
#define MAX_TEXT 1024

// Function to encrypt the text using Caesar cipher
void caesar_encrypt(char *text, int key, char *encrypted) {
    int i, j;
    for (i = 0, j = 0; text[i]!= '\0'; i++) {
        if (isalpha(text[i])) {
            encrypted[j] = (isupper(text[i])? toupper(text[i] + key - 65) : toupper(text[i] + key - 97));
            j++;
        } else {
            encrypted[j] = text[i];
            j++;
        }
    }
    encrypted[j] = '\0';
}

// Function to decrypt the text using Caesar cipher
void caesar_decrypt(char *encrypted, int key, char *decrypted) {
    int i, j;
    for (i = 0, j = 0; encrypted[i]!= '\0'; i++) {
        if (isalpha(encrypted[i])) {
            decrypted[j] = (isupper(encrypted[i])? tolower(encrypted[i] - key + 65) : tolower(encrypted[i] - key + 97));
            j++;
        } else {
            decrypted[j] = encrypted[i];
            j++;
        }
    }
    decrypted[j] = '\0';
}

int main() {
    char text[MAX_TEXT], encrypted[MAX_TEXT], decrypted[MAX_TEXT];
    int key;

    // Get the text from the user
    printf("Enter the text to encrypt: ");
    scanf("%s", text);

    // Get the encryption key from the user
    printf("Enter the encryption key (0-255): ");
    scanf("%d", &key);

    // Encrypt the text using Caesar cipher
    caesar_encrypt(text, key, encrypted);
    printf("Encrypted text: %s\n", encrypted);

    // Decrypt the encrypted text using Caesar cipher
    caesar_decrypt(encrypted, key, decrypted);
    printf("Decrypted text: %s\n", decrypted);

    return 0;
}