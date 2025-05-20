//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256
#define MAX_CODES 4096

typedef struct {
    char ch;
    int freq;
    int code;
} Node;

void Swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

int Compare(Node *a, Node *b) {
    return a->freq - b->freq;
}

void BuildTree(Node *tree, int n, int *freq) {
    int i;
    for (i = 0; i < n; i++) {
        tree[i].freq = freq[i];
        tree[i].code = 0;
        tree[i].ch = i;
    }
    qsort(tree, n, sizeof(Node), Compare);
}

void AssignCode(Node *tree, int n, int *code, int codeSize) {
    int i;
    for (i = 0; i < n; i++) {
        code[tree[i].ch] = codeSize - tree[i].freq;
        codeSize += tree[i].freq;
    }
}

void GenerateCode(char *str, int n, int *code) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c -> %s\n", str[i], str);
    }
}

int main() {
    char str[100];
    int freq[MAX_CHARS] = {0};
    int code[MAX_CHARS] = {0};
    int n = 0;
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    for (i = 0; i < strlen(str); i++) {
        freq[str[i]]++;
        n++;
    }

    Node tree[MAX_CHARS];
    BuildTree(tree, n, freq);

    AssignCode(tree, n, code, 0);

    printf("Huffman codes:\n");
    GenerateCode(str, n, code);

    return 0;
}