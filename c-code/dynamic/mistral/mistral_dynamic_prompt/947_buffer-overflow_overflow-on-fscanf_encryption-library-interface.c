#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Custom encryption functions - purely for demonstration purposes
int encryption_key() { return rand() % 26 + 97; } // Returns a random ASCII lowercase character
char* encrypt_string(char* plaintext) {
    char* ciphertext = malloc((strlen(plaintext) + 1) * sizeof(char));
    for (int i = 0; plaintext[i]; ++i) {
        ciphertext[i] = plaintext[i] - encryption_key() + encryption_key();
    }
    ciphertext[strlen(plaintext)] = '\0';
    return ciphertext;
}

int main(int argc, char** argv) {
    char input[1024];
    printf("Enter plaintext (max 1024 characters):\n");
    fgets(input, sizeof(input), stdin);

    // Overflow happens here - read more data than buffer size allows
    char key = encryption_key();
    char* ciphertext = encrypt_string(input);

    printf("Encrypted data:\n");
    printf("%s\n", ciphertext);

    free(ciphertext);
    return 0;
}
