//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "mysecretkey"
#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10MB

void encrypt(char *input_file, char *output_file) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        printf("Error opening input or output file.\n");
        exit(1);
    }

    int c;
    while ((c = fgetc(input))!= EOF) {
        c ^= KEY[0];
        for (int i = 0; i < strlen(KEY) - 1; i++) {
            c = (c * 31 + KEY[i]) % 256;
        }
        fputc(c, output);
    }

    fclose(input);
    fclose(output);
}

void decrypt(char *input_file, char *output_file) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        printf("Error opening input or output file.\n");
        exit(1);
    }

    int c;
    while ((c = fgetc(input))!= EOF) {
        c ^= KEY[0];
        for (int i = 0; i < strlen(KEY) - 1; i++) {
            c = (c - KEY[i] + 256) % 256;
        }
        fputc(c, output);
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <input_file> <output_file> <encrypt/decrypt>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *mode = argv[3];

    if (strcmp(mode, "encrypt") == 0) {
        encrypt(input_file, output_file);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt(input_file, output_file);
    } else {
        printf("Invalid mode. Use 'encrypt' or 'decrypt'.\n");
        return 1;
    }

    return 0;
}