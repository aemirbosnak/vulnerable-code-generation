//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CODE_LEN 4096
#define MAX_CODE_NUM 4096

typedef struct {
    int len;
    int code;
} CodeTable;

int main(int argc, char **argv) {
    FILE *fp;
    char ch;
    int i, j;
    int len = 0, code = 0;
    char text[MAX_CODE_LEN];
    CodeTable codeTable[MAX_CODE_NUM];

    if (argc!= 3) {
        printf("Usage: %s compress <input_file> | decompress <output_file>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "compress") == 0) {
        fp = fopen(argv[2], "rb");
        if (fp == NULL) {
            printf("Error: cannot open input file.\n");
            return 1;
        }

        while ((ch = fgetc(fp))!= EOF) {
            text[len++] = ch;
        }

        fclose(fp);

        for (i = 0; i < len; i++) {
            for (j = 0; j < i; j++) {
                if (text[i] == text[j]) {
                    break;
                }
            }

            if (j == i) {
                codeTable[code].len = i + 1;
                codeTable[code].code = code++;
            }
        }

        fp = fopen(argv[2], "wb");
        if (fp == NULL) {
            printf("Error: cannot open output file.\n");
            return 1;
        }

        for (i = 0; i < len; i++) {
            fprintf(fp, "%d", codeTable[text[i]].code);
        }

        fclose(fp);

        printf("Compression completed.\n");
    } else if (strcmp(argv[1], "decompress") == 0) {
        fp = fopen(argv[2], "rb");
        if (fp == NULL) {
            printf("Error: cannot open input file.\n");
            return 1;
        }

        while ((ch = fgetc(fp))!= EOF) {
            fprintf(stdout, "%c", ch);
        }

        fclose(fp);

        printf("Decompression completed.\n");
    } else {
        printf("Error: invalid operation.\n");
        return 1;
    }

    return 0;
}