//FormAI DATASET v1.0 Category: Phone Book ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Contact {
    char name[50];
    char phone[15];
} Contact;

void display_menu() {
    printf("\n");
    printf("*************************************\n");
    printf("*** C PHONE BOOK RETRO STYLE 1.0 ***\n");
    printf("*************************************\n");
    printf("1. Add Contact\n");
    printf("2. Update Contact\n");
    printf("3. Delete Contact\n");
    printf("4. Search Contacts\n");
    printf("5. Display All Contacts\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void add_contact(Contact* phonebook, int* num) {
    printf("\n");
    printf("Enter name: ");
    scanf(" %[^\n]s", phonebook[*num].name);
    printf("Enter phone number: ");
    scanf(" %[^\n]s", phonebook[*num].phone);
    printf("Contact added successfully!\n");
    (*num)++;
}

void update_contact(Contact* phonebook, int num) {
    printf("\n");
    char name[50];
    printf("Enter the name of the contact you want to update: ");
    scanf(" %[^\n]s", name);
    int i;
    for (i = 0; i < num; i++) {
        if (strcmp(name, phonebook[i].name) == 0) {
            printf("Enter new name: ");
            scanf(" %[^\n]s", phonebook[i].name);
            printf("Enter new phone number: ");
            scanf(" %[^\n]s", phonebook[i].phone);
            printf("Contact updated successfully!\n");
            return;
        }
    }
    printf("Contact not found!\n");
}

void delete_contact(Contact* phonebook, int* num) {
    printf("\n");
    char name[50];
    printf("Enter the name of the contact you want to delete: ");
    scanf(" %[^\n]s", name);
    int i;
    for (i = 0; i < *num; i++) {
        if (strcmp(name, phonebook[i].name) == 0) {
            int j;
            for (j = i; j < (*num)-1; j++) {
                phonebook[j] = phonebook[j+1];
            }
            printf("Contact deleted successfully!\n");
            (*num)--;
            return;
        }
    }
    printf("Contact not found!\n");
}

void search_contact(Contact* phonebook, int num) {
    printf("\n");
    char name[50];
    printf("Enter the name of the contact you want to search: ");
    scanf(" %[^\n]s", name);
    int i;
    for (i = 0; i < num; i++) {
        if (strstr(phonebook[i].name, name) != NULL) {
            printf("%s\t\t%s\n", phonebook[i].name, phonebook[i].phone);
        }
    }
}

void display_contacts(Contact* phonebook, int num) {
    printf("\n");
    if (num == 0) {
        printf("No contacts to display!\n");
        return;
    }
    printf("Name\t\tPhone\n");
    printf("----\t\t-----\n");
    int i;
    for (i = 0; i < num; i++) {
        printf("%s\t\t%s\n", phonebook[i].name, phonebook[i].phone);
    }
}

int main() {
    Contact phonebook[MAX];
    int num = 0; // number of contacts in phonebook
    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact(phonebook, &num);
                break;
            case 2:
                update_contact(phonebook, num);
                break;
            case 3:
                delete_contact(phonebook, &num);
                break;
            case 4:
                search_contact(phonebook, num);
                break;
            case 5:
                display_contacts(phonebook, num);
                break;
            case 6:
                printf("\nExiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice, please try again!\n");
        }
    }
    return 0;
}