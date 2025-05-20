//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    unsigned char character;
    unsigned char bit;
    int frequency;
    struct node* left;
    struct node* right;
} Node;

typedef struct heap {
    Node* array[256];
    int size;
} Heap;

void init_heap(Heap* heap) {
    heap->size = 0;
}

void swap_nodes(Heap* heap, int i, int j) {
    Node* temp = heap->array[i];
    heap->array[i] = heap->array[j];
    heap->array[j] = temp;
}

void bubble_up(Heap* heap, int index) {
    if (index > 0) {
        int parent = (index - 1) / 2;
        if (heap->array[parent]->frequency > heap->array[index]->frequency) {
            swap_nodes(heap, parent, index);
            bubble_up(heap, parent);
        }
    }
}

void bubble_down(Heap* heap, int index) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int min_index = index;
    if (left < heap->size && heap->array[left]->frequency < heap->array[min_index]->frequency) {
        min_index = left;
    }
    if (right < heap->size && heap->array[right]->frequency < heap->array[min_index]->frequency) {
        min_index = right;
    }
    if (min_index != index) {
        swap_nodes(heap, index, min_index);
        bubble_down(heap, min_index);
    }
}

void insert(Heap* heap, Node* node) {
    heap->array[heap->size] = node;
    heap->size++;
    bubble_up(heap, heap->size - 1);
}

Node* extract_min(Heap* heap) {
    Node* min = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    bubble_down(heap, 0);
    return min;
}

Node* build_huffman_tree(int* frequencies) {
    Heap heap;
    init_heap(&heap);
    for (int i = 0; i < 256; i++) {
        if (frequencies[i] > 0) {
            Node* node = (Node*) malloc(sizeof(Node));
            node->character = i;
            node->bit = 0;
            node->frequency = frequencies[i];
            node->left = NULL;
            node->right = NULL;
            insert(&heap, node);
        }
    }
    while (heap.size > 1) {
        Node* node1 = extract_min(&heap);
        Node* node2 = extract_min(&heap);
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->character = 0;
        new_node->bit = 0;
        new_node->frequency = node1->frequency + node2->frequency;
        new_node->left = node1;
        new_node->right = node2;
        insert(&heap, new_node);
    }
    return extract_min(&heap);
}

void assign_codes(Node* node, unsigned char code, int depth) {
    if (node->left == NULL && node->right == NULL) {
        node->bit = code;
        printf("Character '%c' (ASCII %d) has code: ", node->character, node->character);
        for (int i = depth - 1; i >= 0; i--) {
            if (code & (1 << i)) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    } else {
        assign_codes(node->left, code << 1, depth + 1);
        assign_codes(node->right, (code << 1) | 1, depth + 1);
    }
}

void destroy_tree(Node* node) {
    if (node != NULL) {
        destroy_tree(node->left);
        destroy_tree(node->right);
        free(node);
    }
}

void huffman(int* frequencies) {
    Node* root = build_huffman_tree(frequencies);
    assign_codes(root, 0, 0);
    destroy_tree(root);
}

int main() {
    int frequencies[256] = {0};
    char input[1024];
    printf("Enter a string to Huffman encode: ");
    scanf("%[^\n]", input);
    for (int i = 0; input[i] != '\0'; i++) {
        frequencies[input[i]]++;
    }
    huffman(frequencies);
    return 0;
}