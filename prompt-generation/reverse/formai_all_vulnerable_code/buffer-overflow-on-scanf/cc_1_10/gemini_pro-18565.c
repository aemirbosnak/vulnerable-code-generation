//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: intelligent
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char *name;
    char *number;
} Contact;

Contact *create_contact(char *name, char *number) {
    Contact *contact = malloc(sizeof(Contact));
    contact->name = strdup(name);
    contact->number = strdup(number);
    return contact;
}

void destroy_contact(Contact *contact) {
    free(contact->name);
    free(contact->number);
    free(contact);
}

int compare_contacts(const Contact *a, const Contact *b) {
    return strcmp(a->name, b->name);
}

void print_contact(const Contact *contact) {
    printf("%s: %s\n", contact->name, contact->number);
}

int main() {
    Contact *contacts[100];
    int num_contacts = 0;

    while (1) {
        printf("1. Add contact\n2. Print contacts\n3. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            {
                char name[100];
                char number[100];

                printf("Enter name: ");
                scanf(" %[^\n]", name);

                printf("Enter number: ");
                scanf(" %[^\n]", number);

                Contact *contact = create_contact(name, number);
                contacts[num_contacts++] = contact;
                break;
            }
            case 2:
            {
                qsort(contacts, num_contacts, sizeof(Contact *), compare_contacts);

                for (int i = 0; i < num_contacts; i++) {
                    print_contact(contacts[i]);
                }
                break;
            }
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}