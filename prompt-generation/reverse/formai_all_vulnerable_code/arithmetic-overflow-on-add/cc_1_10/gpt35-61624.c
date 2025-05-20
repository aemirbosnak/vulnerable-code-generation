//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to calculate frequency of characters in input string
int* calc_freq(char* str, int len) {
    int* freq = (int*) calloc(256, sizeof(int)); // assuming input has ASCII characters
    for(int i=0; i<len; i++) {
        freq[(int)str[i]]++;
    }
    return freq;
}

// node structure for Huffman tree
struct node {
    char ch; // character
    int freq; // frequency of character
    struct node* left; // left child
    struct node* right; // right child
};

// function to create a new node in the tree
struct node* create_node(char ch, int freq) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->ch = ch;
    new_node->freq = freq;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// function to compare two nodes based on their frequency
int compare_nodes(const void* a, const void* b) {
    struct node** node_a = (struct node**) a;
    struct node** node_b = (struct node**) b;
    return (*node_a)->freq - (*node_b)->freq;
}

// function to build Huffman tree
struct node* build_tree(int* freq) {
    struct node* tree[(int)strlen(freq)]; // creating an array of nodes for all characters
    int count = 0;
    for(int i=0; i<256; i++) {
        if(freq[i] > 0) {
            tree[count] = create_node((char)i, freq[i]); // adding nodes to array
            count++;
        }
    }
    while(count > 1) {
        qsort(tree, count, sizeof(struct node*), compare_nodes); // sorting nodes based on frequency
        struct node* new_node = create_node('\0', 0); // creating new node as parent
        new_node->left = tree[0];
        new_node->right = tree[1];
        new_node->freq = tree[0]->freq + tree[1]->freq;
        tree[0] = new_node;
        for(int i=1; i<count-1; i++) {
            tree[i] = tree[i+1];
        }
        count--;
    }
    return tree[0]; // root of the Huffman tree
}

// function to traverse the tree and generate Huffman codes
void generate_codes(struct node* root, int* code, int len) {
    if(root == NULL) {
        return;
    }
    if(root->ch != '\0') {
        printf("%c: ", root->ch); // printing character and its code
        for(int i=0; i<len; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    }
    int* left_code = (int*) calloc(len+1, sizeof(int)); // generating code for left child
    memcpy(left_code, code, len*sizeof(int));
    left_code[len] = 0;
    generate_codes(root->left, left_code, len+1);
    int* right_code = (int*) calloc(len+1, sizeof(int)); // generating code for right child
    memcpy(right_code, code, len*sizeof(int));
    right_code[len] = 1;
    generate_codes(root->right, right_code, len+1);
}

int main() {
    char input[] = "hello, world!"; // sample input string
    int* freq = calc_freq(input, strlen(input)); // calculating frequency of characters
    struct node* tree = build_tree(freq); // creating Huffman tree
    int code[256];
    generate_codes(tree, code, 0); // generating Huffman codes for each character
    free(freq);
    return 0;
}