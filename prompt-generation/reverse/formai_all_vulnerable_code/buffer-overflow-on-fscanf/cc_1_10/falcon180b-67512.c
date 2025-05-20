//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: random
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt the file
void encrypt(FILE *file) {
    char ch;
    int key = 5; // Key for encryption
    while (fscanf(file, "%c", &ch)!= EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if (ch > 'z') {
                ch = ch - 26;
            }
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if (ch > 'Z') {
                ch = ch - 26;
            }
        }
        fputc(ch, stdout);
    }
}

// Function to decrypt the file
void decrypt(FILE *file) {
    char ch;
    int key = 5; // Key for decryption
    while (fscanf(file, "%c", &ch)!= EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if (ch < 'a') {
                ch = ch + 26;
            }
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if (ch < 'A') {
                ch = ch + 26;
            }
        }
        fputc(ch, stdout);
    }
}

int main() {
    FILE *file;
    char filename[100];
    int choice;

    // Get the filename from user
    printf("Enter the filename: ");
    scanf("%s", filename);

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found!\n");
        exit(0);
    }

    // Get the choice from user
    printf("Enter your choice:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    // Encrypt or decrypt the file based on user's choice
    if (choice == 1) {
        encrypt(file);
    } else if (choice == 2) {
        decrypt(file);
    } else {
        printf("Invalid choice!\n");
        exit(0);
    }

    // Close the file
    fclose(file);

    return 0;
}