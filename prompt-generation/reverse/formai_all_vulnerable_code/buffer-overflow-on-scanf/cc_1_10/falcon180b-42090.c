//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void encrypt(char *filename, char *key) {
    FILE *input_file, *output_file;
    char ch, encrypted_ch;
    int i = 0;
    int key_len = strlen(key);

    input_file = fopen(filename, "rb");
    if (input_file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    output_file = fopen("encrypted_file.txt", "wb");
    if (output_file == NULL) {
        printf("Error creating output file: encrypted_file.txt\n");
        exit(1);
    }

    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            encrypted_ch = (char) ((int) ch + i);
            if (encrypted_ch > 'z') {
                encrypted_ch = encrypted_ch - 26;
            } else if (encrypted_ch < 'a') {
                encrypted_ch = encrypted_ch + 26;
            }
            fputc(encrypted_ch, output_file);
        } else {
            fputc(ch, output_file);
        }
        i = (i + 1) % key_len;
    }

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully!\n");
}

void decrypt(char *filename, char *key) {
    FILE *input_file, *output_file;
    char ch, decrypted_ch;
    int i = 0;
    int key_len = strlen(key);

    input_file = fopen("encrypted_file.txt", "rb");
    if (input_file == NULL) {
        printf("Error opening file: encrypted_file.txt\n");
        exit(1);
    }

    output_file = fopen("decrypted_file.txt", "wb");
    if (output_file == NULL) {
        printf("Error creating output file: decrypted_file.txt\n");
        exit(1);
    }

    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            decrypted_ch = (char) ((int) ch - i);
            if (decrypted_ch < 'a') {
                decrypted_ch = decrypted_ch + 26;
            } else if (decrypted_ch > 'z') {
                decrypted_ch = decrypted_ch - 26;
            }
            fputc(decrypted_ch, output_file);
        } else {
            fputc(ch, output_file);
        }
        i = (i + 1) % key_len;
    }

    fclose(input_file);
    fclose(output_file);

    printf("File decrypted successfully!\n");
}

int main() {
    char filename[100], key[100];
    int choice;

    printf("Enter the name of the file to be encrypted/decrypted: ");
    scanf("%s", filename);

    printf("Enter the key for encryption/decryption: ");
    scanf("%s", key);

    printf("Enter 1 to encrypt the file or 2 to decrypt the file: ");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(filename, key);
    } else if (choice == 2) {
        decrypt(filename, key);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}