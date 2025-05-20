//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_CHAR 256

typedef struct {
    char ch;
    int freq;
    struct treenode* left;
    struct treenode* right;
} treenode;

treenode* createNode(char ch, int freq) {
    treenode* newNode = (treenode*) malloc(sizeof(treenode));
    if(newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->ch = ch;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

treenode* insert(treenode* root, char ch, int freq) {
    if(root == NULL) {
        root = createNode(ch, freq);
        return root;
    }
    if(freq > root->freq) {
        root->left = insert(root->left, ch, freq);
    }
    else {
        root->right = insert(root->right, ch, freq);
    }
    return root;
}

void encode(treenode* root, char* str, int* code, int codeLen) {
    if(root == NULL) {
        code[codeLen++] = '\0';
        return;
    }
    if(root->left == NULL && root->right == NULL) {
        code[codeLen++] = root->ch;
        return;
    }
    encode(root->left, str, code, codeLen);
    encode(root->right, str, code, codeLen);
}

void decode(treenode* root, int* code, int codeLen, FILE* outFile) {
    if(root == NULL) {
        return;
    }
    if(root->left == NULL && root->right == NULL) {
        fprintf(outFile, "%c", root->ch);
        return;
    }
    int bit = code[codeLen - 1] - '0';
    if(bit == 0) {
        decode(root->left, code, codeLen - 1, outFile);
    }
    else {
        decode(root->right, code, codeLen - 1, outFile);
    }
}

int main() {
    char inputStr[1000];
    printf("Enter input string: ");
    scanf("%s", inputStr);
    int freq[MAX_CHAR] = {0};
    for(int i = 0; i < strlen(inputStr); i++) {
        freq[inputStr[i]]++;
    }
    treenode* root = NULL;
    for(int i = 0; i < MAX_CHAR; i++) {
        if(freq[i] > 0) {
            root = insert(root, i, freq[i]);
        }
    }
    int code[MAX_CHAR] = {0};
    int codeLen = 0;
    encode(root, "", code, codeLen);
    printf("Huffman code for input string:\n");
    for(int i = 0; i < codeLen; i++) {
        printf("%c", code[i]);
    }
    printf("\n");
    FILE* outFile = fopen("output.txt", "wb");
    if(outFile == NULL) {
        printf("Error opening output file\n");
        exit(0);
    }
    decode(root, code, codeLen, outFile);
    fclose(outFile);
    return 0;
}