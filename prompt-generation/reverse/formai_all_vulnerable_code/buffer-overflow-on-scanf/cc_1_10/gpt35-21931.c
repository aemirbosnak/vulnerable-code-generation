//FormAI DATASET v1.0 Category: File Encyptor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt_file(char* file_path, char* encryption_key) {
    FILE* fp_in = fopen(file_path, "rb");
    FILE* fp_out = fopen(strcat(file_path, ".enc"), "wb");
    int key_length = strlen(encryption_key);

    if (fp_in == NULL) {
        printf("Error: File could not be opened.\n");
        return;
    }

    if (fp_out == NULL) {
        printf("Error: Encrypted file could not be created.\n");
        return;
    }

    int i = 0, ch;
    while ((ch = fgetc(fp_in)) != EOF) {
        fputc(ch ^ encryption_key[i % key_length], fp_out);
        i++;
    }

    printf("File successfully encrypted.\n");

    fclose(fp_in);
    fclose(fp_out);
}

void decrypt_file(char* file_path, char* encryption_key) {
    FILE* fp_enc = fopen(file_path, "rb");
    FILE* fp_dec = fopen(strtok(file_path, "."), "wb");
    int key_length = strlen(encryption_key);

    if (fp_enc == NULL) {
        printf("Error: Encrypted file could not be opened.\n");
        return;
    }

    if (fp_dec == NULL) {
        printf("Error: Decrypted file could not be created.\n");
        return;
    }

    int i = 0, ch;
    while ((ch = fgetc(fp_enc)) != EOF) {
        fputc(ch ^ encryption_key[i % key_length], fp_dec);
        i++;
    }

    printf("File successfully decrypted.\n");

    fclose(fp_enc);
    fclose(fp_dec);
}

int main() {
    char file_name[100], encryption_key[100], mode[10];

    printf("Enter file path: ");
    scanf("%s", file_name);

    printf("Enter encryption key: ");
    scanf("%s", encryption_key);

    printf("Enter mode (encrypt/decrypt): ");
    scanf("%s", mode);

    if (strcmp(mode, "encrypt") == 0) {
        encrypt_file(file_name, encryption_key);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt_file(file_name, encryption_key);
    } else {
        printf("Invalid mode.\n");
        return 1;
    }

    return 0;
}