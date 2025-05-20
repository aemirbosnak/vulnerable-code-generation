//FormAI DATASET v1.0 Category: Mailing list manager ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100
#define MAX_LIST_SIZE 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact_t;

typedef struct {
    contact_t* list[MAX_LIST_SIZE];
    int size;
} mailing_list_t;

mailing_list_t* create_list() {
    mailing_list_t* list = malloc(sizeof(mailing_list_t));
    list->size = 0;
    return list;
}

void add_contact(mailing_list_t* list, char* name, char* email) {
    if(list->size >= MAX_LIST_SIZE) {
        printf("Error: Mailing list is full. Cannot add contact.\n");
        return;
    }
    contact_t* contact = malloc(sizeof(contact_t));
    strcpy(contact->name, name);
    strcpy(contact->email, email);
    list->list[list->size++] = contact;
    printf("Contact added successfully.\n");
}

void delete_contact(mailing_list_t* list, int index) {
    if(index < 0 || index >= list->size) {
        printf("Error: Invalid index.\n");
        return;
    }
    free(list->list[index]);
    for(int i=index+1; i<list->size; i++) {
        list->list[i-1] = list->list[i];
    }
    list->size--;
    printf("Contact deleted successfully.\n");
}

void print_list(mailing_list_t* list) {
    printf("Mailing List:\n");
    for(int i=0; i<list->size; i++) {
        printf("%d: %s (%s)\n", i, list->list[i]->name, list->list[i]->email);
    }
}

int main() {
    mailing_list_t* list = create_list();
    int choice, index;
    char name[MAX_NAME_LENGTH], email[MAX_EMAIL_LENGTH];

    do {
        printf("\n-- Mailing List Manager --\n");
        printf("1. Add a contact\n");
        printf("2. Delete a contact\n");
        printf("3. Print the list\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter contact name: ");
                scanf("%s", name);
                printf("Enter contact email: ");
                scanf("%s", email);
                add_contact(list, name, email);
                break;
            case 2:
                printf("Enter index of contact to delete: ");
                scanf("%d", &index);
                delete_contact(list, index);
                break;
            case 3:
                print_list(list);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    } while(choice != 4);

    return 0;
}