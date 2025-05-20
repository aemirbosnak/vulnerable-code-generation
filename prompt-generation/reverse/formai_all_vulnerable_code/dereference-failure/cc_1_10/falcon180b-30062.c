//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "secret_key"
#define BLOCK_SIZE 64

void encrypt(char *input_file, char *output_file) {
    FILE *input_fp, *output_fp;
    char input_buffer[BLOCK_SIZE], output_buffer[BLOCK_SIZE + 1];
    int i, j;

    input_fp = fopen(input_file, "rb");
    if (input_fp == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_fp);
        exit(1);
    }

    while (fread(input_buffer, 1, BLOCK_SIZE, input_fp)!= 0) {
        for (i = 0, j = 0; i < BLOCK_SIZE; i++) {
            char ch = tolower(input_buffer[i]);
            if (isalpha(ch)) {
                output_buffer[j++] = ch ^ KEY[i % strlen(KEY)];
            } else {
                output_buffer[j++] = ch;
            }
        }
        output_buffer[j] = '\0';
        fwrite(output_buffer, 1, j, output_fp);
    }

    fclose(input_fp);
    fclose(output_fp);
}

void decrypt(char *input_file, char *output_file) {
    FILE *input_fp, *output_fp;
    char input_buffer[BLOCK_SIZE], output_buffer[BLOCK_SIZE + 1];
    int i, j;

    input_fp = fopen(input_file, "rb");
    if (input_fp == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_fp);
        exit(1);
    }

    while (fread(input_buffer, 1, BLOCK_SIZE, input_fp)!= 0) {
        for (i = 0, j = 0; i < BLOCK_SIZE; i++) {
            char ch = tolower(input_buffer[i]);
            if (isalpha(ch)) {
                output_buffer[j++] = ch ^ KEY[i % strlen(KEY)];
            } else {
                output_buffer[j++] = ch;
            }
        }
        output_buffer[j] = '\0';
        fwrite(output_buffer, 1, j, output_fp);
    }

    fclose(input_fp);
    fclose(output_fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s [encrypt|decrypt] input_file output_file\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt(argv[2], argv[3]);
    } else {
        printf("Invalid operation.\n");
        return 1;
    }

    return 0;
}