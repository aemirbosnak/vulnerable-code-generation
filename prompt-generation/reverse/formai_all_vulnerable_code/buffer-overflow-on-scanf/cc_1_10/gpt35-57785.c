//FormAI DATASET v1.0 Category: File Encyptor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

void encryptFile(char *path, char *key);
void decryptFile(char *path, char *key);

int main(int argc, char *argv[]) {
    char *path, *key;
    int choice;
    printf("Welcome to the File Encryption Program!\n\n");
    printf("Please choose an option:\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("Your choice: ");
    scanf("%d", &choice);
    getchar();  // clears input buffer

    switch (choice) {
        case 1:
            printf("\nEnter the file path to encrypt: ");
            path = (char*) malloc(sizeof(char) * SIZE);
            fgets(path, SIZE, stdin);
            strtok(path, "\n");  // removes newline character at end of string
            printf("Enter the encryption key: ");
            key = (char*) malloc(sizeof(char) * SIZE);
            fgets(key, SIZE, stdin);
            strtok(key, "\n");  // removes newline character at end of string
            encryptFile(path, key);
            free(path);
            free(key);
            break;
        case 2:
            printf("\nEnter the file path to decrypt: ");
            path = (char*) malloc(sizeof(char) * SIZE);
            fgets(path, SIZE, stdin);
            strtok(path, "\n");
            printf("Enter the decryption key: ");
            key = (char*) malloc(sizeof(char) * SIZE);
            fgets(key, SIZE, stdin);
            strtok(key, "\n");
            decryptFile(path, key);
            free(path);
            free(key);
            break;
        default:
            printf("Invalid choice. Program terminated.\n");
            exit(1);
    }
    return 0;
}

void encryptFile(char *path, char *key) {
    FILE *fp, *fpEnc;
    char ch;
    int i = 0, j = 0, keylen;
    keylen = strlen(key);
    fp = fopen(path, "r");

    if (fp == NULL) {
        printf("Cannot open file %s\n", path);
        exit(1);
    }

    char *encryptedPath = (char*) malloc(sizeof(char) * SIZE);
    strcpy(encryptedPath, path);
    strcat(encryptedPath, ".encrypted");
    fpEnc = fopen(encryptedPath, "w+");

    if (fpEnc == NULL) {
        printf("Cannot create encrypted file %s\n", encryptedPath);
        exit(1);
    }

    while ((ch = fgetc(fp)) != EOF) {
        fputc(ch ^ key[i], fpEnc);
        i++;
        if (i == keylen) {
            i = 0;
        }
    }

    printf("File encrypted and saved as %s\n", encryptedPath);
    fclose(fp);
    fclose(fpEnc);
    free(encryptedPath);
}

void decryptFile(char *path, char *key) {
    FILE *fp, *fpDec;
    char ch;
    int i = 0, j = 0, keylen;
    keylen = strlen(key);
    fp = fopen(path, "r");

    if (fp == NULL) {
        printf("Cannot open file %s\n", path);
        exit(1);
    }

    char *decryptedPath = (char*) malloc(sizeof(char) * SIZE);
    strcpy(decryptedPath, path);
    strcat(decryptedPath, ".decrypted");
    fpDec = fopen(decryptedPath, "w+");

    if (fpDec == NULL) {
        printf("Cannot create decrypted file %s\n", decryptedPath);
        exit(1);
    }

    while ((ch = fgetc(fp)) != EOF) {
        fputc(ch ^ key[i], fpDec);
        i++;
        if (i == keylen) {
            i = 0;
        }
    }

    printf("File decrypted and saved as %s\n", decryptedPath);
    fclose(fp);
    fclose(fpDec);
    free(decryptedPath);
}