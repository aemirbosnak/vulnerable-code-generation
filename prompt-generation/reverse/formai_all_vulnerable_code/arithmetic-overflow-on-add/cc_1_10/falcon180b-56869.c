//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "MySecretKey123"
#define KEY_SIZE 16

// XOR encryption function
void encrypt(char* message, int message_size, char* key) {
    int i;
    for (i = 0; i < message_size; i++) {
        message[i] ^= key[i % KEY_SIZE];
    }
}

// XOR decryption function
void decrypt(char* encrypted_message, int encrypted_size, char* key) {
    int i;
    for (i = 0; i < encrypted_size; i++) {
        encrypted_message[i] ^= key[i % KEY_SIZE];
    }
}

// Read file into buffer
char* read_file(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error reading file\n");
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    fread(buffer, file_size, 1, file);
    fclose(file);
    buffer[file_size] = '\0';
    return buffer;
}

// Write buffer to file
void write_file(char* filename, char* buffer, int size) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error writing file\n");
        exit(1);
    }
    fwrite(buffer, size, 1, file);
    fclose(file);
}

int main() {
    char* message = read_file("message.txt");
    int message_size = strlen(message);
    encrypt(message, message_size, KEY);
    write_file("encrypted_message.txt", message, message_size);
    char* encrypted_message = read_file("encrypted_message.txt");
    decrypt(encrypted_message, message_size, KEY);
    write_file("decrypted_message.txt", encrypted_message, message_size);
    printf("Encryption and decryption complete!\n");
    return 0;
}