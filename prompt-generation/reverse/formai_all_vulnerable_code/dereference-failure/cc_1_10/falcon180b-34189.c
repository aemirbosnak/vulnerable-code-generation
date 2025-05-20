//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"

// Function to encrypt the file
void encrypt(FILE* input, FILE* output) {
    char ch;
    int i = 0;
    while ((ch = fgetc(input))!= EOF) {
        ch ^= KEY[i];
        fputc(ch, output);
        i = (i + 1) % strlen(KEY);
    }
}

// Function to decrypt the file
void decrypt(FILE* input, FILE* output) {
    char ch;
    int i = 0;
    while ((ch = fgetc(input))!= EOF) {
        ch ^= KEY[i];
        fputc(ch, output);
        i = (i + 1) % strlen(KEY);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 5) {
        printf("Usage: %s <input_file> <output_file> <encrypt/decrypt> <mode>\n", argv[0]);
        return 1;
    }

    char* input_file = argv[1];
    char* output_file = argv[2];
    char* operation = argv[3];
    char* mode = argv[4];

    FILE* in = fopen(input_file, "rb");
    if (in == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE* out = fopen(output_file, mode);
    if (out == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(in);
        return 1;
    }

    if (strcmp(operation, "encrypt") == 0) {
        encrypt(in, out);
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt(in, out);
    } else {
        printf("Error: Invalid operation.\n");
        fclose(in);
        fclose(out);
        remove(output_file);
        return 1;
    }

    fclose(in);
    fclose(out);

    printf("File %s successfully %s.\n", input_file, operation);

    return 0;
}