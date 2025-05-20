//FormAI DATASET v1.0 Category: Linked list operations ; Style: enthusiastic
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void insertAtBeginning(int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }

    printf("Hooray! %d was added to the beginning of the list.\n", value);
}

void insertAtEnd(int value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Awesome! %d was added to the end of the list.\n", value);
}

void removeFromBeginning() {
    if (head == NULL) {
        printf("Uh oh! The list is already empty.\n");
    } else {
        Node *temp = head;
        head = head->next;
        printf("Yippee! %d was removed from the beginning of the list.\n", temp->data);
        free(temp);
    }
}

void removeFromEnd() {
    if (head == NULL) {
        printf("Oops! The list is already empty.\n");
    } else if (head->next == NULL) {
        printf("Woohoo! %d was removed from the end of the list.\n", head->data);
        free(head);
        head = NULL;
    } else {
        Node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        printf("Yay! %d was removed from the end of the list.\n", temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
}

void displayList() {
    if (head == NULL) {
        printf("Oh no! The list is empty.\n");
    } else {
        printf("Here's your awesome list: ");
        Node *temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    do {
        printf("Welcome to my super cool linked list!\n");
        printf("1. Add an element to the beginning of the list\n");
        printf("2. Add an element to the end of the list\n");
        printf("3. Remove an element from the beginning of the list\n");
        printf("4. Remove an element from the end of the list\n");
        printf("5. Display the elements of the list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                removeFromBeginning();
                break;
            case 4:
                removeFromEnd();
                break;
            case 5:
                displayList();
                break;
            case 0:
                printf("Thanks for using my super cool linked list! Have a great day!\n");
                break;
            default:
                printf("Oops! Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}