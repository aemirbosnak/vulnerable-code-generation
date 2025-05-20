//FormAI DATASET v1.0 Category: File Encyptor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the contents of a file
void encryptFile(FILE *f, char key[], int index)
{
    if(f == NULL) {
        return;
    }
    
    // Move the file pointer to the beginning of the file
    fseek(f, 0, SEEK_SET);

    // Temporary buffer to read the file contents
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    
    // Read the file contents into the buffer
    int bytesRead = fread(buffer, sizeof(char), sizeof(buffer), f);

    // If the end of the file has not been reached
    if(bytesRead < 1024) {
        // Pad the buffer with null characters
        memset(buffer + bytesRead, '\0', 1024 - bytesRead);
    }
    
    // Encrypt the buffer using the given key
    for(int i = 0; i < 1024; i++) {
        buffer[i] ^= key[index];
        index = (index + 1) % strlen(key);
    }

    // Write the encrypted buffer back to the file
    fseek(f, 0, SEEK_SET);
    fwrite(buffer, sizeof(char), sizeof(buffer), f);

    // Encrypt the next block of data recursively
    encryptFile(f, key, index);
}

int main(int argc, char *argv[])
{
    // Check if the user has provided the file name and key
    if(argc < 3) {
        printf("Usage: %s file.key\n", argv[0]);
        return 1;
    }

    // Open the input file in read mode
    FILE *f = fopen(argv[1], "rb");
    if(f == NULL) {
        printf("Failed to open file: %s\n", argv[1]);
        return 1;
    }

    // Read the key from the key file
    FILE *keyFile = fopen(argv[2], "r");
    if(keyFile == NULL) {
        printf("Failed to open key file: %s\n", argv[2]);
        fclose(f);
        return 1;
    }

    char key[1024];
    fgets(key, sizeof(key), keyFile);
    key[strlen(key) - 1] = '\0';

    // Encrypt the contents of the file recursively using the key
    encryptFile(f, key, 0);

    // Cleanup
    fclose(keyFile);
    fclose(f);

    printf("File encryption successful!\n");
    return 0;
}