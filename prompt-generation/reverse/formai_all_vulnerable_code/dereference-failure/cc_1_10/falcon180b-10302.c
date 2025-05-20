//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "mysecretkey"

void encrypt_file(FILE *input, FILE *output) {
    char buffer[1024];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            char c = buffer[i];
            if (isalpha(c)) {
                c = (c - 'a' + 13) % 26 + 'a';
            } else if (islower(c)) {
                c = toupper(c);
            }
            fwrite(&c, 1, 1, output);
        }
    }
}

void decrypt_file(FILE *input, FILE *output) {
    char buffer[1024];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            char c = buffer[i];
            if (isalpha(c)) {
                c = (c - 'A' + 13) % 26 + 'a';
            } else if (isupper(c)) {
                c = tolower(c);
            }
            fwrite(&c, 1, 1, output);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s [encrypt|decrypt] [input_file] [output_file]\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[2], "rb");
    if (input == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *output = fopen(argv[3], "wb");
    if (output == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt_file(input, output);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt_file(input, output);
    } else {
        printf("Error: Invalid operation.\n");
        return 1;
    }

    fclose(input);
    fclose(output);
    return 0;
}