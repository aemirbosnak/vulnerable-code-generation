//FormAI DATASET v1.0 Category: File Encyptor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 'X'

void encrypt_char(char* c) {
    *c ^= KEY;
}

void encrypt_string(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        encrypt_char(&str[i]);
    }
}

void encrypt_file(FILE* input_file, FILE* output_file) {
    char line[256];
    while (fgets(line, sizeof(line), input_file)) {
        encrypt_string(line);
        fputs(line, output_file);
    }
}

int main() {
    char input_file_name[256];
    char output_file_name[256];
    printf("Enter the name of the file to encrypt: ");
    scanf("%s", input_file_name);
    printf("Enter the name of the output file: ");
    scanf("%s", output_file_name);

    FILE* input_file = fopen(input_file_name, "r");
    if (!input_file) {
        printf("Error: could not open input file\n");
        return 1;
    }

    FILE* output_file = fopen(output_file_name, "w");
    if (!output_file) {
        printf("Error: could not open output file\n");
        fclose(input_file);
        return 1;
    }

    encrypt_file(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("Encryption complete\n");

    return 0;
}