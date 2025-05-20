//FormAI DATASET v1.0 Category: File Encyptor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the data in the file
void encrypt(char *filename, char *key) {
    FILE *file;
    long int size;
    char *buffer;
    int keysize = strlen(key);
    int i, j;

    // Open the file in binary mode
    file = fopen(filename, "rb");

    // Get the size of the file
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the buffer
    buffer = (char*) malloc(size);

    // Read the file into the buffer
    fread(buffer, size, 1, file);

    // Encrypt the data in the buffer
    for(i=0, j=0; i<size; i++, j++) {
        if(j == keysize)
            j = 0;
        buffer[i] ^= key[j];
    }

    // Open the file in write mode
    file = fopen(filename, "wb");

    // Write the encrypted data to the file
    fwrite(buffer, size, 1, file);

    // Free the memory allocated to the buffer
    free(buffer);

    // Close the file
    fclose(file);

    printf("Encryption complete.\n");
}

// Function to decrypt the data in the file
void decrypt(char *filename, char *key) {
    FILE *file;
    long int size;
    char *buffer;
    int keysize = strlen(key);
    int i, j;

    // Open the file in binary mode
    file = fopen(filename, "rb");

    // Get the size of the file
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the buffer
    buffer = (char*) malloc(size);

    // Read the file into the buffer
    fread(buffer, size, 1, file);

    // Decrypt the data in the buffer
    for(i=0, j=0; i<size; i++, j++) {
        if(j == keysize)
            j = 0;
        buffer[i] ^= key[j];
    }

    // Open the file in write mode
    file = fopen(filename, "wb");

    // Write the decrypted data to the file
    fwrite(buffer, size, 1, file);

    // Free the memory allocated to the buffer
    free(buffer);

    // Close the file
    fclose(file);

    printf("Decryption complete.\n");
}

int main() {
    char choice, filename[50], key[50];

    printf("Welcome to the C File Encryptor!\n");

    do {
        printf("\nPlease choose your option:\n");
        printf("(E)ncrypt a file\n");
        printf("(D)ecrypt a file\n");
        printf("(Q)uit\n");
        scanf(" %c", &choice);

        switch(choice) {
            case 'E':
            case 'e':
                printf("\nEnter the filename to encrypt: ");
                scanf("%s", filename);
                printf("Enter the encryption key: ");
                scanf("%s", key);
                encrypt(filename, key);
                break;
            case 'D':
            case 'd':
                printf("\nEnter the filename to decrypt: ");
                scanf("%s", filename);
                printf("Enter the decryption key: ");
                scanf("%s", key);
                decrypt(filename, key);
                break;
            case 'Q':
            case 'q':
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please select again.\n");
                break;
        }
    } while(choice!='Q' && choice!='q');

    return 0;
}