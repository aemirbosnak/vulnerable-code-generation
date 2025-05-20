//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// structure to store each character frequency and its binary code
struct huff_node {
    char character;
    int frequency;
    char* binary;
    struct huff_node* left;
    struct huff_node* right;
};

typedef struct huff_node HuffNode;

// function to count the frequency of each character in the text
int* character_frequency(char* text) {
    int* freq = calloc(256, sizeof(int)); // initialize array of 256 elements
    int i;
    for (i = 0; text[i] != '\0'; i++) {
        freq[(int)text[i]]++;
    }
    return freq;
}

// function to create a huffman tree node
HuffNode* create_node(char character, int frequency) {
    HuffNode* node = malloc(sizeof(HuffNode));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    node->binary = NULL;
    return node;
}

// function to create and return a huffman tree
HuffNode* create_huffman_tree(char* text) {
    int* freq = character_frequency(text);
    int i, total_characters = 0;
    HuffNode **nodes, *root, *left, *right;
    nodes = malloc(sizeof(HuffNode*) * 256);

    // create nodes for each character and add them to the array
    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            nodes[total_characters++] = create_node((char)i, freq[i]);
        }
    }

    // loop until only one node is left
    while (total_characters > 1) {
        // sort array by frequency
        for (i=0; i < total_characters; i++) {
            if (nodes[i]->frequency < nodes[0]->frequency) {
                HuffNode *tmp = nodes[0];
                nodes[0] = nodes[i];
                nodes[i] = tmp;
            }
        }
        // merge first two nodes and add the result to the end of the array
        left = nodes[0];
        right = nodes[1];
        root = create_node('\0', left->frequency+right->frequency);
        root->left = left;
        root->right = right;
        nodes[0] = root;
        total_characters--;
        for (i=1; i < total_characters; i++) {
            nodes[i] = nodes[i+1];
        }
    }
    root = nodes[0];
    free(nodes);
    return root;
}

// recursive function to assign binary codes to each character in the huffman tree
void assign_binary(HuffNode* node, char* binary, int binary_len) {
    if (node->left == NULL && node->right == NULL) {
        node->binary = malloc(sizeof(char) * (binary_len+1));
        strcpy(node->binary, binary);
        return;
    }
    char* left_binary = malloc(sizeof(char) * (binary_len+2));
    char* right_binary = malloc(sizeof(char) * (binary_len+2));
    strcpy(left_binary,binary);
    strcpy(right_binary,binary);
    left_binary[binary_len] = '0'; // append '0' to binary code for left node
    left_binary[binary_len+1] = '\0';
    right_binary[binary_len] = '1'; // append '1' to binary code for right node
    right_binary[binary_len+1] = '\0';
    assign_binary(node->left, left_binary, binary_len+1);
    assign_binary(node->right, right_binary, binary_len+1);
}

// function to print the binary codes for each character in the huffman tree
void print_binary_codes(HuffNode* node) {
    if (node == NULL) {
        return;
    }
    if (node->left == NULL && node->right == NULL) {
        printf("%c: %s\n", node->character, node->binary);
    }
    print_binary_codes(node->left);
    print_binary_codes(node->right);
}

int main() {
    printf("Enter a string:\n");
    char* text = calloc(100, sizeof(char));
    scanf("%[^\n]", text);
    getchar();
    HuffNode* root = create_huffman_tree(text);
    assign_binary(root, "", 0);
    printf("Binary codes for each character in the string:\n");
    print_binary_codes(root);
    return 0;
}