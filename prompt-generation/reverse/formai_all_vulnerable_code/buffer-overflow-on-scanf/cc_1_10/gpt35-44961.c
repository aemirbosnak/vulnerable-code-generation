//FormAI DATASET v1.0 Category: Mailing list manager ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node {
    char email[50];
    struct _node *next;
} Node;

Node* createNode(char* email) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->email, email);
    newNode->next = NULL;
    return newNode;
}

void addToList(Node** head, char* email) {
    Node *newNode = createNode(email);
    if(*head == NULL) {
        *head = newNode;
    } else {
        Node *current = *head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("%s successfully added to list!\n", email);
}

void removeFromList(Node** head, char* email) {
    if(*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *current = *head;
    Node *previous = NULL;
    while(current != NULL) {
        if(strcmp(current->email, email) == 0) {
            if(previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("%s removed from list!\n", email);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Email not found!\n");
}

void displayList(Node* head) {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *current = head;
    while(current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}

void saveList(Node* head) {
    FILE *fp;
    fp = fopen("mailing_list.txt", "w");
    Node *current = head;
    while(current != NULL) {
        fprintf(fp, "%s\n", current->email);
        current = current->next;
    }
    fclose(fp);
    printf("Mailing list saved to file!\n");
}

Node* loadList() {
    FILE *fp;
    Node *head = NULL;
    char email[50];
    fp = fopen("mailing_list.txt", "r");
    if(fp == NULL) {
        printf("Unable to open file!\n");
        return NULL;
    }
    while(fgets(email, 50, fp) != NULL) {
        email[strcspn(email, "\n")] = 0;
        addToList(&head, email);
    }
    fclose(fp);
    printf("Mailing list loaded from file!\n");
    return head;
}

int main() {
    Node *head = loadList();
    int choice;
    char email[50];
    do {
        printf("\nMailing List Manager Menu:\n");
        printf("1. Add email address\n");
        printf("2. Remove email address\n");
        printf("3. View mailing list\n");
        printf("4. Save mailing list\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter email address to add: ");
                scanf("%s", email);
                addToList(&head, email);
                break;
            case 2:
                printf("Enter email address to remove: ");
                scanf("%s", email);
                removeFromList(&head, email);
                break;
            case 3:
                printf("Mailing List:\n");
                displayList(head);
                break;
            case 4:
                saveList(head);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}