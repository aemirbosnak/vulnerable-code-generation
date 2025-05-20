//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 1000
#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 20

typedef struct contact {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} Contact;

int main() {
    FILE *f;
    Contact contacts[MAX_CONTACTS];
    int count = 0;

    // Load contacts from file
    f = fopen("phonebook.txt", "r");
    if (f == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fscanf(f, "%s %s\n", contacts[count].name, contacts[count].number)!= EOF) {
        count++;
        if (count >= MAX_CONTACTS) {
            printf("Error: Maximum number of contacts reached.\n");
            exit(1);
        }
    }

    fclose(f);

    // Search for contact
    char name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(name, contacts[i].name) == 0) {
            printf("Name: %s\nNumber: %s\n", contacts[i].name, contacts[i].number);
            break;
        }
    }

    if (i == count) {
        printf("Contact not found.\n");
    }

    return 0;
}