//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000

typedef struct {
    char name[50];
    char number[15];
} Entry;

Entry phonebook[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    numEntries++;
    printf("Enter name: ");
    scanf("%s", phonebook[numEntries-1].name);
    printf("Enter number: ");
    scanf("%s", phonebook[numEntries-1].number);
}

void searchEntry() {
    char name[50];
    printf("Enter name to search: ");
    scanf("%s", name);
    int i;
    for (i=0; i<numEntries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("%s - %s\n", phonebook[i].name, phonebook[i].number);
        }
    }
}

void deleteEntry() {
    char name[50];
    printf("Enter name to delete: ");
    scanf("%s", name);
    int i;
    for (i=0; i<numEntries; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            memmove(&phonebook[i], &phonebook[i+1], (numEntries-i-1)*sizeof(Entry));
            numEntries--;
            printf("%s deleted from phonebook.\n", name);
        }
    }
}

void printPhonebook() {
    int i;
    for (i=0; i<numEntries; i++) {
        printf("%s - %s\n", phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Print phonebook\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                searchEntry();
                break;
            case 3:
                deleteEntry();
                break;
            case 4:
                printPhonebook();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}