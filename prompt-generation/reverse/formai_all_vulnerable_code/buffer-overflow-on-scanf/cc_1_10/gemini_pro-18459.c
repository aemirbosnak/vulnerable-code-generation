//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Custom data structure to represent an encrypted file
struct EncryptedFile {
    char* filename;
    char* encrypted_data;
    size_t encrypted_data_size;
};

// Function to encrypt a file
struct EncryptedFile* encrypt_file(char* filename, char* key) {
    // Open the file in binary read mode
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    rewind(file);

    // Read the file data into a buffer
    char* file_data = malloc(sizeof(char) * (file_size + 1));
    if (file_data == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }
    fread(file_data, sizeof(char), file_size, file);
    fclose(file);
    file_data[file_size] = '\0';

    // Encrypt the file data
    char* encrypted_data = malloc((sizeof(char) * (file_size + 1)));
    for (size_t i = 0; i < file_size; i++) {
        encrypted_data[i] = file_data[i] ^ key[(i % strlen(key))];
    }

    // Create the EncryptedFile struct and return it
    struct EncryptedFile* encrypted_file = malloc(sizeof(struct EncryptedFile));
    encrypted_file->filename = filename;
    encrypted_file->encrypted_data = encrypted_data;
    encrypted_file->encrypted_data_size = file_size;
    return encrypted_file;
}

// Function to decrypt a file
char* decrypt_file(struct EncryptedFile* encrypted_file, char* key) {
    // Decrypt the encrypted data
    char* decrypted_data = malloc((sizeof(char) * (encrypted_file->encrypted_data_size + 1)));
    for (size_t i = 0; i < encrypted_file->encrypted_data_size; i++) {
        decrypted_data[i] = encrypted_file->encrypted_data[i] ^ key[(i % strlen(key))];
    }

    // Create a new file and write the decrypted data to it
    char* decrypted_filename = malloc(sizeof(char) * (strlen(encrypted_file->filename) + 5));
    sprintf(decrypted_filename, "%s.dec", encrypted_file->filename);
    FILE* decrypted_file = fopen(decrypted_filename, "wb");
    fwrite(decrypted_data, sizeof(char), encrypted_file->encrypted_data_size, decrypted_file);
    fclose(decrypted_file);

    // Return the decrypted filename
    return decrypted_filename;
}

// Main function
int main() {
    // Get the filename and key from the user
    char filename[256];
    char key[256];
    printf("Enter the filename: ");
    scanf("%s", filename);
    printf("Enter the encryption key: ");
    scanf("%s", key);

    // Encrypt the file
    struct EncryptedFile* encrypted_file = encrypt_file(filename, key);
    printf("File encrypted successfully!\n");

    // Decrypt the file
    char* decrypted_filename = decrypt_file(encrypted_file, key);
    printf("File decrypted successfully to: %s\n", decrypted_filename);

    // Free the memory allocated for the encrypted file
    free(encrypted_file->encrypted_data);
    free(encrypted_file->filename);
    free(encrypted_file);
    free(decrypted_filename);
}