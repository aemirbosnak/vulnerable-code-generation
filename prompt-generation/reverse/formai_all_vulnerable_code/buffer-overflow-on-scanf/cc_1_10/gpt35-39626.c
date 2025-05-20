//FormAI DATASET v1.0 Category: File Encyptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_KEY_LENGTH 32

void encrypt(char *file_name, char *key);
void decrypt(char *file_name, char *key);

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    char key[MAX_KEY_LENGTH];
    int choice;

    printf("Welcome to the C File Encryptor!\n\n");

    do {
        printf("Please select an option:\n");
        printf("1. Encrypt a file\n");
        printf("2. Decrypt a file\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name of the file to encrypt: ");
                scanf("%s", file_name);
                printf("Enter the encryption key (max length of %d characters): ", MAX_KEY_LENGTH-1);
                scanf("%s", key);
                encrypt(file_name, key);
                break;
            case 2:
                printf("Enter the name of the file to decrypt: ");
                scanf("%s", file_name);
                printf("Enter the decryption key (max length of %d characters): ", MAX_KEY_LENGTH-1);
                scanf("%s", key);
                decrypt(file_name, key);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n\n");
                break;
        }
    }
    while (choice != 3);

    return 0;
}

void encrypt(char *file_name, char *key) {
    FILE *file_in, *file_out;
    char character;
    int key_index = 0;

    file_in = fopen(file_name, "r");
    if (file_in == NULL) {
        printf("Error: Could not open file %s for reading.\n", file_name);
        return;
    }

    file_out = fopen(strcat(file_name, ".enc"), "w");
    if (file_out == NULL) {
        printf("Error: Could not open file %s for writing.\n", file_name);
        return;
    }

    printf("Encrypting file %s...\n", file_name);

    while ((character = fgetc(file_in)) != EOF) {
        fputc(character ^ key[key_index], file_out);
        key_index = (key_index + 1) % strlen(key);
    }

    fclose(file_in);
    fclose(file_out);

    printf("File %s encrypted successfully.\n\n", file_name);
}

void decrypt(char *file_name, char *key) {
    FILE *file_in, *file_out;
    char character;
    int key_index = 0;

    file_in = fopen(file_name, "r");
    if (file_in == NULL) {
        printf("Error: Could not open file %s for reading.\n", file_name);
        return;
    }

    file_out = fopen(strcat(file_name, ".dec"), "w");
    if (file_out == NULL) {
        printf("Error: Could not open file %s for writing.\n", file_name);
        return;
    }

    printf("Decrypting file %s...\n", file_name);

    while ((character = fgetc(file_in)) != EOF) {
        fputc(character ^ key[key_index], file_out);
        key_index = (key_index + 1) % strlen(key);
    }

    fclose(file_in);
    fclose(file_out);

    printf("File %s decrypted successfully.\n\n", file_name);
}