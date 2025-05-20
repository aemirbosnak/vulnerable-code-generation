//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_FILE_LEN 1000

typedef struct {
    char key[MAX_KEY_LEN];
    char filename[MAX_FILE_LEN];
} Encryptor;

void generate_key(char* key, int key_len) {
    for (int i = 0; i < key_len; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_len - 1] = '\0';
}

void encrypt_file(Encryptor* encryptor) {
    FILE* input_file = fopen(encryptor->filename, "r");
    if (input_file == NULL) {
        printf("Error: Input file not found.\n");
        exit(1);
    }

    FILE* output_file = fopen("encrypted.txt", "w");
    if (output_file == NULL) {
        printf("Error: Output file could not be created.\n");
        exit(1);
    }

    char input_buffer[MAX_FILE_LEN];
    char output_buffer[MAX_FILE_LEN];
    int input_pos = 0;
    int output_pos = 0;

    while (fgets(input_buffer, MAX_FILE_LEN, input_file)!= NULL) {
        int input_len = strlen(input_buffer);
        for (int i = 0; i < input_len; i++) {
            char c = tolower(input_buffer[i]);
            if (isalpha(c)) {
                char key_index = (int)c - 97;
                c = (char)(((int)c - 97 + (int)encryptor->key[key_index % strlen(encryptor->key)]) % 26) + 'a';
            }
            output_buffer[output_pos++] = c;
        }
        output_buffer[output_pos] = '\0';
        fputs(output_buffer, output_file);
        output_pos = 0;
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    Encryptor encryptor;
    printf("Enter filename to encrypt: ");
    scanf("%s", encryptor.filename);

    printf("Enter encryption key: ");
    scanf("%s", encryptor.key);

    encrypt_file(&encryptor);

    printf("File encrypted successfully!\n");

    return 0;
}