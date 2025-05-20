//FormAI DATASET v1.0 Category: File Encyptor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encode(char *str, int code) {
    int i = 0;
    while (str[i]) {
        str[i] += code;
        i++;
    }
}

void decode(char *str, int code) {
    int i = 0;
    while (str[i]) {
        str[i] -= code;
        i++;
    }
}

int main() {
    char filename[100];
    int code;
    printf("Enter the filename to encrypt: ");
    scanf("%s", filename);
    printf("Enter the encryption code: ");
    scanf("%d", &code);

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("ERROR: Could not open file '%s'\n", filename);
        return 1;
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory buffer
    char *buffer = (char *) malloc(size + 1);
    if (buffer == NULL) {
        printf("ERROR: Could not allocate memory for file buffer\n");
        fclose(file);
        return 1;
    }

    // Read file into buffer
    fread(buffer, size, 1, file);

    // Encrypt buffer
    encode(buffer, code);

    // Close file
    fclose(file);

    // Output encrypted file
    char encrypted_filename[100];
    sprintf(encrypted_filename, "%s.enc", filename);
    FILE *encrypted_file = fopen(encrypted_filename, "wb");
    if (encrypted_file == NULL) {
        printf("ERROR: Could not create encrypted file '%s'\n", encrypted_filename);
        free(buffer);
        return 1;
    }

    fwrite(buffer, size, 1, encrypted_file);

    fclose(encrypted_file);

    // Decrypt the file just to check if encryption worked
    printf("Encryption successful! Checking decryption...\n");

    FILE *decrypt_file = fopen(encrypted_filename, "rb");
    if (decrypt_file == NULL) {
        printf("ERROR: Could not open encrypted file '%s'\n", encrypted_filename);
        return 1;
    }

    // Get file size
    fseek(decrypt_file, 0, SEEK_END);
    size = ftell(decrypt_file);
    fseek(decrypt_file, 0, SEEK_SET);

    // Reallocate memory buffer
    buffer = (char *) realloc(buffer, size + 1);
    if (buffer == NULL) {
        printf("ERROR: Could not reallocate memory for file buffer\n");
        fclose(file);
        return 1;
    }

    // Read file into buffer
    fread(buffer, size, 1, decrypt_file);

    // Decrypt buffer
    decode(buffer, code);

    // Output decrypted file
    char decrypted_filename[100];
    sprintf(decrypted_filename, "decrypted_%s", filename);
    FILE *decrypted_file = fopen(decrypted_filename, "wb");
    if (decrypted_file == NULL) {
        printf("ERROR: Could not create decrypted file '%s'\n", decrypted_filename);
        free(buffer);
        return 1;
    }

    fwrite(buffer, size, 1, decrypted_file);

    fclose(decrypted_file);

    printf("Decryption successful! Encrypted file created: '%s'. Decrypted file created: '%s'\n", encrypted_filename, decrypted_filename);

    free(buffer);

    return 0;
}