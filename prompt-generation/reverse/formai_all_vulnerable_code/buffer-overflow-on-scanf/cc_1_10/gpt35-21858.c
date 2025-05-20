//FormAI DATASET v1.0 Category: Mailing list manager ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
    char email[50];
    struct node *next;
} Node;

Node* createNode(char email[]) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->email, email);
    newNode->next = NULL;
    return newNode;
}

Node* insertEmail(Node *head, char email[]) {
    if(head == NULL) {
        head = createNode(email);
    }
    else {
        Node *current = head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = createNode(email);
    }
    return head;
}

Node* deleteEmail(Node *head, char email[]) {
    Node *temp = head;
    if(strcmp(head->email, email) == 0) {
        head = head->next;
        free(temp);
    }
    else {
        Node *current = head;
        while(current->next != NULL && strcmp(current->next->email, email) != 0) {
            current = current->next;
        }
        if(current->next == NULL) {
            printf("Email not found in the list.\n");
        }
        else {
            temp = current->next;
            current->next = temp->next;
            free(temp);
        }
    }
    return head;
}

void printList(Node *head) {
    Node *current = head;
    while(current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

int main() {
    Node *head = NULL;
    int choice;
    char email[50];
    do {
        printf("1. Add email to the list\n");
        printf("2. Delete email from the list\n");
        printf("3. Print mailing list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter email: ");
                scanf("%s", email);
                head = insertEmail(head, email);
                break;
            case 2:
                printf("Enter email: ");
                scanf("%s", email);
                head = deleteEmail(head, email);
                break;
            case 3:
                printf("Mailing List:\n");
                printList(head);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while(choice != 4);
    return 0;
}