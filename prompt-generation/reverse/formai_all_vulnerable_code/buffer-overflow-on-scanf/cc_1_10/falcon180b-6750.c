//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct node {
    char data[MAX_SIZE];
    struct node* next;
};

struct node* createNode(char* data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void addNode(struct node** head, char* data) {
    struct node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void searchNode(struct node* head, char* key) {
    struct node* temp = head;
    while (temp!= NULL) {
        if (strcmp(temp->data, key) == 0) {
            printf("Node found with data: %s\n", temp->data);
            return;
        }
        temp = temp->next;
    }
    printf("Node not found\n");
}

int main() {
    struct node* head = NULL;
    char choice;
    do {
        printf("1. Add node\n2. Search node\n3. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1': {
                char data[MAX_SIZE];
                printf("Enter data: ");
                scanf("%s", data);
                addNode(&head, data);
                break;
            }
            case '2': {
                char key[MAX_SIZE];
                printf("Enter key to search: ");
                scanf("%s", key);
                searchNode(head, key);
                break;
            }
            case '3': {
                printf("Exiting...\n");
                break;
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    } while (choice!= '3');
    return 0;
}