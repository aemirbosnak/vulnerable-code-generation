//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"
#define KEY_LENGTH 12

void encrypt(char* filename, char* encrypted_filename) {
    FILE* input_file = fopen(filename, "rb");
    FILE* output_file = fopen(encrypted_filename, "wb");
    if (!input_file ||!output_file) {
        printf("Error opening file\n");
        exit(1);
    }

    unsigned char key[KEY_LENGTH];
    strcpy((char*)key, KEY);

    int bytes_read;
    unsigned char buffer[1024];
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[i % KEY_LENGTH];
        }
        fwrite(buffer, 1, bytes_read, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

void decrypt(char* filename, char* decrypted_filename) {
    FILE* input_file = fopen(filename, "rb");
    FILE* output_file = fopen(decrypted_filename, "wb");
    if (!input_file ||!output_file) {
        printf("Error opening file\n");
        exit(1);
    }

    unsigned char key[KEY_LENGTH];
    strcpy((char*)key, KEY);

    int bytes_read;
    unsigned char buffer[1024];
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input_file)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[i % KEY_LENGTH];
        }
        fwrite(buffer, 1, bytes_read, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    char filename[50];
    printf("Enter the filename to be encrypted: ");
    scanf("%s", filename);

    char encrypted_filename[50];
    strcat(encrypted_filename, filename);
    strcat(encrypted_filename, ".enc");

    encrypt(filename, encrypted_filename);
    printf("File encrypted successfully!\n");

    char decrypted_filename[50];
    strcat(decrypted_filename, filename);
    strcat(decrypted_filename, ".dec");

    decrypt(encrypted_filename, decrypted_filename);
    printf("File decrypted successfully!\n");

    return 0;
}