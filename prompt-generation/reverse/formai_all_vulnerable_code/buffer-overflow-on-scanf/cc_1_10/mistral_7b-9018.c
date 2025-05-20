//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

void printBinaryTree(Node *root, int space) {
    if (root == NULL)
        return;

    printBinaryTree(root->right, space + 5);

    printf("\n%*s", space, "");
    printf("%d", root->data);

    printBinaryTree(root->left, space + 5);
}

Node* newNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void decodeBinary(Node *root, int *decimal, int base) {
    if (root == NULL)
        return;

    if (root->left != NULL)
        decodeBinary(root->left, decimal, base * 2 + 1);

    if (root->right != NULL)
        decodeBinary(root->right, decimal, base * 2);

    *decimal += (root->data) * (base << (2 * (3 - (int)(log2(root->data) + 1))));
}

void binaryConverter(int decimal) {
    if (decimal == 0) {
        printf("0\n");
        return;
    }

    Node *root = NULL;
    int binary[100] = {0};
    int index = 0;

    while (decimal > 0) {
        binary[index++] = decimal % 2;
        decimal /= 2;
    }

    for (int i = index - 1; i >= 0; i--)
        root = newNode(binary[i])->left ? (root->left = newNode(binary[i])) : (root->right = newNode(binary[i]));

    printBinaryTree(root, 0);
    int decimalValue = 0;
    decodeBinary(root, &decimalValue, 1);
    printf("\nDecimal equivalent: %d\n", decimalValue);

    while (root->left != NULL)
        root = root->left;
    while (root != NULL) {
        root->data = 0;
        root = root->right;
    }
}

int main() {
    int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);
    binaryConverter(decimalNumber);
    return 0;
}