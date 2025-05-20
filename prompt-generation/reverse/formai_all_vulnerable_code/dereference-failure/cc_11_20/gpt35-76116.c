//FormAI DATASET v1.0 Category: HTML beautifier ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SPACE ' '

int main(void)
{
    FILE *fin, *fout;
    char *fileNameIn = "input.html";
    char *fileNameOut = "output.html";
    char c = ' ';
    int depth = 0;
    int i = 0;
    int j = 0;

    fin = fopen(fileNameIn, "r");
    if (fin == NULL) {
        printf("Can't open input file!\n");
        exit(1);
    }

    fout = fopen(fileNameOut, "w");
    if (fout == NULL) {
        printf("Can't open output file!\n");
        exit(1);
    }

    while ((c = fgetc(fin)) != EOF) {
        if (c == '<') {
            if (fgetc(fin) == '/') {
                depth--;
                fprintf(fout, "\n");
                for (i = 0; i < depth; i++) {
                    fprintf(fout, "    ");
                }
            } else {
                if (depth > 0) {
                    fprintf(fout, "\n");
                }

                for (i = 0; i < depth; i++) {
                    fprintf(fout, "    ");
                }

                depth++;
            }

            fseek(fin, -1, SEEK_CUR);
        }

        fputc(c, fout);

        if (c == '>') {
            fprintf(fout, "\n");
            for (j = 0; j < depth; j++) {
                fprintf(fout, "    ");
            }
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}