//GPT-4o-mini DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int bit;
    struct Node* next;
} Node;

Node* createNode(int bit) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->bit = bit;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node** head, int bit) {
    Node* newNode = createNode(bit);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void freeList(Node* head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void printBinary(Node* head) {
    if (!head) {
        printf("0");
        return;
    }
    Node* temp = head;
    while (temp) {
        printf("%d", temp->bit);
        temp = temp->next;
    }
    printf("\n");
}

void decimalToBinary(int decimal) {
    Node* binaryList = NULL;
    if (decimal == 0) {
        appendNode(&binaryList, 0);
    } else {
        while (decimal > 0) {
            int bit = decimal % 2;
            appendNode(&binaryList, bit);
            decimal /= 2;
        }
    }

    // Reverse the linked list to get the correct binary representation
    Node* prev = NULL;
    Node* current = binaryList;
    Node* next;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    binaryList = prev;

    printBinary(binaryList);
    freeList(binaryList);
}

int main() {
    int decimalNumber;
    
    printf("Welcome to the Decimal to Binary Converter!\n");
    printf("Please enter a decimal number: ");
    
    while (scanf("%d", &decimalNumber) != 1 || decimalNumber < 0) {
        printf("Invalid input. Please enter a non-negative integer: ");
        while(getchar() != '\n'); // Clear invalid input
    }

    printf("Binary representation: ");
    decimalToBinary(decimalNumber);

    return 0;
}