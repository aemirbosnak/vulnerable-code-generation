//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_SIZE 100000
#define MAX_ALPHABET_SIZE 256

struct Node{
    char symbol;
    int freq;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(char symbol, int freq){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->symbol = symbol;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void freeNode(struct Node* root){
    if(root!= NULL){
        freeNode(root->left);
        freeNode(root->right);
        free(root);
    }
}

void insertNode(struct Node* root, char symbol, int freq){
    if(root == NULL){
        root = createNode(symbol, freq);
    }
    else if(root->symbol > symbol){
        insertNode(root->left, symbol, freq);
    }
    else if(root->symbol < symbol){
        insertNode(root->right, symbol, freq);
    }
}

void traverse(struct Node* root){
    if(root!= NULL){
        traverse(root->left);
        printf("%c %d %c %d\n", root->symbol, root->freq, root->left->symbol, root->left->freq);
        traverse(root->right);
    }
}

int main(){
    char input[MAX_SIZE];
    int n, i, cnt[MAX_ALPHABET_SIZE];
    struct Node* root = NULL;
    printf("Enter the number of characters in the input string: ");
    scanf("%d", &n);
    printf("Enter the input string: ");
    for(i = 0; i < n; i++){
        scanf("%c", &input[i]);
        if(cnt[input[i]] == 0){
            cnt[input[i]]++;
            insertNode(root, input[i], 1);
        }
        else{
            cnt[input[i]]++;
            insertNode(root, input[i], cnt[input[i]]);
        }
    }
    traverse(root);
    freeNode(root);
    printf("Huffman Coding Implementation\n");
    return 0;
}