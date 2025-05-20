//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to create a substitution cipher key
void createSubstitutionKey(char *key, char *substitution) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        substitution[i] = key[i];
    }
}

// Function to encrypt the message
void encryptMessage(const char *message, const char *substitution, char *encrypted) {
    for (int i = 0; message[i] != '\0'; i++) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            int index = (message[i] - base) % ALPHABET_SIZE;
            encrypted[i] = substitution[index];
            if (isupper(message[i])) {
                encrypted[i] = toupper(encrypted[i]);
            } else {
                encrypted[i] = tolower(encrypted[i]);
            }
        } else {
            encrypted[i] = message[i];
        }
    }
    encrypted[strlen(message)] = '\0'; // Null-terminate the encrypted string
}

// Function to decrypt the message
void decryptMessage(const char *encrypted, const char *substitution, char *decrypted) {
    for (int i = 0; encrypted[i] != '\0'; i++) {
        if (isalpha(encrypted[i])) {
            char base = isupper(encrypted[i]) ? 'A' : 'a';
            char *pos = strchr(substitution, tolower(encrypted[i]));
            if (pos) {
                int index = pos - substitution;
                decrypted[i] = base + index;
            } else {
                decrypted[i] = encrypted[i]; // In case of a non-substituted character
            }
        } else {
            decrypted[i] = encrypted[i];
        }
    }
    decrypted[strlen(encrypted)] = '\0'; // Null-terminate the decrypted string
}

int main() {
    char key[ALPHABET_SIZE + 1];
    char substitution[ALPHABET_SIZE + 1];
    char message[256];
    char encrypted[256];
    char decrypted[256];

    // Input the substitution key
    printf("Enter a substitution key (26 unique letters, no spaces): ");
    scanf("%s", key);
    
    // Validate key length
    if (strlen(key) != ALPHABET_SIZE) {
        fprintf(stderr, "Error: Key must be exactly 26 letters long.\n");
        return EXIT_FAILURE;
    }

    // Create the substitution key
    createSubstitutionKey(key, substitution);
    
    // Input the message
    printf("Enter a message to encrypt: ");
    getchar(); // clear the buffer
    fgets(message, sizeof(message), stdin);
    
    // Remove trailing newline character from message
    message[strcspn(message, "\n")] = 0;

    // Encrypt the message
    encryptMessage(message, substitution, encrypted);
    printf("Encrypted message: %s\n", encrypted);

    // Decrypt the message
    decryptMessage(encrypted, substitution, decrypted);
    printf("Decrypted message: %s\n", decrypted);

    return EXIT_SUCCESS;
}