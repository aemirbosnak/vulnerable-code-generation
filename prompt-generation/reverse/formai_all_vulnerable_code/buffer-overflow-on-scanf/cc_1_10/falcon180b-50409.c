//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the file
void encrypt(FILE *fp, char *key) {
    char ch;
    int key_len = strlen(key);
    int i = 0;

    // Loop through each character in the file
    while ((ch = fgetc(fp))!= EOF) {
        // Encrypt the character using the key
        ch = ch ^ key[i];
        // Increment the key index
        i++;
        if (i == key_len) {
            i = 0;
        }
        // Write the encrypted character to the file
        fputc(ch, fp);
    }
}

// Function to decrypt the file
void decrypt(FILE *fp, char *key) {
    char ch;
    int key_len = strlen(key);
    int i = 0;

    // Loop through each character in the file
    while ((ch = fgetc(fp))!= EOF) {
        // Decrypt the character using the key
        ch = ch ^ key[i];
        // Increment the key index
        i++;
        if (i == key_len) {
            i = 0;
        }
        // Write the decrypted character to the file
        fputc(ch, fp);
    }
}

int main() {
    FILE *fp;
    char key[100];

    // Open the file
    fp = fopen("file.txt", "rb+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Get the encryption key from the user
    printf("Enter encryption key: ");
    scanf("%s", key);

    // Encrypt the file
    encrypt(fp, key);

    // Close the file
    fclose(fp);

    // Open the encrypted file
    fp = fopen("file.txt", "rb+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Decrypt the file
    decrypt(fp, key);

    // Close the file
    fclose(fp);

    printf("File encrypted and decrypted successfully!\n");

    return 0;
}