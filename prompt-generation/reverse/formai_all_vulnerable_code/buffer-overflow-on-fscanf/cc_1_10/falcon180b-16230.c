//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a function to encrypt a file
void encrypt_file(FILE *in_file, FILE *out_file, char *key) {
    char ch;
    int key_index = 0;
    while ((ch = fgetc(in_file))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            ch = (ch + key[key_index]) % 26 + 'A';
        } else {
            ch = ch;
        }
        fputc(ch, out_file);
        key_index = (key_index + 1) % strlen(key);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage: %s input_file output_file key_file key\n", argv[0]);
        return 1;
    }

    FILE *in_file = fopen(argv[1], "rb");
    if (in_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *out_file = fopen(argv[2], "wb");
    if (out_file == NULL) {
        printf("Error opening output file.\n");
        fclose(in_file);
        return 1;
    }

    char key[100];
    FILE *key_file = fopen(argv[3], "r");
    if (key_file == NULL) {
        printf("Error opening key file.\n");
        fclose(in_file);
        fclose(out_file);
        return 1;
    }

    fscanf(key_file, "%s", key);
    fclose(key_file);

    encrypt_file(in_file, out_file, key);

    fclose(in_file);
    fclose(out_file);

    printf("File encryption completed successfully.\n");
    return 0;
}