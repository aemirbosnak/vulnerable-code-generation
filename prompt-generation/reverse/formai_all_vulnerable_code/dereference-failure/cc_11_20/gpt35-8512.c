//FormAI DATASET v1.0 Category: HTML beautifier ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE *fp;
    long lSize;
    char *buffer;

    if (argc != 2) {
        printf("Usage: ./beautify <input_file>\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("File opening failed");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0L, SEEK_END);
    lSize = ftell(fp);
    rewind(fp);

    buffer = calloc(1, lSize + 1);
    if (!buffer) {
        fclose(fp);
        fputs("Memory allocation failed", stderr);
        exit(EXIT_FAILURE);
    }

    if (fread(buffer, lSize, 1, fp) != 1) {
        fclose(fp);
        free(buffer);
        fputs("File read failed", stderr);
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    char *p1 = buffer;
    char *p2 = buffer;

    while (*p2) {
        if (*p2 == '<') {
            if (p2 > p1) {
                putchar('\n');
                *p2 = '\0';
                printf("%s", p1);
                p1 = p2;
            }
            while (*p2 && *p2 != '>') {
                putchar(*p2++);
            }
            if (*p2 == '>') {
                putchar(*p2++);
            }
        } else {
            ++p2;
        }
    }

    if (p2 > p1) {
        putchar('\n');
        printf("%s", p1);
    }

    free(buffer);

    return 0;
}