//FormAI DATASET v1.0 Category: Data recovery tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node **headReference, int data) {
    struct Node *temp = createNode(data);
    temp->next = *headReference;
    *headReference = temp;
}

void printLinkedList(struct Node *head) {
    printf("\nRecovered data: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i, choice;
    struct Node* head = NULL;
    printf("\nSELECT A FILE RECOVERY OPTION\n");
    printf("1 - Quick Recovery\n");
    printf("2 - Deep Recovery\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if(choice == 1) {
        printf("\nQuick Recovery initiated...");
        for (i = 0; i < 10; i++) {
            if (i % 2 == 0) {
                insertNode(&head, data[i]);
            }
        }
        printLinkedList(head);
    } else if(choice == 2) {
        printf("\nDeep Recovery initiated...");
        for (i = 0; i < 10; i++) {
            insertNode(&head, data[i]);
        }
        printLinkedList(head);
    } else {
        printf("\nInvalid Choice!");
    }
    return 0;
}