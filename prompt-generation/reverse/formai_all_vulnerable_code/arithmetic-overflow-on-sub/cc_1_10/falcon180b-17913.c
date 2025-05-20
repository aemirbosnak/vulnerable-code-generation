//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_SIZE 1024
#define MAX_DATA_SIZE 1024
#define MAX_BLOCK_SIZE 16

// Function prototypes
void generate_key(char *key, int key_size);
void encrypt(char *data, int data_size, char *key, char *output);
void decrypt(char *data, int data_size, char *key, char *output);

int main() {
    char key[MAX_KEY_SIZE];
    char data[MAX_DATA_SIZE];
    char encrypted_data[MAX_DATA_SIZE];
    char decrypted_data[MAX_DATA_SIZE];
    int key_size, data_size;
    int choice;

    // Get user input for key size
    printf("Enter the key size (between 1 and %d): ", MAX_KEY_SIZE);
    scanf("%d", &key_size);

    // Generate key
    generate_key(key, key_size);

    // Get user input for data size
    printf("Enter the data size (between 1 and %d): ", MAX_DATA_SIZE);
    scanf("%d", &data_size);

    // Get user input for data
    printf("Enter the data: ");
    scanf("%s", data);

    // Encrypt data
    encrypt(data, data_size, key, encrypted_data);

    // Print encrypted data
    printf("Encrypted data: %s\n", encrypted_data);

    // Decrypt encrypted data
    decrypt(encrypted_data, strlen(encrypted_data), key, decrypted_data);

    // Print decrypted data
    printf("Decrypted data: %s\n", decrypted_data);

    return 0;
}

void generate_key(char *key, int key_size) {
    srand(time(NULL));
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size-1] = '\0';
}

void encrypt(char *data, int data_size, char *key, char *output) {
    int i, j, n;
    for (i = 0, j = 0; i < data_size; i++) {
        if ((i % 16) == 0 && i!= 0) {
            output[j++] = '\n';
        }
        n = (int)data[i] + (int)key[i % key[0]];
        if (n > 126) {
            n -= 26;
        } else if (n < 33) {
            n += 26;
        }
        output[j++] = n;
    }
    output[j] = '\0';
}

void decrypt(char *data, int data_size, char *key, char *output) {
    int i, j, n;
    for (i = 0, j = 0; i < data_size; i++) {
        if ((i % 16) == 0 && i!= 0) {
            output[j++] = '\n';
        }
        n = (int)data[i] - (int)key[i % key[0]];
        if (n < 33) {
            n += 26;
        } else if (n > 126) {
            n -= 26;
        }
        output[j++] = n;
    }
    output[j] = '\0';
}