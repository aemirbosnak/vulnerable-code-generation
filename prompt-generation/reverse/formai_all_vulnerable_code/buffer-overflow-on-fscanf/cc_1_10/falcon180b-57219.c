//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} contact;

int main() {
    FILE *file;
    contact contacts[100];
    int num_contacts = 0;

    // Open file for reading
    file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("Error: could not open contacts file.\n");
        return 1;
    }

    // Read in contacts
    while (fscanf(file, "%s %s\n", contacts[num_contacts].name, contacts[num_contacts].email)!= EOF) {
        num_contacts++;
    }
    fclose(file);

    // Display contacts
    printf("Contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s (%s)\n", contacts[i].name, contacts[i].email);
    }

    // Add a new contact
    printf("\nEnter name and email of new contact:\n");
    scanf("%s %s", contacts[num_contacts].name, contacts[num_contacts].email);
    num_contacts++;

    // Open file for writing
    file = fopen("contacts.txt", "w");
    if (file == NULL) {
        printf("Error: could not open contacts file for writing.\n");
        return 1;
    }

    // Write out contacts
    for (int i = 0; i < num_contacts; i++) {
        fprintf(file, "%s %s\n", contacts[i].name, contacts[i].email);
    }
    fclose(file);

    return 0;
}