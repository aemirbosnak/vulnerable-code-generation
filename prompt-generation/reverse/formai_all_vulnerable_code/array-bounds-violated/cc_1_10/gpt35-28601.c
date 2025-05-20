//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Huffman tree node structure
struct node {
    char data;
    unsigned int freq;
    struct node *left, *right;
};

// Define the Huffman encoding structure
struct code {
    char data;
    char *code;
};

// Define function prototypes
void get_frequency(char *input, unsigned int *freq);
void create_node(struct node **original, struct node **clone);
int get_min_index(struct node **ptr, int size);
void create_huffman(struct node **ptr, int size);
void generate_code(struct node *root, char *temp, int index, struct code *huffman_code);
void encode(char *input, struct code *huffman_code, char *output);

int main() {
    char input[100], output[100], temp[10];
    unsigned int freq[256] = {0};
    struct code huffman_code[256];
    struct node *ptr[256];
    int i, size;

    // Get user input
    printf("Enter input string: ");
    fgets(input, 100, stdin);
    input[strlen(input) - 1] = '\0';

    // Get frequency of each character in input string
    get_frequency(input, freq);

    // Create Huffman tree nodes
    create_node(ptr, ptr + 256);

    // Initialize Huffman tree nodes with frequency and character data
    size = 0;
    for(i = 0; i < 256; i++) {
        if(freq[i] > 0) {
            ptr[size] -> data = (char)i;
            ptr[size] -> freq = freq[i];
            size++;
        }
    }

    // Create Huffman tree
    create_huffman(ptr, size);

    // Generate Huffman codes 
    temp[0] = '\0';
    generate_code(ptr[0], temp, 0, huffman_code);

    // Encode input string using Huffman codes
    encode(input, huffman_code, output);

    // Display the encoded string and codes for each character
    printf("\nEncoded string: %s\n", output);
    for(i = 0; i < 256; i++) {
        if(huffman_code[i].code != NULL) {
            printf("'%c': %s\n", huffman_code[i].data, huffman_code[i].code);
        }
    }

    // Free memory allocated for nodes and codes
    for(i = 0; i < 256; i++) {
        if(ptr[i] != NULL) {
            free(ptr[i]);
        }
        if(huffman_code[i].code != NULL) {
            free(huffman_code[i].code);
        }
    }

    return 0;
}

// Function to get the frequency of each character in input string
void get_frequency(char *input, unsigned int *freq) {
    int i;
    for(i = 0; i < strlen(input); i++) {
        freq[(int)input[i]]++;
    }
}

// Function to create Huffman tree nodes
void create_node(struct node **original, struct node **clone) {
    int i;
    for(i = 0; i < 256; i++) {
        original[i] = (struct node*)malloc(sizeof(struct node));
        clone[i] = (struct node*)malloc(sizeof(struct node));
        original[i] -> left = NULL;
        original[i] -> right = NULL;
        clone[i] -> left = NULL;
        clone[i] -> right = NULL;
    }
}

// Function to get the index of the node with the minimum frequency
int get_min_index(struct node **ptr, int size) {
    int i, min_freq = __INT_MAX__, min_index = -1;
    for(i = 0; i < size; i++) {
        if(ptr[i] != NULL && ptr[i] -> freq < min_freq) {
            min_freq = ptr[i] -> freq;
            min_index = i;
        }
    }
    return min_index;
}

// Function to create the Huffman tree
void create_huffman(struct node **ptr, int size) {
    int i, j, min1, min2;
    for(i = 0; i < size - 1; i++) {
        min1 = get_min_index(ptr, size - i);
        min2 = get_min_index(ptr, size - i);
        ptr[size + i] = (struct node*)malloc(sizeof(struct node));
        ptr[size + i] -> left = ptr[min1];
        ptr[size + i] -> right = ptr[min2];
        ptr[size + i] -> freq = ptr[min1] -> freq + ptr[min2] -> freq;
        ptr[min1] = NULL;
        ptr[min2] = ptr[size + i];
    }
}

// Function to generate Huffman codes
void generate_code(struct node *root, char *temp, int index, struct code *huffman_code) {
    if(root == NULL) {
        return;
    }
    if(root -> left == NULL && root -> right == NULL) {
        temp[index] = '\0';
        huffman_code[(int)root -> data].data = root -> data;
        huffman_code[(int)root -> data].code = (char*)malloc(strlen(temp) + 1);
        strcpy(huffman_code[(int)root -> data].code, temp);
    }
    else {
        temp[index] = '0';
        generate_code(root -> left, temp, index + 1, huffman_code);
        temp[index] = '1';
        generate_code(root -> right, temp, index + 1, huffman_code);
    }
}

// Function to encode input string using Huffman codes
void encode(char *input, struct code *huffman_code, char *output) {
    int i, j;
    output[0] = '\0';
    for(i = 0; i < strlen(input); i++) {
        strcat(output, huffman_code[(int)input[i]].code);
    }
}