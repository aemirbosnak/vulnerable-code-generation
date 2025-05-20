//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000

typedef struct contact {
    char name[50];
    char phone_number[15];
} contact_t;

contact_t phone_book[MAX_CONTACTS];
int num_contacts = 0;

void add_contact() {
    printf("Enter name: ");
    scanf("%s", phone_book[num_contacts].name);
    printf("Enter phone number: ");
    scanf("%s", phone_book[num_contacts].phone_number);
    num_contacts++;
}

void delete_contact() {
    int index;
    printf("Enter index of contact to delete: ");
    scanf("%d", &index);
    if (index >= 0 && index < num_contacts) {
        for (int i = index; i < num_contacts - 1; i++) {
            strcpy(phone_book[i].name, phone_book[i + 1].name);
            strcpy(phone_book[i].phone_number, phone_book[i + 1].phone_number);
        }
        num_contacts--;
    } else {
        printf("Invalid index\n");
    }
}

void search_contact() {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, name) == 0) {
            printf("Name: %s\nPhone number: %s\n", phone_book[i].name, phone_book[i].phone_number);
        }
    }
}

void print_all_contacts() {
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\nPhone number: %s\n", phone_book[i].name, phone_book[i].phone_number);
    }
}

int main() {
    int choice;
    do {
        printf("\nPhone Book\n");
        printf("1. Add contact\n");
        printf("2. Delete contact\n");
        printf("3. Search contact\n");
        printf("4. Print all contacts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_contact();
            break;
        case 2:
            delete_contact();
            break;
        case 3:
            search_contact();
            break;
        case 4:
            print_all_contacts();
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice!= 5);
    return 0;
}