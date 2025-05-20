//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_EMAILS 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
} contact;

int main() {
    int num_contacts;
    contact *contacts;

    // Get number of contacts from user
    printf("Enter number of contacts: ");
    scanf("%d", &num_contacts);

    // Allocate memory for contacts array
    contacts = (contact *) malloc(num_contacts * sizeof(contact));

    // Get contact information from user
    for (int i = 0; i < num_contacts; i++) {
        printf("Enter name for contact %d: ", i+1);
        scanf("%s", contacts[i].name);

        printf("Enter email for contact %d: ", i+1);
        scanf("%s", contacts[i].email);
    }

    // Sort contacts alphabetically by name
    for (int i = 0; i < num_contacts-1; i++) {
        for (int j = i+1; j < num_contacts; j++) {
            if (strcmp(contacts[i].name, contacts[j].name) > 0) {
                contact temp = contacts[i];
                contacts[i] = contacts[j];
                contacts[j] = temp;
            }
        }
    }

    // Print sorted contact list
    printf("\nSorted contact list:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].email);
    }

    // Free memory allocated for contacts array
    free(contacts);

    return 0;
}