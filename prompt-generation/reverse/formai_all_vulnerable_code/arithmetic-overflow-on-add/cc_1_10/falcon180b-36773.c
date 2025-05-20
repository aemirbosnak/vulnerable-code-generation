//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000
#define MAX_CODE_SIZE 4096

typedef struct {
    int freq;
    int code;
    int next;
} Node;

Node tree[MAX_CODE_SIZE];
int code_size = 0;
int code_index = 0;
int next_code = 0;
int freq[256] = {0};
int code_table[256];

void build_tree(int *text, int len) {
    int i;
    for (i = 0; i < len; i++) {
        freq[text[i]]++;
    }
    for (i = 0; i < 256; i++) {
        if (freq[i]) {
            tree[code_size].freq = freq[i];
            tree[code_size].code = next_code++;
            tree[code_size].next = 0;
            code_size++;
        }
    }
    for (i = 0; i < 256; i++) {
        if (freq[i]) {
            tree[i].freq = freq[i];
            tree[i].code = next_code++;
            tree[i].next = 0;
            code_size++;
        }
    }
}

void build_code_table() {
    int i;
    for (i = 0; i < 256; i++) {
        if (tree[i].freq) {
            code_table[i] = tree[i].code;
        }
    }
}

void encode(int *text, int len, FILE *out) {
    int i;
    for (i = 0; i < len; i++) {
        fprintf(out, "%c", text[i]);
    }
}

void decode(int *text, int len, FILE *in) {
    int i;
    for (i = 0; i < len; i++) {
        if (feof(in)) {
            text[i] = 0;
            break;
        }
        int c = getc(in);
        if (c == EOF) {
            text[i] = 0;
            break;
        }
        text[i] = c;
    }
}

int main() {
    int i, j, len;
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);
    FILE *in = fopen(filename, "rb");
    if (in == NULL) {
        printf("File not found.\n");
        return 1;
    }
    fseek(in, 0, SEEK_END);
    len = ftell(in);
    rewind(in);
    int *text = malloc(len + 1);
    if (text == NULL) {
        printf("Memory error.\n");
        return 1;
    }
    encode(text, len, stdout);
    build_tree(text, len);
    build_code_table();
    printf("Compressed file size: %d\n", code_size * 8);
    FILE *out = fopen("compressed.bin", "wb");
    if (out == NULL) {
        printf("File not found.\n");
        return 1;
    }
    for (i = 0; i < 256; i++) {
        fprintf(out, "%d %d\n", tree[i].code, tree[i].freq);
    }
    for (i = 0; i < len; i++) {
        fprintf(out, "%d", code_table[text[i]]);
    }
    fclose(in);
    fclose(out);
    return 0;
}