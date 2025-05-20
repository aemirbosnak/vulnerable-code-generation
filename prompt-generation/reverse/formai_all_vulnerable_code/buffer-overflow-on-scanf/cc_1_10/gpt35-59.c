//FormAI DATASET v1.0 Category: Mailing list manager ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char email[50];
    struct node* next;
};

struct node* head = NULL;

void addToList(char* email)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->email, email);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        return;
    }

    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void removeFromList(char* email)
{
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = head;

    // If the head needs to be removed
    if (strcmp(head->email, email) == 0) {
        head = head->next;
        free(temp);
        printf("%s removed from the list\n", email);
        return;
    }

    while (temp->next != NULL) {
        if (strcmp(temp->next->email, email) == 0) {
            struct node* remove_node = temp->next;
            temp->next = temp->next->next;
            free(remove_node);
            printf("%s removed from the list\n", email);
            return;
        }
        temp = temp->next;
    }

    printf("%s not found in the list\n", email);
}

void displayList()
{
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("Mailing list:\n");
    struct node* temp = head;
    while (temp != NULL) {
        printf("%s\n", temp->email);
        temp = temp->next;
    }
}

int main()
{
    int choice;
    char email[50];

    do {
        printf("\n1. Add email to list\n2. Remove email from list\n3. Display list\n4. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nEnter the email to add: ");
            scanf("%s", email);
            addToList(email);
            break;

        case 2:
            printf("\nEnter the email to remove: ");
            scanf("%s", email);
            removeFromList(email);
            break;

        case 3:
            displayList();
            break;

        case 4:
            printf("\nExiting the program...\n");
            exit(0);
            break;

        default:
            printf("\nInvalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}