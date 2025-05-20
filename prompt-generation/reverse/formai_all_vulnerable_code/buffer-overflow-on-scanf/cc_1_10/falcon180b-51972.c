//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LEN 1024
#define MAX_KEY_LEN 1024

// Function to encrypt the file
void encrypt_file(char *file_name, char *key) {
    FILE *fp;
    char ch;
    char encrypted_ch;
    int i = 0;
    fp = fopen(file_name, "rb+");
    if (fp == NULL) {
        printf("Error: File %s not found.\n", file_name);
        exit(1);
    }
    rewind(fp);
    while ((ch = fgetc(fp))!= EOF) {
        encrypted_ch = ch ^ key[i];
        if (isalpha(ch)) {
            encrypted_ch = toupper(encrypted_ch);
        }
        fseek(fp, -1, SEEK_CUR);
        fputc(encrypted_ch, fp);
        i = (i + 1) % strlen(key);
    }
    fclose(fp);
    printf("File %s encrypted successfully.\n", file_name);
}

// Function to decrypt the file
void decrypt_file(char *file_name, char *key) {
    FILE *fp;
    char ch;
    char decrypted_ch;
    int i = 0;
    fp = fopen(file_name, "rb+");
    if (fp == NULL) {
        printf("Error: File %s not found.\n", file_name);
        exit(1);
    }
    rewind(fp);
    while ((ch = fgetc(fp))!= EOF) {
        decrypted_ch = ch ^ key[i];
        if (isalpha(ch)) {
            decrypted_ch = tolower(decrypted_ch);
        }
        fseek(fp, -1, SEEK_CUR);
        fputc(decrypted_ch, fp);
        i = (i + 1) % strlen(key);
    }
    fclose(fp);
    printf("File %s decrypted successfully.\n", file_name);
}

int main() {
    char file_name[MAX_FILE_NAME_LEN];
    char key[MAX_KEY_LEN];
    printf("Enter the name of the file to encrypt/decrypt: ");
    scanf("%s", file_name);
    printf("Enter the encryption/decryption key: ");
    scanf("%s", key);
    printf("Enter 1 to encrypt the file or 2 to decrypt the file: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        encrypt_file(file_name, key);
    } else if (choice == 2) {
        decrypt_file(file_name, key);
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}