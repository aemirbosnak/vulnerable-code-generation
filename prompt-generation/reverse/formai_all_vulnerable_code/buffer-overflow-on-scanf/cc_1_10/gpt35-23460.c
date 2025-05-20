//FormAI DATASET v1.0 Category: Mailing list manager ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 50

struct node {
    char email[MAX_LEN];
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

// function prototypes
void addToList(char email[]);
void removeFromList(char email[]);
void printList();

int main() {
    int choice;
    char email[MAX_LEN];

    do {
        printf("Menu\n");
        printf("1. Add email to list\n");
        printf("2. Remove email from list\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // add email to list
                printf("Enter email to add: ");
                scanf("%s", email);
                addToList(email);
                printf("Email added to list.\n");
                break;

            case 2: // remove email from list
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeFromList(email);
                printf("Email removed from list.\n");
                break;

            case 3: // print list
                printList();
                break;

            case 4: // exit program
                printf("Exiting program...\n");
                break;

            default: // invalid choice
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while(choice != 4);

    return 0;
}

// adds email to list
void addToList(char email[]) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp->email, email);
    temp->next = NULL;

    if(head == NULL) {
        head = temp;
        tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

// removes email from list
void removeFromList(char email[]) {
    struct node *current = head, *prev = NULL;

    while(current != NULL) {
        if(strcmp(current->email, email) == 0) {
            if(prev == NULL) { // removing the first node
                head = current->next;
                free(current);
            }
            else { // removing a node in the middle or end of list
                prev->next = current->next;
                free(current);
            }
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Email not found in list.\n");
}

// prints all emails in list
void printList() {
    struct node *current = head;

    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Email list:\n");

    while(current != NULL) {
        printf("%s\n", current->email);
        current = current->next;
    }
}