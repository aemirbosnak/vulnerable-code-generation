//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 64
#define MAX_EMAIL_LEN 256

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

int main(void) {
    FILE *file = fopen("contacts.txt", "r");
    int num_contacts = 0;
    contact *contacts = NULL;

    if (file == NULL) {
        printf("Error: contacts.txt not found.\n");
        return 1;
    }

    // Count the number of contacts in the file
    while (fscanf(file, "%s %s\n", contacts[num_contacts].name, contacts[num_contacts].email)!= EOF) {
        num_contacts++;
    }

    rewind(file);

    // Allocate memory for the contacts
    contacts = malloc(num_contacts * sizeof(contact));

    // Read the contacts from the file
    for (int i = 0; i < num_contacts; i++) {
        fscanf(file, "%s %s\n", contacts[i].name, contacts[i].email);
    }

    fclose(file);

    // Print the list of contacts
    printf("Mailing List:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s <%s>\n", contacts[i].name, contacts[i].email);
    }

    // Free memory
    free(contacts);

    return 0;
}