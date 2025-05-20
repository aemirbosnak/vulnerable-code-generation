//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

int main() {
    FILE *phonebook_file = fopen("phonebook.txt", "r");

    if (phonebook_file == NULL) {
        printf("Error: Phonebook file not found.\n");
        return 1;
    }

    Contact phonebook[MAX_CONTACTS];
    int contact_count = 0;

    while (fscanf(phonebook_file, "%s %s", phonebook[contact_count].name, phonebook[contact_count].number)!= EOF) {
        contact_count++;
    }

    fclose(phonebook_file);

    char search_name[MAX_NAME_LENGTH];
    printf("Enter name to search for: ");
    scanf("%s", search_name);

    Contact *contact = NULL;
    for (int i = 0; i < contact_count; i++) {
        if (strcmp(phonebook[i].name, search_name) == 0) {
            contact = &phonebook[i];
            break;
        }
    }

    if (contact == NULL) {
        printf("Contact not found.\n");
    } else {
        printf("Name: %s\n", contact->name);
        printf("Number: %s\n", contact->number);
    }

    return 0;
}