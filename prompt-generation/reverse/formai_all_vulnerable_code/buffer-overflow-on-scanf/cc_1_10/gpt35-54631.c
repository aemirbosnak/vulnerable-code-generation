//FormAI DATASET v1.0 Category: Mailing list manager ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *email;
    struct node *next;
} Node;

Node *head = NULL;

void addEmail(char *email) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->email = (char*)malloc(strlen(email)+1);
    strcpy(newNode->email, email);
    newNode->next = NULL;
    if(head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList() {
    Node *temp = head;
    while(temp != NULL) {
        printf("%s\n", temp->email);
        temp = temp->next;
    }
}

void deleteEmail(char *email) {
    Node *temp = head;
    Node *previous = NULL;
    while(temp != NULL) {
        if(strcmp(temp->email, email) == 0) {
            if(previous == NULL) {
                head = temp->next;
            } else {
                previous->next = temp->next;
            }
            free(temp->email);
            free(temp);
            return;
        }
        previous = temp;
        temp = temp->next;
    }
    printf("Email not found!\n");
}

int main() {
    int choice;
    char email[256];
    while(1) {
        printf("1. Add email\n2. Print all emails\n3. Delete email\n4. Quit\n\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter email: ");
                scanf("%s", email);
                addEmail(email);
                printf("Email added!\n\n");
                break;
            case 2:
                printf("Printing all emails:\n");
                printList();
                printf("\n");
                break;
            case 3:
                printf("Enter email to delete: ");
                scanf("%s", email);
                deleteEmail(email);
                printf("\n");
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n\n");
                break;
        }
    }
    return 0;
}