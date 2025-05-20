//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_KEY_LEN 32

// Function to encrypt a file using a key
void encrypt_file(FILE *input_file, FILE *output_file, char *key) {
    int ch;
    int key_index = 0;
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            ch = ch + ((key[key_index] - 'A') % 26);
            if (ch > 'Z') {
                ch = ch - 26;
            }
            fputc(ch, output_file);
        } else {
            fputc(ch, output_file);
        }
        key_index++;
        if (key_index >= strlen(key)) {
            key_index = 0;
        }
    }
}

// Function to decrypt a file using a key
void decrypt_file(FILE *input_file, FILE *output_file, char *key) {
    int ch;
    int key_index = 0;
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            ch = ch - ((key[key_index] - 'A') % 26);
            if (ch < 'A') {
                ch = ch + 26;
            }
            fputc(ch, output_file);
        } else {
            fputc(ch, output_file);
        }
        key_index++;
        if (key_index >= strlen(key)) {
            key_index = 0;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <encrypt/decrypt> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *mode = argv[1];
    char input_file_name[MAX_FILE_NAME_LEN];
    char output_file_name[MAX_FILE_NAME_LEN];
    strcpy(input_file_name, argv[2]);
    strcpy(output_file_name, argv[3]);

    FILE *input_file;
    FILE *output_file;

    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    char key[MAX_KEY_LEN];
    printf("Enter encryption/decryption key (up to %d characters):\n", MAX_KEY_LEN - 1);
    scanf("%s", key);

    if (strcmp(mode, "encrypt") == 0) {
        encrypt_file(input_file, output_file, key);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt_file(input_file, output_file, key);
    } else {
        printf("Error: Invalid mode.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    fclose(input_file);
    fclose(output_file);
    printf("Done.\n");

    return 0;
}