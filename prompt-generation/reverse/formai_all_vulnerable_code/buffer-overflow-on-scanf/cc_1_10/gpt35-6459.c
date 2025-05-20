//FormAI DATASET v1.0 Category: Phone Book ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for contact information
typedef struct Contact {
    char name[50];
    char phone_no[15];
    char email[50];
} Contact;

// function to add a new contact in the phone book
void add_contact(Contact **phone_book, int *n) {
    *n += 1;
    *phone_book = realloc(*phone_book, *n * sizeof(Contact));
    printf("\nEnter name: ");
    scanf("%s", (*phone_book)[*n-1].name);
    printf("Enter phone number: ");
    scanf("%s", (*phone_book)[*n-1].phone_no);
    printf("Enter email address: ");
    scanf("%s", (*phone_book)[*n-1].email);
    printf("\nContact has been added successfully!\n");
}

// function to search for a contact by name
void search_contact(Contact *phone_book, int n, char *name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("\nName: %s\n", phone_book[i].name);
            printf("Phone number: %s\n", phone_book[i].phone_no);
            printf("Email address: %s\n", phone_book[i].email);
            return;
        }
    }
    printf("\nContact not found!\n");
}

// function to delete a contact by name
void delete_contact(Contact **phone_book, int *n, char *name) {
    for (int i = 0; i < *n; i++) {
        if (strcmp((*phone_book)[i].name, name) == 0) {
            for (int j = i + 1; j < *n; j++) {
                strcpy((*phone_book)[j-1].name, (*phone_book)[j].name);
                strcpy((*phone_book)[j-1].phone_no, (*phone_book)[j].phone_no);
                strcpy((*phone_book)[j-1].email, (*phone_book)[j].email);
            }
            *n -= 1;
            *phone_book = realloc(*phone_book, *n * sizeof(Contact));
            printf("\nContact has been deleted successfully!\n");
            return;
        }
    }
    printf("\nContact not found!\n");
}

// function to print all contacts in the phone book
void print_contacts(Contact *phone_book, int n) {
    printf("\n-- Phone Book --\n");
    for (int i = 0; i < n; i++) {
        printf("\nName: %s\n", phone_book[i].name);
        printf("Phone number: %s\n", phone_book[i].phone_no);
        printf("Email address: %s\n", phone_book[i].email);
    }
}

// main function
int main() {
    Contact *phone_book = NULL;
    int n = 0;
    
    while (1) {
        printf("\n-- Phone Book Menu --\n");
        printf("1. Add a new contact\n");
        printf("2. Search for a contact\n");
        printf("3. Delete a contact\n");
        printf("4. Print all contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_contact(&phone_book, &n);
                break;
            case 2:
                printf("\nEnter name to search: ");
                char search_name[50];
                scanf("%s", search_name);
                search_contact(phone_book, n, search_name);
                break;
            case 3:
                printf("\nEnter name to delete: ");
                char delete_name[50];
                scanf("%s", delete_name);
                delete_contact(&phone_book, &n, delete_name);
                break;
            case 4:
                print_contacts(phone_book, n);
                break;
            case 5:
                printf("\nExiting phone book!\n");
                free(phone_book);
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}