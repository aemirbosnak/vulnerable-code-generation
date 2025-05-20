//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MIN_SIZE 5

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void deleteList(struct Node** head) {
    struct Node* current = *head;
    struct Node* prev = NULL;
    while (current!= NULL) {
        if (current->next == NULL) {
            if (prev!= NULL) {
                prev->next = NULL;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("List is empty.\n");
}

void main() {
    struct Node* head = NULL;
    int num, size;
    printf("Enter size of the list: ");
    scanf("%d", &size);
    while (size > MIN_SIZE) {
        printf("Enter %d elements of the list: ", size);
        for (int i = 0; i < size; i++) {
            scanf("%d", &num);
            insert(&head, num);
        }
        printList(head);
        printf("Do you want to delete the list? (Y/N): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'Y') {
            deleteList(&head);
        }
        printf("Enter size of the list: ");
        scanf("%d", &size);
    }
}