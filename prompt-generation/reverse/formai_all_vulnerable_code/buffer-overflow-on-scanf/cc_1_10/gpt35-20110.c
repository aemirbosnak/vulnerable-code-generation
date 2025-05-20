//FormAI DATASET v1.0 Category: Phone Book ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[50];
    char number[20];
} Contact;

void display_menu();
void add_contact(Contact phonebook[], int *count);
void search_contact(Contact phonebook[], int count);
void remove_contact(Contact phonebook[], int *count);
void display_all_contacts(Contact phonebook[], int count);

int main() {
    Contact phonebook[MAX_SIZE];
    int option, count = 0;

    printf("*** Welcome to the C Phone Book ***\n");

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_contact(phonebook, &count);
                printf("Contact added successfully!\n");
                break;
            case 2:
                search_contact(phonebook, count);
                break;
            case 3:
                remove_contact(phonebook, &count);
                break;
            case 4:
                display_all_contacts(phonebook, count);
                break;
            case 5:
                printf("Thank you for using C Phone Book!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while(option != 5);

    return 0;
}

void display_menu() {
    printf("\n=== Menu ===\n");
    printf("1. Add Contact\n");
    printf("2. Search Contact\n");
    printf("3. Remove Contact\n");
    printf("4. Display All Contacts\n");
    printf("5. Quit\n");
}

void add_contact(Contact phonebook[], int *count) {
    if (*count == MAX_SIZE) {
        printf("Phone book is full. Cannot add new contact.\n");
        return;
    }

    Contact new_contact;
    printf("Enter name: ");
    scanf("%s", new_contact.name);

    printf("Enter number: ");
    scanf("%s", new_contact.number);

    phonebook[*count] = new_contact;
    (*count)++;
}

void search_contact(Contact phonebook[], int count) {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Number: %s\n", phonebook[i].number);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void remove_contact(Contact phonebook[], int *count) {
    char name[50];
    printf("Enter name to remove: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            // shift all elements to the left to remove the contact
            for (int j = i; j < *count - 1; j++) {
                phonebook[j] = phonebook[j+1];
            }
            (*count)--;
            found = 1;
            printf("Contact removed successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("Contact not found.\n");
    }
}

void display_all_contacts(Contact phonebook[], int count) {
    if (count == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("=== All Contacts ===\n");

    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", phonebook[i].name);
        printf("Number: %s\n", phonebook[i].number);
        printf("\n");
    }
}