//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the file
void encrypt_file(const char* filename, const char* key) {
    // Open the file for reading
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }
    
    // Read the file into a buffer
    char buffer[100000];
    size_t bytes_read = fread(buffer, sizeof(char), sizeof(buffer), file);
    
    // Close the file
    fclose(file);
    
    // Encrypt the buffer using the key
    char encrypted[bytes_read];
    for (int i = 0; i < bytes_read; i++) {
        encrypted[i] = buffer[i] ^ key[i % strlen(key)];
    }
    
    // Write the encrypted buffer to a new file
    FILE* new_file = fopen(filename, "w");
    if (new_file == NULL) {
        printf("Error opening the new file.\n");
        return;
    }
    fwrite(encrypted, sizeof(char), bytes_read, new_file);
    fclose(new_file);
    
    // Print a success message
    printf("File encrypted successfully.\n");
}

int main() {
    // Prompt the user for the file and key
    printf("Enter the name of the file to encrypt: ");
    char filename[100];
    scanf("%s", filename);
    
    printf("Enter the encryption key: ");
    char key[100];
    scanf("%s", key);
    
    // Call the encryption function
    encrypt_file(filename, key);
    
    return 0;
}