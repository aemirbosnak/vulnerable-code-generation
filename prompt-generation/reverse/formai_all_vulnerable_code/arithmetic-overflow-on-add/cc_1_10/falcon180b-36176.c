//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the file
void encrypt(FILE *file, int key) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            ch = (ch + key - 97) % 26 + 97;
            printf("%c", ch);
        } else {
            printf("%c", ch);
        }
        i++;
        if (i == 80) {
            printf("\n");
            i = 0;
        }
    }
}

// Function to decrypt the file
void decrypt(FILE *file, int key) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            ch = (ch - key - 97) % 26 + 97;
            printf("%c", ch);
        } else {
            printf("%c", ch);
        }
        i++;
        if (i == 80) {
            printf("\n");
            i = 0;
        }
    }
}

// Function to read the file
void read_file(FILE *file) {
    char ch;
    int i = 0;

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            printf("%c", ch);
        } else {
            printf("%c", ch);
        }
        i++;
        if (i == 80) {
            printf("\n");
            i = 0;
        }
    }
}

int main() {
    FILE *file;
    char filename[100];
    int choice, key;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File not found\n");
        exit(0);
    }

    // Get encryption/decryption choice from user
    printf("Enter 1 to encrypt and 2 to decrypt: ");
    scanf("%d", &choice);

    // Get encryption/decryption key from user
    printf("Enter key: ");
    scanf("%d", &key);

    // Perform encryption/decryption
    if (choice == 1) {
        encrypt(file, key);
    } else if (choice == 2) {
        decrypt(file, key);
    }

    // Close the file
    fclose(file);

    return 0;
}