//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

struct node {
    int data;
    struct node* next;
};

typedef struct node Node;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(!new_node) {
        printf("Memory error\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void add_to_end(Node** head, int data) {
    Node* new_node = create_node(data);
    Node* temp = *head;
    if(*head == NULL) {
        *head = new_node;
        return;
    }
    while(temp->next!= NULL)
        temp = temp->next;
    temp->next = new_node;
}

void print_list(Node* head) {
    Node* temp = head;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void search_element(Node* head, int search_key) {
    Node* temp = head;
    while(temp!= NULL) {
        if(temp->data == search_key) {
            printf("Element found\n");
            return;
        }
        temp = temp->next;
    }
    printf("Element not found\n");
}

int main() {
    Node* head = NULL;
    int choice, data, search_key;

    do {
        printf("1. Add element to list\n");
        printf("2. Print list\n");
        printf("3. Search element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to add: ");
                scanf("%d", &data);
                add_to_end(&head, data);
                break;
            case 2:
                print_list(head);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &search_key);
                search_element(head, search_key);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while(1);

    return 0;
}