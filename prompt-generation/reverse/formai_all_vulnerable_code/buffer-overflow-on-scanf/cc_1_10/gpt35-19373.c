//FormAI DATASET v1.0 Category: Mailing list manager ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_EMAILS 1000

typedef struct email {
    char to[50];
    char subject[100];
    char body[1000];
} email;

typedef struct node {
    email email;
    struct node *next;
} node;

void printEmail(email e) {
    printf("To: %s\nSubject: %s\nBody: %s\n\n", e.to, e.subject, e.body);
}

void printList(node *head) {
    node *current = head;
    while(current != NULL) {
        printEmail(current->email);
        current = current->next;
    }
}

node *addEmail(node *head, email e) {
    node *newNode = (node*) malloc(sizeof(node));
    newNode->email = e;
    newNode->next = head;
    head = newNode;
    return head;
}

node *removeEmail(node *head, char *to) {
    node *current = head;
    node *prev = NULL;
    while(current != NULL) {
        if(strcmp(current->email.to, to) == 0) {
            if(prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    }
    printf("Email not found!\n");
    return head;
}

int main() {
    node *head = NULL;
    int choice;
    email e;
    while(1) {
        printf("1. Add email\n2. Delete email\n3. View all emails\n4. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter recipient: ");
                scanf("%s", e.to);
                printf("Enter subject: ");
                scanf("%s", e.subject);
                printf("Enter body: ");
                scanf("%s", e.body);
                printf("\nEmail added!\n\n");
                head = addEmail(head, e);
                break;
            case 2:
                printf("Enter recipient: ");
                scanf("%s", e.to);
                head = removeEmail(head, e.to);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}