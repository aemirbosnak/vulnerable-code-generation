//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000

typedef struct {
    char name[50];
    char phone[15];
} contact;

contact phonebook[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    printf("Enter contact name: ");
    scanf("%s", phonebook[num_contacts].name);
    printf("Enter contact phone number: ");
    scanf("%s", phonebook[num_contacts].phone);
    num_contacts++;
}

void view_contacts() {
    printf("Phone Book:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s - %s\n", phonebook[i].name, phonebook[i].phone);
    }
}

void search_contact() {
    char name[50];
    printf("Enter contact name to search: ");
    scanf("%s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("%s - %s\n", phonebook[i].name, phonebook[i].phone);
        }
    }
}

void delete_contact() {
    char name[50];
    printf("Enter contact name to delete: ");
    scanf("%s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            strcpy(phonebook[i].name, "");
            strcpy(phonebook[i].phone, "");
            printf("%s deleted from phone book.\n", name);
        }
    }
}

int main() {
    printf("Welcome to the Phone Book!\n");
    while (1) {
        printf("\n1. Add contact\n2. View contacts\n3. Search contact\n4. Delete contact\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                view_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                delete_contact();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}