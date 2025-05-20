//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ENCRYPT 1
#define DECRYPT 2

int get_mode(char *mode) {
    if (strcmp(mode, "encrypt") == 0) {
        return ENCRYPT;
    } else if (strcmp(mode, "decrypt") == 0) {
        return DECRYPT;
    } else {
        return -1;
    }
}

void encrypt_file(FILE *in, FILE *out, int mode, int key) {
    char ch;
    while ((ch = fgetc(in))!= EOF) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            if (mode == ENCRYPT) {
                ch = (ch + key - 97) % 26 + 97;
            } else {
                ch = (ch - key - 97) % 26 + 97;
            }
        }
        fputc(ch, out);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage: %s <mode> <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    int mode = get_mode(argv[1]);
    if (mode == -1) {
        printf("Invalid mode.\n");
        return 1;
    }

    FILE *in = fopen(argv[2], "rb");
    if (in == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *out = fopen(argv[3], "wb");
    if (out == NULL) {
        printf("Error opening output file.\n");
        fclose(in);
        return 1;
    }

    int key = atoi(argv[4]);

    encrypt_file(in, out, mode, key);

    fclose(in);
    fclose(out);

    return 0;
}