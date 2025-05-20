//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_LENGTH 1000000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char filename[MAX_FILE_LENGTH];
} file_encryptor_t;

void generate_key(file_encryptor_t *encryptor) {
    char key[MAX_KEY_LENGTH];
    int i;

    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }

    strcpy(encryptor->key, key);
}

void encrypt_file(file_encryptor_t *encryptor) {
    FILE *file;
    char buffer[MAX_FILE_LENGTH];
    int i, j, key_index;

    file = fopen(encryptor->filename, "r");

    if (file == NULL) {
        printf("Error: File not found\n");
        return;
    }

    key_index = 0;

    while (fgets(buffer, MAX_FILE_LENGTH, file)!= NULL) {
        for (i = 0; i < strlen(buffer); i++) {
            if (isalpha(buffer[i])) {
                buffer[i] = buffer[i] + encryptor->key[key_index];
            } else {
                buffer[i] = buffer[i];
            }

            key_index++;

            if (key_index >= strlen(encryptor->key)) {
                key_index = 0;
            }
        }

        fprintf(stdout, "%s", buffer);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    file_encryptor_t encryptor;

    if (argc!= 3) {
        printf("Usage: %s <filename> <key>\n", argv[0]);
        return 1;
    }

    strcpy(encryptor.filename, argv[1]);
    strcpy(encryptor.key, argv[2]);

    generate_key(&encryptor);
    encrypt_file(&encryptor);

    return 0;
}