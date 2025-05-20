//FormAI DATASET v1.0 Category: Linked list operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* root = NULL;

void append(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (root == NULL) {
        root = temp;
    }
    else {
        struct Node* p = root;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

void display() {
    printf("Current linked list: ");
    struct Node* p = root;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int length() {
    int count = 0;
    struct Node* p = root;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void insertAtBeginning(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = root;

    root = temp;
}

void insertAtPosition(int position, int data) {
    if (position < 0 || position > length()) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 0) {
        insertAtBeginning(data);
        return;
    }

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;

    struct Node* p = root;
    int i;
    for (i = 0; i < position-1; i++) {
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
}

void delete(int data) {
    struct Node* p = root;
    struct Node* q = NULL;
    while (p != NULL && p->data != data) {
        q = p;
        p = p->next;
    }
    if (p == NULL) {
        printf("Value not found in linked list.\n");
        return;
    }
    if (q == NULL) {
        root = p->next;
    }
    else {
        q->next = p->next;
    }
    free(p);
}

int main() {
    int choice, data, position;
    printf("Linked List Operations\n");
    do {
        printf("1. Append\n");
        printf("2. Display\n");
        printf("3. Length\n");
        printf("4. Insert at beginning\n");
        printf("5. Insert at position\n");
        printf("6. Delete\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                append(data);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Length of linked list: %d\n", length());
                break;
            case 4:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 5:
                printf("Enter position: ");
                scanf("%d", &position);
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtPosition(position, data);
                break;
            case 6:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    } while(1);

    return 0;
}