//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a character
char encrypt(char c, int key) {
    // Check if the character is an alphabet
    if (isalpha(c)) {
        // Shift the character by the key
        c += key;

        // Handle the case when the character goes beyond 'z' or 'Z'
        if (c > 'z') {
            c -= 26;
        } else if (c > 'Z') {
            c -= 26;
        }
    }

    return c;
}

// Function to decrypt a character
char decrypt(char c, int key) {
    // Check if the character is an alphabet
    if (isalpha(c)) {
        // Shift the character back by the key
        c -= key;

        // Handle the case when the character goes before 'a' or 'A'
        if (c < 'a') {
            c += 26;
        } else if (c < 'A') {
            c += 26;
        }
    }

    return c;
}

// Function to encrypt a file
void encryptFile(char *filename, int key) {
    // Open the file in read mode
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // Create a new file in write mode
    FILE *fp2 = fopen("encrypted.txt", "w");
    if (fp2 == NULL) {
        perror("Error creating encrypted file");
        fclose(fp);
        return;
    }

    // Read the characters from the input file one by one
    char c;
    while ((c = fgetc(fp)) != EOF) {
        // Encrypt the character
        c = encrypt(c, key);

        // Write the encrypted character to the output file
        fputc(c, fp2);
    }

    // Close both the files
    fclose(fp);
    fclose(fp2);
}

// Function to decrypt a file
void decryptFile(char *filename, int key) {
    // Open the file in read mode
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    // Create a new file in write mode
    FILE *fp2 = fopen("decrypted.txt", "w");
    if (fp2 == NULL) {
        perror("Error creating decrypted file");
        fclose(fp);
        return;
    }

    // Read the characters from the input file one by one
    char c;
    while ((c = fgetc(fp)) != EOF) {
        // Decrypt the character
        c = decrypt(c, key);

        // Write the decrypted character to the output file
        fputc(c, fp2);
    }

    // Close both the files
    fclose(fp);
    fclose(fp2);
}

// Main function
int main() {
    // Get the filename and key from the user
    char filename[256];
    int key;
    printf("Enter the filename: ");
    scanf("%s", filename);
    printf("Enter the key: ");
    scanf("%d", &key);

    // Encrypt the file
    encryptFile(filename, key);

    // Decrypt the file
    decryptFile("encrypted.txt", key);

    return 0;
}