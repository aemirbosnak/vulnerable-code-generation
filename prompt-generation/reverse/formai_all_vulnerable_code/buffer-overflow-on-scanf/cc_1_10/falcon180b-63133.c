//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

struct contact {
    char name[50];
    char phone[20];
};

struct contact phonebook[MAX_SIZE];
int count = 0;

void add_contact() {
    if (count >= MAX_SIZE) {
        printf("Phonebook is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", phonebook[count].name);

    printf("Enter phone number: ");
    scanf("%s", phonebook[count].phone);

    count++;
}

void view_contacts() {
    printf("\nPhonebook:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", phonebook[i].name, phonebook[i].phone);
    }
}

void search_contact() {
    char search_name[50];
    printf("Enter name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < count; i++) {
        if (strcmp(search_name, phonebook[i].name) == 0) {
            printf("%s - %s\n", phonebook[i].name, phonebook[i].phone);
        }
    }
}

void delete_contact() {
    char delete_name[50];
    printf("Enter name to delete: ");
    scanf("%s", delete_name);

    for (int i = 0; i < count; i++) {
        if (strcmp(delete_name, phonebook[i].name) == 0) {
            strcpy(phonebook[i].name, "");
            strcpy(phonebook[i].phone, "");
            printf("%s deleted.\n", delete_name);
            return;
        }
    }

    printf("%s not found.\n", delete_name);
}

int main() {
    int choice;

    do {
        printf("\n1. Add contact\n2. View contacts\n3. Search contact\n4. Delete contact\n5. Exit\n");
        printf("Enter your choice: ");
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
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}