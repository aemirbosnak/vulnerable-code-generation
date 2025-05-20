//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_FILE_NAME 256
#define MAX_KEY_SIZE 256

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
} EncryptionKey;

EncryptionKey generate_key() {
    EncryptionKey key;
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    time_t t;
    srand((unsigned int) time(&t));
    for (int i = 0; i < MAX_KEY_SIZE; i++) {
        key.key[i] = charset[rand() % strlen(charset)];
    }
    key.key_size = MAX_KEY_SIZE;
    return key;
}

void encrypt_file(FILE *file, EncryptionKey key) {
    char input_buffer[1024];
    char output_buffer[1024];
    while (fgets(input_buffer, sizeof(input_buffer), file)!= NULL) {
        int input_size = strlen(input_buffer);
        for (int i = 0; i < input_size; i++) {
            char input_char = tolower(input_buffer[i]);
            int key_index = (int) (rand() % key.key_size);
            char key_char = key.key[key_index];
            if (isalpha(input_char)) {
                if (isupper(input_char)) {
                    output_buffer[i] = (char) ((int) input_char + (int) key_char - 65);
                } else {
                    output_buffer[i] = (char) ((int) input_char + (int) key_char - 97);
                }
            } else {
                output_buffer[i] = input_char;
            }
        }
        output_buffer[input_size] = '\0';
        fputs(output_buffer, stdout);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }
    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");
    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    EncryptionKey key = generate_key();
    encrypt_file(input_file, key);
    fclose(input_file);
    fclose(output_file);
    return 0;
}