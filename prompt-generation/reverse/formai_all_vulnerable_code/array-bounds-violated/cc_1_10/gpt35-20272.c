//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024
#define MAX_TREE_HEIGHT 100

typedef struct node {
    unsigned frequency;
    char character;
    struct node *left, *right;
} Node;

typedef struct queue {
    unsigned size;
    unsigned capacity;
    Node **nodes;
} Queue;

typedef struct huffman_tree {
    Node *root;
} HuffmanTree;

typedef struct huffman_code {
    char character;
    char *code;
} HuffmanCode;

void error(char *message) {
    fprintf(stderr, "Error: %s", message);
    exit(1);
}

Node *new_node(char character, unsigned frequency) {
    Node *new = malloc(sizeof(Node));
    new->character = character;
    new->frequency = frequency;
    new->left = new->right = NULL;
    return new;
}

Queue *new_queue(unsigned capacity) {
    Queue *new = malloc(sizeof(Queue));
    new->size = 0;
    new->capacity = capacity;
    new->nodes = malloc(sizeof(Node *) * capacity);
    return new;
}

void destroy_queue(Queue *queue) {
    for (unsigned i = 0; i < queue->size; i++) {
        free(queue->nodes[i]);
    }
    free(queue->nodes);
    free(queue);
}

void enqueue(Queue *queue, Node *node) {
    if (queue->size == queue->capacity) {
        error("queue is full");
    }
    unsigned index = queue->size;
    while (index > 0 && node->frequency < queue->nodes[index - 1]->frequency) {
        queue->nodes[index] = queue->nodes[index - 1];
        index--;
    }
    queue->nodes[index] = node;
    queue->size++;
}

Node *dequeue(Queue *queue) {
    if (queue->size == 0) {
        error("queue is empty");
    }
    Node *node = queue->nodes[queue->size - 1];
    queue->size--;
    return node;
}

Queue *build_frequency_table(char *string) {
    unsigned frequencies[256] = {0};
    for (unsigned i = 0; string[i] != '\0'; i++) {
        frequencies[(unsigned) string[i]]++;
    }

    Queue *queue = new_queue(256);
    for (unsigned i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            enqueue(queue, new_node((char) i, frequencies[i]));
        }
    }
    return queue;
}

void build_huffman_tree(Queue *queue, HuffmanTree *tree) {
    if (queue->size == 0) {
        error("queue is empty");
    }
    while (queue->size > 1) {
        Node *left = dequeue(queue);
        Node *right = dequeue(queue);
        Node *parent = new_node('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        enqueue(queue, parent);
    }
    tree->root = dequeue(queue);
}

void walk_huffman_tree(Node *node, char **codes, char *code, unsigned height) {
    if (node->left == NULL && node->right == NULL) {
        code[height] = '\0';
        *codes = malloc(sizeof(char) * height);
        strcpy(*codes, code);
        return;
    }
    code[height] = '0';
    walk_huffman_tree(node->left, codes, code, height + 1);
    code[height] = '1';
    walk_huffman_tree(node->right, codes, code, height + 1);
}

void build_huffman_codes(Node *node, HuffmanCode *codes, char *code, unsigned height) {
    if (node->left == NULL && node->right == NULL) {
        codes[(unsigned) node->character].character = node->character;
        codes[(unsigned) node->character].code = malloc(sizeof(char) * height);
        strcpy(codes[(unsigned) node->character].code, code);
        return;
    }
    code[height] = '0';
    build_huffman_codes(node->left, codes, code, height + 1);
    code[height] = '1';
    build_huffman_codes(node->right, codes, code, height + 1);
}

void print_huffman_codes(HuffmanCode *codes) {
    printf("Character\tCode\n");
    for (unsigned i = 0; i < 256; i++) {
        if (codes[i].code != NULL) {
            printf("'%c'\t\t%s\n", codes[i].character, codes[i].code);
        }
    }
}

void encode_string(char *string, HuffmanCode *codes, char *encoded) {
    unsigned length = strlen(string);
    unsigned encoded_index = 0;
    for (unsigned i = 0; i < length; i++) {
        char *code = codes[(unsigned) string[i]].code;
        unsigned code_length = strlen(code);
        for (unsigned j = 0; j < code_length; j++) {
            encoded[encoded_index] = code[j];
            encoded_index++;
        }
    }
    encoded[encoded_index] = '\0';
}

void decode_string(char *encoded, HuffmanTree *tree, char *decoded) {
    Node *node = tree->root;
    unsigned length = strlen(encoded);
    unsigned decoded_index = 0;
    for (unsigned i = 0; i < length; i++) {
        if (encoded[i] == '0') {
            node = node->left;
        } else {
            node = node->right;
        }
        if (node->left == NULL && node->right == NULL) {
            decoded[decoded_index] = node->character;
            decoded_index++;
            node = tree->root;
        }
    }
    decoded[decoded_index] = '\0';
}

int main() {
    char buffer[BUFFER_SIZE];
    printf("Enter the string to encode: ");
    scanf("%[^\n]", buffer);
    getchar();

    Queue *queue = build_frequency_table(buffer);
    HuffmanTree tree;
    build_huffman_tree(queue, &tree);
    HuffmanCode codes[256];
    char code[MAX_TREE_HEIGHT];
    walk_huffman_tree(tree.root, &code, code, 0);
    build_huffman_codes(tree.root, codes, code, 0);

    char encoded[BUFFER_SIZE * 8];
    encode_string(buffer, codes, encoded);
    printf("Encoded: %s\n", encoded);

    char decoded[BUFFER_SIZE];
    decode_string(encoded, &tree, decoded);
    printf("Decoded: %s\n", decoded);

    print_huffman_codes(codes);

    destroy_queue(queue);
    for (int i = 0; i < 256; i++) {
        if (codes[i].code != NULL) {
            free(codes[i].code);
        }
    }

    return 0;
}