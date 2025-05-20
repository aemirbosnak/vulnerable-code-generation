//FormAI DATASET v1.0 Category: File Encyptor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 256
#define MAX_SECRET_KEY_SIZE 256

void encrypt_file(char* filename, char* secret_key);
void decrypt_file(char* filename, char* secret_key);

int main(void) {
    char choice;
    char filename[MAX_FILENAME_SIZE];
    char secret_key[MAX_SECRET_KEY_SIZE];    

    while(1) {
        printf("\nPlease select an option:\n");
        printf("1. Encrypt a file\n");
        printf("2. Decrypt a file\n");
        printf("3. Exit\n");

        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                printf("Please enter the filename to encrypt: ");
                scanf("%s", filename);
                printf("Please enter the secret key: ");
                scanf("%s", secret_key);
                encrypt_file(filename, secret_key);
                printf("%s has been encrypted.\n", filename);
                break;
            case '2':
                printf("Please enter the filename to decrypt: ");
                scanf("%s", filename);
                printf("Please enter the secret key: ");
                scanf("%s", secret_key);
                decrypt_file(filename, secret_key);
                printf("%s has been decrypted.\n", filename);
                break;
            case '3':
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");            
        }
    }

    return 0;
}

void encrypt_file(char* filename, char* secret_key) {
    FILE* file_ptr;
    FILE* encrypted_file_ptr;
    char* encrypted_filename;
    char buffer[256];
    int i;

    // Create encrypted filename by adding ".enc" to original filename
    encrypted_filename = (char*) malloc(strlen(filename) + 5);
    strcpy(encrypted_filename, filename);
    strcat(encrypted_filename, ".enc");

    // Open original file for read and encrypted file for write
    file_ptr = fopen(filename, "r");
    encrypted_file_ptr = fopen(encrypted_filename, "w");

    // Encrypt file using secret key
    while(fgets(buffer, 255, file_ptr)) {
        for(i=0; i<strlen(buffer)-1; i++) {
            buffer[i] ^= secret_key[i % strlen(secret_key)];
        }
        fprintf(encrypted_file_ptr, "%s", buffer);
    }

    // Close files and delete original file
    fclose(file_ptr);
    fclose(encrypted_file_ptr);
    remove(filename);

    // Rename encrypted file to original filename
    rename(encrypted_filename, filename);

    free(encrypted_filename);
}

void decrypt_file(char* filename, char* secret_key) {
    FILE* file_ptr;
    FILE* decrypted_file_ptr;
    char* decrypted_filename;
    char buffer[256];
    int i;

    // Create decrypted filename by removing ".enc" from original filename
    decrypted_filename = (char*) malloc(strlen(filename) + 1);
    strncpy(decrypted_filename, filename, strlen(filename)-4);
    decrypted_filename[strlen(filename)-4] = '\0';

    // Open encrypted file for read and decrypted file for write
    file_ptr = fopen(filename, "r");
    decrypted_file_ptr = fopen(decrypted_filename, "w");

    // Decrypt file using secret key
    while(fgets(buffer, 255, file_ptr)) {
        for(i=0; i<strlen(buffer)-1; i++) {
            buffer[i] ^= secret_key[i % strlen(secret_key)];
        }
        fprintf(decrypted_file_ptr, "%s", buffer);
    }

    // Close files and delete encrypted file
    fclose(file_ptr);
    fclose(decrypted_file_ptr);
    remove(filename);

    free(decrypted_filename);
}