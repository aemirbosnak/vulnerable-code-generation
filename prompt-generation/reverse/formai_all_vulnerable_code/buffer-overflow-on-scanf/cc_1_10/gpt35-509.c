//FormAI DATASET v1.0 Category: Mailing list manager ; Style: curious
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char email[50];
    struct Node* next;
} Node;

Node* createNode(char* email) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->email, email);
    new_node->next = NULL;
    return new_node;
}

void printList(Node* head) {
    Node* curr = head;
    printf("\n\t\tMailing List\n");
    while(curr != NULL) {
        printf("\nEmail: %s\n", curr->email);
        curr = curr->next;
    }
}

void addEmail(Node** head, char* email) {
    Node* new_node = createNode(email);
    if(*head == NULL) {
        *head = new_node;
    } else {
        Node* curr = *head;
        while(curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

void deleteEmail(Node** head, char* email) {
    Node* curr = *head;
    Node* prev = NULL;
    while(curr != NULL) {
        if(strcmp(curr->email, email) == 0) {
            if(prev == NULL) {
                *head = curr->next;
            } else {
                prev->next = curr->next;
            }
            free(curr);
            printf("\n%s has been deleted from the mailing list.\n", email);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("\n%s not found in mailing list.\n", email);
}

int main() {
    Node* head = NULL;
    int choice;
    char email[50];
    do {
        printf("\n\t\tMailing List Manager\n");
        printf("\n1. Add email\n2. Delete email\n3. Print mailing list\n4. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: 
                printf("\nEnter email to add: ");
                scanf("%s", email);
                addEmail(&head, email);
                printf("\n%s has been added to the mailing list.\n", email);
                break;
            case 2:
                printf("\nEnter email to delete: ");
                scanf("%s", email);
                deleteEmail(&head, email);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                printf("\nExiting mailing list manager.\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    } while(choice != 4);

    Node* curr = head;
    while(head != NULL) {
        curr = head;
        head = head->next;
        free(curr);
    }
    return 0;
}