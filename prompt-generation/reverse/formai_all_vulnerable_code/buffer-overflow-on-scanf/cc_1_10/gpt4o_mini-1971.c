//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The noble scribe of the encryption scroll
void write_encrypted_scroll(const char *message, int key, char *ciphertext) {
    for (int i = 0; message[i] != '\0'; i++) {
        char letter = message[i];

        // Only encrypt letters
        if (letter >= 'A' && letter <= 'Z') {
            // Encrypt uppercase letters
            letter = (letter - 'A' + key) % 26 + 'A';
        } else if (letter >= 'a' && letter <= 'z') {
            // Encrypt lowercase letters
            letter = (letter - 'a' + key) % 26 + 'a';
        }

        ciphertext[i] = letter; // Store the encrypted letter
    }
    ciphertext[strlen(message)] = '\0'; // Properly end the string
}

// Ancient parchment printing for revealing the secrets
void reveal_scroll(const char *ciphertext) {
    printf("The encrypted scroll reads:\n%s\n", ciphertext);
}

// A true knight will guard the secrets within this function
int is_valid_key(int key) {
    return (key >= 1 && key <= 25);
}

// The main scribe of the parchment creation
int main() {
    char message[256], ciphertext[256];
    int key;
    
    // The herald brings forth the encryption message
    printf("Greetings, noble traveler! What secret message dost thou wish to encrypt?\n");
    fgets(message, sizeof(message), stdin);
    
    // Removing newline character from fgets input
    size_t length = strlen(message);
    if (length > 0 && message[length - 1] == '\n') {
        message[length - 1] = '\0';
    }

    // The wise elder inquires about the sacred key
    printf("Choose a sacred key for thine encryption (between 1 and 25):\n");
    scanf("%d", &key);

    // If the key is unworthy, we shall not proceed
    if (!is_valid_key(key)) {
        printf("Alas! The chosen key is unworthy. Thou must choose a key between 1 and 25.\n");
        return 1;
    }

    // Penning down the encrypted message
    write_encrypted_scroll(message, key, ciphertext);
    
    // Revealing the secrets of the encrypted scroll
    reveal_scroll(ciphertext);
    
    printf("Thus, the encryption hath been completed!\nMay your secrets remain safe within the scroll!\n");

    return 0;
}