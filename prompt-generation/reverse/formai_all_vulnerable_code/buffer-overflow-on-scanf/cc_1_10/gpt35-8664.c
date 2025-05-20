//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

//Structure for Linked List Node
struct Node {
    int data;
    struct Node *next;
};

//Insertion Operations
struct Node *insertAtEnd(struct Node *head, int val) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return head;
    }

    struct Node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
    return head;
}

struct Node *insertAtBeginning(struct Node *head, int val) {
    struct Node *newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return head;
    }

    newnode->next = head;
    head = newnode;
    return head;
}

//Print List
void printList(struct Node *head) {
    if (head == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("\nList: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Main Function
int main() {
    int choice, val;
    struct Node *head = NULL;

    do {
        printf("Main Menu\n");
        printf("1. Insert at end\n");
        printf("2. Insert at beginning\n");
        printf("3. Print list\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &val);
                head = insertAtEnd(head, val);
                break;

            case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d", &val);
                head = insertAtBeginning(head, val);
                break;

            case 3:
                printList(head);
                break;

            case 4:
                printf("Exiting program.");
                exit(0);

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}