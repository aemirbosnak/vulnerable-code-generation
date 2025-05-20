//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define HASH_LENGTH 32
#define SALT_LENGTH 16

// Function to generate a salt
void generate_salt(char salt[SALT_LENGTH]) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int i;
    for (i = 0; i < SALT_LENGTH; i++) {
        int rand_index = rand() % 62;
        salt[i] = charset[rand_index];
    }
}

// Function to hash a password with a given salt
void hash_password(char password[100], char salt[SALT_LENGTH], char hash[HASH_LENGTH]) {
    int i, j;
    for (i = 0, j = 0; i < strlen(password); i++) {
        hash[j++] = password[i] ^ salt[i % SALT_LENGTH];
    }
}

// Function to compare two hashed passwords
int compare_hashes(char hash1[HASH_LENGTH], char hash2[HASH_LENGTH]) {
    int i;
    for (i = 0; i < HASH_LENGTH; i++) {
        if (hash1[i]!= hash2[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char password[100];
    char salt[SALT_LENGTH];
    char hash[HASH_LENGTH];

    // Get password from user
    printf("Enter password: ");
    scanf("%s", password);

    // Generate salt
    generate_salt(salt);

    // Hash password with salt
    hash_password(password, salt, hash);

    // Print hashed password and salt
    printf("Hashed password: ");
    for (int i = 0; i < HASH_LENGTH; i++) {
        printf("%02X", hash[i]);
    }
    printf("\n");
    printf("Salt: ");
    for (int i = 0; i < SALT_LENGTH; i++) {
        printf("%c", salt[i]);
    }
    printf("\n");

    return 0;
}