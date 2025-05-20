//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 32
#define SALT_SIZE 16

// Function to convert hex string to binary
void hex_to_bin(char* hex, char* bin, int len) {
    for (int i = 0; i < len; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            sprintf(&bin[i * 2], "%02X", hex[i] - '0');
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            sprintf(&bin[i * 2], "%02X", hex[i] - 'A' + 10);
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            sprintf(&bin[i * 2], "%02X", hex[i] - 'a' + 10);
        } else {
            printf("Invalid hex character: %c\n", hex[i]);
            exit(1);
        }
    }
}

// Function to generate salt
void generate_salt(char* salt, int len) {
    char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < len; i++) {
        salt[i] = chars[rand() % strlen(chars)];
    }
    salt[len] = '\0';
}

// Function to hash password with salt
void hash_password(char* password, char* salt, char* hash) {
    char bin_password[HASH_SIZE / 2];
    char bin_salt[SALT_SIZE / 2];

    hex_to_bin(password, bin_password, strlen(password));
    hex_to_bin(salt, bin_salt, strlen(salt));

    for (int i = 0; i < strlen(password); i++) {
        hash[i] = bin_password[i] ^ bin_salt[i % strlen(salt)];
    }
}

// Main function
int main() {
    char password[100];
    char salt[SALT_SIZE];
    char hash[HASH_SIZE];

    printf("Enter password: ");
    scanf("%s", password);

    generate_salt(salt, SALT_SIZE);

    hash_password(password, salt, hash);

    printf("Password: %s\n", password);
    printf("Salt: %s\n", salt);
    printf("Hash: %s\n", hash);

    return 0;
}