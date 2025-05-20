//FormAI DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[30];
    char phone[20];
    char email[50];
};

void addContact(struct contact* phonebook, int* size) {
    printf("Enter contact name: ");
    scanf("%s", (phonebook + *size)->name);
    printf("Enter contact phone number: ");
    scanf("%s", (phonebook + *size)->phone);
    printf("Enter contact email: ");
    scanf("%s", (phonebook + *size)->email);

    printf("Contact successfully added!\n\n");
    
    (*size)++;
}

void displayContacts(struct contact* phonebook, int size) {
    if (size == 0) {
        printf("No contacts found!\n\n");
        return;
    }

    printf("Contacts in phonebook:\n");
    printf("---------------------\n");

    for (int i = 0; i < size; i++) {
        printf("Name: %s\n", (phonebook + i)->name);
        printf("Phone: %s\n", (phonebook + i)->phone);
        printf("Email: %s\n", (phonebook + i)->email);
        printf("\n");
    }
}

void searchContact(struct contact* phonebook, int size) {
    if (size == 0) {
        printf("No contacts found!\n\n");
        return;
    }

    char search[30];
    printf("Enter name to search: ");
    scanf("%s", search);

    for (int i = 0; i < size; i++) {
        if (strcmp((phonebook + i)->name, search) == 0) {
            printf("Contact found!\n");
            printf("Name: %s\n", (phonebook + i)->name);
            printf("Phone: %s\n", (phonebook + i)->phone);
            printf("Email: %s\n", (phonebook + i)->email);
            printf("\n");

            return;
        }
    }

    printf("Contact not found!\n\n");
}

void deleteContact(struct contact* phonebook, int* size) {
    if (*size == 0) {
        printf("No contacts found!\n\n");
        return;
    }

    char search[30];
    printf("Enter name to delete: ");
    scanf("%s", search);

    for (int i = 0; i < *size; i++) {
        if (strcmp((phonebook + i)->name, search) == 0) {
            // move all contacts after the deleted contact up by one
            for (int j = i; j < (*size - 1); j++) {
                strcpy((phonebook + j)->name, (phonebook + j + 1)->name);
                strcpy((phonebook + j)->phone, (phonebook + j + 1)->phone);
                strcpy((phonebook + j)->email, (phonebook + j + 1)->email);
            }

            memset((phonebook + (*size - 1))->name, '\0', sizeof((phonebook + (*size - 1))->name));
            memset((phonebook + (*size - 1))->phone, '\0', sizeof((phonebook + (*size - 1))->phone));
            memset((phonebook + (*size - 1))->email, '\0', sizeof((phonebook + (*size - 1))->email));

            (*size)--;

            printf("Contact successfully deleted!\n\n");
            return;
        }
    }

    printf("Contact not found!\n\n");
}

int main() {
    struct contact phonebook[100];
    int size = 0;
    int choice = 0;

    printf("================ C PHONEBOOK ================\n\n");

    do {
        printf("Choose from the following options:\n");
        printf("1. Add contact\n");
        printf("2. Display contacts\n");
        printf("3. Search contact\n");
        printf("4. Delete contact\n");
        printf("5. Exit\n");

        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                addContact(phonebook, &size);
                break;
            case 2:
                displayContacts(phonebook, size);
                break;
            case 3:
                searchContact(phonebook, size);
                break;
            case 4:
                deleteContact(phonebook, &size);
                break;
            case 5:
                printf("Closing phonebook...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    } while (choice != 5);

    return 0;
}