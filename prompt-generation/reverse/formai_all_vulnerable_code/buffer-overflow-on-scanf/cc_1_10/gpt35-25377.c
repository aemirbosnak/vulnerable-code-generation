//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    int freq;
    struct Node *left;
    struct Node *right;
};

typedef struct Node Node;

Node *newNode(char data, int freq, Node *left, Node *right) {
    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

Node **sortNodesByFreq(Node **nodes, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            // Sort nodes by ascending frequency
            if (nodes[i]->freq > nodes[j]->freq) {
                Node *temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
            }
        }
    }
    return nodes;
}

Node *generateHuffmanTree(Node *root, Node **nodes, int size) {
    nodes = sortNodesByFreq(nodes, size);
    if (size == 1) {
        // If only one node exists, make it the root
        root = nodes[0];
        return root;
    } else {
        Node *left = nodes[0];
        Node *right = nodes[1];
        Node *parent = newNode('$', left->freq + right->freq, left, right);
        nodes[1] = parent;
        // Remove the two nodes with lowest frequency
        for (int i = 2; i < size; i++) {
            nodes[i - 1] = nodes[i];
        }
        size--;
        nodes = sortNodesByFreq(nodes, size);
        // Recursive function call to generate the Huffman tree
        return generateHuffmanTree(root, nodes, size);
    }
}

void printCodes(Node *root, int arr[], int top) {
    if (root->left != NULL) {
        // Traverse left and append 0 to the code array
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right != NULL) {
        // Traverse right and append 1 to the code array
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (root->left == NULL && root->right == NULL) {
        // Print the leaf node's character and its code
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

void compress(char *inputFile, char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    if (in == NULL) {
        printf("Error: Could not open '%s'.\n", inputFile);
        exit(EXIT_FAILURE);
    }
    int freq[256] = {0};
    char c;
    while ((c = fgetc(in)) != EOF) {
        // Update the frequency array
        freq[c]++;
    }
    fclose(in);
    int numNodes = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            numNodes++;
        }
    }
    Node **nodes = (Node **) calloc(numNodes, sizeof(Node *));
    if (nodes == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    int j = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            nodes[j] = newNode(i, freq[i], NULL, NULL);
            j++;
        }
    }
    Node *root = NULL;
    root = generateHuffmanTree(root, nodes, numNodes);
    int code[100];
    int top = 0;
    // Print the codes for each character in the input file
    printf("Huffman Codes:\n");
    printCodes(root, code, top);
    // Write the compressed data to the output file
    in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "wb");
    if (in == NULL) {
        printf("Error: Could not open '%s'.\n", inputFile);
        exit(EXIT_FAILURE);
    }
    if (out == NULL) {
        printf("Error: Could not create '%s'.\n", outputFile);
        exit(EXIT_FAILURE);
    }
    int bitsWritten = 0;
    unsigned char byte = 0;
    while ((c = fgetc(in)) != EOF) {
        // Write the Huffman code for current character to the output file
        int i;
        for (i = 0; i < numNodes; i++) {
            if (nodes[i]->data == c) {
                for (int j = 0; j < top; j++) {
                    if (code[j] == 0) {
                        byte = byte << 1;
                        bitsWritten++;
                    } else {
                        byte = byte << 1;
                        byte = byte | 1;
                        bitsWritten++;
                    }
                    if (bitsWritten == 8) {
                        fwrite(&byte, sizeof(unsigned char), 1, out);
                        byte = 0;
                        bitsWritten = 0;
                    }
                }
            }
        }
    }
    if (bitsWritten > 0) {
        // Pad with zeros if needed
        byte = byte << (8 - bitsWritten);
        fwrite(&byte, sizeof(unsigned char), 1, out);
    }
    fclose(in);
    fclose(out);
    printf("Compression successful!\n");
}

void decompress(char *inputFile, char *outputFile) {
    FILE *in = fopen(inputFile, "rb");
    if (in == NULL) {
        printf("Error: Could not open '%s'.\n", inputFile);
        exit(EXIT_FAILURE);
    }
    Node *root = NULL;
    fread(&root, sizeof(Node *), 1, in);
    FILE *out = fopen(outputFile, "w");
    if (out == NULL) {
        printf("Error: Could not create '%s'.\n", outputFile);
        exit(EXIT_FAILURE);
    }
    Node *curr = root;
    unsigned char byte;
    while (fread(&byte, sizeof(unsigned char), 1, in) == 1) {
        // Traverse the Huffman tree and write the corresponding characters to the output file
        for (int i = 0; i < 8; i++) {
            if (byte & (1 << (7 - i))) {
                curr = curr->right;
            } else {
                curr = curr->left;
            }
            if (curr->left == NULL && curr->right == NULL) {
                fprintf(out, "%c", curr->data);
                curr = root;
            }
        }
    }
    fclose(in);
    fclose(out);
    printf("Decompression successful!\n");
}

int main() {
    int choice;
    char inputFile[100];
    char outputFile[100];
    printf("Multivariable C Compression Algorithm\n");
    while (1) {
        printf("\n1. Compress\n2. Decompress\n3. Exit\nEnter your choice: ");
        fflush(stdout);
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the name of the file to be compressed: ");
                fflush(stdout);
                scanf("%s", inputFile);
                strcpy(outputFile, inputFile);
                strcat(outputFile, ".huff");
                compress(inputFile, outputFile);
                break;
            case 2:
                printf("Enter the name of the file to be decompressed: ");
                fflush(stdout);
                scanf("%s", inputFile);
                strcpy(outputFile, inputFile);
                outputFile[strlen(outputFile) - 5] = '\0';
                decompress(inputFile, outputFile);
                break;
            case 3:
                printf("Exiting...");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}