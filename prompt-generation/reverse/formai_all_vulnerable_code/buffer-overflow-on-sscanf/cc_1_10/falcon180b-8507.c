//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20

typedef struct contact {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Contact;

int main() {
    Contact contacts[MAX_CONTACTS];
    int num_contacts = 0;
    char input[80];
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
    int i;

    printf("Welcome to the Phone Book!\n");

    // Read in contacts
    while (fgets(input, sizeof(input), stdin)!= NULL && num_contacts < MAX_CONTACTS) {
        if (sscanf(input, "%s %s", name, number) == 2) {
            strcpy(contacts[num_contacts].name, name);
            strcpy(contacts[num_contacts].number, number);
            num_contacts++;
        } else {
            printf("Invalid input: %s\n", input);
        }
    }

    // Sort contacts alphabetically
    for (i = 0; i < num_contacts - 1; i++) {
        int j;
        for (j = i + 1; j < num_contacts; j++) {
            if (strcmp(contacts[i].name, contacts[j].name) > 0) {
                Contact temp = contacts[i];
                contacts[i] = contacts[j];
                contacts[j] = temp;
            }
        }
    }

    // Print contacts
    printf("\nContacts:\n");
    for (i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", contacts[i].name, contacts[i].number);
    }

    return 0;
}