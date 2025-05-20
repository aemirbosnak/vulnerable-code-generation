//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct node {
    int value;
    struct node* next;
} node;

node* createNode(int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

node* push(node* head, int value) {
    node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    return head;
}

void printList(node* head) {
    while(head!= NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
}

int main() {
    char input[100];
    int decimal, binary[100], i = 0;

    printf("Enter a decimal number: ");
    scanf("%s", input);

    for(int j = 0; input[j]!= '\0'; j++) {
        if(!isdigit(input[j])) {
            printf("Invalid input. Please enter a valid decimal number.\n");
            return 0;
        }
    }

    decimal = atoi(input);

    while(decimal!= 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }

    printf("The binary representation of %d is: ", decimal);
    for(int k = i - 1; k >= 0; k--) {
        printf("%d", binary[k]);
    }

    printf("\n");

    return 0;
}