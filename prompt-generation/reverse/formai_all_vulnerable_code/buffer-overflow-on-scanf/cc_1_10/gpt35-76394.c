//FormAI DATASET v1.0 Category: Mailing list manager ; Style: retro
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct MailingList {
    char name[100];
    char emailAddress[100];
    struct MailingList *next;
};

void addContact(struct MailingList **head, char name[], char emailAddress[]) {
    struct MailingList *newNode = (struct MailingList*) malloc(sizeof(struct MailingList));
    strcpy(newNode->name, name);
    strcpy(newNode->emailAddress, emailAddress);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct MailingList *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void printList(struct MailingList *head) {
    if (head == NULL) {
        printf("\nThe list is empty\n");
        return;
    }

    printf("\nName\tEmail Address\n");
    printf("-------------------------------------\n");
    while (head != NULL) {
        printf("%s\t%s\n", head->name, head->emailAddress);
        head = head->next;
    }
}

void searchContact(struct MailingList *head, char name[]) {
    if (head == NULL) {
        printf("\nThe list is empty\n");
        return;
    }

    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            printf("\nName\tEmail Address\n");
            printf("-----------------------------------\n");
            printf("%s\t%s\n", head->name, head->emailAddress);
            return;
        }
        head = head->next;
    }
    printf("\nNo contact found with the name %s", name);
}

void deleteContact(struct MailingList **head, char name[]) {
    if (*head == NULL) {
        printf("\nThe list is empty\n");
        return;
    }

    struct MailingList *temp = *head;
    struct MailingList *prev = NULL;

    if (strcmp(temp->name, name) == 0) {
        *head = temp->next;
        free(temp);
        printf("\nContact deleted successfully");
        return;
    }

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nNo contact found with the name %s", name);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("\nContact deleted successfully");
}

int main() {
    int choice;
    char name[100], emailAddress[100];
    struct MailingList *head = NULL;

    while (1) {
        printf("\n*********Mailing List Manager*********\n");
        printf("\n1.Add Contact\n2.Display Contacts\n3.Search Contact\n4.Delete Contact\n5.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the name: ");
                scanf("%s", name);
                printf("\nEnter the email address: ");
                scanf("%s", emailAddress);
                addContact(&head, name, emailAddress);
                printf("\nContact added successfully!");
                break;

            case 2:
                printList(head);
                break;

            case 3:
                printf("\nEnter the name to search: ");
                scanf("%s", name);
                searchContact(head, name);
                break;

            case 4:
                printf("\nEnter the name to delete: ");
                scanf("%s", name);
                deleteContact(&head, name);
                break;

            case 5:
                printf("\nExiting the program");
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.");
        }
    }

    return 0;
}