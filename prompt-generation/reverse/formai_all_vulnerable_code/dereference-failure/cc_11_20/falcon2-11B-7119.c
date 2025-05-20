//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: mind-bending
#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} node;

int main() {
    node* head = NULL;
    node* current = NULL;
    node* temp = NULL;
    int choice = 0, data = 0;

    while (choice!= 5) {
        printf("1. Insert at the beginning\n2. Insert at the end\n3. Insert at a specific position\n4. Delete a node\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                temp = (node*)malloc(sizeof(node));
                temp->data = data;
                temp->next = head;
                head = temp;
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                temp = (node*)malloc(sizeof(node));
                temp->data = data;
                if (head == NULL) {
                    head = temp;
                } else {
                    current = head;
                    while (current->next!= NULL) {
                        current = current->next;
                    }
                    current->next = temp;
                }
                break;
            case 3:
                printf("Enter data to insert at a specific position: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &data);
                temp = (node*)malloc(sizeof(node));
                temp->data = data;
                current = head;
                for (int i = 0; i < data - 1; i++) {
                    current = current->next;
                }
                temp->next = current->next;
                current->next = temp;
                break;
            case 4:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                current = head;
                while (current->data!= data && current->next!= NULL) {
                    temp = current->next;
                    free(current);
                    current = temp;
                }
                if (current->data == data) {
                    if (current == head) {
                        head = head->next;
                        free(current);
                    } else {
                        current->next = current->next->next;
                        free(current);
                    }
                }
                break;
            case 5:
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}