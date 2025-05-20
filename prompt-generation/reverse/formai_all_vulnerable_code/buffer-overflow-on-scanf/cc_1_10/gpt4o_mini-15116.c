//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define ENCRYPTION_KEY 155

void encrypt(char *input, char *output);
void decrypt(char *input, char *output);
void display_menu();
void get_filename(char *filename);

int main() {
    char filename[MAX_BUFFER];
    char choice;
    char plaintext[MAX_BUFFER];
    char ciphertext[MAX_BUFFER];

    display_menu();
    printf("Enter your choice (e/d): ");
    scanf(" %c", &choice);

    printf("Enter the file name (with extension): ");
    get_filename(filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s for reading.\n", filename);
        return 1;
    }
    
    // Read file content
    fread(plaintext, sizeof(char), MAX_BUFFER, file);
    fclose(file);
    plaintext[MAX_BUFFER - 1] = '\0'; // Ensure null termination

    if (choice == 'e') {
        encrypt(plaintext, ciphertext);
        snprintf(filename, sizeof(filename), "encrypted_%s", filename);
        FILE *enc_file = fopen(filename, "w");
        fwrite(ciphertext, sizeof(char), strlen(ciphertext), enc_file);
        fclose(enc_file);
        printf("File encrypted successfully as %s\n", filename);
    } else if (choice == 'd') {
        decrypt(plaintext, ciphertext);
        snprintf(filename, sizeof(filename), "decrypted_%s", filename);
        FILE *dec_file = fopen(filename, "w");
        fwrite(ciphertext, sizeof(char), strlen(ciphertext), dec_file);
        fclose(dec_file);
        printf("File decrypted successfully as %s\n", filename);
    } else {
        fprintf(stderr, "Invalid choice! Please select 'e' for encrypt or 'd' for decrypt.\n");
    }

    return 0;
}

void encrypt(char *input, char *output) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] ^ ENCRYPTION_KEY; // Simple XOR encryption
    }
    output[i] = '\0'; // Null terminate
}

void decrypt(char *input, char *output) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] ^ ENCRYPTION_KEY; // Simple XOR decryption
    }
    output[i] = '\0'; // Null terminate
}

void display_menu() {
    printf("==============================================\n");
    printf("              C File Encryptor               \n");
    printf("==============================================\n");
    printf("Options:\n");
    printf("e - Encrypt a file\n");
    printf("d - Decrypt a file\n");
    printf("==============================================\n");
}

void get_filename(char *filename) {
    scanf("%s", filename);
    size_t len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0'; // Remove trailing newline
    }
}