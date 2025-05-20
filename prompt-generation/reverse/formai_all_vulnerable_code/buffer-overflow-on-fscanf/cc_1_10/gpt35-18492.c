//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Huffman tree node
struct Node {
    int frequency;
    char character;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new huffman tree node
struct Node* create_node(char character, int frequency, struct Node* left, struct Node* right) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->character = character;
    temp->frequency = frequency;
    temp->left = left;
    temp->right = right;
    return temp;
}

// Utility function to read the frequency table from file and create the huffman tree
struct Node* create_huffman_tree_from_file(char* filename) {
    FILE* fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Error opening file! \n");
        exit(1);
    }
    char c;
    int f;
    struct Node* nodes[256];
    for (int i = 0; i < 256; i++) {
        fscanf(fp, "%c %d\n", &c, &f);
        nodes[i] = create_node(c, f, NULL, NULL);
    }
    fclose(fp);
    int num_nodes = 256;

    while (num_nodes > 1) {
        int min1 = 0, min2 = 1;
        if (nodes[min2]->frequency < nodes[min1]->frequency) {
            int temp = min1;
            min1 = min2;
            min2 = temp;
        }
        for (int i = 2; i < num_nodes; i++) {
            if (nodes[i]->frequency < nodes[min1]->frequency) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->frequency < nodes[min2]->frequency) {
                min2 = i;
            }
        }

        struct Node* new_node = create_node('*', nodes[min1]->frequency + nodes[min2]->frequency, nodes[min1], nodes[min2]);

        nodes[min1] = new_node;

        for (int i = min2; i < num_nodes - 1; i++) {
            nodes[i] = nodes[i+1];
        }
        num_nodes--;

        // Update min2 in case it was referring to the node just deleted
        if (min1 == num_nodes) {
            int temp = min1;
            min1 = min2;
            min2 = temp;
        }
        for (int i = min2; i < num_nodes - 1; i++) {
            if (nodes[i]->frequency < nodes[min1]->frequency) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->frequency < nodes[min2]->frequency) {
                min2 = i;
            }
        }
    } 

    return nodes[0];
}

// Utility function to print the huffman code for all characters
void print_huffman_codes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        print_huffman_codes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        print_huffman_codes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    char* filename = "frequency_table.txt";
    struct Node* root = create_huffman_tree_from_file(filename);
    int arr[100], top = 0;
    print_huffman_codes(root, arr, top);
    return 0;
}