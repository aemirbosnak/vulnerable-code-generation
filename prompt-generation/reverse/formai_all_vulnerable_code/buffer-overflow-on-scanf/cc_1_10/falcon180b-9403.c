//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_CHARS 256
#define MAX_TREE_HEIGHT 1000

typedef struct node{
    char ch;
    int freq;
    struct node *left;
    struct node *right;
}node;

//Function to create a new node
node* newNode(char ch, int freq){
    node* temp = (node*)malloc(sizeof(node));
    temp->ch = ch;
    temp->freq = freq;
    temp->left = temp->right = NULL;
    return temp;
}

//Function to insert a node in the tree
void insert(node** root, char ch, int freq){
    if(*root == NULL){
        *root = newNode(ch, freq);
        return;
    }
    if(ch < (*root)->ch){
        insert(&(*root)->left, ch, freq);
    }
    else{
        insert(&(*root)->right, ch, freq);
    }
}

//Function to print the Huffman codes
void printCodes(node* root, char* code, int index){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        printf("%c %s\n", root->ch, code);
        return;
    }
    code[index] = '0';
    printCodes(root->left, code, index+1);
    code[index] = '1';
    printCodes(root->right, code, index+1);
}

//Function to build the Huffman tree
node* buildTree(char* text, int freq[], int n){
    node* root = NULL;
    for(int i=0;i<n;i++){
        insert(&root, text[i], freq[i]);
    }
    return root;
}

//Function to calculate the frequency of each character
void calcFreq(char* text, int freq[], int n){
    for(int i=0;i<n;i++){
        freq[i] = 0;
    }
    for(int i=0;i<n;i++){
        freq[text[i]]++;
    }
}

int main(){
    char text[1000];
    int freq[MAX_CHARS] = {0};
    int n;
    printf("Enter the text: ");
    scanf("%s", text);
    n = strlen(text);
    calcFreq(text, freq, n);
    node* root = buildTree(text, freq, n);
    printf("Huffman codes:\n");
    char code[MAX_TREE_HEIGHT] = {0};
    printCodes(root, code, 0);
    return 0;
}