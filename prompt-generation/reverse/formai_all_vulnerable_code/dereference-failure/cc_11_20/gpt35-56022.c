//FormAI DATASET v1.0 Category: File Encyptor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 50
#define MAX_KEY_LEN 50

int main() {
    char filename[MAX_FILENAME_LEN];
    char key[MAX_KEY_LEN];
    size_t len;
    FILE *fp, *fp_out;

    printf("Enter the filename: ");
    fgets(filename, MAX_FILENAME_LEN, stdin);
    len = strlen(filename);
    if (len > 0 && filename[len - 1] == '\n') {
        filename[len - 1] = '\0';
    }

    printf("Enter the encryption key: ");
    fgets(key, MAX_KEY_LEN, stdin);
    len = strlen(key);
    if (len > 0 && key[len - 1] == '\n') {
        key[len - 1] = '\0';
    }

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Could not open %s\n", filename);
        return 1;
    }

    char encrypted_filename[MAX_FILENAME_LEN + 4];
    sprintf(encrypted_filename, "%s.enc", filename);

    fp_out = fopen(encrypted_filename, "wb");
    if (fp_out == NULL) {
        printf("Could not create encrypted file %s\n", encrypted_filename);
        return 1;
    }

    char buffer[MAX_KEY_LEN];
    size_t key_len = strlen(key);
    size_t i = 0;
    char c;
    while (fread(&c, 1, 1, fp) == 1) {
        buffer[i] = c;
        i++;
        if (i == key_len) {
            for (size_t j = 0; j < i; j++) {
                buffer[j] = buffer[j] ^ key[j];
            }
            fwrite(buffer, i, 1, fp_out);
            i = 0;
        }
    }
    if (i > 0) {
        for (size_t j = 0; j < i; j++) {
            buffer[j] = buffer[j] ^ key[j];
        }
        fwrite(buffer, i, 1, fp_out);
    }

    fclose(fp);
    fclose(fp_out);

    printf("Successfully encrypted file %s\n", filename);

    return 0;
}