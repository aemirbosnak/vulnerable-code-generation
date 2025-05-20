//FormAI DATASET v1.0 Category: Compression algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 255
#define MAX_NODES 511

struct huffman_tree_node {
    int freq;
    char c;
    int parent;
    int left;
    int right;
};

void get_char_frequencies(char *string, int *freq) {
    int i;
    for (i = 0; i < MAX_CHARS; i++) {
        freq[i] = 0;
    }
    for (i = 0; i < strlen(string); i++) {
        freq[string[i]]++;
    }
}

void sort_nodes(struct huffman_tree_node *nodes, int n) {
    int i, j;
    struct huffman_tree_node temp_node;
    for (i = 0; i < (n - 1); i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (nodes[j].freq > nodes[j+1].freq) {
                temp_node = nodes[j];
                nodes[j] = nodes[j+1];
                nodes[j+1] = temp_node;
            }
        }
    }
}

void huffman_encode(char *string) {
    int freq[MAX_CHARS], n_nodes = 0, i, j, temp_node_idx;
    struct huffman_tree_node nodes[MAX_NODES];

    get_char_frequencies(string, freq);

    for (i = 0; i < MAX_CHARS; i++) {
        if (freq[i] > 0) {
            nodes[n_nodes].freq = freq[i];
            nodes[n_nodes].c = (char) i;
            nodes[n_nodes].parent = -1;
            nodes[n_nodes].left = -1;
            nodes[n_nodes].right = -1;
            n_nodes++;
        }
    }

    sort_nodes(nodes, n_nodes);

    while (n_nodes > 1) {
        temp_node_idx = n_nodes - 1;
        nodes[n_nodes].freq = nodes[temp_node_idx].freq + nodes[temp_node_idx - 1].freq;
        nodes[n_nodes].c = '\0';
        nodes[n_nodes].parent = -1;
        nodes[nodes[temp_node_idx - 1].left].parent = n_nodes;
        nodes[nodes[temp_node_idx].right].parent = n_nodes;
        nodes[nodes[temp_node_idx].parent].right = n_nodes;
        nodes[nodes[temp_node_idx - 1].parent].left = n_nodes;
        nodes[nodes[n_nodes].left = nodes[temp_node_idx - 1].left].parent = n_nodes;
        nodes[nodes[n_nodes].right = nodes[temp_node_idx].right].parent = n_nodes;
        n_nodes--;
        sort_nodes(nodes, n_nodes);
    }

    printf("Printing Huffman codes:\n");

    for (i = 0; i < strlen(string); i++) {
        j = (int) string[i];
        printf("%d", i);
        while (nodes[j].parent >= 0) {
            if (nodes[nodes[j].parent].left == j) {
                printf("0");
            } else {
                printf("1");
            }
            j = nodes[j].parent;
        }
        printf("\n");
    }
}

int main() {
    char *string;
    string = (char*)malloc(sizeof(char) * 100);

    printf("Enter the string: ");
    scanf("%s", string);

    huffman_encode(string);

    free(string);
    return 0;
}