//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Define a structure for the Huffman Tree Node
typedef struct HuffmanTreeNode {
    char character;
    int frequency;
    struct HuffmanTreeNode* left_child;
    struct HuffmanTreeNode* right_child;
} HuffmanTreeNode;

//Define a structure for the Huffman Tree
typedef struct HuffmanTree {
    HuffmanTreeNode* root;
} HuffmanTree;

//Define a structure for the Huffman Code
typedef struct HuffmanCode {
    char character;
    char* code;
} HuffmanCode;

//Create a new Huffman Tree Node
HuffmanTreeNode* new_node(char character, int frequency) {
    HuffmanTreeNode* node = (HuffmanTreeNode*)malloc(sizeof(HuffmanTreeNode));
    node->character = character;
    node->frequency = frequency;
    node->left_child = NULL;
    node->right_child = NULL;
    return node;
}

//Create a new Huffman Tree
HuffmanTree* new_tree(HuffmanTreeNode* root) {
    HuffmanTree* tree = (HuffmanTree*)malloc(sizeof(HuffmanTree));
    tree->root = root;
    return tree;
}

//Calculate the frequency of each character in the input string
int* get_frequencies(char* input_string, int input_length) {
    int* frequencies = (int*)calloc(256,sizeof(int));
    for(int i = 0; i < input_length; i++) {
        frequencies[(int)input_string[i]]++;
    }
    return frequencies;
}

//Create a priority queue of Huffman Tree Nodes based on their frequency
HuffmanTreeNode** create_priority_queue(int* frequencies) {
    HuffmanTreeNode** priority_queue = (HuffmanTreeNode**)malloc(256*sizeof(HuffmanTreeNode*));
    int n = 0;
    for(int i = 0; i < 256; i++) {
        if(frequencies[i] != 0) {
            priority_queue[n++] = new_node((char)i, frequencies[i]);
        }
    }
    priority_queue = (HuffmanTreeNode**)realloc(priority_queue, n*sizeof(HuffmanTreeNode*));
    return priority_queue;
}

//Get the minimum frequency node from the priority queue
HuffmanTreeNode* get_minimum(HuffmanTreeNode** priority_queue, int queue_length) {
    HuffmanTreeNode* minimum = priority_queue[0];
    int index = 0;
    for(int i = 1; i < queue_length; i++) {
        if(priority_queue[i]->frequency < minimum->frequency) {
            minimum = priority_queue[i];
            index = i;
        }
    }
    for(int i = index; i < queue_length-1; i++) {
        priority_queue[i] = priority_queue[i+1];
    }
    priority_queue = (HuffmanTreeNode**)realloc(priority_queue, (queue_length-1)*sizeof(HuffmanTreeNode*));
    return minimum;
}

//Build the Huffman Tree from the priority queue
HuffmanTree* build_tree(HuffmanTreeNode** priority_queue, int queue_length) {
    while(queue_length > 1) {
        HuffmanTreeNode* left_child = get_minimum(priority_queue, queue_length--);
        HuffmanTreeNode* right_child = get_minimum(priority_queue, queue_length--);
        HuffmanTreeNode* parent = new_node('\0', left_child->frequency + right_child->frequency);
        parent->left_child = left_child;
        parent->right_child = right_child;
        priority_queue = (HuffmanTreeNode**)realloc(priority_queue, (queue_length+1)*sizeof(HuffmanTreeNode*));
        priority_queue[queue_length++] = parent;
    }
    return new_tree(priority_queue[0]);
}

//Get the Huffman Codes for each character
void get_codes(HuffmanTreeNode* node, char* code, HuffmanCode* huffman_codes) {
    if(node->left_child == NULL && node->right_child == NULL) {
        for(int i = 0; i < 256; i++) {
            if(node->character == (char)i) {
                huffman_codes[i].code = (char*)malloc(strlen(code)*sizeof(char));
                strcpy(huffman_codes[i].code, code);
                huffman_codes[i].character = node->character;
                break;
            }
        }
    } else {
        char* left_code = (char*)malloc((strlen(code)+1)*sizeof(char));
        strcpy(left_code, code);
        strcat(left_code, "0");
        get_codes(node->left_child, left_code, huffman_codes);
        char* right_code = (char*)malloc((strlen(code)+1)*sizeof(char));
        strcpy(right_code, code);
        strcat(right_code, "1");
        get_codes(node->right_child, right_code, huffman_codes);
    }
}

//Encode the input string using the Huffman Code
char* encode_string(char* input_string, HuffmanCode* huffman_codes, int input_length) {
    int length = 0;
    for(int i = 0; i < input_length; i++) {
        length += strlen(huffman_codes[(int)input_string[i]].code);
    }
    char* encoded_string = (char*)malloc(length*sizeof(char));
    int index = 0;
    for(int i = 0; i < input_length; i++) {
        char* code = huffman_codes[(int)input_string[i]].code;
        strcpy(&encoded_string[index], code);
        index += strlen(code);
    }
    return encoded_string;
}

//Decode the encoded string using the Huffman Tree
char* decode_string(char* encoded_string, HuffmanTree* tree, int encoded_length) {
    HuffmanTreeNode* node = tree->root;
    char* decoded_string = (char*)malloc(encoded_length*sizeof(char));
    int index = 0;
    for(int i = 0; i < encoded_length; i++) {
        if(encoded_string[i] == '0') {
            node = node->left_child;
        } else {
            node = node->right_child;
        }
        if(node->left_child == NULL && node->right_child == NULL) {
            decoded_string[index++] = node->character;
            node = tree->root;
        }
    }
    decoded_string[index] = '\0';
    return decoded_string;
}

//Free the memory used by the Huffman Tree
void free_tree(HuffmanTreeNode* node) {
    if(node != NULL) {
        free_tree(node->left_child);
        free_tree(node->right_child);
        free(node);
    }
}

//Free the memory used by the Huffman Code
void free_codes(HuffmanCode* huffman_codes) {
    for(int i = 0; i < 256; i++) {
        if(huffman_codes[i].code != NULL) {
            free(huffman_codes[i].code);
        }
    }
}

int main() {
    char input_string[100];
    printf("Enter the input string: ");
    scanf("%s", input_string);
    int input_length = strlen(input_string);
    int* frequencies = get_frequencies(input_string, input_length);
    HuffmanTreeNode** priority_queue = create_priority_queue(frequencies);
    HuffmanTree* tree = build_tree(priority_queue, input_length);
    HuffmanCode huffman_codes[256];
    get_codes(tree->root, "", huffman_codes);
    char* encoded_string = encode_string(input_string, huffman_codes, input_length);
    printf("Encoded String: %s\n", encoded_string);
    char* decoded_string = decode_string(encoded_string, tree, strlen(encoded_string));
    printf("Decoded String: %s\n", decoded_string);
    free_tree(tree->root);
    free_codes(huffman_codes);
    free(frequencies);
    free(priority_queue);
    free(encoded_string);
    free(decoded_string);
    return 0;
}