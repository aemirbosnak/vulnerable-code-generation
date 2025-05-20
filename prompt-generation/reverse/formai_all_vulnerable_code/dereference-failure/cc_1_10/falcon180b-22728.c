//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0

//node structure
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

//tree structure
typedef struct tree{
    node* root;
}tree;

//function prototypes
void* create_node(void* arg);
void insert_node(node** node_ref, int data);
void* create_tree(void* arg);
void traverse_tree(node* node);

int main(){
    pthread_t thread_id;

    //create a new tree
    tree* new_tree = (tree*)malloc(sizeof(tree));
    new_tree->root = NULL;

    //create a new node
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = 5;
    new_node->left = NULL;
    new_node->right = NULL;

    //insert the node into the tree
    insert_node(&(new_tree->root), 5);

    //print the tree
    traverse_tree(new_tree->root);

    return 0;
}

void* create_node(void* arg){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = *(int*)arg;
    new_node->left = NULL;
    new_node->right = NULL;

    return (void*)new_node;
}

void insert_node(node** node_ref, int data){
    node* new_node = create_node(&data);

    if(*node_ref == NULL){
        *node_ref = new_node;
        return;
    }

    if(data < (*node_ref)->data){
        insert_node(&((*node_ref)->left), data);
    }
    else{
        insert_node(&((*node_ref)->right), data);
    }
}

void* create_tree(void* arg){
    int num_nodes = *(int*)arg;
    int i;

    tree* new_tree = (tree*)malloc(sizeof(tree));
    new_tree->root = NULL;

    for(i=1; i<=num_nodes; i++){
        insert_node(&(new_tree->root), i);
    }

    return (void*)new_tree;
}

void traverse_tree(node* node){
    if(node == NULL){
        return;
    }

    traverse_tree(node->left);
    printf("%d ", node->data);
    traverse_tree(node->right);
}