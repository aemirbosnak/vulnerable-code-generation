//FormAI DATASET v1.0 Category: File Encyptor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 100
#define MAX_BUFFER 1024

// function prototypes
void encrypt_file(char* filename, int key);
void encrypt_buffer(char* buffer, int key);
void decrypt_file(char* filename, int key);
void decrypt_buffer(char* buffer, int key);

int main(int argc, char** argv) {
    // check for correct number of arguments
    if(argc != 4) {
        printf("Usage: %s <encrypt/decrypt> <filename> <encryption key>\n", argv[0]);
        exit(1);
    }

    // get user input
    char* mode = argv[1];
    char* filename = argv[2];
    int key = strtol(argv[3], NULL, 10);

    // determine operation
    if(strcmp(mode, "encrypt") == 0) {
        encrypt_file(filename, key);
    }
    else if(strcmp(mode, "decrypt") == 0) {
        decrypt_file(filename, key);
    }
    else {
        printf("Invalid mode, please use 'encrypt' or 'decrypt'\n");
        exit(1);
    }

    return 0;
}

void encrypt_file(char* filename, int key) {
    // open file
    FILE* fp = fopen(filename, "r+");
    if(fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    // get file size
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

    // allocate buffer
    char* buffer = malloc(size + 1);
    fseek(fp, 0, SEEK_SET);
    fread(buffer, size, 1, fp);

    // close file
    fclose(fp);

    // encrypt buffer
    encrypt_buffer(buffer, key);

    // write encrypted buffer back to file
    fp = fopen(filename, "w");
    fwrite(buffer, size, 1, fp);
    fclose(fp);

    free(buffer);

    printf("File '%s' encrypted successfully with key %d\n", filename, key);
}

void encrypt_buffer(char* buffer, int key) {
    // calculate buffer length
    int len = strlen(buffer);

    // encrypt buffer
    for(int i = 0; i < len; i++) {
        buffer[i] = buffer[i] ^ key;
    }

    // call function recursively on every 2nd character
    for(int i = 1; i < len; i += 2) {
        encrypt_buffer(&buffer[i], key);
    }
}

void decrypt_file(char* filename, int key) {
    // open file
    FILE* fp = fopen(filename, "r+");
    if(fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    // get file size
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

    // allocate buffer
    char* buffer = malloc(size + 1);
    fseek(fp, 0, SEEK_SET);
    fread(buffer, size, 1, fp);

    // close file
    fclose(fp);

    // decrypt buffer
    decrypt_buffer(buffer, key);

    // write decrypted buffer back to file
    fp = fopen(filename, "w");
    fwrite(buffer, size, 1, fp);
    fclose(fp);

    free(buffer);

    printf("File '%s' decrypted successfully with key %d\n", filename, key);
}

void decrypt_buffer(char* buffer, int key) {
    // calculate buffer length
    int len = strlen(buffer);

    // call function recursively on every 2nd character
    for(int i = 1; i < len; i += 2) {
        decrypt_buffer(&buffer[i], key);
    }

    // decrypt buffer
    for(int i = 0; i < len; i++) {
        buffer[i] = buffer[i] ^ key;
    }
}