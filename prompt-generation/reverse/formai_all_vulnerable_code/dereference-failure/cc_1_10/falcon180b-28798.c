//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey123"

void encrypt(char *file_name, char *output_file_name) {
    FILE *input_file, *output_file;
    char ch;
    int i, j;

    input_file = fopen(file_name, "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    while ((ch = fgetc(input_file))!= EOF) {
        for (i = 0; i < strlen(KEY); i++) {
            j = (int) ch ^ (int) KEY[i];
            fputc(j, output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);
}

void decrypt(char *file_name, char *output_file_name) {
    FILE *input_file, *output_file;
    char ch;
    int i, j;

    input_file = fopen(file_name, "r");
    if (input_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    while ((ch = fgetc(input_file))!= EOF) {
        for (i = 0; i < strlen(KEY); i++) {
            j = (int) ch ^ (int) KEY[i];
            fputc(j, output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./program_name [encrypt/decrypt] [input_file_name] [output_file_name]\n");
        exit(1);
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt(argv[2], argv[3]);
    } else {
        printf("Invalid operation\n");
        exit(1);
    }

    return 0;
}