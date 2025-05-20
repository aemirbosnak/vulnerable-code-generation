//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_SIZE 32
#define MAX_FILE_SIZE 1000000

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <key> <encrypt/decrypt> <file>\n", argv[0]);
        return 1;
    }

    char *key = argv[1];
    int mode = strcmp(argv[2], "encrypt") == 0? 1 : 0;
    FILE *file = fopen(argv[3], "rb+");

    if (!file) {
        printf("Error: could not open file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);

    if (file_size <= 0 || file_size > MAX_FILE_SIZE) {
        printf("Error: file size is invalid.\n");
        fclose(file);
        return 1;
    }

    rewind(file);

    char *buffer = malloc(file_size + 1);
    if (!buffer) {
        printf("Error: could not allocate memory.\n");
        fclose(file);
        return 1;
    }

    fread(buffer, file_size, 1, file);
    fclose(file);

    int key_size = strlen(key);
    if (key_size <= 0 || key_size > MAX_KEY_SIZE) {
        printf("Error: key size is invalid.\n");
        free(buffer);
        return 1;
    }

    int i, j;
    for (i = 0; i < file_size; i++) {
        char c = tolower(buffer[i]);
        if (isalpha(c)) {
            j = c - 'a';
            j = (j + key_size) % 26;
            c = (mode == 1)? (char) (j + 'a') : (char) (j + 'A');
        }
        buffer[i] = c;
    }

    file = fopen(argv[3], "wb");
    if (!file) {
        printf("Error: could not open file.\n");
        free(buffer);
        return 1;
    }

    fwrite(buffer, file_size, 1, file);
    fclose(file);

    free(buffer);

    printf("File \"%s\" has been %s.\n", argv[3], mode == 1? "encrypted" : "decrypted");

    return 0;
}