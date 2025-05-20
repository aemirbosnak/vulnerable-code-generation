//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100
#define MAX_EMAIL_SIZE 100

typedef struct {
    char name[MAX_EMAIL_SIZE];
    char email[MAX_EMAIL_SIZE];
} contact;

contact mailing_list[MAX_LIST_SIZE];
int mailing_list_size = 0;

void add_contact(char* name, char* email) {
    if (mailing_list_size >= MAX_LIST_SIZE) {
        printf("Error: Mailing list is full.\n");
        return;
    }

    strncpy(mailing_list[mailing_list_size].name, name, MAX_EMAIL_SIZE);
    strncpy(mailing_list[mailing_list_size].email, email, MAX_EMAIL_SIZE);

    mailing_list_size++;
}

void remove_contact(char* email) {
    int i;

    for (i = 0; i < mailing_list_size; i++) {
        if (strcmp(mailing_list[i].email, email) == 0) {
            strcpy(mailing_list[i].name, "");
            strcpy(mailing_list[i].email, "");

            mailing_list_size--;

            return;
        }
    }

    printf("Error: Contact not found.\n");
}

void print_contact(int index) {
    if (index >= 0 && index < mailing_list_size) {
        printf("Name: %s\nEmail: %s\n", mailing_list[index].name, mailing_list[index].email);
    } else {
        printf("Error: Invalid contact index.\n");
    }
}

void print_contacts() {
    int i;

    for (i = 0; i < mailing_list_size; i++) {
        print_contact(i);
    }
}

int main() {
    int choice;

    do {
        printf("\nMailing List Manager\n");
        printf("1. Add contact\n2. Remove contact\n3. Print contacts\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", mailing_list[mailing_list_size - 1].name);
                printf("Enter email: ");
                scanf("%s", mailing_list[mailing_list_size - 1].email);
                break;

            case 2:
                printf("Enter email to remove: ");
                scanf("%s", mailing_list[mailing_list_size - 1].email);
                break;

            case 3:
                print_contacts();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}