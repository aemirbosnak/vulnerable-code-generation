//FormAI DATASET v1.0 Category: File Encyptor ; Style: irregular
/* Welcome to my unique C File Encryptor program! */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the file contents using XOR cipher
void encrypt(char *filename, char *key) {
    FILE *file = fopen(filename, "rb"); // open the file in binary mode
    if (file == NULL) {
        printf("Error opening file!");
        return;
    }
    FILE *encrypted_file = fopen("encrypted.bin", "wb+"); // create a new file for encrypted contents
    if (encrypted_file == NULL) {
        printf("Error creating encrypted file!");
        return;
    }
    int key_len = strlen(key);
    int i = 0, j = 0, ch;
    while ((ch = fgetc(file)) != EOF) { // read one byte at a time
        fputc(ch ^ key[j % key_len], encrypted_file); // perform XOR operation with key and write to encrypted file
        j++;
    }
    printf("File encrypted successfully!\n");
    fclose(file);
    fclose(encrypted_file);
}

// Function to decrypt the file contents using XOR cipher
void decrypt(char *filename, char *key) {
    FILE *encrypted_file = fopen(filename, "rb"); // open the encrypted file in binary mode
    if (encrypted_file == NULL) {
        printf("Error opening encrypted file!");
        return;
    }
    FILE *decrypted_file = fopen("decrypted.txt", "w+"); // create a new file for decrypted contents
    if (decrypted_file == NULL) {
        printf("Error creating decrypted file!");
        return;
    }
    int key_len = strlen(key);
    int i = 0, j = 0, ch;
    while ((ch = fgetc(encrypted_file)) != EOF) { // read one byte at a time
        fputc(ch ^ key[j % key_len], decrypted_file); // perform XOR operation with key and write to decrypted file
        j++;
    }
    printf("File decrypted successfully!\n");
    fclose(encrypted_file);
    fclose(decrypted_file);
}

int main() {
    printf("Welcome to my unique C File Encryptor program!\n");
    printf("Enter filename to encrypt (with extension): ");
    char filename[100];
    scanf("%s", filename);
    printf("Enter encryption key: ");
    char key[100];
    scanf("%s", key);
    encrypt(filename, key);
    printf("\nEnter filename to decrypt (with extension): ");
    scanf("%s", filename);
    printf("Enter decryption key: ");
    scanf("%s", key);
    decrypt(filename, key);
    return 0;
}