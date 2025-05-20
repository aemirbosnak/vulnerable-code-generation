//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int data;
    struct node* next;
} node;

node* head = NULL;

void insert(int id, int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->id = id;
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        node* temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void delete(int id) {
    node* temp = head;
    if (temp!= NULL && temp->id == id) {
        head = temp->next;
        free(temp);
    } else {
        while (temp!= NULL && temp->id!= id) {
            temp = temp->next;
        }
        if (temp!= NULL) {
            node* next_node = temp->next;
            free(temp);
            temp = next_node;
        }
    }
}

void search(int id) {
    node* temp = head;
    while (temp!= NULL) {
        if (temp->id == id) {
            printf("ID: %d, Data: %d\n", temp->id, temp->data);
            return;
        }
        temp = temp->next;
    }
    printf("ID not found\n");
}

int main() {
    srand(time(NULL));
    int choice, id, data;
    while (1) {
        printf("1. Insert\n2. Delete\n3. Search\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter ID and Data: ");
                scanf("%d %d", &id, &data);
                insert(id, data);
                break;
            case 2:
                printf("Enter ID: ");
                scanf("%d", &id);
                delete(id);
                break;
            case 3:
                printf("Enter ID: ");
                scanf("%d", &id);
                search(id);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}