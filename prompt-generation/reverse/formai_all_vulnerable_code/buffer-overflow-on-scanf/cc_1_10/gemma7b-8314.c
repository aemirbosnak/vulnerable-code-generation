//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    char binary[100];
    printf("Enter a binary number: ");
    scanf("%s", binary);

    for (int i = 0; binary[i] != '\0'; i++) {
        int digit = binary[i] - '0';
        insertAtTail(head, digit);
    }

    printList(head);

    int decimal = 0;
    int power = 0;

    for (Node* current = head; current; current = current->next) {
        decimal += current->data * pow(2, power);
        power++;
    }

    printf("Decimal equivalent: %d\n", decimal);

    return 0;
}