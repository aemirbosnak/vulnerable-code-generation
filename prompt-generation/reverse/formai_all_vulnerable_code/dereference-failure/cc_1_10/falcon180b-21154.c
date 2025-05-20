//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_NAME_LEN];
} contact;

contact *create_contact(char *name, char *email) {
    contact *new_contact = (contact *)malloc(sizeof(contact));
    strncpy(new_contact->name, name, MAX_NAME_LEN);
    strncpy(new_contact->email, email, MAX_NAME_LEN);
    return new_contact;
}

void print_contact(contact *c) {
    printf("Name: %s\nEmail: %s\n", c->name, c->email);
}

int main() {
    contact *contacts[10];
    int num_contacts = 0;

    while(1) {
        printf("1. Add contact\n2. Print contacts\n3. Quit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                char name[MAX_NAME_LEN];
                char email[MAX_NAME_LEN];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter email: ");
                scanf("%s", email);
                contacts[num_contacts] = create_contact(name, email);
                num_contacts++;
                break;
            }
            case 2: {
                for(int i = 0; i < num_contacts; i++) {
                    print_contact(contacts[i]);
                }
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    }

    return 0;
}