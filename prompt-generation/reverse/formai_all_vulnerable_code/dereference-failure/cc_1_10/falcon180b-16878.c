//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 256
#define MAX_FILE_NAME_LENGTH 1024

typedef struct {
    char* key;
    int key_length;
} Encryptor;

Encryptor* create_encryptor(char* key) {
    int key_length = strlen(key);
    Encryptor* encryptor = (Encryptor*) malloc(sizeof(Encryptor));
    encryptor->key = (char*) malloc(key_length + 1);
    strcpy(encryptor->key, key);
    encryptor->key_length = key_length;
    return encryptor;
}

void destroy_encryptor(Encryptor* encryptor) {
    free(encryptor->key);
    free(encryptor);
}

void encrypt_file(Encryptor* encryptor, FILE* input_file, FILE* output_file) {
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), input_file)!= NULL) {
        int buffer_length = strlen(buffer);
        char encrypted_buffer[buffer_length + 1];
        encrypted_buffer[buffer_length] = '\0';
        for (int i = 0; i < buffer_length; i++) {
            char c = tolower(buffer[i]);
            int key_index = c - 'a';
            if (key_index >= 0 && key_index < encryptor->key_length) {
                char key_char = encryptor->key[key_index];
                int new_index = (key_char + 'a' - 'a' + 26) % 26 + 'a';
                encrypted_buffer[i] = new_index;
            } else {
                encrypted_buffer[i] = c;
            }
        }
        fputs(encrypted_buffer, output_file);
    }
}

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: %s <key> <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    char* key = argv[1];
    char* input_file_name = argv[2];
    char* output_file_name = argv[3];
    FILE* input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error opening input file: %s\n", input_file_name);
        return 1;
    }
    FILE* output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error opening output file: %s\n", output_file_name);
        fclose(input_file);
        return 1;
    }
    Encryptor* encryptor = create_encryptor(key);
    encrypt_file(encryptor, input_file, output_file);
    fclose(input_file);
    fclose(output_file);
    destroy_encryptor(encryptor);
    printf("File encrypted successfully.\n");
    return 0;
}