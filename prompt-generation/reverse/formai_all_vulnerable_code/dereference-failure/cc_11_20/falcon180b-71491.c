//Falcon-180B DATASET v1.0 Category: Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 1024
#define MAX_PLAIN_TEXT_LENGTH 1024
#define MAX_CIPHER_TEXT_LENGTH (MAX_PLAIN_TEXT_LENGTH + 1)

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Usage: %s <key> <mode> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *key = argv[1];
    char *mode = argv[2];
    FILE *input_file = fopen(argv[3], "rb");
    if(input_file == NULL) {
        printf("Error: Failed to open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[4], "wb");
    if(output_file == NULL) {
        printf("Error: Failed to open output file.\n");
        fclose(input_file);
        return 1;
    }

    int key_length = strlen(key);
    if(key_length == 0) {
        printf("Error: Key cannot be empty.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    char *buffer = malloc(MAX_PLAIN_TEXT_LENGTH);
    if(buffer == NULL) {
        printf("Error: Failed to allocate memory.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    int plain_text_length = 0;

    char *encrypted_buffer = malloc(MAX_CIPHER_TEXT_LENGTH);
    if(encrypted_buffer == NULL) {
        printf("Error: Failed to allocate memory.\n");
        fclose(input_file);
        fclose(output_file);
        free(buffer);
        return 1;
    }

    int encrypted_text_length = 0;

    if(strcmp(mode, "encrypt") == 0) {
        while((plain_text_length = fread(buffer, 1, MAX_PLAIN_TEXT_LENGTH, input_file)) > 0) {
            for(int i = 0; i < plain_text_length; i++) {
                char c = tolower(buffer[i]);
                if(isalpha(c)) {
                    c = (c - 'a' + key_length) % 26 + 'a';
                } else {
                    c = c;
                }
                encrypted_buffer[encrypted_text_length++] = c;
            }
        }
    } else if(strcmp(mode, "decrypt") == 0) {
        while((plain_text_length = fread(buffer, 1, MAX_PLAIN_TEXT_LENGTH, input_file)) > 0) {
            for(int i = 0; i < plain_text_length; i++) {
                char c = tolower(buffer[i]);
                if(isalpha(c)) {
                    c = (c - 'a' + 26 - key_length) % 26 + 'a';
                } else {
                    c = c;
                }
                encrypted_buffer[encrypted_text_length++] = c;
            }
        }
    } else {
        printf("Error: Invalid mode.\n");
        fclose(input_file);
        fclose(output_file);
        free(buffer);
        free(encrypted_buffer);
        return 1;
    }

    fwrite(encrypted_buffer, 1, encrypted_text_length, output_file);

    fclose(input_file);
    fclose(output_file);

    free(buffer);
    free(encrypted_buffer);

    return 0;
}