//FormAI DATASET v1.0 Category: File Encyptor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char key[10] = "surrealism";
    int key_len = strlen(key);
    char filename[50];

    printf("Enter the filename to encrypt: ");
    scanf("%s", filename);

    FILE *file_in = fopen(filename, "rb");
    if(file_in == NULL) {
        printf("File not found!\n");
        exit(1);
    }

    int file_size;
    fseek(file_in, 0, SEEK_END);
    file_size = ftell(file_in);
    fseek(file_in, 0, SEEK_SET);

    char *plaintext = malloc(file_size);
    int bytes_read = fread(plaintext, sizeof(char), file_size, file_in);
    fclose(file_in);

    char *xor_key = malloc(file_size + 1);
    for(int i = 0; i < file_size; i++) {
        xor_key[i] = key[i % key_len];
    }
    xor_key[file_size] = '\0';

    char *ciphertext = malloc(file_size + 1);
    for(int i = 0; i < file_size; i++) {
        ciphertext[i] = plaintext[i] ^ xor_key[i];
    }
    ciphertext[file_size] = '\0';

    char new_filename[50];
    sprintf(new_filename, "surreal_%s", filename);
    FILE *file_out = fopen(new_filename, "wb");
    if(file_out == NULL) {
        printf("Failed to create encrypted file!\n");
        exit(1);
    }

    fwrite(ciphertext, sizeof(char), file_size, file_out);
    fclose(file_out);

    printf("Encryption complete!\n");
    return 0;
}