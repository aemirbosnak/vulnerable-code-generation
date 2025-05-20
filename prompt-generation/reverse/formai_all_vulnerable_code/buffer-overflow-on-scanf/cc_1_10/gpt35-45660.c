//FormAI DATASET v1.0 Category: Phone Book ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char phone[20];
};

void add_contact(struct contact *book, int *count) {
    printf("\nAdding a new contact:\n");
    printf("Enter the name: ");
    scanf("%s", book[*count].name);
    printf("Enter the phone number: ");
    scanf("%s", book[*count].phone);
    (*count)++;
}

void delete_contact(struct contact *book, int *count) {
    int i;
    char name[50];
    printf("\nDeleting a contact:\n");
    printf("Enter the name of the contact to delete: ");
    scanf("%s", name);
    for (i = 0; i < *count; i++) {
        if (strcmp(name, book[i].name) == 0) {
            (*count)--;
            book[i] = book[*count];
            printf("%s's contact has been deleted.\n", name);
            return;
        }
    }
    printf("Contact not found.\n");
}

void search_contact(struct contact *book, int count) {
    int i;
    char name[50];
    printf("\nSearching for a contact:\n");
    printf("Enter the name of the contact: ");
    scanf("%s", name);
    for (i = 0; i < count; i++) {
        if (strcmp(name, book[i].name) == 0) {
            printf("Name: %s\nPhone: %s\n", book[i].name, book[i].phone);
            return;
        }
    }
    printf("Contact not found.\n");
}

void print_book(struct contact *book, int count) {
    int i;
    printf("\nCurrent phone book:\n");
    for (i = 0; i < count; i++) {
        printf("Name: %s\nPhone: %s\n\n", book[i].name, book[i].phone);
    }
}

int main() {
    struct contact phone_book[100];
    int choice, count = 0;
    printf("Welcome to the C Phone Book!\n");
    do {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a new contact\n");
        printf("2. Delete a contact\n");
        printf("3. Search for a contact\n");
        printf("4. Print the phone book\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact(phone_book, &count);
                break;
            case 2:
                delete_contact(phone_book, &count);
                break;
            case 3:
                search_contact(phone_book, count);
                break;
            case 4:
                print_book(phone_book, count);
                break;
            case 5:
                printf("\nExiting the C Phone Book...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}