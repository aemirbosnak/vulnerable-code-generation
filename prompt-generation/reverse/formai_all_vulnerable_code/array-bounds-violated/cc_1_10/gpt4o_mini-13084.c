//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_KEY_LENGTH 256 // AES key length
#define BLOCK_SIZE 16       // Size of AES block in bytes
#define MAX_FILE_SIZE 1024  // Max size read from the file for encryption

typedef struct {
    unsigned char key[AES_KEY_LENGTH / 8];
} AES128Cipher;

// Function to generate random AES key
void generate_key(AES128Cipher *cipher) {
    if (!RAND_bytes(cipher->key, sizeof(cipher->key))) {
        fprintf(stderr, "Error generating random key\n");
        exit(EXIT_FAILURE);
    }
}

// Function to display the AES key in hexadecimal format
void print_hex(const char *label, const unsigned char *data, int len) {
    printf("%s: ", label);
    for (int i = 0; i < len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

// Function to encrypt data using AES
void aes_encrypt(const unsigned char *input, unsigned char *output, 
                 AES128Cipher *cipher) {
    AES_KEY enc_key;
    if (AES_set_encrypt_key(cipher->key, AES_KEY_LENGTH, &enc_key) < 0) {
        fprintf(stderr, "Error setting encryption key\n");
        exit(EXIT_FAILURE);
    }

    AES_encrypt(input, output, &enc_key);
}

// Function to decrypt data using AES
void aes_decrypt(const unsigned char *input, unsigned char *output, 
                 AES128Cipher *cipher) {
    AES_KEY dec_key;
    if (AES_set_decrypt_key(cipher->key, AES_KEY_LENGTH, &dec_key) < 0) {
        fprintf(stderr, "Error setting decryption key\n");
        exit(EXIT_FAILURE);
    }

    AES_decrypt(input, output, &dec_key);
}

// Function to pad data to be block-aligned
void pad_data(const unsigned char *data, int data_len, unsigned char *padded_data) {
    int padding = BLOCK_SIZE - (data_len % BLOCK_SIZE);
    memcpy(padded_data, data, data_len);
    for (int i = 0; i < padding; i++) {
        padded_data[data_len + i] = padding; // PKCS#7 padding
    }
}

// Function to read data from a file
int read_file(const char *filename, unsigned char *buffer) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return 0;
    }

    size_t bytes_read = fread(buffer, sizeof(unsigned char), MAX_FILE_SIZE, file);
    fclose(file);
    return bytes_read;
}

// Function to write data to a file
void write_file(const char *filename, const unsigned char *buffer, size_t length) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error writing to file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fwrite(buffer, sizeof(unsigned char), length, file);
    fclose(file);
}

// Function to encrypt a file
void encrypt_file(const char *input_file, const char *output_file, AES128Cipher *cipher) {
    unsigned char input_data[MAX_FILE_SIZE];
    unsigned char padded_data[MAX_FILE_SIZE + BLOCK_SIZE];
    unsigned char encrypted_data[MAX_FILE_SIZE + BLOCK_SIZE];

    int input_length = read_file(input_file, input_data);

    pad_data(input_data, input_length, padded_data);

    for (int i = 0; i < (input_length + BLOCK_SIZE - 1) / BLOCK_SIZE; i++) {
        aes_encrypt(padded_data + i * BLOCK_SIZE, 
                    encrypted_data + i * BLOCK_SIZE, cipher);
    }

    write_file(output_file, encrypted_data, ((input_length + BLOCK_SIZE - 1) / BLOCK_SIZE) * BLOCK_SIZE);
}

// Function to decrypt a file
void decrypt_file(const char *input_file, const char *output_file, AES128Cipher *cipher) {
    unsigned char encrypted_data[MAX_FILE_SIZE];
    unsigned char decrypted_data[MAX_FILE_SIZE];

    int encrypted_length = read_file(input_file, encrypted_data);

    for (int i = 0; i < encrypted_length / BLOCK_SIZE; i++) {
        aes_decrypt(encrypted_data + i * BLOCK_SIZE, 
                    decrypted_data + i * BLOCK_SIZE, cipher);
    }

    // Remove padding
    int padding = decrypted_data[encrypted_length - 1];
    int actual_length = encrypted_length - padding;

    write_file(output_file, decrypted_data, actual_length);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <encrypt|decrypt> <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    AES128Cipher cipher;
    generate_key(&cipher);
    print_hex("AES Key", cipher.key, sizeof(cipher.key));

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt_file(argv[2], argv[3], &cipher);
        printf("Encryption complete. Encrypted data saved to %s\n", argv[3]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt_file(argv[2], argv[3], &cipher);
        printf("Decryption complete. Decrypted data saved to %s\n", argv[3]);
    } else {
        fprintf(stderr, "Invalid operation: %s. Use 'encrypt' or 'decrypt'.\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}