//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_CONTENT_LENGTH 1000000

// Function to encrypt the file content using the provided key
void encrypt(char *file_content, char *key) {
    int i, j;
    for (i = 0; i < strlen(file_content); i++) {
        if (isalpha(file_content[i])) {
            file_content[i] = file_content[i] + (int)key[i % strlen(key)];
        }
    }
}

// Function to decrypt the file content using the provided key
void decrypt(char *file_content, char *key) {
    int i, j;
    for (i = 0; i < strlen(file_content); i++) {
        if (isalpha(file_content[i])) {
            file_content[i] = file_content[i] - (int)key[i % strlen(key)];
        }
    }
}

// Function to read the file content into a buffer
void read_file(char *file_name, char *buffer) {
    FILE *fp;
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        exit(1);
    }
    fread(buffer, sizeof(char), MAX_FILE_CONTENT_LENGTH, fp);
    fclose(fp);
}

// Function to write the encrypted/decrypted file content to a file
void write_file(char *file_name, char *buffer) {
    FILE *fp;
    fp = fopen(file_name, "w");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        exit(1);
    }
    fwrite(buffer, sizeof(char), strlen(buffer), fp);
    fclose(fp);
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    char file_content[MAX_FILE_CONTENT_LENGTH];
    char key[MAX_KEY_LENGTH];

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", file_name);

    // Read the file content into a buffer
    read_file(file_name, file_content);

    // Get the key from the user
    printf("Enter the key: ");
    scanf("%s", key);

    // Encrypt the file content
    encrypt(file_content, key);

    // Write the encrypted file content to a new file
    char encrypted_file_name[MAX_FILE_NAME_LENGTH];
    strcpy(encrypted_file_name, file_name);
    strcat(encrypted_file_name, ".enc");
    write_file(encrypted_file_name, file_content);

    printf("File encrypted successfully!\n");

    return 0;
}