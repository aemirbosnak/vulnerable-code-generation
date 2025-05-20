//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: creative
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
    contact list[100];
    int num_contacts = 0;

    // Open mailing list file
    file = fopen("mailing_list.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open mailing list file.\n");
        return 1;
    }

    // Read contacts from file
    while (fscanf(file, "%s %s\n", list[num_contacts].name, list[num_contacts].email)!= EOF) {
        num_contacts++;
    }

    fclose(file);

    // Print list of contacts
    printf("Mailing list:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("Name: %s\nEmail: %s\n\n", list[i].name, list[i].email);
    }

    // Add a new contact
    contact new_contact;
    printf("Enter name: ");
    fgets(new_contact.name, MAX_NAME_LEN, stdin);
    printf("Enter email: ");
    fgets(new_contact.email, MAX_EMAIL_LEN, stdin);

    // Append new contact to file
    file = fopen("mailing_list.txt", "a");
    if (file == NULL) {
        printf("Error: Could not open mailing list file for writing.\n");
        return 1;
    }

    fprintf(file, "%s %s\n", new_contact.name, new_contact.email);

    fclose(file);

    printf("New contact added to mailing list.\n");

    return 0;
}