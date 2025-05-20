//Falcon2-11B DATASET v1.0 Category: Huffman Coding Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

/* Structure to represent a node in the Huffman tree */
struct Node
{
    char symbol;
    int freq;
    struct Node* left;
    struct Node* right;
};

/* Helper function to create a node with a given symbol and frequency */
struct Node* create_node(char symbol, int freq)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->symbol = symbol;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Helper function to free the memory allocated for a node */
void free_node(struct Node* node)
{
    if (node == NULL)
        return;
    free_node(node->left);
    free_node(node->right);
    free(node);
}

/* Helper function to find the minimum frequency node in the tree */
struct Node* find_min(struct Node* node)
{
    while (node->left!= NULL)
        node = node->left;
    return node;
}

/* Helper function to build the Huffman tree */
void build_tree(struct Node* root, struct Node* tree[], int num_nodes)
{
    int i, j;

    if (root == NULL)
        return;

    tree[i++] = root;
    build_tree(root->left, tree, num_nodes);
    build_tree(root->right, tree, num_nodes);
}

/* Helper function to create the encoded string */
char* encode(char* symbol_string, struct Node* tree[])
{
    int i, j;
    char* encoded_string = (char*) malloc(strlen(symbol_string) * 2);
    int length = strlen(symbol_string);

    for (i = 0; i < length; i++)
    {
        struct Node* node = tree[i];
        while (node!= NULL)
        {
            if (node->symbol == symbol_string[i])
            {
                encoded_string[j++] = node->symbol;
                encoded_string[j++] = '0';
                break;
            }
            else
            {
                node = node->left;
            }
        }
    }
    encoded_string[j] = '\0';

    return encoded_string;
}

/* Main function */
int main()
{
    char symbol_string[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int num_nodes = 26;
    struct Node* tree[num_nodes];

    for (int i = 0; i < num_nodes; i++)
    {
        tree[i] = create_node(' ', 0);
    }

    /* Populate the tree with nodes representing the frequency of each symbol */
    for (int i = 0; i < num_nodes; i++)
    {
        struct Node* node = tree[i];
        int count = 0;
        while (count < strlen(symbol_string))
        {
            if (symbol_string[count] == 'A' && i == 0)
            {
                node->symbol = 'A';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'B' && i == 1)
            {
                node->symbol = 'B';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'C' && i == 2)
            {
                node->symbol = 'C';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'D' && i == 3)
            {
                node->symbol = 'D';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'E' && i == 4)
            {
                node->symbol = 'E';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'F' && i == 5)
            {
                node->symbol = 'F';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'G' && i == 6)
            {
                node->symbol = 'G';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'H' && i == 7)
            {
                node->symbol = 'H';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'I' && i == 8)
            {
                node->symbol = 'I';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'J' && i == 9)
            {
                node->symbol = 'J';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'K' && i == 10)
            {
                node->symbol = 'K';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'L' && i == 11)
            {
                node->symbol = 'L';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'M' && i == 12)
            {
                node->symbol = 'M';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'N' && i == 13)
            {
                node->symbol = 'N';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'O' && i == 14)
            {
                node->symbol = 'O';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'P' && i == 15)
            {
                node->symbol = 'P';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'Q' && i == 16)
            {
                node->symbol = 'Q';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'R' && i == 17)
            {
                node->symbol = 'R';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'S' && i == 18)
            {
                node->symbol = 'S';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'T' && i == 19)
            {
                node->symbol = 'T';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'U' && i == 20)
            {
                node->symbol = 'U';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'V' && i == 21)
            {
                node->symbol = 'V';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'W' && i == 22)
            {
                node->symbol = 'W';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'X' && i == 23)
            {
                node->symbol = 'X';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'Y' && i == 24)
            {
                node->symbol = 'Y';
                node->freq = 1;
                break;
            }
            else if (symbol_string[count] == 'Z' && i == 25)
            {
                node->symbol = 'Z';
                node->freq = 1;
                break;
            }
            count++;
        }
    }

    /* Build the Huffman tree */
    struct Node* root = find_min(tree[0]);
    build_tree(root, tree, num_nodes);

    /* Encode the symbol string using the Huffman tree */
    char* encoded_string = encode(symbol_string, tree);
    printf("Encoded string: %s\n", encoded_string);

    /* Free memory allocated for the tree */
    for (int i = 0; i < num_nodes; i++)
    {
        struct Node* node = tree[i];
        while (node!= NULL)
        {
            free_node(node);
            node = NULL;
        }
    }

    free(encoded_string);

    return 0;
}