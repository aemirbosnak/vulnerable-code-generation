//Code Llama-13B DATASET v1.0 Category: File Encyptor ; Style: statistical
/*
 * File Encryptor
 *
 * Encrypts a file using a simple substitution cipher
 *
 * Usage: file_encryptor <file_name> <key>
 *
 * Key is an integer between 0 and 25, inclusive
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file_name> <key>\n", argv[0]);
        return 1;
    }

    FILE *infile = fopen(argv[1], "r");
    if (!infile) {
        perror("fopen");
        return 1;
    }

    char *key = argv[2];
    int key_int = atoi(key);
    if (key_int < 0 || key_int > 25) {
        fprintf(stderr, "Key must be an integer between 0 and 25, inclusive\n");
        return 1;
    }

    FILE *outfile = fopen("encrypted.txt", "w");
    if (!outfile) {
        perror("fopen");
        return 1;
    }

    int c;
    while ((c = fgetc(infile)) != EOF) {
        c = (c + key_int) % 26;
        fputc(c, outfile);
    }

    fclose(infile);
    fclose(outfile);

    return 0;
}