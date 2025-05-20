//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Huffman coding struct
struct HuffmanNode {
    char character;
    int frequency;
    struct HuffmanNode *left;
    struct HuffmanNode *right;
};

// Queue struct for Huffman coding
struct QueueNode {
    struct HuffmanNode *huffman_node;
    struct QueueNode *next;
};

// Function prototypes
struct HuffmanNode *new_huffmannode(char,char,int);
struct QueueNode *new_queuenode(struct HuffmanNode*);
void enqueue(struct QueueNode**, struct QueueNode*);
struct QueueNode *dequeue(struct QueueNode**);
void printCodes(struct HuffmanNode*, int[], int);
void encodeHuffman(char[]);
void decodeHuffman(char[], struct HuffmanNode*);
void destroy_tree(struct HuffmanNode*);

// Main function
int main() {
    char input_string[100];
    printf("Enter a string to encode: ");
    scanf("%s", input_string);
    printf("\nOriginal string: %s\n", input_string);
    encodeHuffman(input_string);
    return 0;
}

// Helper function for creating new Huffman nodes
struct HuffmanNode *new_huffmannode(char character, char frequency, int depth) {
    struct HuffmanNode *temp = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    temp->character = character;
    temp->frequency = frequency;
    temp->left = temp->right = NULL;
    return temp;
}

// Helper function for creating new queue nodes
struct QueueNode *new_queuenode(struct HuffmanNode *huffman_node) {
    struct QueueNode *temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->huffman_node = huffman_node;
    temp->next = NULL;
}

// Enqueue a Huffman node onto the queue
void enqueue(struct QueueNode **queue, struct QueueNode *newqueue) {
    if (*queue == NULL) {
        *queue = newqueue;
    }
    else {
        struct QueueNode *temp = *queue;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newqueue;
    }
}

// Dequeue a Huffman node from the queue
struct QueueNode *dequeue(struct QueueNode **queue) {
    if (*queue == NULL) {
        return NULL;
    }
    else {
        struct QueueNode *temp = *queue;
        *queue = (*queue)->next;
        return temp;
    }
}

// Print the Huffman codes for all characters
void printCodes(struct HuffmanNode *root, int code[], int index) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        printf("%c: ", root->character);
        for (int i = 0; i < index; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    }

    code[index] = 0;
    printCodes(root->left, code, index+1);

    code[index] = 1;
    printCodes(root->right, code, index+1);
}

// Encode a string using Huffman coding
void encodeHuffman(char input_string[]) {
    int char_freq[256] = {0};
    int str_len = strlen(input_string);

    // Count frequency of each character
    for (int i = 0; i < str_len; i++) {
        char_freq[input_string[i]]++;
    }

    struct QueueNode *priority_queue = NULL;

    // Add each character/frequency pair to the priority queue as a node
    for (int i = 0; i < 256; i++) {
        if (char_freq[i] != 0) {
            struct HuffmanNode *new_huffman = new_huffmannode(i, char_freq[i], 0);
            struct QueueNode *new_queue = new_queuenode(new_huffman);
            enqueue(&priority_queue, new_queue);
        }
    }

    // Build Huffman tree
    struct HuffmanNode *huffman_tree_root = NULL;
    while (priority_queue->next != NULL) {
        struct QueueNode *min_1 = dequeue(&priority_queue);
        struct QueueNode *min_2 = dequeue(&priority_queue);
        int sum_freq = min_1->huffman_node->frequency + min_2->huffman_node->frequency;
        struct HuffmanNode *new_node = new_huffmannode(0, sum_freq, 0);
        new_node->left = min_1->huffman_node;
        new_node->right = min_2->huffman_node;
        struct QueueNode *new_queue = new_queuenode(new_node);
        enqueue(&priority_queue, new_queue);
        huffman_tree_root = new_node;
    }

    // Store Huffman codes for each character
    int huffman_code[100];
    printCodes(huffman_tree_root, huffman_code, 0);

    // Encode the input string using the Huffman codes
    printf("Encoded string: ");
    for (int i = 0; i < str_len; i++) {
        for (int j = 0; j < 100; j++) {
            if (huffman_tree_root->character == input_string[i]) {
                printf("%d", 0);
                break;
            }
            else if (huffman_tree_root->left->character == input_string[i]) {
                huffman_tree_root = huffman_tree_root->left;
                printf("%d", 0);
                break;
            }
            else if (huffman_tree_root->right->character == input_string[i]) {
                huffman_tree_root = huffman_tree_root->right;
                printf("%d", 1);
                break;
            }
        }
    }
    printf("\n");

    // Decode the encoded string (for demonstration purposes)
    decodeHuffman("100010111110111000111011111000000001110101111101101011000001111010110001011111101101101001100110100110011", huffman_tree_root);
}

// Decode an encoded string using a Huffman tree
void decodeHuffman(char encoded_string[], struct HuffmanNode *huffman_tree_root) {
    printf("Decoded string: ");
    int str_len = strlen(encoded_string);
    for (int i = 0; i < str_len; i++) {
        if (encoded_string[i] == '0') {
            huffman_tree_root = huffman_tree_root->left;
        }
        else if (encoded_string[i] == '1') {
            huffman_tree_root = huffman_tree_root->right;
        }

        if (huffman_tree_root->left == NULL && huffman_tree_root->right == NULL) {
            printf("%c", huffman_tree_root->character);
            huffman_tree_root = huffman_tree_root;
        }
    }
    printf("\n");
}

// Destroy the Huffman tree after encoding/decoding is complete
void destroy_tree(struct HuffmanNode *root) {
    if (root == NULL) {
        return;
    }

    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
}