//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_ascii(char *str, int row, int col, int len) {
    int i;
    for (i = 0; i < len; i++) {
        printf("%c", str[i]);
        if (i == len - 1) {
            printf("\n");
        }
    }
}

void print_ascii_art(char *filename) {
    FILE *fp;
    char ch;
    int count = 0;
    int row = 0;
    int col = 0;

    fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Cannot open file %s", filename);
        exit(0);
    }

    while ((ch = getc(fp))!= EOF) {
        if (ch == '\n') {
            row++;
            col = 0;
        } else {
            printf("%c", ch);
            col++;
            if (col == 80) {
                row++;
                col = 0;
            }
        }
        count++;
        if (count == 24) {
            printf("\n");
            row++;
            col = 0;
            count = 0;
        }
    }

    fclose(fp);
}

int main() {
    char filename[100];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    print_ascii_art(filename);

    return 0;
}