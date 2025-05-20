//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    char data[MAX_SIZE];
    struct node* next;
};

struct node* create_node(char* str) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->data, str);
    new_node->next = NULL;
    return new_node;
}

void insert_node(struct node** head, char* str) {
    struct node* new_node = create_node(str);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void display_list(struct node* head) {
    struct node* temp = head;
    printf("List: ");
    while (temp!= NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void search_node(struct node* head, char* str) {
    struct node* temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, str) == 0) {
            printf("Node found!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Node not found.\n");
}

int main() {
    struct node* head = NULL;
    char str[MAX_SIZE];
    int choice = 0;
    while (choice!= 4) {
        printf("1. Insert node\n2. Display list\n3. Search node\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter string: ");
                scanf("%s", str);
                insert_node(&head, str);
                break;
            case 2:
                display_list(head);
                break;
            case 3:
                printf("Enter string to search: ");
                scanf("%s", str);
                search_node(head, str);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}