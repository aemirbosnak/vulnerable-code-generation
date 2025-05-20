//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    char phone[20];
} Contact;

void printMenu() {
    printf("\n************************************\n");
    printf("*** Welcome to C Phone Book! ***\n");
    printf("*** Press 1 to Add Contact ***\n");
    printf("*** Press 2 to Search Contact ***\n");
    printf("*** Press 3 to Display All Contacts ***\n");
    printf("*** Press 4 to Exit ***\n");
    printf("************************************\n");
}

void addContact(Contact contacts[], int *size) {
    if (*size >= 10) {
        printf("Phone Book is Full!\n");
        return;
    }

    printf("Enter Contact Name: ");
    scanf("%s", contacts[*size].name);
    fflush(stdin);

    printf("Enter Contact Phone Number: ");
    scanf("%s", contacts[*size].phone);
    fflush(stdin);

    (*size)++;
}

int searchContact(Contact contacts[], int size, char name[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            printf("\nContact Found!\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            return 1;
        }
    }

    printf("Contact Not Found!\n");
    return 0;
}

void displayAllContacts(Contact contacts[], int size) {
    printf("\nContacts List:\n");

    for (int i = 0; i < size; i++) {
        printf("Name: %s\n", contacts[i].name);
        printf("Phone: %s\n", contacts[i].phone);
        printf("------------------------\n");
    }
}

int main() {
    Contact contacts[10];
    int size = 0;
    int choice;
    char searchName[50];

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact(contacts, &size);
                break;
            case 2:
                printf("Enter Contact Name to Search: ");
                scanf("%s", searchName);
                searchContact(contacts, size, searchName);
                break;
            case 3:
                displayAllContacts(contacts, size);
                break;
            case 4:
                printf("Goodbye! Have a nice day!\n");
                exit(0);
            default:
                printf("Invalid Option!\n");
                break;
        }
    }

    return 0;
}