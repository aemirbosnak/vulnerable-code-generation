//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_CHARS 256
#define MAX_CODE_LEN 8

typedef struct {
    char ch;
    int freq;
    int code;
} Node;

void build_tree(Node *tree, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        tree[i].freq = 0;
    }
    for (i = 0; i < n; i++) {
        scanf("%c", &tree[i].ch);
        tree[i].freq++;
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (tree[j].freq > tree[i].freq) {
                Node temp = tree[i];
                tree[i] = tree[j];
                tree[j] = temp;
            }
        }
    }
}

void encode(Node *tree, int n, char *text, int *code_len) {
    int i, j;
    int code = 0;
    for (i = 0; i < n; i++) {
        code = (code << 1) | 1;
        if (tree[i].freq > 0) {
            tree[i].code = code;
            code += 1;
        } else {
            tree[i].code = 0;
        }
    }
    int len = 0;
    for (i = 0; i < strlen(text); i++) {
        j = 0;
        while (tree[j].ch!= text[i]) {
            j++;
        }
        len += tree[j].code;
    }
    *code_len = len;
}

void decode(Node *tree, int n, int *code, char *text) {
    int i, j;
    int code_len = 0;
    while (code[code_len]!= 0) {
        i = 0;
        while (tree[i].code!= code[code_len]) {
            i++;
        }
        text[code_len] = tree[i].ch;
        code_len++;
    }
    text[code_len] = '\0';
}

int main() {
    Node tree[MAX_CHARS];
    int n, i;
    char text[1000];
    int code_len;

    printf("Enter the number of characters: ");
    scanf("%d", &n);

    printf("Enter the characters:\n");
    for (i = 0; i < n; i++) {
        scanf("%c", &text[i]);
    }

    build_tree(tree, n);

    encode(tree, n, text, &code_len);

    printf("Code length: %d\n", code_len);

    char code[MAX_CODE_LEN];
    for (i = 0; i < code_len; i++) {
        code[code_len - i - 1] = (code_len - i - 1) % 2 + '0';
    }

    printf("Code: %s\n", code);

    char decoded_text[1000];
    decode(tree, n, code, decoded_text);

    printf("Decoded text: %s\n", decoded_text);

    return 0;
}