//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1000000) // 1 MB
#define KEY "secret_key"

// Function to encrypt the file
void encrypt_file(char *file_name) {
    FILE *file;
    char *buffer = malloc(MAX_FILE_SIZE);
    char *encrypted_buffer = malloc(MAX_FILE_SIZE);
    int buffer_size = 0;
    int i;

    // Open the file in read mode
    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        exit(1);
    }

    // Read the file into a buffer
    while ((buffer_size = fread(buffer, sizeof(char), MAX_FILE_SIZE, file)) > 0) {
        // Encrypt the buffer
        for (i = 0; i < buffer_size; i++) {
            if (isalpha(buffer[i])) {
                encrypted_buffer[i] = buffer[i] ^ (KEY[i % strlen(KEY)] + 1);
            } else {
                encrypted_buffer[i] = buffer[i];
            }
        }

        // Write the encrypted buffer to a new file
        FILE *encrypted_file = fopen("encrypted_file.txt", "w");
        if (encrypted_file == NULL) {
            printf("Error: Could not create encrypted file\n");
            exit(1);
        }

        fwrite(encrypted_buffer, sizeof(char), buffer_size, encrypted_file);
        fclose(encrypted_file);
    }

    fclose(file);
    free(buffer);
    free(encrypted_buffer);
}

int main() {
    char file_name[100];
    printf("Enter the name of the file you want to encrypt: ");
    scanf("%s", file_name);

    // Call the encrypt_file function
    encrypt_file(file_name);

    printf("File encrypted successfully!\n");
    return 0;
}