//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE_LEN 5

typedef struct {
    int freq;
    char code[MAX_CODE_LEN];
} node;

void calc_freq(char *str, int len, node *table) {
    int i;
    for (i = 0; i < len; i++) {
        table[i].freq = 0;
    }
    for (i = 0; i < len; i++) {
        table[i].freq++;
    }
}

void build_tree(node *table, int len) {
    int i, j, k;
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            if (table[i].freq < table[j].freq) {
                node temp = table[i];
                table[i] = table[j];
                table[j] = temp;
            }
        }
    }
}

void encode(char *str, int len, node *table, char *code) {
    int i, j;
    for (i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            code[i] = table[i].code[0];
        }
    }
}

void decode(char *str, int len, node *table) {
    int i, j;
    for (i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            for (j = 0; j < MAX_CODE_LEN; j++) {
                if (table[i].code[j] == str[i]) {
                    break;
                }
            }
        }
    }
}

int main() {
    char str[100];
    int len, i;

    printf("Enter a string: ");
    scanf("%s", str);
    len = strlen(str);

    node table[256];
    calc_freq(str, len, table);
    build_tree(table, len);

    printf("Frequency:\n");
    for (i = 0; i < len; i++) {
        printf("%c: %d\n", table[i].code[0], table[i].freq);
    }

    printf("Huffman code:\n");
    encode(str, len, table, str);
    printf("%s\n", str);

    printf("Decoded string:\n");
    decode(str, len, table);
    printf("%s\n", str);

    return 0;
}