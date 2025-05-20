//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to encrypt the file
void encrypt(FILE* file, int key) {
    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + key) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + key) % 26 + 'A';
        }
        fputc(ch, stdout);
    }
}

// Function to decrypt the file
void decrypt(FILE* file, int key) {
    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - key + 26) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - key + 26) % 26 + 'A';
        }
        fputc(ch, stdout);
    }
}

int main() {
    FILE* file;
    char filename[100];
    int key;

    // Get the filename from the user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file in read mode
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Get the encryption key from the user
    printf("Enter the encryption key: ");
    scanf("%d", &key);

    // Encrypt the file
    rewind(file);
    encrypt(file, key);

    // Close the file
    fclose(file);

    // Open the encrypted file in write mode
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Decrypt the file
    rewind(file);
    decrypt(file, key);

    // Close the file
    fclose(file);

    printf("File encrypted and decrypted successfully!\n");

    return 0;
}