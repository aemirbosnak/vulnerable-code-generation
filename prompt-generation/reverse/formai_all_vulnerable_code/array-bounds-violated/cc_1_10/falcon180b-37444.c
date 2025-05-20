//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 300

typedef struct node {
    char ch;
    int freq;
    struct node *left;
    struct node *right;
} Node;

void calcFreq(char str[], int freq[], int n) {
    for (int i = 0; i < n; i++) {
        freq[str[i]]++;
    }
}

void buildTree(char str[], int freq[], int n, Node **root) {
    Node *left[MAX_SIZE], *right[MAX_SIZE];
    int i = 0, j = 0;

    for (int k = 0; k < n; k++) {
        if (freq[str[k]] > 0) {
            if (i == MAX_SIZE - 1) {
                printf("Overflow\n");
                exit(0);
            }
            left[i] = (Node *) malloc(sizeof(Node));
            left[i]->ch = str[k];
            left[i]->freq = freq[str[k]];
            left[i]->left = NULL;
            left[i]->right = NULL;
            i++;
        }
    }

    for (int k = 0; k < i - 1; k++) {
        for (int l = k + 1; l < i; l++) {
            if (left[k]->freq < left[l]->freq) {
                Node *temp = left[k];
                left[k] = left[l];
                left[l] = temp;
            }
        }
    }

    for (int k = 0; k < i - 1; k++) {
        right[k] = left[k + 1];
    }
    right[i - 1] = NULL;

    *root = left[0];
}

void encode(Node *root, char str[], int *index, FILE *fp) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        str[*index] = root->ch;
        *index += 1;
    } else {
        str[*index] = '0';
        *index += 1;
    }

    encode(root->left, str, index, fp);
}

void decode(Node *root, int ch, FILE *fp) {
    if (root == NULL) {
        return;
    }

    if (ch == '0') {
        decode(root->left, ch, fp);
    } else {
        fprintf(fp, "%c", root->ch);
        ch = ch - '0';
        decode(root->right, ch, fp);
    }
}

int main() {
    char inputStr[MAX_SIZE];
    int freq[256] = { 0 };
    int n;

    printf("Enter the string: ");
    scanf("%s", inputStr);

    n = strlen(inputStr);

    calcFreq(inputStr, freq, n);

    Node *root = NULL;

    buildTree(inputStr, freq, n, &root);

    printf("\nFrequency\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i]!= 0) {
            printf("%c %d\n", i, freq[i]);
        }
    }

    printf("\nHuffman Codes\n");
    encode(root, inputStr, &n, stdout);

    printf("\n\nDecoded string: ");
    decode(root, '0', stdout);

    return 0;
}