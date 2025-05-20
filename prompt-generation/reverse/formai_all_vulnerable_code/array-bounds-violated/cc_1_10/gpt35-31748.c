//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Huffman tree node
struct node
{
    char character;
    int frequency;
    struct node *left;
    struct node *right;
};

// Huffman tree
struct tree
{
    struct node *root;
};

// Huffman code
struct code
{
    char character;
    char *bits;
};

// Function prototypes
void merge_sort(struct node *nodes[], int length);
void merge(struct node *nodes[], struct node *left[], int left_length, struct node *right[], int right_length);
struct node *build_huffman_tree(struct node *nodes[], int length);
void encode_huffman_tree(struct node *root, char *bits, int bit_length, struct code encoding_table[]);
struct code *build_encoding_table(struct node *nodes[], int length);
char *huffman_encode(struct code encoding_table[], char *message);
char *huffman_decode(struct node *root, char *bits);

int main()
{
    char message[1000];
    printf("Enter message to encode: ");
    fgets(message, 1000, stdin);
    message[strcspn(message, "\n")] = '\0'; // Remove newline character from message if it exists

    // Count frequency of characters in message
    int frequencies[128] = {0}; // Initialize all values to 0
    for (int i = 0; i < strlen(message); i++)
    {
        frequencies[(int)message[i]]++;
    }

    // Create array of nodes to represent each character and its frequency
    int num_nodes = 0;
    struct node *nodes[128];
    for (int i = 0; i < 128; i++)
    {
        if (frequencies[i] > 0)
        {
            struct node *n = malloc(sizeof(struct node));
            n->character = (char)i;
            n->frequency = frequencies[i];
            n->left = NULL;
            n->right = NULL;
            nodes[num_nodes] = n;
            num_nodes++;
        }
    }

    // Sort nodes by frequency in increasing order using merge sort
    merge_sort(nodes, num_nodes);

    // Build Huffman tree from nodes
    struct node *root = build_huffman_tree(nodes, num_nodes);
    struct tree *huffman_tree = malloc(sizeof(struct tree));
    huffman_tree->root = root;

    // Build encoding table from Huffman tree
    struct code encoding_table[num_nodes];
    encode_huffman_tree(root, "", 0, encoding_table);

    // Encode message using encoding table
    char *bits = huffman_encode(encoding_table, message);
    printf("Encoded bits: %s\n", bits);

    // Decode bits using Huffman tree
    char *decoded_message = huffman_decode(root, bits);
    printf("Decoded message: %s\n", decoded_message);

    // Free memory
    free(huffman_tree);
    free(bits);
    free(decoded_message);
    for (int i = 0; i < num_nodes; i++)
    {
        free(nodes[i]);
    }
    return 0;
}

// Sort nodes by frequency in increasing order using merge sort
void merge_sort(struct node *nodes[], int length)
{
    if (length <= 1)
    {
        return;
    }
    int left_length = length / 2;
    int right_length = length - left_length;
    struct node *left[left_length];
    struct node *right[right_length];
    for (int i = 0; i < left_length; i++)
    {
        left[i] = nodes[i];
    }
    for (int i = 0; i < right_length; i++)
    {
        right[i] = nodes[i + left_length];
    }
    merge_sort(left, left_length);
    merge_sort(right, right_length);
    merge(nodes, left, left_length, right, right_length);
}

// Merge two sorted arrays of nodes by frequency in increasing order
void merge(struct node *nodes[], struct node *left[], int left_length, struct node *right[], int right_length)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < left_length && j < right_length)
    {
        if (left[i]->frequency < right[j]->frequency)
        {
            nodes[k] = left[i];
            i++;
        }
        else
        {
            nodes[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < left_length)
    {
        nodes[k] = left[i];
        i++;
        k++;
    }
    while (j < right_length)
    {
        nodes[k] = right[j];
        j++;
        k++;
    }
}

// Build Huffman tree from nodes
struct node *build_huffman_tree(struct node *nodes[], int length)
{
    while (length > 1)
    {
        int min_index1 = 0;
        int min_frequency1 = nodes[0]->frequency;
        int min_index2 = 1;
        int min_frequency2 = nodes[1]->frequency;
        if (min_frequency2 < min_frequency1)
        {
            int temp_index = min_index1;
            int temp_frequency = min_frequency1;
            min_index1 = min_index2;
            min_frequency1 = min_frequency2;
            min_index2 = temp_index;
            min_frequency2 = temp_frequency;
        }
        for (int i = 2; i < length; i++)
        {
            int frequency = nodes[i]->frequency;
            if (frequency < min_frequency1)
            {
                min_frequency2 = min_frequency1;
                min_index2 = min_index1;
                min_frequency1 = frequency;
                min_index1 = i;
            }
            else if (frequency < min_frequency2)
            {
                min_frequency2 = frequency;
                min_index2 = i;
            }
        }
        struct node *new_node = malloc(sizeof(struct node));
        new_node->character = '\0';
        new_node->frequency = min_frequency1 + min_frequency2;
        new_node->left = nodes[min_index1];
        new_node->right = nodes[min_index2];
        nodes[min_index1] = new_node;
        for (int i = min_index2; i < length - 1; i++)
        {
            nodes[i] = nodes[i + 1];
        }
        length--;
    }
    return nodes[0];
}

// Recursively encode Huffman tree to build encoding table
void encode_huffman_tree(struct node *root, char *bits, int bit_length, struct code encoding_table[])
{
    if (root->left == NULL && root->right == NULL)
    {
        char character = root->character;
        int index = (int)character;
        encoding_table[index].character = character;
        encoding_table[index].bits = malloc((bit_length + 1) * sizeof(char));
        memcpy(encoding_table[index].bits, bits, bit_length * sizeof(char));
        encoding_table[index].bits[bit_length] = '\0';
        return;
    }
    char *left_bits = malloc((bit_length + 1) * sizeof(char));
    memcpy(left_bits, bits, bit_length * sizeof(char));
    left_bits[bit_length] = '0';
    encode_huffman_tree(root->left, left_bits, bit_length + 1, encoding_table);
    char *right_bits = malloc((bit_length + 1) * sizeof(char));
    memcpy(right_bits, bits, bit_length * sizeof(char));
    right_bits[bit_length] = '1';
    encode_huffman_tree(root->right, right_bits, bit_length + 1, encoding_table);
}

// Build encoding table from nodes
struct code *build_encoding_table(struct node *nodes[], int length)
{
    struct code *encoding_table = malloc(length * sizeof(struct code));
    for (int i = 0; i < length; i++)
    {
        char character = nodes[i]->character;
        int index = (int)character;
        encoding_table[index].character = character;
        encoding_table[index].bits = malloc(nodes[i]->frequency * sizeof(char));
        encoding_table[index].bits[0] = '\0';
    }
    for (int i = 0; i < length; i++)
    {
        if (nodes[i]->left == NULL && nodes[i]->right == NULL)
        {
            continue;
        }
        char *left_bits = malloc(nodes[i]->frequency * sizeof(char));
        left_bits[0] = '0';
        left_bits[1] = '\0';
        char *right_bits = malloc(nodes[i]->frequency * sizeof(char));
        right_bits[0] = '1';
        right_bits[1] = '\0';
        int left_index = (int)nodes[i]->left->character;
        int right_index = (int)nodes[i]->right->character;
        strcat(encoding_table[left_index].bits, left_bits);
        strcat(encoding_table[right_index].bits, right_bits);
    }
    return encoding_table;
}

// Encode message using encoding table
char *huffman_encode(struct code encoding_table[], char *message)
{
    int num_bits = 0;
    for (int i = 0; i < strlen(message); i++)
    {
        int index = (int)message[i];
        num_bits += strlen(encoding_table[index].bits);
    }
    char *bits = malloc((num_bits + 1) * sizeof(char));
    bits[0] = '\0';
    for (int i = 0; i < strlen(message); i++)
    {
        int index = (int)message[i];
        strcat(bits, encoding_table[index].bits);
    }
    return bits;
}

// Decode bits using Huffman tree
char *huffman_decode(struct node *root, char *bits)
{
    struct node *current_node = root;
    char *decoded_message = malloc(1000 * sizeof(char));
    int decoded_index = 0;
    for (int i = 0; i <= strlen(bits); i++)
    {
        char bit = bits[i];
        if (bit == '0')
        {
            current_node = current_node->left;
        }
        else if (bit == '1')
        {
            current_node = current_node->right;
        }
        if (current_node->left == NULL && current_node->right == NULL)
        {
            decoded_message[decoded_index] = current_node->character;
            decoded_index++;
            current_node = root;
        }
    }
    decoded_message[decoded_index] = '\0';
    return decoded_message;
}