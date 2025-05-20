//GEMINI-pro DATASET v1.0 Category: Huffman Coding Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

typedef struct Node {
    int frequency;
    char character;
    struct Node *left, *right;
} Node;

typedef struct MinHeap {
    int size;
    Node **nodes;
} MinHeap;

Node* create_node(char character, int frequency) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;
    return node;
}

MinHeap* create_min_heap(int max_size) {
    MinHeap *min_heap = (MinHeap*)malloc(sizeof(MinHeap));
    min_heap->size = 0;
    min_heap->nodes = (Node**)malloc(max_size * sizeof(Node*));
    return min_heap;
}

void swap_nodes(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(MinHeap *min_heap, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < min_heap->size && min_heap->nodes[left]->frequency < min_heap->nodes[smallest]->frequency) {
        smallest = left;
    }

    if (right < min_heap->size && min_heap->nodes[right]->frequency < min_heap->nodes[smallest]->frequency) {
        smallest = right;
    }

    if (smallest != i) {
        swap_nodes(&min_heap->nodes[i], &min_heap->nodes[smallest]);
        min_heapify(min_heap, smallest);
    }
}

int is_min_heap_empty(MinHeap *min_heap) {
    return min_heap->size == 0;
}

Node* extract_min(MinHeap *min_heap) {
    if (is_min_heap_empty(min_heap)) {
        return NULL;
    }

    Node *min_node = min_heap->nodes[0];
    min_heap->nodes[0] = min_heap->nodes[min_heap->size - 1];
    min_heap->size--;
    min_heapify(min_heap, 0);

    return min_node;
}

void insert_node(MinHeap *min_heap, Node *node) {
    min_heap->nodes[min_heap->size] = node;
    min_heap->size++;

    int i = min_heap->size - 1;
    while (i > 0 && min_heap->nodes[(i - 1) / 2]->frequency > min_heap->nodes[i]->frequency) {
        swap_nodes(&min_heap->nodes[(i - 1) / 2], &min_heap->nodes[i]);
        i = (i - 1) / 2;
    }
}

void build_min_heap(MinHeap *min_heap) {
    for (int i = min_heap->size / 2 - 1; i >= 0; i--) {
        min_heapify(min_heap, i);
    }
}

Node* build_huffman_tree(MinHeap *min_heap) {
    while (min_heap->size > 1) {
        Node *left_node = extract_min(min_heap);
        Node *right_node = extract_min(min_heap);

        Node *parent_node = create_node(' ', left_node->frequency + right_node->frequency);
        parent_node->left = left_node;
        parent_node->right = right_node;

        insert_node(min_heap, parent_node);
    }

    return extract_min(min_heap);
}

void print_code(Node *root, char *code, int top) {
    if (root->left) {
        code[top] = '0';
        print_code(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = '1';
        print_code(root->right, code, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: %s\n", root->character, code);
    }
}

void huffman_encoding(char *text) {
    int frequency[ALPHABET_SIZE] = {0};
    for (int i = 0; text[i] != '\0'; i++) {
        frequency[text[i] - 'a']++;
    }

    MinHeap *min_heap = create_min_heap(ALPHABET_SIZE);
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (frequency[i] > 0) {
            insert_node(min_heap, create_node('a' + i, frequency[i]));
        }
    }

    build_min_heap(min_heap);

    Node *huffman_tree = build_huffman_tree(min_heap);

    char code[100];
    print_code(huffman_tree, code, 0);
}

int main() {
    char text[] = "the quick brown fox jumps over the lazy dog";
    huffman_encoding(text);
    return 0;
}