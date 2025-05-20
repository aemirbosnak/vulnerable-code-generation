//FormAI DATASET v1.0 Category: File Encyptor ; Style: imaginative
#include <stdio.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_BUFFER_SIZE 1024

void encrypt_file(char *filename);
void decrypt_file(char *filename);

int main() {
    char filename[MAX_FILENAME_LENGTH];
    int choice;

    printf("1. Encrypt a file\n2. Decrypt a file\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter filename with extension: ");
    scanf("%s", filename);

    switch(choice) {
        case 1: encrypt_file(filename);
                printf("Encryption Complete!\n");
                break;
        case 2: decrypt_file(filename);
                printf("Decryption Complete!\n");
                break;
        default: printf("Invalid choice!\n");
    }

    return 0;
}

void encrypt_file(char *filename) {
    FILE *fp;
    char buffer[MAX_BUFFER_SIZE];
    int i, key;

    printf("Enter key (integer): ");
    scanf("%d", &key);

    fp = fopen(filename, "rb");

    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    strcat(filename, ".enc");
    FILE *fp_encrypted = fopen(filename, "wb");

    while(!feof(fp)) {
        size_t bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, fp);

        for(i=0; i<bytes_read; i++) {
            buffer[i] = buffer[i] ^ key;
        }

        fwrite(buffer, 1, bytes_read, fp_encrypted);
    }

    fclose(fp);
    fclose(fp_encrypted);
}

void decrypt_file(char *filename) {
    FILE *fp;
    char buffer[MAX_BUFFER_SIZE];
    int i, key;

    printf("Enter key (integer): ");
    scanf("%d", &key);

    fp = fopen(filename, "rb");

    if(fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char *dot_pos = strrchr(filename, '.');
    *dot_pos = '\0';

    strcat(filename, "_decrypted");
    FILE *fp_decrypted = fopen(filename, "wb");

    while(!feof(fp)) {
        size_t bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, fp);

        for(i=0; i<bytes_read; i++) {
            buffer[i] = buffer[i] ^ key;
        }

        fwrite(buffer, 1, bytes_read, fp_decrypted);
    }

    fclose(fp);
    fclose(fp_decrypted);
}