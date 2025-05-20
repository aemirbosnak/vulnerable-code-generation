//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} PhoneBookEntry;

PhoneBookEntry phoneBook[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    printf("Enter name (up to %d characters): ", MAX_NAME_LEN - 1);
    scanf("%s", phoneBook[numEntries].name);

    printf("Enter phone number (up to %d characters): ", MAX_NUMBER_LEN - 1);
    scanf("%s", phoneBook[numEntries].number);

    numEntries++;
}

void searchEntry() {
    char searchName[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, searchName) == 0) {
            printf("Name: %s\nPhone number: %s\n", phoneBook[i].name, phoneBook[i].number);
        }
    }
}

int main() {
    printf("Welcome to the Phone Book!\n");

    while (1) {
        printf("1. Add entry\n2. Search entry\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addEntry();
            break;

        case 2:
            searchEntry();
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}