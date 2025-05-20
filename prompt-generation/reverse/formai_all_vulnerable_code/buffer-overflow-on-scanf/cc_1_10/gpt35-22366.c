//FormAI DATASET v1.0 Category: Linked list operations ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void addElement(struct Node **head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void deleteElement(struct Node **head, int data) {
    struct Node *temp = *head, *prev = NULL;

    if(temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("\nElement not found in linked list.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void display(struct Node *head) {
    printf("\nLinked list:\n");
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void search(struct Node *head, int data) {
    int pos = 1;
    while(head != NULL) {
        if(head->data == data) {
            printf("\nElement found at position %d.\n", pos);
            return;
        }
        pos++;
        head = head->next;
    }

    printf("\nElement not found in linked list.\n");
}

int main() {
    struct Node *head = NULL;
    int choice, data;

    do {
        printf("\n1. Add element\n2. Delete element\n3. Display\n4. Search\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("\nEnter the element to add: ");
                    scanf("%d", &data);
                    addElement(&head, data);
                    break;

            case 2: printf("\nEnter the element to delete: ");
                    scanf("%d", &data);
                    deleteElement(&head, data);
                    break;

            case 3: display(head);
                    break;

            case 4: printf("\nEnter the element to search: ");
                    scanf("%d", &data);
                    search(head, data);
                    break;

            case 5: printf("\nExiting...");
                    exit(0);
                    break;

            default: printf("\nInvalid choice. Try again.\n");
                     break;
        }

    } while(choice != 5);

    return 0;
}