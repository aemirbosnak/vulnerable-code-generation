//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 16
#define MAX_FILE_LEN 1024

void generate_key(char *key) {
    int i;
    for (i = 0; i < MAX_KEY_LEN; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_LEN] = '\0';
}

void encrypt_file(char *input_file, char *output_file, char *key) {
    FILE *fp_in, *fp_out;
    int c, i;

    fp_in = fopen(input_file, "rb");
    if (fp_in == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    fp_out = fopen(output_file, "wb");
    if (fp_out == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    for (i = 0; i < MAX_KEY_LEN; i++) {
        c = toupper(key[i]);
        if (c < 'A' || c > 'Z') {
            printf("Error: Invalid key.\n");
            exit(1);
        }
    }

    while ((c = fgetc(fp_in))!= EOF) {
        if (isalpha(c)) {
            c = toupper(c);
            c = (c - 'A' + 26 - (key[0] - 'A')) % 26 + 'A';
        }
        fputc(c, fp_out);
    }

    fclose(fp_in);
    fclose(fp_out);
}

int main(int argc, char *argv[]) {
    char input_file[MAX_FILE_LEN], output_file[MAX_FILE_LEN];
    char key[MAX_KEY_LEN];

    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        exit(1);
    }

    strcpy(input_file, argv[1]);
    strcpy(output_file, argv[2]);
    strcpy(key, argv[3]);

    generate_key(key);
    encrypt_file(input_file, output_file, key);

    printf("File encrypted.\n");

    return 0;
}