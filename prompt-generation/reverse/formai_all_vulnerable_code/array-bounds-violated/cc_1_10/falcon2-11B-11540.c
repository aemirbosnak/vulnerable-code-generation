//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    FILE *in_file = fopen(argv[1], "rb");
    if (!in_file) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return 2;
    }

    FILE *out_file = fopen(argv[2], "wb");
    if (!out_file) {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        fclose(in_file);
        return 3;
    }

    int char_count[256] = {0};
    int max_char_count = 0;
    int max_char_index = 0;

    int ch;
    while ((ch = fgetc(in_file))!= EOF) {
        char_count[ch]++;
        if (char_count[ch] > max_char_count) {
            max_char_count = char_count[ch];
            max_char_index = ch;
        }
    }

    fclose(in_file);

    for (int i = 0; i < 256; i++) {
        char_count[i] = (char_count[i] == 0)? 1 : 1 + (max_char_count - char_count[i]);
    }

    for (int i = 0; i < 256; i++) {
        fputc(i, out_file);
        fputc(char_count[i], out_file);
    }

    fclose(out_file);
    return 0;
}