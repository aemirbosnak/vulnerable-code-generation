//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of Huffman Tree Node
typedef struct Node {
    char value;  // character (if leaf node)
    int freq;    // frequency of the character
    struct Node* left;  // left child of the node
    struct Node* right; // right child of the node
} Node;

// Definition of PriorityQueue Node
typedef struct PQNode {
    Node* node; // pointer to the Huffman node
    struct PQNode* next; // pointer to the next node in the priority queue
} PQNode;

// Definition of PriorityQueue
typedef struct PriorityQueue {
    PQNode* head; // pointer to the head of the priority queue
} PriorityQueue;

/*
  Function to create new Huffman Tree node
*/
Node* newHTNode(char value, int freq) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/*
  Function to create new PriorityQueue Node
*/
PQNode* newPQNode(Node* node) {
    PQNode* pqnode = (PQNode*)malloc(sizeof(PQNode));
    pqnode->node = node;
    pqnode->next = NULL;
    return pqnode;
}

/*
  Function to create new PriorityQueue
*/
PriorityQueue* newPriorityQueue() {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->head = NULL;
    return pq;
}

/*
  Function to insert node into PriorityQueue
  (implemented using linked list)
*/
void insertIntoPriorityQueue(PriorityQueue* pq, PQNode* pqnode) {
    if (pq->head == NULL || pqnode->node->freq < pq->head->node->freq) {
        pqnode->next = pq->head;
        pq->head = pqnode;
    } else {
        PQNode* current = pq->head;
        while (current->next != NULL && current->next->node->freq <= pqnode->node->freq) {
            current = current->next;
        }
        pqnode->next = current->next;
        current->next = pqnode;
    }
}

/*
  Function to remove node from the PriorityQueue
*/
PQNode* removeFromPriorityQueue(PriorityQueue* pq) {
    if (pq->head == NULL) {
        return NULL;
    } else {
        PQNode* pqnode = pq->head;
        pq->head = pq->head->next;
        return pqnode;
    }
}

/*
  Function to construct Huffman Tree
*/
Node* constructHuffmanTree(char* inputString) {
    int freq[256] = {0}; // to store the frequency of each character
    int i;
    for (i = 0; i < strlen(inputString); i++) {
        freq[(int)inputString[i]]++;
    }
    PriorityQueue* pq = newPriorityQueue();
    for (i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            Node* node = newHTNode((char)i, freq[i]);
            PQNode* pqnode = newPQNode(node);
            insertIntoPriorityQueue(pq, pqnode);
        }
    }
    PQNode* first;
    PQNode* second;
    while (pq->head->next != NULL) {
        first = removeFromPriorityQueue(pq);
        second = removeFromPriorityQueue(pq);
        Node* parent = newHTNode('\0', first->node->freq + second->node->freq);
        parent->left = first->node;
        parent->right = second->node;
        PQNode* pqnode = newPQNode(parent);
        insertIntoPriorityQueue(pq, pqnode);
    }
    return pq->head->node;
}

/*
  Function to print Huffman Codes for each character
*/
void printHuffmanCodes(Node* root, char* code, int index) {
    if (root == NULL) {
        return;
    }
    if (root->value != '\0') {
        printf("%c: %s\n", root->value, code);
    }
    code[index] = '0';
    printHuffmanCodes(root->left, code, index + 1);
    code[index] = '1';
    printHuffmanCodes(root->right, code, index + 1);
}

int main() {
    char inputString[256];
    scanf("%s", inputString);
    Node* root = constructHuffmanTree(inputString);
    char code[256];
    int index = 0;
    printHuffmanCodes(root, code, index);
    return 0;
}