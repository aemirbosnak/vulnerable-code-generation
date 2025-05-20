//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

void encrypt(char *input, char *output, int key);
void decrypt(char *input, char *output, int key);
void read_file(const char *filename, char *buffer);
void write_file(const char *filename, char *buffer);

int main() {
    char input[MAX_BUFFER];
    char output[MAX_BUFFER];
    int key;
    
    printf("Welcome to the Turing Encryption Program!\n");
    
    printf("Enter a key for encryption (1-25): ");
    scanf("%d", &key);
    
    // Ensuring the key is within acceptable range
    if (key < 1 || key > 25) {
        printf("Invalid key. Please restart the program and use a valid key.\n");
        return 1;
    }
    
    // Read the file to encrypt
    printf("Enter the name of the input file (to encrypt): ");
    scanf("%s", input);
    
    read_file(input, output);
    
    // Encrypt the content
    encrypt(output, output, key);
    
    // Write encrypted content to a new file
    char output_file[50];
    snprintf(output_file, sizeof(output_file), "encrypted_%s", input);
    write_file(output_file, output);
    
    printf("Encryption complete! Encrypted file: %s\n", output_file);
    
    // Now for decryption
    printf("Enter the name of the encrypted file (to decrypt): ");
    scanf("%s", input);
    
    read_file(input, output);
    
    // Decrypt the content
    decrypt(output, output, key);
    
    // Write decrypted content to a new file
    char decrypted_file[50];
    snprintf(decrypted_file, sizeof(decrypted_file), "decrypted_%s", input);
    write_file(decrypted_file, output);
    
    printf("Decryption complete! Decrypted file: %s\n", decrypted_file);
    
    return 0;
}

void encrypt(char *input, char *output, int key) {
    for (int i = 0; input[i] != '\0'; ++i) {
        char c = input[i];
        
        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            output[i] = (c + key - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            output[i] = (c + key - 'a') % 26 + 'a';
        }
        // Keep other characters unchanged
        else {
            output[i] = c;
        }
    }
    output[strlen(input)] = '\0'; // Null terminate
}

void decrypt(char *input, char *output, int key) {
    for (int i = 0; input[i] != '\0'; ++i) {
        char c = input[i];
        
        // Decrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            output[i] = (c - key + 26 - 'A') % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            output[i] = (c - key + 26 - 'a') % 26 + 'a';
        }
        // Keep other characters unchanged
        else {
            output[i] = c;
        }
    }
    output[strlen(input)] = '\0'; // Null terminate
}

void read_file(const char *filename, char *buffer) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open the file");
        exit(EXIT_FAILURE);
    }
    
    fread(buffer, sizeof(char), MAX_BUFFER, file);
    fclose(file);
}

void write_file(const char *filename, char *buffer) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open the file");
        exit(EXIT_FAILURE);
    }
    
    fwrite(buffer, sizeof(char), strlen(buffer), file);
    fclose(file);
}