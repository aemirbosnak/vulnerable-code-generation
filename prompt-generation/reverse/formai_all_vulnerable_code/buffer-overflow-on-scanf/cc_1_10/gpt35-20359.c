//FormAI DATASET v1.0 Category: Phone Book ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char phone[20];
};

void add_contact(struct contact *phone_book, int *num_contacts);
void list_contacts(struct contact *phone_book, int num_contacts);
void search_contacts(struct contact *phone_book, int num_contacts);
void delete_contact(struct contact *phone_book, int *num_contacts);

int main() {
    struct contact phone_book[100];
    int num_contacts = 0;
    int choice;

    do {
        printf("\n\n--- Phone Book ---\n\n");
        printf("1. Add contact\n");
        printf("2. List contacts\n");
        printf("3. Search contacts\n");
        printf("4. Delete contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact(phone_book, &num_contacts);
                break;
            case 2:
                list_contacts(phone_book, num_contacts);
                break;
            case 3:
                search_contacts(phone_book, num_contacts);
                break;
            case 4:
                delete_contact(phone_book, &num_contacts);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void add_contact(struct contact *phone_book, int *num_contacts) {
    if (*num_contacts == 100) {
        printf("Phone book is full.\n");
        return;
    }

    printf("\nEnter name: ");
    scanf("%s", phone_book[*num_contacts].name);
    printf("Enter phone number: ");
    scanf("%s", phone_book[*num_contacts].phone);

    (*num_contacts)++;
    printf("\nContact added successfully!\n");
}

void list_contacts(struct contact *phone_book, int num_contacts) {
    if (num_contacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    printf("\n--- Contact List (%d) ---\n", num_contacts);
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s, Phone: %s\n", phone_book[i].name, phone_book[i].phone);
    }
}

void search_contacts(struct contact *phone_book, int num_contacts) {
    if (num_contacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    char search_name[50];
    int found = 0;

    printf("\nEnter name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(phone_book[i].name, search_name) == 0) {
            printf("\n--- Contact found ---\n");
            printf("Name: %s, Phone: %s\n", phone_book[i].name, phone_book[i].phone);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nContact not found.\n");
    }
}

void delete_contact(struct contact *phone_book, int *num_contacts) {
    if (*num_contacts == 0) {
        printf("Phone book is empty.\n");
        return;
    }

    char delete_name[50];
    int found = 0;
    int index = 0;

    printf("\nEnter name to delete: ");
    scanf("%s", delete_name);

    for (int i = 0; i < *num_contacts; i++) {
        if (strcmp(phone_book[i].name, delete_name) == 0) {
            index = i;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nContact not found.\n");
        return;
    }

    (*num_contacts)--;
    for (int i = index; i < *num_contacts; i++) {
        strcpy(phone_book[i].name, phone_book[i+1].name);
        strcpy(phone_book[i].phone, phone_book[i+1].phone);
    }

    printf("\nContact deleted successfully!\n");
}