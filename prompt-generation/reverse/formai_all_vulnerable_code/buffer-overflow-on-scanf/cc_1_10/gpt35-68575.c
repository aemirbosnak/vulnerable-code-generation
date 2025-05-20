//FormAI DATASET v1.0 Category: Phone Book ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for contact information
typedef struct Contact {
    char name[100];
    char phone[20];
    char address[200];
} Contact;

// Define a function to add a contact to the phone book
void add_contact(Contact* phone_book, int* count) {
    printf("Enter the name: ");
    scanf("%s", phone_book[*count].name);
    printf("Enter the phone: ");
    scanf("%s", phone_book[*count].phone);
    printf("Enter the address: ");
    scanf("%s", phone_book[*count].address);
    (*count)++;
    printf("Contact added successfully!\n");
}

// Define a function to search for a contact in the phone book
void search_contact(Contact* phone_book, int count) {
    printf("Enter the name to search for: ");
    char name_search[100];
    scanf("%s", name_search);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(phone_book[i].name, name_search) == 0) {
            printf("Contact found!\nName: %s\nPhone: %s\nAddress: %s\n", 
                    phone_book[i].name, phone_book[i].phone, phone_book[i].address);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    Contact phone_book[100];
    int count = 0;
    int option;
    do {
        printf("\n1. Add a contact\n");
        printf("2. Search for a contact\n");
        printf("3. Exit\n");
        printf("Enter an option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_contact(phone_book, &count);
                break;
            case 2:
                search_contact(phone_book, count);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 3);
    return 0;
}