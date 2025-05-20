//FormAI DATASET v1.0 Category: Encryption ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char key[100], iv[100];
int key_len, iv_len;

int main() {
    // Get key and IV from user
    printf("Enter Key: ");
    scanf("%s", key);
    printf("Enter IV: ");
    scanf("%s", iv);

    key_len = strlen(key);
    iv_len = strlen(iv);

    // Open file to encrypt
    FILE *fp = fopen("file.txt", "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    // Get file size
    fseek(fp, 0, SEEK_END);
    long int file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Read file into buffer
    char *buffer = (char*) malloc(file_size + 1);
    if (buffer == NULL) {
        printf("Error allocating memory.\n");
        return 0;
    }
    fread(buffer, sizeof(char), file_size, fp);
    fclose(fp);

    // Encrypt buffer using AES-256-CBC
    for (int i = 0; i < file_size; i++) {
        buffer[i] ^= key[i%key_len];
        buffer[i] ^= iv[i%iv_len];
    }

    // Write encrypted buffer to file
    fp = fopen("encrypted.txt", "wb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    fwrite(buffer, sizeof(char), file_size, fp);
    fclose(fp);

    free(buffer); // Free memory allocated for buffer

    printf("Encryption Successful.\n");

    return 0;
}