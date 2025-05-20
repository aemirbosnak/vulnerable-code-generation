//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct node{
    char data[50];
    int count;
    struct node* left;
    struct node* right;
}node;

node* create(char str[]){
    node* new = (node*)malloc(sizeof(node));
    strcpy(new->data,str);
    new->count = 1;
    new->left = NULL;
    new->right = NULL;
    return new;
}

node* insert(node* root, char str[]){
    if(root == NULL){
        return create(str);
    }
    if(strcmp(root->data,str) == 0){
        root->count++;
    }
    else if(strcmp(root->data,str) > 0){
        root->left = insert(root->left,str);
    }
    else{
        root->right = insert(root->right,str);
    }
    return root;
}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%s %d\n",root->data,root->count);
    inorder(root->right);
}

int main(){
    node* root = NULL;
    char word[50];
    FILE* file = fopen("words.txt","r");
    while(fscanf(file,"%s",word)!= EOF){
        root = insert(root,word);
    }
    fclose(file);
    inorder(root);
    return 0;
}