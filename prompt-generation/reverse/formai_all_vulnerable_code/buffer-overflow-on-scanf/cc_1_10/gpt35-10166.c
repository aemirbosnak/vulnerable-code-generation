//FormAI DATASET v1.0 Category: File Encyptor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

void encrypt(char *input_file, char *output_file, int key);
void decrypt(char *input_file, char *output_file, int key);

int main(int argc, char *argv[]) {

    int key;
    char input_file[MAX_LEN], output_file[MAX_LEN], action[MAX_LEN];

    printf("Enter the key: ");
    scanf("%d", &key);

    printf("Enter the input file: ");
    scanf("%s", input_file);

    printf("Enter the output file: ");
    scanf("%s", output_file);

    printf("Enter 'e' to encrypt or 'd' to decrypt: ");
    scanf("%s", action);

    if(strcmp(action, "e") == 0) {
        encrypt(input_file, output_file, key);
    } else if(strcmp(action, "d") == 0) {
        decrypt(input_file, output_file, key);
    } else {
        fprintf(stderr, "Invalid action specified.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

void encrypt(char *input_file, char *output_file, int key) {
    FILE *in, *out;
    int ch;

    in = fopen(input_file, "rb");
    if(in == NULL) {
        fprintf(stderr, "Failed to open input file.\n");
        exit(EXIT_FAILURE);
    }

    out = fopen(output_file, "wb");
    if(out == NULL) {
        fclose(in);
        fprintf(stderr, "Failed to open output file.\n");
        exit(EXIT_FAILURE);
    }

    while((ch = fgetc(in)) != EOF) {
        fputc(ch + key, out);
    }

    fclose(in);
    fclose(out);

    printf("Encryption successful!\n");
}

void decrypt(char *input_file, char *output_file, int key) {
    FILE *in, *out;
    int ch;

    in = fopen(input_file, "rb");
    if(in == NULL) {
        fprintf(stderr, "Failed to open input file.\n");
        exit(EXIT_FAILURE);
    }

    out = fopen(output_file, "wb");
    if(out == NULL) {
        fclose(in);
        fprintf(stderr, "Failed to open output file.\n");
        exit(EXIT_FAILURE);
    }

    while((ch = fgetc(in)) != EOF) {
        fputc(ch - key, out);
    }

    fclose(in);
    fclose(out);

    printf("Decryption successful!\n");
}