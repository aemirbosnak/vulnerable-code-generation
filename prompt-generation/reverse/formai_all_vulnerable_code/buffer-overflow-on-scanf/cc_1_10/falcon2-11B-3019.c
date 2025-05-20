//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    int freq;
    char data;
    struct node* left;
    struct node* right;
}node;

node* get_node(char data)
{
    node* new_node = (node*)malloc(sizeof(node));
    new_node->freq = 1;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* merge(node* left, node* right)
{
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;

    if(left->freq < right->freq)
    {
        left->right = merge(left->right, right);
        left->freq += right->freq;
        free(right);
        return left;
    }
    else
    {
        right->left = merge(left, right->left);
        right->freq += left->freq;
        free(left);
        return right;
    }
}

void inorder(node* root)
{
    if(root!= NULL)
    {
        inorder(root->left);
        printf("%d %c", root->freq, root->data);
        inorder(root->right);
    }
}

void huffman_code(node* root, char* output)
{
    if(root->left == NULL && root->right == NULL)
    {
        int i;
        for(i=0; output[i]!='\0'; i++)
            printf("%d %c", root->freq, output[i]);
        printf("\n");
        return;
    }

    huffman_code(root->left, output);
    huffman_code(root->right, output);
}

int main()
{
    node* root = NULL;
    char ch;
    node* new_node = NULL;
    char* output = (char*)malloc(sizeof(char)*100);
    int i, j;
    printf("Enter the number of input characters: ");
    scanf("%d", &i);
    printf("Enter the input characters: ");
    for(j=0; j<i; j++)
    {
        scanf("%c", &ch);
        new_node = get_node(ch);
        root = merge(root, new_node);
    }
    printf("Huffman Tree: ");
    inorder(root);
    huffman_code(root, output);
    printf("Huffman Code: ");
    for(j=0; output[j]!='\0'; j++)
        printf("%c", output[j]);
    return 0;
}