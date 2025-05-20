//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 15

typedef struct contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

int main() {
    FILE *phonebook;
    int num_contacts = 0;
    Contact *contacts = NULL;

    phonebook = fopen("phonebook.txt", "r");
    if (phonebook == NULL) {
        printf("Error opening phonebook file.\n");
        exit(1);
    }

    while (fscanf(phonebook, "%s %s\n", contacts[num_contacts].name, contacts[num_contacts].number)!= EOF) {
        num_contacts++;
        contacts = realloc(contacts, sizeof(Contact) * num_contacts);
    }

    fclose(phonebook);

    char search_name[MAX_NAME_LENGTH];
    printf("Enter a name to search for: ");
    scanf("%s", search_name);

    tolower(search_name); // convert to lowercase for case-insensitive search

    int found = 0;
    for (int i = 0; i < num_contacts; i++) {
        if (strcmp(contacts[i].name, search_name) == 0) {
            printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
            found = 1;
        }
    }

    if (!found) {
        printf("No contact found with that name.\n");
    }

    free(contacts);
    return 0;
}