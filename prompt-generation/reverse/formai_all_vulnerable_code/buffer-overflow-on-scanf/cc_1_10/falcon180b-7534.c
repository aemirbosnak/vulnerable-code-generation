//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_FILE_SIZE 100000

typedef struct {
    char key[MAX_KEY_SIZE];
    char file_path[MAX_FILE_SIZE];
} file_encryptor_t;

void encrypt_file(file_encryptor_t *encryptor) {
    FILE *input_file = fopen(encryptor->file_path, "rb");
    FILE *output_file = fopen("encrypted_file.txt", "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char ch;
    while ((ch = fgetc(input_file))!= EOF) {
        ch = tolower(ch);
        int key_index = 0;
        while (encryptor->key[key_index]!= '\0') {
            if (encryptor->key[key_index] == ch) {
                ch = 'a';
                break;
            }
            key_index++;
        }
        fputc(ch, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    file_encryptor_t encryptor;
    printf("Enter file path: ");
    scanf("%s", encryptor.file_path);
    printf("Enter encryption key: ");
    scanf("%s", encryptor.key);

    encrypt_file(&encryptor);

    printf("File encrypted successfully!\n");
    return 0;
}