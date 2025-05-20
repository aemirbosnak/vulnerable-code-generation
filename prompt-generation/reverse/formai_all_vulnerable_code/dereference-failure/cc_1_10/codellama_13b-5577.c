//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: authentic
/*
 * Unique C File Encyptor example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define FILE_NAME_LEN 256
#define KEY_LEN 16

void encrypt_file(char *filename, char *key) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Failed to open file for reading\n");
        return;
    }

    char *encrypted_data = malloc(FILE_NAME_LEN * sizeof(char));
    if (!encrypted_data) {
        printf("Failed to allocate memory for encrypted data\n");
        fclose(fp);
        return;
    }

    char *key_buf = malloc(KEY_LEN * sizeof(char));
    if (!key_buf) {
        printf("Failed to allocate memory for key buffer\n");
        fclose(fp);
        free(encrypted_data);
        return;
    }

    memset(key_buf, 0, KEY_LEN);
    memcpy(key_buf, key, strlen(key));

    size_t data_size = fread(encrypted_data, 1, FILE_NAME_LEN, fp);
    fclose(fp);

    for (size_t i = 0; i < data_size; i++) {
        encrypted_data[i] = (char)(encrypted_data[i] ^ key_buf[i % KEY_LEN]);
    }

    fp = fopen(filename, "wb");
    if (!fp) {
        printf("Failed to open file for writing\n");
        free(encrypted_data);
        free(key_buf);
        return;
    }

    fwrite(encrypted_data, 1, data_size, fp);
    fclose(fp);

    free(encrypted_data);
    free(key_buf);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file> <key>\n", argv[0]);
        return 1;
    }

    encrypt_file(argv[1], argv[2]);

    return 0;
}