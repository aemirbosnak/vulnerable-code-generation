//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void printList(Node *head) {
    Node *current = head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    Node *current = NULL;
    int choice, data;

    while (1) {
        printf("Enter 1 to add element to the list\n");
        printf("Enter 2 to print the list\n");
        printf("Enter 3 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be added: ");
                scanf("%d", &data);
                current = malloc(sizeof(Node));
                if (current == NULL) {
                    printf("Memory allocation failed\n");
                    return 1;
                }
                current->data = data;
                current->next = NULL;
                if (head == NULL) {
                    head = current;
                } else {
                    current->next = head;
                    head = current;
                }
                break;
            case 2:
                if (head == NULL) {
                    printf("List is empty\n");
                    break;
                }
                printList(head);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}