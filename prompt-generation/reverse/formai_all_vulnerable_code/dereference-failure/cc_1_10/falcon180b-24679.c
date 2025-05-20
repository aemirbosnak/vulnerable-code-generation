//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 10

void encrypt_file(FILE *input_file, FILE *output_file, char *key) {
    char buffer[1024];
    char encrypted_buffer[1024];
    int buffer_length;
    int i;

    while ((buffer_length = fread(buffer, 1, 1024, input_file)) > 0) {
        for (i = 0; i < buffer_length; i++) {
            int key_index = (i % MAX_KEY_LENGTH);
            int buffer_index = (i % 26) + 'a';

            encrypted_buffer[i] = buffer[i] ^ key[key_index];
        }

        fwrite(encrypted_buffer, 1, buffer_length, output_file);
    }
}

void decrypt_file(FILE *input_file, FILE *output_file, char *key) {
    char buffer[1024];
    char decrypted_buffer[1024];
    int buffer_length;
    int i;

    while ((buffer_length = fread(buffer, 1, 1024, input_file)) > 0) {
        for (i = 0; i < buffer_length; i++) {
            int key_index = (i % MAX_KEY_LENGTH);
            int buffer_index = (i % 26) + 'a';

            decrypted_buffer[i] = buffer[i] ^ key[key_index];
        }

        fwrite(decrypted_buffer, 1, buffer_length, output_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage: %s [encrypt/decrypt] [input_file] [output_file] [key]\n", argv[0]);
        return 1;
    }

    char *mode = argv[1];
    char *input_filename = argv[2];
    char *output_filename = argv[3];
    char *key = argv[4];

    FILE *input_file = fopen(input_filename, "rb");
    FILE *output_file = fopen(output_filename, "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    if (strcmp(mode, "encrypt") == 0) {
        encrypt_file(input_file, output_file, key);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt_file(input_file, output_file, key);
    } else {
        printf("Invalid mode.\n");
        return 1;
    }

    fclose(input_file);
    fclose(output_file);

    printf("Done.\n");
    return 0;
}