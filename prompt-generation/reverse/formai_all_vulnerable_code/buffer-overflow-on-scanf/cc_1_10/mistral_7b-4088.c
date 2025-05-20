//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 25

typedef struct {
    char name[50];
    char phone[20];
} Entry;

void createEntry(Entry* entry, char* name, char* phone) {
    strcpy(entry->name, name);
    strcpy(entry->phone, phone);
}

void displayEntry(const Entry* entry) {
    printf("----------------------------------------\n");
    printf("| Name         : %s |\n", entry->name);
    printf("| Phone Number : %s |\n", entry->phone);
    printf("----------------------------------------\n");
}

void searchEntry(const Entry entries[], char name[], int size) {
    int index = -1;

    for (int i = 0; i < size; ++i) {
        if (strcmp(entries[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        displayEntry(&entries[index]);
    } else {
        printf("----------------------------------------\n");
        printf("| Name not found!                        |\n");
        printf("----------------------------------------\n");
    }
}

int main() {
    Entry phoneBook[MAX_ENTRIES];
    int numEntries = 0;

    while (numEntries < MAX_ENTRIES && fgetc(stdin) != EOF) {
        char name[50], phone[20];

        printf("Enter a name: ");
        scanf("%s", name);

        printf("Enter a phone number: ");
        scanf("%s", phone);

        createEntry(&phoneBook[numEntries], name, phone);
        ++numEntries;
    }

    char searchName[50];

    while (1) {
        printf("Enter a name to search for or type 'quit' to exit: ");
        scanf("%s", searchName);

        if (strcmp(searchName, "quit") == 0) {
            break;
        }

        searchEntry(phoneBook, searchName, numEntries);
    }

    return 0;
}