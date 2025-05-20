//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mind-bending bit manipulation macros
#define FLIP(x) (~x)
#define ROL(x, n) ((x << n) | (x >> (sizeof(x) * 8 - n)))
#define ROR(x, n) ((x >> n) | (x << (sizeof(x) * 8 - n)))

// Function to encrypt a diary entry using bitwise XOR and bit rotations
char *encrypt_entry(char *entry) {
    int len = strlen(entry);
    for (int i = 0; i < len; i++) {
        entry[i] ^= 0x5A;
        entry[i] = ROL(entry[i], 3);
        entry[i] = ROR(entry[i], 5);
    }
    return entry;
}

// Function to decrypt a diary entry using bitwise XOR and bit rotations
char *decrypt_entry(char *entry) {
    int len = strlen(entry);
    for (int i = 0; i < len; i++) {
        entry[i] = FLIP(ROR(entry[i], 5));
        entry[i] = FLIP(ROL(entry[i], 3));
        entry[i] ^= 0x5A;
    }
    return entry;
}

int main() {
    // Get the diary entry from the user
    char entry[1000];
    printf("Enter your secret diary entry: ");
    scanf(" %[^\n]", entry);

    // Encrypt the diary entry
    char *encrypted_entry = encrypt_entry(entry);

    // Display the encrypted entry
    printf("\nEncrypted entry: %s\n", encrypted_entry);

    // Decrypt the diary entry
    char *decrypted_entry = decrypt_entry(encrypted_entry);

    // Display the decrypted entry
    printf("\nDecrypted entry: %s\n", decrypted_entry);

    return 0;
}