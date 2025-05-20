//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char name[50];
    char email[100];
} contact;

void add_contact(contact *list, int size, char *name, char *email) {
    if (size >= MAX_SIZE) {
        printf("Error: Contact list is full.\n");
        return;
    }

    strcpy(list[size].name, name);
    strcpy(list[size].email, email);

    printf("Contact added successfully.\n");
}

void delete_contact(contact *list, int size, char *email) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(list[i].email, email) == 0) {
            strcpy(list[i].name, "");
            strcpy(list[i].email, "");

            printf("Contact deleted successfully.\n");
            return;
        }
    }

    printf("Contact not found.\n");
}

void display_contacts(contact *list, int size) {
    int i;

    for (i = 0; i < size; i++) {
        if (strcmp(list[i].name, "")!= 0 && strcmp(list[i].email, "")!= 0) {
            printf("%s - %s\n", list[i].name, list[i].email);
        }
    }
}

int main() {
    contact list[MAX_SIZE];
    int size = 0;

    while (1) {
        printf("\n1. Add contact\n2. Delete contact\n3. Display contacts\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &size);

        switch (size) {
            case 1: {
                char name[50], email[100];

                printf("Enter name: ");
                scanf("%s", name);

                printf("Enter email: ");
                scanf("%s", email);

                add_contact(list, size, name, email);
                break;
            }

            case 2: {
                char email[100];

                printf("Enter email: ");
                scanf("%s", email);

                delete_contact(list, size, email);
                break;
            }

            case 3: {
                display_contacts(list, size);
                break;
            }

            case 4: {
                exit(0);
            }

            default: {
                printf("Invalid choice.\n");
            }
        }
    }

    return 0;
}