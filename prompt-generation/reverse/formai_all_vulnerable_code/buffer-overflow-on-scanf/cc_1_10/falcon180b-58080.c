//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_FILE_NAME 100 // maximum length of file name
#define MAX_KEY_LENGTH 100 // maximum length of encryption key

// function to encrypt the file
void encrypt_file(FILE *fp_in, FILE *fp_out, char *key) {
    char ch;
    int key_index = 0;
    while ((ch = fgetc(fp_in))!= EOF) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            ch = ch + key_index % 26;
            if (ch > 'z') {
                ch = 'a' + (ch - 'z') % 26;
            }
            key_index++;
        } else {
            ch = ch;
        }
        fputc(ch, fp_out);
    }
}

// function to decrypt the file
void decrypt_file(FILE *fp_in, FILE *fp_out, char *key) {
    char ch;
    int key_index = 0;
    while ((ch = fgetc(fp_in))!= EOF) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            ch = ch - key_index % 26;
            if (ch < 'a') {
                ch = 'z' + (ch - 'a') % 26;
            }
            key_index++;
        } else {
            ch = ch;
        }
        fputc(ch, fp_out);
    }
}

// function to generate the encryption key
char *generate_key(int key_length) {
    char *key = malloc(key_length + 1);
    for (int i = 0; i < key_length; i++) {
        key[i] = 'a' + rand() % 26;
    }
    key[key_length] = '\0';
    return key;
}

int main() {
    char input_file[MAX_FILE_NAME], output_file[MAX_FILE_NAME], key[MAX_KEY_LENGTH];
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    // generate the encryption key
    char *encryption_key = generate_key(strlen(input_file));

    // encrypt the file
    FILE *fp_in = fopen(input_file, "rb");
    FILE *fp_out = fopen(output_file, "wb");
    encrypt_file(fp_in, fp_out, encryption_key);
    fclose(fp_in);
    fclose(fp_out);

    // print the encryption key
    printf("The encryption key is: %s\n", encryption_key);

    return 0;
}