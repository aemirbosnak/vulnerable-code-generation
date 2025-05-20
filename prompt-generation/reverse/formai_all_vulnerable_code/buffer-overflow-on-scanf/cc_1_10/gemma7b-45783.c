//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void traverseList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    char input[10];
    printf("Enter binary number: ");
    scanf("%s", input);

    // Convert input to linked list
    for (int i = 0; input[i] != '\0'; i++) {
        int digit = input[i] - '0';
        head = insertAtTail(head, digit);
    }

    // Traverse the list and convert to decimal
    traverseList(head);
    printf("\nDecimal equivalent: ");
    int decimal = 0;
    int power = 0;
    for (Node* node = head; node; node = node->next) {
        decimal += node->data * pow(2, power);
        power++;
    }

    printf("%d", decimal);

    return 0;
}