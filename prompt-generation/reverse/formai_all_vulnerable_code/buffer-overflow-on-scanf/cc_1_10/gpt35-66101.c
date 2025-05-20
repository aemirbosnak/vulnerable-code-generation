//FormAI DATASET v1.0 Category: File Encyptor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *filename, char *key) {
    FILE *fp;
    char ch;
    int i = 0, keyLength = strlen(key);

    // Opening the file to be encrypted.
    fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(0);
    }

    // Traverse through the file and encrypt the characters.
    while (ch = fgetc(fp)) {
        if (ch == EOF) {
            break;
        }
        ch += key[i];

        // Add an extra element if the key length is shorter than the file size.
        if (i == keyLength - 1) {
            i = 0;
        } else {
            i++;
        }
        fseek(fp, -1, SEEK_CUR);
        fputc(ch, fp);
    }

    // Close the file.
    fclose(fp);
}

void decrypt(char *filename, char *key) {
    FILE *fp;
    char ch;
    int i = 0, keyLength = strlen(key);

    // Opening the file to be decrypted.
    fp = fopen(filename, "r+");
    if (fp == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(0);
    }

    // Traverse through the file and decrypt the characters.
    while (ch = fgetc(fp)) {
        if (ch == EOF) {
            break;
        }
        ch -= key[i];

        // Add an extra element if the key length is shorter than the file size.
        if (i == keyLength - 1) {
            i = 0;
        } else {
            i++;
        }
        fseek(fp, -1, SEEK_CUR);
        fputc(ch, fp);
    }

    // Close the file.
    fclose(fp);
}

int main() {
    char filename[50];
    char key[50];
    int choice;

    printf("Enter the filename to encrypt/decrypt: ");
    scanf("%s", filename);
    printf("Enter the key to encrypt/decrypt: ");
    scanf("%s", key);

    printf("Enter your choice:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(filename, key);
            printf("File Encrypted Successfully.\n");
            break;
        case 2:
            decrypt(filename, key);
            printf("File Decrypted Successfully.\n");
            break;
        default:
            printf("Invalid Choice.\n");
            break;
    }

    return 0;
}