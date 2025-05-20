#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Fake encryption function to introduce buffer overflow
void encrypt(char* message, char* ciphertext, int size) {
    for (int i = 0; i < size; ++i) {
        ciphertext[i] = message[i] + 3; // Simple encryption function to simulate a real one
    }
}

int main() {
    char secret_message[256];
    char encrypted_message[10];
    int message_size = sizeof(secret_message) / sizeof(char);

    printf("Enter your secret message:\n");
    gets(secret_message); // Buffer overflow vulnerability: gets function does not check array bounds

    encrypt(secret_message, encrypted_message, message_size);
    printf("Encrypted message: %s\n", encrypted_message);

    return 0;
}
