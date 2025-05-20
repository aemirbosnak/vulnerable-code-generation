//FormAI DATASET v1.0 Category: File Encyptor ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILE_NAME_LENGTH 255
#define MAX_BUFFER_LENGTH 1024

// Function to encrypt file
void encryptFile(char* filename, char* key) {
    FILE *fp = NULL;
    FILE *out_fp = NULL;

    int ch, i = 0, key_length = strlen(key);

    fp = fopen(filename, "r");
    out_fp = fopen("encrypted_file", "w");

    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    if(out_fp == NULL) {
        printf("Error opening output file\n");
        return;
    }

    while((ch = fgetc(fp)) != EOF) {
        // XOR each character with corresponding key character
        fputc(ch ^ key[i], out_fp);
        i++;
        if(i == key_length) {
            i = 0;
        }
    }

    fclose(fp);
    fclose(out_fp);

    printf("File encrypted successfully!\n");
}

// Function to decrypt file
void decryptFile(char* filename, char* key) {
    FILE *fp = NULL;
    FILE *out_fp = NULL;

    int ch, i = 0, key_length = strlen(key);

    fp = fopen(filename, "r");
    out_fp = fopen("decrypted_file", "w");

    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    if(out_fp == NULL) {
        printf("Error opening output file\n");
        return;
    }

    while((ch = fgetc(fp)) != EOF) {
        // XOR each character with corresponding key character
        fputc(ch ^ key[i], out_fp);
        i++;
        if(i == key_length) {
            i = 0;
        }
    }

    fclose(fp);
    fclose(out_fp);

    printf("File decrypted successfully!\n");
}

int main() {
    char filename[MAX_FILE_NAME_LENGTH];
    char key[MAX_BUFFER_LENGTH];
    int mode = 0;

    printf("\nWelcome to the C File Encryptor program!\n\n");

    while(1) {
        printf("Please select a mode:\n");
        printf("1. Encrypt a file\n");
        printf("2. Decrypt a file\n");
        printf("3. Exit program\n");
        scanf("%d", &mode);

        switch(mode) {
            case 1:
                printf("Please enter the filename to encrypt: ");
                scanf("%s", filename);
                printf("Please enter the encryption key: ");
                scanf("%s", key);
                encryptFile(filename, key);
                printf("\n");
                break;

            case 2:
                printf("Please enter the filename to decrypt: ");
                scanf("%s", filename);
                printf("Please enter the decryption key: ");
                scanf("%s", key);
                decryptFile(filename, key);
                printf("\n");
                break;

            case 3:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid mode selected. Please try again.\n\n");
                break;
        }
    }
    return 0;
}