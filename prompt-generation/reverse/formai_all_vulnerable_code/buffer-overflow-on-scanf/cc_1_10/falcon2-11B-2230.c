//Falcon2-11B DATASET v1.0 Category: System administration ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

// Function to decrypt a message
void decrypt_message(char* message) {
    char encrypted_message[256];
    char decrypted_message[256];
    int i;

    for (i = 0; i < strlen(message); i++) {
        encrypted_message[i] = message[i] ^ 0x1F;
    }

    for (i = 0; i < strlen(encrypted_message); i++) {
        decrypted_message[i] = encrypted_message[i] ^ 0xDF;
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

// Function to encrypt a message
void encrypt_message(char* message) {
    char encrypted_message[256];
    char decrypted_message[256];
    int i;

    for (i = 0; i < strlen(message); i++) {
        encrypted_message[i] = message[i] ^ 0x1F;
    }

    for (i = 0; i < strlen(encrypted_message); i++) {
        decrypted_message[i] = encrypted_message[i] ^ 0xDF;
    }

    printf("Encrypted message: %s\n", decrypted_message);
}

int main() {
    char message[256];
    printf("Enter a message to encrypt or decrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter 1 to encrypt and 2 to decrypt: ");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt_message(message);
            break;
        case 2:
            decrypt_message(message);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}