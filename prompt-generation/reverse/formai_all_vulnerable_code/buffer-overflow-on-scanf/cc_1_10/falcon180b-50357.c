//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

void add_contact(contact *list, int size, char *name, char *email) {
    if (size == 0) {
        printf("Error: List is full.\n");
        return;
    }

    strcpy(list[size-1].name, name);
    strcpy(list[size-1].email, email);

    printf("Contact added successfully.\n");
}

void delete_contact(contact *list, int size, char *email) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(list[i].email, email) == 0) {
            memmove(&list[i], &list[i+1], (size-i-1)*sizeof(contact));
            size--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

void print_contacts(contact *list, int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("Name: %s\nEmail: %s\n", list[i].name, list[i].email);
    }
}

int main() {
    contact list[10];
    int size = 0;

    while (1) {
        printf("1. Add contact\n2. Delete contact\n3. Print contacts\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    char name[MAX_NAME_LEN], email[MAX_EMAIL_LEN];
                    printf("Enter name: ");
                    scanf("%s", name);
                    printf("Enter email: ");
                    scanf("%s", email);

                    add_contact(list, size, name, email);
                    break;
                }

            case 2:
                {
                    char email[MAX_EMAIL_LEN];
                    printf("Enter email to delete: ");
                    scanf("%s", email);

                    delete_contact(list, size, email);
                    break;
                }

            case 3:
                {
                    print_contacts(list, size);
                    break;
                }

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}