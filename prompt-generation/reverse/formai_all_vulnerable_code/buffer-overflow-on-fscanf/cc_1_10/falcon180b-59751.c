//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char email[MAX_EMAIL_LENGTH];
    char name[MAX_NAME_LENGTH];
} Contact;

int main() {
    FILE *file;
    Contact contacts[100];
    int num_contacts = 0;
    char input[100];

    // Open the contacts file
    file = fopen("contacts.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open contacts file.\n");
        exit(1);
    }

    // Read in each contact
    while (fscanf(file, "%s %s\n", contacts[num_contacts].email, contacts[num_contacts].name)!= EOF) {
        num_contacts++;
    }

    // Print the list of contacts
    printf("Contacts:\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].email);
    }

    // Close the contacts file
    fclose(file);

    // Allow the user to add a new contact
    printf("\nDo you want to add a new contact? (y/n) ");
    fgets(input, sizeof(input), stdin);
    if (strcmp(input, "y\n") == 0) {
        printf("Enter the name of the new contact: ");
        fgets(input, sizeof(input), stdin);
        strcpy(contacts[num_contacts].name, input);
        printf("Enter the email address of the new contact: ");
        fgets(input, sizeof(input), stdin);
        strcpy(contacts[num_contacts].email, input);
        num_contacts++;

        // Open the contacts file in append mode
        file = fopen("contacts.txt", "a");
        if (file == NULL) {
            printf("Error: Could not open contacts file.\n");
            exit(1);
        }

        // Write the new contact to the file
        fprintf(file, "%s %s\n", contacts[num_contacts - 1].email, contacts[num_contacts - 1].name);

        // Close the contacts file
        fclose(file);

        printf("\nNew contact added.\n");
    }

    return 0;
}