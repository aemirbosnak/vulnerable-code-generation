//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 100000 // Maximum file size in bytes

// Function to encrypt the file
void encrypt_file(FILE *file, char *key) {
    int ch, i;
    char buffer[MAX_FILE_SIZE];

    while ((ch = getc(file))!= EOF) {
        if (isalpha(ch)) {
            ch = ch + ((int)key[i] % 26);
            if (isupper(ch)) {
                ch = ch - 65;
            } else {
                ch = ch + 97;
            }
        }
        else {
            ch = ch;
        }
        putc(ch, stdout);
        i = (i + 1) % strlen(key);
    }
}

// Function to decrypt the file
void decrypt_file(FILE *file, char *key) {
    int ch, i;
    char buffer[MAX_FILE_SIZE];

    while ((ch = getc(file))!= EOF) {
        if (isalpha(ch)) {
            ch = ch - ((int)key[i] % 26);
            if (isupper(ch)) {
                ch = ch + 65;
            } else {
                ch = ch - 97;
            }
        }
        else {
            ch = ch;
        }
        putc(ch, stdout);
        i = (i + 1) % strlen(key);
    }
}

// Function to read the key from the user
void read_key(char *key) {
    printf("Enter the encryption/decryption key: ");
    scanf("%s", key);
}

int main() {
    char key[50], file_name[50], mode[10];
    FILE *file;

    printf("Enter the mode (encrypt/decrypt): ");
    scanf("%s", mode);

    printf("Enter the file name: ");
    scanf("%s", file_name);

    file = fopen(file_name, "rb+");

    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    if (strcmp(mode, "encrypt") == 0) {
        read_key(key);
        encrypt_file(file, key);
    } else if (strcmp(mode, "decrypt") == 0) {
        read_key(key);
        decrypt_file(file, key);
    } else {
        printf("Invalid mode\n");
        exit(1);
    }

    fclose(file);

    return 0;
}