//GEMINI-pro DATASET v1.0 Category: Password management ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/sha.h>
#include <openssl/rand.h>
#include <openssl/aes.h>

// Database of usernames and encrypted passwords
struct user {
    char username[256];
    unsigned char password[32];
};

struct user database[] = {
    {"alice", {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10}},
    {"bob",   {0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20}},
    {NULL,   {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}}
};

// Generate a random salt
void generate_salt(unsigned char *salt) {
    RAND_bytes(salt, 16);
}

// Hash a password with a salt
void hash_password(const char *password, unsigned char *salt, unsigned char *hashed_password) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Update(&sha256, salt, 16);
    SHA256_Final(hashed_password, &sha256);
}

// Encrypt a password with a key
void encrypt_password(const unsigned char *password, unsigned char *key, unsigned char *encrypted_password) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);
    AES_encrypt(password, encrypted_password, &aes_key);
}

// Decrypt a password with a key
void decrypt_password(const unsigned char *encrypted_password, unsigned char *key, unsigned char *password) {
    AES_KEY aes_key;
    AES_set_decrypt_key(key, 128, &aes_key);
    AES_decrypt(encrypted_password, password, &aes_key);
}

// Authenticate a user
int authenticate_user(const char *username, const char *password) {
    // Find the user in the database
    int i;
    for (i = 0; database[i].username != NULL; i++) {
        if (strcmp(username, database[i].username) == 0) {
            break;
        }
    }

    // Check if the user was found
    if (database[i].username == NULL) {
        return 0;
    }

    // Generate a salt
    unsigned char salt[16];
    generate_salt(salt);

    // Hash the password with the salt
    unsigned char hashed_password[32];
    hash_password(password, salt, hashed_password);

    // Check if the hashed password matches the stored password
    if (memcmp(hashed_password, database[i].password, 32) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main() {
    // Get the username and password from the user
    char username[256];
    char password[256];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Authenticate the user
    int authenticated = authenticate_user(username, password);

    // Print the result
    if (authenticated) {
        printf("Authentication successful!\n");
    } else {
        printf("Authentication failed!\n");
    }

    return 0;
}