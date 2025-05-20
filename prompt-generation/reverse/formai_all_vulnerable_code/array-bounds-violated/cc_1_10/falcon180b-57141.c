//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_CODE_LEN 4
#define MAX_SYMBOLS 256

typedef struct node {
    char ch;
    int freq;
    struct node *left;
    struct node *right;
    int code[MAX_CODE_LEN];
} Node;

Node *create_node(char ch, int freq) {
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->ch = ch;
    newnode->freq = freq;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void encode(Node *root, char str[], int len, int *codeptr) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        strcpy(root->code, "");
        strcat(root->code, "0");
        strcat(root->code, "");
        for (int i = 0; i < MAX_CODE_LEN - strlen(root->code); i++) {
            strcat(root->code, "0");
        }
        *codeptr = strlen(root->code);
    } else {
        strcpy(root->code, "");
        strcat(root->code, "1");
        strcat(root->code, "");
        for (int i = 0; i < MAX_CODE_LEN - strlen(root->code); i++) {
            strcat(root->code, "0");
        }
        *codeptr = strlen(root->code);
        encode(root->left, str, len, codeptr);
        encode(root->right, str, len, codeptr);
    }
}

void decode(Node *root, int code[], int len, FILE *fp) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        fprintf(fp, "%c", root->ch);
    } else {
        if (code[0] == '0') {
            decode(root->left, code + 1, len - 1, fp);
        } else {
            fprintf(fp, "%c", root->ch);
            decode(root->right, code + 1, len - 1, fp);
        }
    }
}

int main() {
    char input[100000];
    int freq[MAX_SYMBOLS] = {0};
    Node *root = NULL;
    int codeptr = 0;

    printf("Enter the input string: ");
    fgets(input, 100000, stdin);
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        freq[input[i]]++;
    }

    for (int i = 0; i < MAX_SYMBOLS; i++) {
        if (freq[i]!= 0) {
            root = create_node(i, freq[i]);
            encode(root, input, len, &codeptr);
            break;
        }
    }

    FILE *fp = fopen("output.txt", "w");
    fprintf(fp, "Huffman codes:\n");
    for (int i = 0; i < codeptr; i++) {
        fprintf(fp, "%c", root->code[i]);
    }
    fprintf(fp, "\n");

    decode(root, root->code, codeptr, fp);

    fclose(fp);

    return 0;
}