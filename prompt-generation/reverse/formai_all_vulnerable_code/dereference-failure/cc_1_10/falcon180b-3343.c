//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 16
#define MAX_FILE_LEN 1000000

char *encrypt(char *key, char *file) {
    FILE *fptr;
    char *buffer = malloc(MAX_FILE_LEN);
    char *encrypted_buffer = malloc(MAX_FILE_LEN);
    char *encrypted_file = malloc(MAX_FILE_LEN);
    char *encrypted_key = malloc(MAX_KEY_LEN);
    int i, j, k, n;

    // Encrypt key
    for (i = 0; i < strlen(key); i++) {
        if (isalpha(key[i])) {
            encrypted_key[i] = key[i] + 13;
        } else {
            encrypted_key[i] = key[i];
        }
    }

    // Open file for reading
    fptr = fopen(file, "r");
    if (fptr == NULL) {
        printf("File not found.\n");
        exit(1);
    }

    // Read file into buffer
    fread(buffer, 1, MAX_FILE_LEN, fptr);
    n = strlen(buffer);

    // Encrypt buffer
    for (i = 0; i < n; i++) {
        if (isalpha(buffer[i])) {
            encrypted_buffer[i] = buffer[i] + 13;
        } else {
            encrypted_buffer[i] = buffer[i];
        }
    }

    // Create encrypted file name
    strcpy(encrypted_file, file);
    strcat(encrypted_file, ".enc");

    // Write encrypted buffer to file
    fptr = fopen(encrypted_file, "w");
    if (fptr == NULL) {
        printf("Error creating encrypted file.\n");
        exit(1);
    }
    fwrite(encrypted_buffer, 1, n, fptr);
    fclose(fptr);

    free(buffer);
    free(encrypted_buffer);
    free(encrypted_file);
    free(encrypted_key);

    return encrypted_file;
}

int main() {
    char *key = "secret_key";
    char *file = "example.txt";
    char *encrypted_file = encrypt(key, file);
    printf("Encrypted file: %s\n", encrypted_file);

    return 0;
}