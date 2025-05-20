//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure to store the huffman tree node
struct node {
    char data;
    unsigned freq;
    struct node *left, *right;
};

//structure to store huffman code for each character
struct code {
    char data;
    char *string;
};

//creating a new huffman tree node
struct node* newNode(char data, unsigned freq) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

//sorting the huffman tree nodes in ascending order by their frequencies
void sort(struct node *arr[], int size) {
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            if(arr[j]->freq < arr[i]->freq) {
                struct node *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//building the huffman tree using the sorted array of huffman tree nodes
struct node* buildTree(struct node *arr[], int size) {
    while(size > 1) {
        struct node *left = arr[0], *right = arr[1];
        struct node *temp = newNode('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        size--;
        arr[0] = temp;
        for(int i=1; i<size; i++)
            arr[i] = arr[i+1];
        sort(arr, size);
    }
    return arr[0];
}

//assigning huffman codes to each character
void assignCodes(struct node *root, char str[], int level, struct code *codeArr[]) {
    if(root->left) {
        str[level] = '0';
        assignCodes(root->left, str, level+1, codeArr);
    }
    if(root->right) {
        str[level] = '1';
        assignCodes(root->right, str, level+1, codeArr);
    }
    if(!root->left && !root->right) {
        struct code *temp = (struct code*)malloc(sizeof(struct code));
        temp->data = root->data;
        temp->string = (char*)malloc(sizeof(char)*level);
        for(int i=0; i<level; i++)
            temp->string[i] = str[i];
        codeArr[root->data] = temp;
    }
}

//printing the huffman codes for each character
void printCodes(struct code *codeArr[]) {
    printf("Huffman Codes:\n");
    for(int i=0; i<256; i++)
        if(codeArr[i])
            printf("%c: %s\n", codeArr[i]->data, codeArr[i]->string);
}

int main() {
    printf("Welcome to my Huffman Coding program in C!\n");
    printf("This program will encode and decode messages using Huffman Coding!\n");
    printf("Please enter the message you want to encode:\n");
    char message[256];
    fgets(message, 256, stdin);
    int freq[256], size = 0;
    memset(freq, 0, sizeof(freq));
    for(int i=0; message[i]!='\0'; i++) {
        freq[message[i]]++;
        size++;
    }
    struct node *arr[size];
    int k = 0;
    for(int i=0; i<256; i++)
        if(freq[i])
            arr[k++] = newNode(i, freq[i]);
    sort(arr, size);
    struct node *root = buildTree(arr, size);
    char str[256];
    memset(str, 0, sizeof(str));
    struct code *codeArr[256];
    memset(codeArr, 0, sizeof(codeArr));
    assignCodes(root, str, 0, codeArr);
    printCodes(codeArr);
    printf("Encoded message:\n");
    for(int i=0; message[i]!='\0'; i++)
        printf("%s", codeArr[message[i]]->string);
    printf("\n");
    printf("Decoded message:\n");
    struct node *temp = root;
    for(int i=0; message[i]!='\0'; i++) {
        if(message[i] == '0')
            temp = temp->left;
        else
            temp = temp->right;
        if(!temp->left && !temp->right) {
            printf("%c", temp->data);
            temp = root;
        }
    }
    printf("\nThank you for using my program!\n");
    return 0;
}