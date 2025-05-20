//FormAI DATASET v1.0 Category: Mailing list manager ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char email[100];
    struct Node* next;
};

struct Node* createNode(char* email) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    strcpy(newNode->email, email);
    newNode->next = NULL;
    return newNode; 
}

struct Node* addToEnd(char* email, struct Node* head) {
    struct Node* newNode = createNode(email);
    if (head == NULL) {
        head = newNode;
    }
    else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

void displayList(struct Node* head) {
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Mailing List:\n");
    printf("---------------\n");
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%s\n", temp->email);
        temp = temp->next;
    }
    printf("---------------\n");
}

int main() {
    struct Node* head = NULL;
    int choice;
    char email[100];
    do {
        printf("1. Add email to mailing list\n");
        printf("2. Display Mailing list\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter email: ");
                scanf("%s", email);
                head = addToEnd(email, head);
                printf("%s added to mailing list.\n", email);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);
    return 0;
}