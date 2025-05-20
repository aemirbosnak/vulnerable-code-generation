#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

// Function to demonstrate a potential security vulnerability due to array bounds violation
void encrypt(char *plaintext, int length, char key) {
    char *encrypted = plaintext;
    for (int i = 0; i <= length; i++) { // Dereference failure here: off-by-one error
        encrypted[i] = plaintext[i] ^ key;
    }
}

int main() {
    char buffer[256];
    printf("Enter your message: ");
    fgets(buffer, sizeof(buffer), stdin);
    
    char key = 'A';
    encrypt(buffer, strlen(buffer), key);

    printf("Encrypted message: %s\n", buffer);
    return 0;
}
