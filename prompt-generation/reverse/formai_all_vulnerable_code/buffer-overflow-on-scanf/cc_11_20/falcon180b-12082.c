//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LEN 4096

int main(int argc, char *argv[]) {
    FILE *in, *out;
    char input_file[100], output_file[100];
    unsigned char in_buf[4096], out_buf[4096];
    int in_len, out_len, code_len = 0;
    unsigned char code_buf[MAX_CODE_LEN];

    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    in = fopen(input_file, "rb");
    if (in == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    out = fopen(output_file, "wb");
    if (out == NULL) {
        printf("Error opening output file\n");
        fclose(in);
        exit(1);
    }

    while ((in_len = fread(in_buf, 1, sizeof(in_buf), in)) > 0) {
        out_len = 0;
        for (int i = 0; i < in_len; i++) {
            if (code_len == MAX_CODE_LEN) {
                fprintf(stderr, "Code buffer full, truncating\n");
                break;
            }
            if (i == 0 || in_buf[i]!= in_buf[i - 1]) {
                code_buf[code_len++] = in_buf[i];
            }
        }
        fwrite(code_buf, 1, code_len, out);
        out_len += code_len;
        code_len = 0;
        if (out_len % 3 == 0) {
            unsigned char pad = 0;
            fwrite(&pad, 1, 1, out);
        }
    }

    if (code_len > 0) {
        fwrite(code_buf, 1, code_len, out);
        out_len += code_len;
    }

    if (out_len % 3 == 1) {
        unsigned char pad = 0;
        fwrite(&pad, 1, 1, out);
    }

    if (out_len % 3 == 2) {
        unsigned char pad = 0;
        fwrite(&pad, 1, 1, out);
    }

    fclose(in);
    fclose(out);

    printf("Compression completed\n");

    return 0;
}