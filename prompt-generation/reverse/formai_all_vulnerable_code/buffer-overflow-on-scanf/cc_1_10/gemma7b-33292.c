//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

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

int main() {
    char input[MAX_BUFFER_SIZE];
    printf("Enter a binary number: ");
    scanf("%s", input);

    Node* head = NULL;
    for (int i = 0; input[i] != '\0'; i++) {
        int number = input[i] - '0';
        head = insertAtTail(head, number);
    }

    int result = convertBinaryToDecimal(head);
    printf("Decimal equivalent: %d\n", result);

    return 0;
}

int convertBinaryToDecimal(Node* head) {
    int decimal = 0;
    int power = 0;

    while (head) {
        int digit = head->data;
        int digitValue = digit * pow(2, power);
        decimal += digitValue;
        power++;
        head = head->next;
    }

    return decimal;
}