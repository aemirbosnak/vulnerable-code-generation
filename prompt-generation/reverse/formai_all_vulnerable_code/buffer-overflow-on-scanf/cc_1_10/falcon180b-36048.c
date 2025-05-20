//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LENGTH 32
#define MAX_FILENAME_LENGTH 256
#define MAX_ENCRYPTED_LENGTH (MAX_FILENAME_LENGTH + 64)

typedef struct {
    char key[MAX_KEY_LENGTH];
    char encrypted_filename[MAX_ENCRYPTED_LENGTH];
} EncryptedFile;

void generate_key(char* key) {
    srand(time(NULL));
    for (int i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_LENGTH - 1] = '\0';
}

void encrypt_file(const char* filename, const char* key, char* encrypted_filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(file, 0L, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    unsigned char buffer[file_size];
    size_t bytes_read = fread(buffer, sizeof(unsigned char), file_size, file);
    if (bytes_read!= file_size) {
        printf("Error: could not read file '%s'\n", filename);
        exit(1);
    }

    fclose(file);

    int key_index = 0;
    for (int i = 0; i < file_size; i++) {
        encrypted_filename[i * 2] = tolower(filename[i]);
        encrypted_filename[i * 2 + 1] = key[key_index++ % MAX_KEY_LENGTH];
    }
    encrypted_filename[file_size * 2] = '\0';
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the filename to encrypt: ");
    scanf("%s", filename);

    char key[MAX_KEY_LENGTH];
    generate_key(key);

    char encrypted_filename[MAX_ENCRYPTED_LENGTH];
    encrypt_file(filename, key, encrypted_filename);

    printf("Encrypted filename: %s\n", encrypted_filename);

    return 0;
}