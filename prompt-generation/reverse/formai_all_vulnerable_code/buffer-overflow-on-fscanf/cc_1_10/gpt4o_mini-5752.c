//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 256
#define PUBLIC_KEY_SIZE 128
#define PRIVATE_KEY_SIZE 128
#define MESSAGE_SIZE 256

void generate_key_pair(char public_key[PUBLIC_KEY_SIZE], char private_key[PRIVATE_KEY_SIZE]) {
    // Simulate the key generation process in a world where technology is disintegrating
    snprintf(public_key, PUBLIC_KEY_SIZE, "PUB_KEY_%d", rand() % 10000);
    snprintf(private_key, PRIVATE_KEY_SIZE, "PRI_KEY_%d", rand() % 10000);
}

void encrypt_message(const char *public_key, const char *message, char *ciphertext) {
    snprintf(ciphertext, MESSAGE_SIZE, "ENCRYPTED(%s_with_%s)", message, public_key);
}

void decrypt_message(const char *private_key, const char *ciphertext, char *message) {
    // Simulating decryption with the remnants of the old world
    sscanf(ciphertext, "ENCRYPTED(%[^_])_with_%*s", message);
}

void save_keys_to_file(const char *filename, const char *public_key, const char *private_key) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file to save keys");
        return;
    }
    fprintf(file, "Public Key: %s\n", public_key);
    fprintf(file, "Private Key: %s\n", private_key);
    fclose(file);
}

void load_keys_from_file(const char *filename, char *public_key, char *private_key) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file to load keys");
        return;
    }
    fscanf(file, "Public Key: %s\n", public_key);
    fscanf(file, "Private Key: %s\n", private_key);
    fclose(file);
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    char public_key[PUBLIC_KEY_SIZE];
    char private_key[PRIVATE_KEY_SIZE];
    char message[MESSAGE_SIZE];
    char ciphertext[MESSAGE_SIZE];
    char decrypted_message[MESSAGE_SIZE];

    // 1. Generate key pair
    generate_key_pair(public_key, private_key);
    printf("Public Key: %s\nPrivate Key: %s\n", public_key, private_key);

    // 2. Save keys to a file (the last remnants of paper in this world)
    const char *key_file = "keys.txt";
    save_keys_to_file(key_file, public_key, private_key);
    printf("Keys saved to %s\n", key_file);

    // 3. Load keys from the file to see if they still exist
    char loaded_public_key[PUBLIC_KEY_SIZE];
    char loaded_private_key[PRIVATE_KEY_SIZE];
    load_keys_from_file(key_file, loaded_public_key, loaded_private_key);
    
    printf("Loaded Public Key: %s\nLoaded Private Key: %s\n", loaded_public_key, loaded_private_key);

    // 4. Message handling
    snprintf(message, MESSAGE_SIZE, "MESSAGE_OF_SALVATION");

    // 5. Encrypt the message
    encrypt_message(loaded_public_key, message, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    // 6. Decrypt the message
    decrypt_message(loaded_private_key, ciphertext, decrypted_message);
    printf("Decrypted Message: %s\n", decrypted_message);

    // 7. Validate if decryption is successful
    if (strcmp(message, decrypted_message) == 0) {
        printf("Decryption successful! The world still has hope.\n");
    } else {
        printf("Decryption failed! The shadows loom closer.\n");
    }
    
    return 0;
}