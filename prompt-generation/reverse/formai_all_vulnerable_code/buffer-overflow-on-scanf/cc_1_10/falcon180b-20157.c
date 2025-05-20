//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char key[MAX_KEY_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
} file_encryptor_t;

void generate_key(char *key, int key_length) {
    int i;
    for (i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length - 1] = '\0';
}

void encrypt_file(file_encryptor_t *encryptor) {
    FILE *input_file;
    FILE *output_file;
    char ch;
    int key_length = strlen(encryptor->key);
    int i;

    input_file = fopen(encryptor->file_name, "rb");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    output_file = fopen("encrypted.bin", "wb");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    while ((ch = fgetc(input_file))!= EOF) {
        ch ^= (key_length % 26 + 'a');
        for (i = 0; i < key_length; i++) {
            ch = (ch - encryptor->key[i]) % 26 + 'a';
        }
        fputc(ch, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    file_encryptor_t encryptor;
    int key_length;

    printf("Welcome to the Funny File Encryptor!\n");
    printf("Please enter the file name to encrypt: ");
    scanf("%s", encryptor.file_name);

    printf("Please enter the length of the encryption key (between 1 and %d): ", MAX_KEY_LENGTH);
    scanf("%d", &key_length);

    if (key_length < 1 || key_length > MAX_KEY_LENGTH) {
        printf("Invalid key length\n");
        exit(1);
    }

    generate_key(encryptor.key, key_length);

    printf("Encrypting %s with key %s...\n", encryptor.file_name, encryptor.key);
    encrypt_file(&encryptor);

    printf("Encryption complete!\n");

    return 0;
}