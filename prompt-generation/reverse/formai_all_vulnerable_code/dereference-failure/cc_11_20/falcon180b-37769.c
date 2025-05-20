//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    int g = 0, count = 0, i, j;
    char *filename;
    char *ext;
    char *dot;
    char *base;

    if (argc!= 3) {
        printf("Usage: %s <filename> <output>\n", argv[0]);
        exit(1);
    }

    filename = argv[1];
    ext = strrchr(filename, '.');
    dot = strchr(filename, '.');

    if (ext == NULL) {
        printf("Invalid file format.\n");
        exit(1);
    }

    base = filename;
    if (dot!= NULL) {
        *dot = '\0';
    }

    if ((fp = fopen(filename, "rb")) == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("ASCII Art of %s:\n", base);

    while ((ch = fgetc(fp))!= EOF) {
        if (ch >= 32 && ch <= 126) {
            for (i = 0; i < 8; i++) {
                for (j = 0; j < 8; j++) {
                    if (((ch >> (7 - i)) & 1) == 1) {
                        printf("X");
                    } else {
                        printf(" ");
                    }
                }
                printf("\n");
            }
            count++;
        }
    }

    printf("\nTotal characters: %d\n", count);

    fclose(fp);
    return 0;
}