//Falcon-180B DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_EMAIL_LENGTH 256

typedef struct {
    char name[MAX_EMAIL_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} contact;

int main() {
    FILE *file;
    contact *contacts = NULL;
    int num_contacts = 0;
    char line[MAX_LINE_LENGTH];

    // Open file
    file = fopen("contacts.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read file
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        // Parse line
        char *name = strtok(line, ",");
        name[strcspn(name, "\n")] = '\0'; // Remove newline character
        char *email = strtok(NULL, ",");
        email[strcspn(email, "\n")] = '\0'; // Remove newline character

        // Add contact to list
        contacts = realloc(contacts, sizeof(contact) * ++num_contacts);
        strcpy(contacts[num_contacts-1].name, name);
        strcpy(contacts[num_contacts-1].email, email);
    }

    // Close file
    fclose(file);

    // Print list
    printf("Name\tEmail\n");
    for (int i = 0; i < num_contacts; i++) {
        printf("%s\t%s\n", contacts[i].name, contacts[i].email);
    }

    // Free memory
    for (int i = 0; i < num_contacts; i++) {
        free(contacts[i].name);
        free(contacts[i].email);
    }
    free(contacts);

    return 0;
}