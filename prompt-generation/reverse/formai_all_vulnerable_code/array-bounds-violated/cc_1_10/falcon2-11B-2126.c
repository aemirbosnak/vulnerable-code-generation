//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BITS 8

typedef struct {
    char* code;
    int frequency;
} Node;

void build_heap(Node* nodes, int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        int smallest = i;
        int j = i + 1;

        while (j <= (n - 1) && nodes[j].frequency < nodes[smallest].frequency) {
            smallest = j;
            j++;
        }

        if (smallest!= i) {
            Node temp = nodes[i];
            nodes[i] = nodes[smallest];
            nodes[smallest] = temp;
        }
    }
}

Node* heap_sort(Node* nodes, int n) {
    build_heap(nodes, n);

    Node* sorted_nodes = malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
        sorted_nodes[i] = nodes[i];
        nodes[i] = nodes[n - 1];
        nodes[n - 1] = sorted_nodes[i];
    }

    free(nodes);
    return sorted_nodes;
}

void generate_code(Node* nodes, int n) {
    for (int i = 0; i < n; i++) {
        Node node = nodes[i];
        printf("%c%d\n", node.code[0], node.frequency);
    }
}

int main() {
    int freq[26] = {0};
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; charset[i]; i++) {
        freq[charset[i] - 'a']++;
    }

    Node nodes[26];
    for (int i = 0; i < 26; i++) {
        nodes[i].frequency = freq[i];
        nodes[i].code = malloc(strlen(charset) * sizeof(char));
        strcpy(nodes[i].code, charset + i);
    }

    build_heap(nodes, 26);
    Node* sorted_nodes = heap_sort(nodes, 26);

    generate_code(sorted_nodes, 26);

    free(sorted_nodes);
    for (int i = 0; i < 26; i++) {
        free(nodes[i].code);
    }
    return 0;
}