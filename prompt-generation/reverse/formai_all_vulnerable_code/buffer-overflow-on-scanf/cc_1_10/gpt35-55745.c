//FormAI DATASET v1.0 Category: Mailing list manager ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LENGTH 20
#define MAX_EMAIL_LENGTH 50

struct Node {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    struct Node* next;
};

struct List {
    struct Node* head;
};

void add_email(struct List* list, char* name, char* email) {
    struct Node* newEmail = calloc(1, sizeof(struct Node));
    strncpy(newEmail->name, name, MAX_NAME_LENGTH);
    strncpy(newEmail->email, email, MAX_EMAIL_LENGTH);
    if (list->head == NULL) {
        list->head = newEmail;
    }
    else {
        struct Node* temp = list->head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newEmail;
    }
}

void display_emails(struct List* list) {
    if (list->head == NULL) {
        printf("The list is empty.\n");
    }
    else {
        struct Node* temp = list->head;
        while(temp != NULL) {
            printf("%s: %s\n", temp->name, temp->email);
            temp = temp->next;
        }
    }
}

void delete_email(struct List* list, char* email) {
    if (list->head == NULL) {
        printf("The list is empty.\n");
    }
    else if (strcmp(list->head->email, email) == 0) {
        struct Node* oldEmail = list->head;
        list->head = oldEmail->next;
        free(oldEmail);
    }
    else {
        struct Node* temp = list->head;
        while(temp->next != NULL && strcmp(temp->next->email, email) != 0) {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            printf("Email not found.\n");
        }
        else {
            struct Node* oldEmail = temp->next;
            temp->next = oldEmail->next;
            free(oldEmail);
        }
    }
}

int main() {
    struct List emailList = {NULL};
    char choice;
    char name[MAX_NAME_LENGTH], email[MAX_EMAIL_LENGTH];
    do {
        printf("Enter 'a' to add an email, 'd' to delete an email, 's' to show the list, or 'q' to quit.\n");
        scanf(" %c", &choice);
        switch (choice) {
            case 'a':
                printf("Enter the name: ");
                scanf(" %s", name);
                printf("Enter the email: ");
                scanf(" %s", email);
                add_email(&emailList, name, email);
                break;
            case 'd':
                printf("Enter the email to delete: ");
                scanf(" %s", email);
                delete_email(&emailList, email);
                break;
            case 's':
                display_emails(&emailList);
                break;
            case 'q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 'q');

    return 0;
}