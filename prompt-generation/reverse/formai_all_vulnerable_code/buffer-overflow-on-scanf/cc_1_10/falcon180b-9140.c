//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

// Phone book entry structure
typedef struct {
    char name[50];
    char phone[15];
    char email[50];
} Entry;

int main() {
    Entry phonebook[MAX_ENTRIES];
    int numEntries = 0;

    // Add a new entry
    char name[50];
    char phone[15];
    char email[50];

    printf("Enter name: ");
    scanf("%s", name);
    strcpy(phonebook[numEntries].name, name);

    printf("Enter phone number: ");
    scanf("%s", phone);
    strcpy(phonebook[numEntries].phone, phone);

    printf("Enter email: ");
    scanf("%s", email);
    strcpy(phonebook[numEntries].email, email);

    numEntries++;

    // Search for an entry
    char searchName[50];

    printf("Enter name to search for: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phonebook[i].name, searchName) == 0) {
            printf("Name: %s\n", phonebook[i].name);
            printf("Phone number: %s\n", phonebook[i].phone);
            printf("Email: %s\n", phonebook[i].email);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Entry not found.\n");
    }

    return 0;
}