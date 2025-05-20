//FormAI DATASET v1.0 Category: Phone Book ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct phonebook {
    char name[30];
    char number[10];
    struct phonebook *next;
};

struct phonebook *add_contact(struct phonebook *head);
void display_contacts(struct phonebook *head);
struct phonebook *delete_contact(struct phonebook *head, char name[]);
struct phonebook *search_contact(struct phonebook *head, char name[]);

int main() {
    struct phonebook *head = NULL;
    char choice;

    do {
        printf("\n\nPhone Book\n\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Delete Contact\n");
        printf("4. Search Contact\n");
        printf("5. Exit\n");

        printf("\nPlease enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                head = add_contact(head);
                break;

            case '2':
                display_contacts(head);
                break;

            case '3': {
                char name[30];
                printf("Please enter the name of the contact you wish to delete: ");
                scanf(" %[^\n]", name);
                head = delete_contact(head, name);
            }
                break;

            case '4': {
                char name[30];
                printf("Please enter the name of the contact you wish to search for: ");
                scanf(" %[^\n]", name);
                struct phonebook *result = search_contact(head, name);
                if(result) {
                    printf("\n%s's number is %s\n", result->name, result->number);
                } else {
                    printf("\nContact not found.\n");
                }
            }
                break;

            case '5':
                printf("\nGoodbye\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != '5');

    return 0;
}

struct phonebook *add_contact(struct phonebook *head) {
    if(head == NULL) {
        head = (struct phonebook *) malloc(sizeof(struct phonebook));
        printf("Please enter the name of the contact: ");
        scanf(" %[^\n]", head->name);
        printf("Please enter the number of the contact: ");
        scanf(" %s", head->number);
        head->next = NULL;
    } else {
        head->next = add_contact(head->next);
    }

    return head;
}

void display_contacts(struct phonebook *head) {
    if(head == NULL) {
        printf("\nPhone book is empty.\n");
    } else {
        printf("\nPhone Book\n\n");
        printf("Name\t\tNumber\n");
        printf("----\t\t------\n");
        while(head != NULL) {
            printf("%s\t\t%s\n", head->name, head->number);
            head = head->next;
        }
    }
}

struct phonebook *delete_contact(struct phonebook *head, char name[]) {
    if(head == NULL) {
        printf("\nContact not found.\n");
    } else if(strcmp(head->name, name) == 0) {
        struct phonebook *temp = head;
        head = head->next;
        free(temp);
        printf("\nContact deleted.\n");
    } else {
        head->next = delete_contact(head->next, name);
    }

    return head;
}

struct phonebook *search_contact(struct phonebook *head, char name[]) {
    if(head == NULL || strcmp(head->name, name) == 0) {
        return head;
    } else {
        return search_contact(head->next, name);
    }
}