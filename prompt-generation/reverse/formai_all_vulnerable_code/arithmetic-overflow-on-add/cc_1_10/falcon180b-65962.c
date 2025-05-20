//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_KEY_LENGTH 100

void generate_key(char* key);

int main(int argc, char** argv) {
    if (argc!= 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    char input_file[MAX_FILE_NAME_LENGTH];
    char output_file[MAX_FILE_NAME_LENGTH];
    char key[MAX_KEY_LENGTH];

    strcpy(input_file, argv[1]);
    strcpy(output_file, argv[2]);
    strcpy(key, argv[3]);

    FILE* input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE* output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_fp);
        return 1;
    }

    generate_key(key);

    int c;
    while ((c = fgetc(input_fp))!= EOF) {
        if (isalpha(c)) {
            c = c + 3;
        } else if (isdigit(c)) {
            c = c + 7;
        } else {
            c = c + 1;
        }
        fputc(c, output_fp);
    }

    fclose(input_fp);
    fclose(output_fp);

    printf("File encryption complete.\n");

    return 0;
}

void generate_key(char* key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = toupper(key[i]);
    }
}