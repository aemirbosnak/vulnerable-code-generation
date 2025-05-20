//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encrypt(char *text, int key);
void decrypt(char *text, int key);
void displayMenu();
void processFile(const char *filename, int key, int mode);

#define ENCRYPT_MODE 1
#define DECRYPT_MODE 2

int main() {
    char filename[256];
    int key, mode;

    printf("//////////////////////////\n");
    printf(" C File Encryptor v1.0 \n");
    printf("//////////////////////////\n");

    printf("Enter filename to encrypt/decrypt: ");
    scanf("%s", filename);

    printf("Enter encryption/decryption key (integer): ");
    scanf("%d", &key);

    displayMenu();
    printf("Select an operation (1 for encrypt, 2 for decrypt): ");
    scanf("%d", &mode);

    processFile(filename, key, mode);

    printf("Operation completed successfully!\n");
    return 0;
}

void displayMenu() {
    printf("//////////////////////////\n");
    printf("   Operation Menu        \n");
    printf("1. Encrypt File         \n");
    printf("2. Decrypt File         \n");
    printf("//////////////////////////\n");
}

void processFile(const char *filename, int key, int mode) {
    FILE *file;
    char *text;
    long length;

    file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Unable to open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    // Get the length of the file
    fseek(file, 0, SEEK_END);
    length = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the file text
    text = (char *)malloc(length + 1);
    if (!text) {
        printf("Error: Memory allocation failed\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fread(text, 1, length, file);
    text[length] = '\0'; // Null-terminate the string
    fclose(file);

    // Encrypt or decrypt based on the selected mode
    if (mode == ENCRYPT_MODE) {
        encrypt(text, key);
        printf("File '%s' encrypted successfully.\n", filename);
    } else if (mode == DECRYPT_MODE) {
        decrypt(text, key);
        printf("File '%s' decrypted successfully.\n", filename);
    } else {
        printf("Error: Invalid mode selected\n");
        free(text);
        exit(EXIT_FAILURE);
    }

    // Write to a new file
    char outputFilename[256];
    sprintf(outputFilename, "%s_result.txt", filename);
    file = fopen(outputFilename, "wb");
    if (!file) {
        printf("Error: Unable to open output file '%s'\n", outputFilename);
        free(text);
        exit(EXIT_FAILURE);
    }

    fwrite(text, 1, length, file);
    fclose(file);
    free(text);
}

void encrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] += key; // Shift the character
    }
}

void decrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        text[i] -= key; // Reverse the shift
    }
}