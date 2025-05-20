//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 20
#define MAX_BUFFER_SIZE 1024

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    int num_rounds;
} encryption_parameters;

void generate_key(char* key) {
    int i = 0;
    while (i < MAX_KEY_LENGTH) {
        key[i] = rand() % 26 + 'a';
        i++;
    }
    key[i] = '\0';
}

void encrypt_file(FILE* input_file, FILE* output_file, encryption_parameters* params) {
    char buffer[MAX_BUFFER_SIZE];
    char key[MAX_KEY_LENGTH];
    char encrypted_buffer[MAX_BUFFER_SIZE];
    int buffer_length = 0;
    int encrypted_buffer_length = 0;
    int i = 0;
    int j = 0;
    int num_rounds = params->num_rounds;
    int key_length = params->key_length;
    strcpy(key, params->key);
    while (fgets(buffer, MAX_BUFFER_SIZE, input_file)!= NULL) {
        buffer_length = strlen(buffer);
        encrypted_buffer_length = 0;
        for (i = 0; i < buffer_length; i++) {
            buffer[i] = toupper(buffer[i]);
            if (isalpha(buffer[i])) {
                encrypted_buffer[encrypted_buffer_length] = key[(int)buffer[i] % key_length];
                encrypted_buffer_length++;
            } else {
                encrypted_buffer[encrypted_buffer_length] = buffer[i];
                encrypted_buffer_length++;
            }
        }
        for (i = 0; i < num_rounds; i++) {
            for (j = 0; j < encrypted_buffer_length; j++) {
                encrypted_buffer[j] = encrypted_buffer[j] ^ key[(int)encrypted_buffer[j] % key_length];
            }
        }
        fputs(encrypted_buffer, output_file);
    }
}

int main(int argc, char* argv[]) {
    FILE* input_file;
    FILE* output_file;
    encryption_parameters params;
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }
    params.key_length = strlen(argv[3]);
    strcpy(params.key, argv[3]);
    params.num_rounds = atoi(argv[2]);
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open input file\n");
        return 1;
    }
    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: could not open output file\n");
        fclose(input_file);
        return 1;
    }
    encrypt_file(input_file, output_file, &params);
    fclose(input_file);
    fclose(output_file);
    return 0;
}