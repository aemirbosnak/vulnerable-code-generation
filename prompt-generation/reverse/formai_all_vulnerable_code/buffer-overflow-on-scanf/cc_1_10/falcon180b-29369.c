//Falcon-180B DATASET v1.0 Category: Huffman Coding Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256
#define MAX_NODES 1000

struct node {
    int freq;
    char ch;
    struct node *left, *right;
};

struct node *newNode(int freq, char ch) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->freq = freq;
    newnode->ch = ch;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int freq, char ch) {
    if (root == NULL) {
        return newNode(freq, ch);
    }
    if (freq < root->freq) {
        root->left = insert(root->left, freq, ch);
    } else if (freq > root->freq) {
        root->right = insert(root->right, freq, ch);
    }
    return root;
}

struct node *minValueNode(struct node *node) {
    node = node->left;
    while (node->right!= NULL) {
        node = node->right;
    }
    return node;
}

void encode(struct node *root, char str[], int *j) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        str[*j] = '\0';
        strcat(str, root->ch);
        *j += strlen(root->ch);
    }
    encode(root->left, str, j);
    encode(root->right, str, j);
}

void decode(struct node *root, int index, char str[]) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        strcat(str, root->ch);
        return;
    }
    if (index < root->freq) {
        if (root->left == NULL) {
            strcat(str, root->ch);
        } else {
            decode(root->left, index, str);
        }
    } else {
        if (root->right == NULL) {
            strcat(str, root->ch);
        } else {
            decode(root->right, index - root->freq, str);
        }
    }
}

int main() {
    char str[100];
    int freq[MAX_CHARS] = {0};
    int i, j = 0;
    struct node *root = NULL;

    printf("Enter the string: ");
    scanf("%s", str);

    for (i = 0; i < strlen(str); i++) {
        freq[str[i]]++;
    }

    root = newNode(freq[str[0]], str[0]);
    root->left = NULL;
    root->right = NULL;

    for (i = 1; i < strlen(str); i++) {
        root = insert(root, freq[str[i]], str[i]);
    }

    printf("Encoded string: ");
    encode(root, str, &j);
    printf("%s\n", str);

    printf("Decoded string: ");
    decode(root, 0, str);
    printf("%s\n", str);

    return 0;
}