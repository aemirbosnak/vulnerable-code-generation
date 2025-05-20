//FormAI DATASET v1.0 Category: File Encyptor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the file
void encrypt(FILE* file, int key) {
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        ch = ch + key;
        fputc(ch, file);
    }
    printf("Encryption Successful!\n");
}

// Function to decrypt the file
void decrypt(FILE* file, int key) {
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        ch = ch - key;
        fputc(ch, file);
    }
    printf("Decryption Successful!\n");
}

int main() {
    char file_path[100];
    int key, choice;

    printf("Enter the file path to encrypt/decrypt: ");
    scanf("%s", file_path);

    printf("Enter the key: ");
    scanf("%d", &key);

    printf("Enter your choice:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    FILE* file = fopen(file_path, "r+");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    switch(choice) {
        case 1:
            encrypt(file, key);
            break;
        case 2:
            decrypt(file, key);
            break;
        default:
            printf("Invalid input!\n");
    }

    fclose(file);
    return 0;
}