//Code Llama-13B DATASET v1.0 Category: Data recovery tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char name[32];
    char email[64];
    char phone[16];
} Contact;

void print_contact(Contact *contact) {
    printf("Name: %s\n", contact->name);
    printf("Email: %s\n", contact->email);
    printf("Phone: %s\n", contact->phone);
}

int main(int argc, char *argv[]) {
    Contact *contacts = NULL;
    int num_contacts = 0;
    int i;

    // Parse the command-line arguments
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--help") == 0) {
            printf("Usage: %s [--help] <contact1> <contact2> ... <contactN>\n", argv[0]);
            return 0;
        }

        Contact *contact = (Contact *) malloc(sizeof(Contact));
        if (contact == NULL) {
            fprintf(stderr, "Failed to allocate memory for contact\n");
            return 1;
        }

        strncpy(contact->name, argv[i], 32);
        contact->name[32] = '\0';

        if (i + 1 < argc) {
            strncpy(contact->email, argv[i + 1], 64);
            contact->email[64] = '\0';
            i++;
        }

        if (i + 1 < argc) {
            strncpy(contact->phone, argv[i + 1], 16);
            contact->phone[16] = '\0';
            i++;
        }

        contacts = realloc(contacts, (num_contacts + 1) * sizeof(Contact));
        if (contacts == NULL) {
            fprintf(stderr, "Failed to reallocate memory for contacts\n");
            return 1;
        }

        contacts[num_contacts] = *contact;
        num_contacts++;
    }

    // Print the contacts
    for (i = 0; i < num_contacts; i++) {
        print_contact(&contacts[i]);
    }

    // Free the memory
    for (i = 0; i < num_contacts; i++) {
        free(contacts[i].name);
        free(contacts[i].email);
        free(contacts[i].phone);
    }
    free(contacts);

    return 0;
}