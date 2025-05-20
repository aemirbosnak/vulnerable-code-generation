//FormAI DATASET v1.0 Category: Linked list operations ; Style: genious
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int value;
    struct ListNode *next;
};

int length(struct ListNode *head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

void reverse(struct ListNode **head) {
    struct ListNode *prev = NULL;
    struct ListNode *current = *head;
    struct ListNode *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void insert(struct ListNode **head, int value, int position) {
    int k = 1;
    struct ListNode *newNode = (struct ListNode *) malloc(sizeof(struct ListNode));
    if (!newNode) {
        printf("Memory Allocation Error!\n");
        return;
    }
    newNode->value = value;
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct ListNode *temp = *head;
        while (temp != NULL && k < position - 1) {
            temp = temp->next;
            k++;
        }
        if (temp == NULL) {
            printf("\nPosition not found\n");
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("\nInsertion completed\n");
}

void delete(struct ListNode **head, int position) {
    int k = 1;
    struct ListNode *temp = *head, *q;
    if (*head == NULL) {
        printf("List is Empty\n");
        return;
    }
    if (position == 1) {
        *head = (*head)->next;
        free(temp);
        printf("\nDeletion completed\n");
        return;
    } else {
        while (temp != NULL && k < position) {
            k++;
            q = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("\nPosition not found\n");
            return;
        }
        q->next = temp->next;
        free(temp);
        printf("\nDeletion completed\n");
    }
}

void display(struct ListNode *head) {
    if (head == NULL) {
        printf("\nList is Empty\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
}

int main() {
    int choice, value, position;
    struct ListNode *head = NULL;
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Reverse\n5. Length\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter a value: ");
                scanf("%d", &value);
                printf("Enter a position: ");
                scanf("%d", &position);
                insert(&head, value, position);
                break;
            case 2:
                printf("\nEnter a position: ");
                scanf("%d", &position);
                delete(&head, position);
                break;
            case 3:
                printf("\nElements: ");
                display(head);
                break;
            case 4:
                reverse(&head);
                printf("\nList is reversed!\n");
                break;
            case 5:
                printf("\nLength: %d\n", length(head));
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    } while (choice != 6);

    return 0;
}