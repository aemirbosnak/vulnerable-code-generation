//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIST_SIZE 100
#define MAX_NAME_SIZE 50
#define MAX_EMAIL_SIZE 100

typedef struct {
    char name[MAX_NAME_SIZE];
    char email[MAX_EMAIL_SIZE];
} contact;

contact mailing_list[MAX_LIST_SIZE];
int list_size = 0;

void add_contact() {
    if (list_size >= MAX_LIST_SIZE) {
        printf("Error: Mailing list is full.\n");
        return;
    }

    printf("Enter contact name: ");
    scanf("%s", mailing_list[list_size].name);

    printf("Enter contact email: ");
    scanf("%s", mailing_list[list_size].email);

    list_size++;
    printf("Contact added successfully.\n");
}

void remove_contact() {
    if (list_size == 0) {
        printf("Error: Mailing list is empty.\n");
        return;
    }

    printf("Enter contact email to remove: ");
    scanf("%s", mailing_list[list_size-1].email);

    list_size--;
    printf("Contact removed successfully.\n");
}

void display_contacts() {
    printf("Mailing List:\n");
    for (int i = 0; i < list_size; i++) {
        printf("%s - %s\n", mailing_list[i].name, mailing_list[i].email);
    }
}

void sort_contacts() {
    for (int i = 0; i < list_size-1; i++) {
        for (int j = i+1; j < list_size; j++) {
            if (strcmp(mailing_list[i].name, mailing_list[j].name) > 0) {
                contact temp = mailing_list[i];
                mailing_list[i] = mailing_list[j];
                mailing_list[j] = temp;
            }
        }
    }
}

int main() {
    int choice;

    do {
        printf("1. Add contact\n2. Remove contact\n3. Display contacts\n4. Sort contacts\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                remove_contact();
                break;
            case 3:
                display_contacts();
                break;
            case 4:
                sort_contacts();
                display_contacts();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 5);

    return 0;
}