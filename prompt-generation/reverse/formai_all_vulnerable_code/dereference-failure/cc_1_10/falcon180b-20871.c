//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Node {
    int data;
    struct Node* next;
};

struct Node* create_node(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct Node* insert_node(struct Node* head, int data) {
    struct Node* new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
        return head;
    }
    struct Node* temp = head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

void delete_node(struct Node* head, int data) {
    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp!= NULL && temp->data!= data) {
        prev = temp;
        temp = temp->next;
    }
    if (temp!= NULL) {
        if (prev!= NULL) {
            prev->next = temp->next;
        } else {
            head = temp->next;
        }
        free(temp);
    }
}

void search_node(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp!= NULL) {
        if (temp->data == data) {
            printf("Data found!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Data not found.\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        printf("Enter 1 to insert data\n");
        printf("Enter 2 to delete data\n");
        printf("Enter 3 to search data\n");
        printf("Enter 0 to exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to be inserted:\n");
                scanf("%d", &data);
                head = insert_node(head, data);
                break;
            case 2:
                printf("Enter the data to be deleted:\n");
                scanf("%d", &data);
                delete_node(head, data);
                break;
            case 3:
                printf("Enter the data to be searched:\n");
                scanf("%d", &data);
                search_node(head, data);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}