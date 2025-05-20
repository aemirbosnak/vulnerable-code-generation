//Falcon2-11B DATASET v1.0 Category: Searching algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* search(Node* head, int target) {
    Node* current = head;
    while (current!= NULL) {
        if (current->data == target) {
            printf("The target value is found at index %d.\n", current->data);
            return current;
        }
        current = current->next;
    }
    printf("The target value is not found.\n");
    return NULL;
}

int main() {
    Node* head = NULL;
    int target = 10;
    int choice;

    while (1) {
        printf("Welcome to the Medieval Searching Algorithm!\n");
        printf("1. Search for a value in the list\n");
        printf("2. Add a new value to the list\n");
        printf("3. Print the entire list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (head == NULL) {
                    printf("The list is empty.\n");
                } else {
                    printf("Enter the target value: ");
                    scanf("%d", &target);
                    Node* result = search(head, target);
                    if (result!= NULL) {
                        printf("The target value is found at index %d.\n", result->data);
                    } else {
                        printf("The target value is not found.\n");
                    }
                }
                break;
            case 2:
                if (head == NULL) {
                    printf("The list is empty.\n");
                } else {
                    printf("Enter the value to add: ");
                    scanf("%d", &target);
                    Node* newNode = (Node*) malloc(sizeof(Node));
                    newNode->data = target;
                    newNode->next = NULL;
                    if (head == NULL) {
                        head = newNode;
                    } else {
                        Node* current = head;
                        while (current->next!= NULL) {
                            current = current->next;
                        }
                        current->next = newNode;
                    }
                }
                break;
            case 3:
                if (head == NULL) {
                    printf("The list is empty.\n");
                } else {
                    Node* current = head;
                    while (current!= NULL) {
                        printf("%d ", current->data);
                        current = current->next;
                    }
                }
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}