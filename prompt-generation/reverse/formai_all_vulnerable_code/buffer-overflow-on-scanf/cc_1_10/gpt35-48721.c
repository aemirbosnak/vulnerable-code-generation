//FormAI DATASET v1.0 Category: Phone Book ; Style: complete
#include <stdio.h>
#include <string.h>
#define MAX_CONTACTS 100

struct Contact {
    char name[50], phone_number[12], email[50];
};

void add_contact(struct Contact phone_book[], int *num_of_contacts);
void display_contacts(struct Contact phone_book[], int num_of_contacts);
void search_contact(struct Contact phone_book[], int num_of_contacts);

int main() {
    struct Contact phone_book[MAX_CONTACTS];
    int num_of_contacts = 0, choice;
    do {
        printf("--------Phone Book--------\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact(phone_book, &num_of_contacts);
                break;
            case 2:
                display_contacts(phone_book, num_of_contacts);
                break;
            case 3:
                search_contact(phone_book, num_of_contacts);
                break;
            case 4:
                printf("Exiting Phone Book...Thank You!\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while (choice != 4);

    return 0;
}

void add_contact(struct Contact phone_book[], int *num_of_contacts) {
    if (*num_of_contacts >= MAX_CONTACTS) {
        printf("Sorry! Maximum number of Contacts reached.\n");
        return;
    }

    printf("Enter Contact Name: ");
    scanf(" %[^\n]s", phone_book[*num_of_contacts].name);
    printf("Enter Phone Number: ");
    scanf(" %s", phone_book[*num_of_contacts].phone_number);
    printf("Enter Email: ");
    scanf(" %s", phone_book[*num_of_contacts].email);
    (*num_of_contacts)++;
    printf("Contact Added Successfully!\n");
}

void display_contacts(struct Contact phone_book[], int num_of_contacts) {
    if (num_of_contacts == 0) {
        printf("No Contacts found!\n");
        return;
    }

    printf("--------List of Contacts--------\n");
    for (int i = 0; i < num_of_contacts; i++) {
        printf("Contact #%d\n", i+1);
        printf("Name: %s\n", phone_book[i].name);
        printf("Phone Number: %s\n", phone_book[i].phone_number);
        printf("Email: %s\n", phone_book[i].email);
    }
}

void search_contact(struct Contact phone_book[], int num_of_contacts) {
    if (num_of_contacts == 0) {
        printf("No Contacts found!\n");
        return;
    }

    char search_term[50];
    printf("Enter Contact Name or Phone Number to Search: ");
    scanf(" %[^\n]s", search_term);

    printf("--------Search Results--------\n");
    for (int i = 0; i < num_of_contacts; i++) {
        if (strstr(phone_book[i].name, search_term) != NULL ||
            strstr(phone_book[i].phone_number, search_term) != NULL) {

            printf("Name: %s\n", phone_book[i].name);
            printf("Phone Number: %s\n", phone_book[i].phone_number);
            printf("Email: %s\n", phone_book[i].email);
        }
    }
}