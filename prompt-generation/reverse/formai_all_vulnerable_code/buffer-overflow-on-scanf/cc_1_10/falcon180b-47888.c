//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 256
#define MAX_FILE_NAME_LENGTH 256

struct Key {
    char key[MAX_KEY_LENGTH];
    int key_length;
};

struct Key generate_key() {
    struct Key key;
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    int charset_length = strlen(charset);
    int i;

    for (i = 0; i < MAX_KEY_LENGTH - 1; i++) {
        key.key[i] = charset[rand() % charset_length];
    }
    key.key[MAX_KEY_LENGTH - 1] = '\0';
    key.key_length = MAX_KEY_LENGTH;

    return key;
}

void encrypt_file(char* input_file_name, char* output_file_name, struct Key key) {
    FILE* input_file;
    FILE* output_file;
    char input_buffer[MAX_FILE_NAME_LENGTH];
    char output_buffer[MAX_FILE_NAME_LENGTH];
    int input_buffer_length;
    int output_buffer_length;
    int i;

    input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        printf("Error: cannot open input file %s\n", input_file_name);
        exit(1);
    }

    output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Error: cannot open output file %s\n", output_file_name);
        exit(1);
    }

    while ((input_buffer_length = fread(input_buffer, 1, MAX_FILE_NAME_LENGTH, input_file)) > 0) {
        for (i = 0; i < input_buffer_length; i++) {
            output_buffer[i] = input_buffer[i] ^ key.key[i % key.key_length];
        }
        output_buffer_length = input_buffer_length;
        fwrite(output_buffer, 1, output_buffer_length, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    struct Key key;
    char input_file_name[MAX_FILE_NAME_LENGTH];
    char output_file_name[MAX_FILE_NAME_LENGTH];

    printf("Enter the name of the input file: ");
    scanf("%s", input_file_name);

    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);

    key = generate_key();

    encrypt_file(input_file_name, output_file_name, key);

    printf("File encryption completed!\n");

    return 0;
}