//FormAI DATASET v1.0 Category: Phone Book ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contact {
    char name[50];
    char phone[20];
} Contact;

void add_contact(Contact* phone_book, int* count);
void remove_contact(Contact* phone_book, int* count);
void search_contact(Contact* phone_book, int count);
void print_phonebook(Contact* phone_book, int count);

int main() {
    Contact phone_book[100];
    int count = 0;
    int option;

    printf("Welcome to your C Phone Book!\n\n");

    do {
        printf("What would you like to do?\n");
        printf("1. Add a contact\n");
        printf("2. Remove a contact\n");
        printf("3. Search for a contact\n");
        printf("4. Print phone book\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_contact(phone_book, &count);
                break;
            case 2:
                remove_contact(phone_book, &count);
                break;
            case 3:
                search_contact(phone_book, count);
                break;
            case 4:
                print_phonebook(phone_book, count);
                break;
            case 5:
                printf("Thank you for using C Phone Book. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select an option from 1-5.\n");
        }
        printf("\n");
    } while (option != 5);

    return 0;
}

void add_contact(Contact* phone_book, int* count) {
    char name[50], phone[20];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter phone number: ");
    scanf("%s", phone);
    strcpy(phone_book[*count].name, name);
    strcpy(phone_book[*count].phone, phone);
    (*count)++;
    printf("Contact added successfully!\n");
}

void remove_contact(Contact* phone_book, int* count) {
    char name[50];
    int i, j, found = 0;
    printf("Enter name of contact to remove: ");
    scanf("%s", name);
    for (i = 0; i < *count; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            found = 1;
            for (j = i; j < *count - 1; j++) {
                strcpy(phone_book[j].name, phone_book[j+1].name);
                strcpy(phone_book[j].phone, phone_book[j+1].phone);
            }
            (*count)--;
            printf("Contact removed successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("No contact found with name %s.\n", name);
    }
}

void search_contact(Contact* phone_book, int count) {
    char name[50];
    int i, found = 0;
    printf("Enter name to search for: ");
    scanf("%s", name);
    for (i = 0; i < count; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            found = 1;
            printf("Contact details:\n");
            printf("Name: %s\n", phone_book[i].name);
            printf("Phone: %s\n", phone_book[i].phone);
            break;
        }
    }
    if (!found) {
        printf("No contact found with name %s.\n", name);
    }
}

void print_phonebook(Contact* phone_book, int count) {
    int i;
    printf("Phone book:\n");
    printf("Name\t\tPhone\n");
    for (i = 0; i < count; i++) {
        printf("%-15s%-15s\n", phone_book[i].name, phone_book[i].phone);
    }
}