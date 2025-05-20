//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_NAME_LENGTH 100
#define MAX_ENCRYPTED_FILE_NAME_LENGTH MAX_FILE_NAME_LENGTH + 5

typedef struct {
    char key[MAX_KEY_LENGTH];
    char encrypted_file_name[MAX_ENCRYPTED_FILE_NAME_LENGTH];
} EncryptionContext;

void generate_random_key(char *key, int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_length] = '\0';
}

int encrypt_file(EncryptionContext *context, FILE *input_file, FILE *output_file) {
    char input_buffer[1024];
    char output_buffer[1024];

    while (fgets(input_buffer, sizeof(input_buffer), input_file)!= NULL) {
        int input_buffer_length = strlen(input_buffer);
        int output_buffer_length = 0;

        for (int i = 0; i < input_buffer_length; i++) {
            char c = tolower(input_buffer[i]);

            if (isalpha(c)) {
                c = (c - 'a' + context->key[i % strlen(context->key)]) % 26 + 'a';
            }

            output_buffer[output_buffer_length++] = c;
        }

        output_buffer[output_buffer_length] = '\0';
        fputs(output_buffer, output_file);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    FILE *output_file = fopen(argv[2], "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    EncryptionContext context;

    strncpy(context.key, argv[3], MAX_KEY_LENGTH);

    encrypt_file(&context, input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");

    return 0;
}