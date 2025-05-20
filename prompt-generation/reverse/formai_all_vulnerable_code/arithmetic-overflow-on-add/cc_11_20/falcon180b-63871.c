//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int freq;
    char c;
} Symbol;

int main() {
    FILE *input, *output;
    char ch;
    int i = 0, j = 0;
    Symbol table[256];
    char *text = (char *)malloc(1000000);

    input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    while ((ch = fgetc(input))!= EOF) {
        if (i == 256) {
            printf("Error: Too many symbols\n");
            exit(1);
        }
        if (table[ch].freq == 0) {
            table[ch].freq = 1;
            table[ch].c = ch;
            i++;
        } else {
            table[ch].freq++;
        }
    }

    fclose(input);

    for (i = 0; i < 256; i++) {
        if (table[i].freq > 0) {
            printf("%c %d\n", table[i].c, table[i].freq);
        }
    }

    output = fopen("output.txt", "w");
    if (output == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    for (i = 0; i < strlen(text); i++) {
        for (j = 0; j < 256; j++) {
            if (table[j].c == text[i]) {
                fprintf(output, "%c", j);
                break;
            }
        }
    }

    fclose(output);

    return 0;
}