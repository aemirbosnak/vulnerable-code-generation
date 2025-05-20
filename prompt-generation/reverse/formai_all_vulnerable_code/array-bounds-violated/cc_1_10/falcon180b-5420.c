//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE_LENGTH 7

typedef struct {
    char *code;
    int value;
} Code;

Code huffman_codes[256];
int num_codes;

void build_tree(char *str, int freq, int depth) {
    if (depth == MAX_CODE_LENGTH) {
        huffman_codes[num_codes].code = strdup(str);
        huffman_codes[num_codes++].value = freq;
        return;
    }

    char *left_str = str;
    char *right_str = str + depth;

    int left_freq = freq;
    int right_freq = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '\0') {
            right_freq = freq - left_freq;
            break;
        }

        if (tolower(str[i]) == '0') {
            left_freq++;
        } else {
            right_freq++;
        }
    }

    build_tree(left_str, left_freq, depth + 1);
    build_tree(right_str, right_freq, depth + 1);
}

void generate_codes(void) {
    int freq[256] = {0};

    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        freq[ch]++;
    }

    fclose(fp);

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            build_tree((char*)&i, freq[i], 0);
        }
    }
}

void print_codes(void) {
    for (int i = 0; i < num_codes; i++) {
        printf("%s -> %d\n", huffman_codes[i].code, huffman_codes[i].value);
    }
}

int main(void) {
    generate_codes();
    print_codes();

    return 0;
}