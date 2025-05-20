//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20
#define MAX_ADDRESS_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char address[MAX_ADDRESS_LEN];
} Contact;

void print_contact(Contact *c) {
    printf("Name: %s\n", c->name);
    printf("Phone: %s\n", c->phone);
    printf("Address: %s\n", c->address);
}

int main() {
    Contact *contacts = NULL;
    int num_contacts = 0;

    while(1) {
        printf("Enter 1 to add a contact, 2 to search for a contact, 3 to exit: ");
        int choice;
        scanf("%d", &choice);

        if(choice == 1) {
            Contact *new_contact = malloc(sizeof(Contact));
            if(new_contact == NULL) {
                printf("Error: Out of memory\n");
                continue;
            }

            printf("Enter name: ");
            scanf("%s", new_contact->name);

            printf("Enter phone number: ");
            scanf("%s", new_contact->phone);

            printf("Enter address: ");
            scanf("%s", new_contact->address);

            contacts = realloc(contacts, sizeof(Contact) * (num_contacts + 1));
            if(contacts == NULL) {
                printf("Error: Out of memory\n");
                free(new_contact);
                continue;
            }

            contacts[num_contacts] = *new_contact;
            free(new_contact);
            num_contacts++;
        } else if(choice == 2) {
            printf("Enter name to search for: ");
            char name[MAX_NAME_LEN];
            scanf("%s", name);

            Contact *found_contact = NULL;
            for(int i = 0; i < num_contacts; i++) {
                if(strcmp(contacts[i].name, name) == 0) {
                    found_contact = &contacts[i];
                    break;
                }
            }

            if(found_contact!= NULL) {
                print_contact(found_contact);
            } else {
                printf("Contact not found\n");
            }
        } else if(choice == 3) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    free(contacts);
    return 0;
}