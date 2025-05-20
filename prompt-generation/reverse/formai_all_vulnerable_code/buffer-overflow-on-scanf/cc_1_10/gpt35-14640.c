//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold Huffman Tree Node
typedef struct node{
    char c;
    int freq;
    struct node *left, *right;
}Node;

// Structure to hold Huffman Code
typedef struct code{
    char c;
    char *code;
}Code;

// Compare function for qsort()
int cmp(const void * a, const void * b){
    return (((Node*)a)->freq - ((Node*)b)->freq);
}

// Traverse Huffman Tree and generate Huffman Code
void traverse(Node *root, char *code, Code *codes, int index){
    if(root->left){
        code[index] = '0';
        traverse(root->left, code, codes, index+1);
    }
    if(root->right){
        code[index] = '1';
        traverse(root->right, code, codes, index+1);
    }
    if(!root->left && !root->right){
        code[index] = '\0';
        for(int i=0; i<26; i++){
            if(codes[i].c == root->c){
                codes[i].code = strdup(code);
                break;
            }
        }
    }
}

// Build Huffman Tree and generate codes
void buildHuffmanTree(char *s, Code *codes){
    Node *nodes = (Node*) malloc(26 * sizeof(Node));
    for(int i=0; i<26; i++){
        nodes[i].c = 'a' + i;
        nodes[i].freq = 0;
        nodes[i].left = nodes[i].right = NULL;
    }
    int len = strlen(s);
    for(int i=0; i<len; i++){
        nodes[s[i] - 'a'].freq++;
    }
    qsort(nodes, 26, sizeof(Node), cmp);
    while(nodes[1].freq != 0){
        Node *newNode = (Node*) malloc(sizeof(Node));
        newNode->left = (Node*) malloc(sizeof(Node));
        *(newNode->left) = nodes[0];
        newNode->right = (Node*) malloc(sizeof(Node));
        *(newNode->right) = nodes[1];
        newNode->freq = nodes[0].freq + nodes[1].freq;
        for(int i=2; i<26; i++){
            nodes[i-2] = nodes[i];
        }
        nodes[24] = *newNode;
        qsort(nodes, 25, sizeof(Node), cmp);
    }
    char code[26];
    traverse(&nodes[0], code, codes, 0);
}

// Main function to test Huffman Coding
int main(){
    char s[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", s);
    Code codes[26];
    for(int i=0; i<26; i++){
        codes[i].c = 'a' + i;
        codes[i].code = NULL;
    }
    buildHuffmanTree(s, codes);
    printf("Huffman Codes:\n");
    for(int i=0; i<26; i++){
        if(codes[i].code != NULL){
            printf("%c: %s\n", codes[i].c, codes[i].code);
        }
    }
    return 0;
}