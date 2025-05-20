//FormAI DATASET v1.0 Category: File Encyptor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* file_name, char* key) {
    FILE *in_file, *out_file;
    char ch;
    int key_index = 0;
    in_file = fopen(file_name, "r");
    out_file = fopen("encrypted.txt", "w");
    while ((ch = fgetc(in_file)) != EOF) {
        ch = ch ^ key[key_index];
        fputc(ch, out_file);
        key_index++;
        if (key_index == strlen(key)) {
            key_index = 0;
        }
    }
    fclose(in_file);
    fclose(out_file);
}

void decrypt(char* file_name, char* key) {
    FILE *in_file, *out_file;
    char ch;
    int key_index = 0;
    in_file = fopen(file_name, "r");
    out_file = fopen("decrypted.txt", "w");
    while ((ch = fgetc(in_file)) != EOF) {
        ch = ch ^ key[key_index];
        fputc(ch, out_file);
        key_index++;
        if (key_index == strlen(key)) {
            key_index = 0;
        }
    }
    fclose(in_file);
    fclose(out_file);
}

int main() {
    char file_name[50], key[50], choice[10];
    printf("Welcome to surprise C File Encryptor!\n");
    printf("Please enter the file name to be encrypted: ");
    scanf("%s", file_name);
    printf("Please enter the key for encryption: ");
    scanf("%s", key);
    printf("Are you sure to encrypt file %s with key %s? (y/n): ", file_name, key);
    scanf("%s", choice);
    if (strcmp(choice, "y") == 0) {
        encrypt(file_name, key);
        printf("File encrypted successfully!\n");
    } else {
        printf("Encryption cancelled by user.\n");
        return 0;
    }
    printf("Do you want to decrypt the encrypted file? (y/n): ");
    scanf("%s", choice);
    if (strcmp(choice, "y") == 0) {
        decrypt("encrypted.txt", key);
        printf("File decrypted successfully!\n");
    } else {
        printf("Decryption cancelled by user.\n");
    }
    return 0;
}