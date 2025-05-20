//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char data;
    int freq;
    struct node *left;
    struct node *right;
}node;

node *create_node(char data){
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=data;
    new_node->freq=0;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}

void insert_node(node *root, char data){
    if(root==NULL){
        root=create_node(data);
        return;
    }
    if(data<root->data){
        insert_node(root->left, data);
    }
    else{
        insert_node(root->right, data);
    }
}

void encode(node *root, char *str){
    if(root==NULL){
        printf("%c", str[0]);
        return;
    }
    if(root->left==NULL && root->right==NULL){
        printf("%d%c", root->freq, str[0]);
        return;
    }
    encode(root->left, str);
    encode(root->right, str);
}

void decode(node *root, int *index, char *str){
    if(root==NULL){
        printf("%c", str[*index]);
        (*index)++;
        return;
    }
    if(root->left==NULL && root->right==NULL){
        printf("%c", str[*index]);
        (*index)++;
        return;
    }
    if(str[*index]==root->data){
        decode(root->left, index, str);
    }
    else{
        decode(root->right, index, str);
    }
}

int main(){
    char input_str[1000];
    char output_str[1000];
    printf("Enter the input string: ");
    scanf("%s", input_str);
    int i=0;
    node *root=NULL;
    while(input_str[i]!='\0'){
        insert_node(root, input_str[i]);
        i++;
    }
    encode(root, input_str);
    printf("\nEncoded string: %s\n", output_str);
    i=0;
    while(output_str[i]!='\0'){
        decode(root, &i, output_str);
    }
    printf("\nDecoded string: %s\n", input_str);
    return 0;
}