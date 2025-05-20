//GEMINI-pro DATASET v1.0 Category: Password management ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Advanced Encryption Standard (AES) library
#include <openssl/aes.h>

// Password database structure
typedef struct {
    char username[100];
    char password[100];
} Password;

// Create a new password
void create_password(Password *password) {
    printf("Enter your username: ");
    scanf("%s", password->username);
    printf("Enter your password: ");
    scanf("%s", password->password);
}

// Encrypt a password
void encrypt_password(Password *password) {
    // Generate a random 128-bit encryption key
    unsigned char key[AES_BLOCK_SIZE];
    RAND_bytes(key, AES_BLOCK_SIZE);

    // Create an AES encryption context
    AES_KEY enc_key;
    AES_set_encrypt_key(key, AES_BLOCK_SIZE * 8, &enc_key);

    // Encrypt the password
    unsigned char ciphertext[100];
    AES_encrypt((unsigned char *)password->password, ciphertext, &enc_key);

    // Store the encrypted password
    strcpy(password->password, (char *)ciphertext);
}

// Decrypt a password
void decrypt_password(Password *password) {
    // Generate the encryption key from the username
    unsigned char key[AES_BLOCK_SIZE];
    SHA256((unsigned char *)password->username, strlen(password->username), key);

    // Create an AES decryption context
    AES_KEY dec_key;
    AES_set_decrypt_key(key, AES_BLOCK_SIZE * 8, &dec_key);

    // Decrypt the password
    unsigned char plaintext[100];
    AES_decrypt((unsigned char *)password->password, plaintext, &dec_key);

    // Store the decrypted password
    strcpy(password->password, (char *)plaintext);
}

// Main function
int main() {
    // Create a password database
    Password password_database[100];

    // Get the number of passwords
    int num_passwords;
    printf("Enter the number of passwords: ");
    scanf("%d", &num_passwords);

    // Create and encrypt the passwords
    for (int i = 0; i < num_passwords; i++) {
        create_password(&password_database[i]);
        encrypt_password(&password_database[i]);
    }

    // Decrypt and print the passwords
    for (int i = 0; i < num_passwords; i++) {
        decrypt_password(&password_database[i]);
        printf("Username: %s\nPassword: %s\n", password_database[i].username, password_database[i].password);
    }

    return 0;
}