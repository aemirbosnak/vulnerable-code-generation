//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char phone[20];
} Contact;

void print_menu() {
    printf("\n************ RETRO PHONEBOOK ************\n");
    printf("1. Add Contact\n");
    printf("2. Delete Contact\n");
    printf("3. Search Contact\n");
    printf("4. Display All Contacts\n");
    printf("5. Quit\n");
}

void add_contact(Contact contacts[], int *size) {
    if (*size == 10) {
        printf("\nPhonebook is full!\n");
        return;
    }

    printf("\nEnter Contact Name: ");
    scanf("%s", contacts[*size].name);
    printf("Enter Contact Phone Number: ");
    scanf("%s", contacts[*size].phone);

    (*size)++;
}

void delete_contact(Contact contacts[], int *size, char name[]) {
    int index = -1;

    for (int i = 0; i < *size; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("\nContact not found!\n");
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        contacts[i] = contacts[i + 1];
    }

    (*size)--;
}

void search_contact(Contact contacts[], int size, char name[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("\nName: %s\nPhone: %s\n", contacts[i].name, contacts[i].phone);
            return;
        }
    }

    printf("\nContact not found!\n");
}

void display_contacts(Contact contacts[], int size) {
    printf("\n************ RETRO PHONEBOOK ************\n");
    printf("Name\tPhone\n");

    for (int i = 0; i < size; i++) {
        printf("%s\t%s\n", contacts[i].name, contacts[i].phone);
    }
}

int main() {
    Contact phonebook[10];
    int size = 0;
    char choice, name[50], search_name[50];

    do {
        print_menu();
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                add_contact(phonebook, &size);
                break;
            case '2':
                printf("Enter Contact Name to Delete: ");
                scanf("%s", name);
                delete_contact(phonebook, &size, name);
                break;
            case '3':
                printf("Enter Contact Name to Search: ");
                scanf("%s", search_name);
                search_contact(phonebook, size, search_name);
                break;
            case '4':
                display_contacts(phonebook, size);
                break;
            case '5':
                printf("\nThanks for using Retro Phonebook! Bye.\n");
                break;
            default:
                printf("\nInvalid option! Please try again.\n");
        }
    } while (choice != '5');

    return 0;
}