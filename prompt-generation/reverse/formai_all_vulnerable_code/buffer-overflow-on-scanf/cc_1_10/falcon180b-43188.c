//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LEN 50
#define MAX_NUMBER_LEN 15

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} Entry;

Entry phonebook[MAX_ENTRIES];
int numEntries = 0;

void addEntry(const char* name, const char* number) {
    if(numEntries >= MAX_ENTRIES) {
        printf("Phone book is full.\n");
        return;
    }
    strcpy(phonebook[numEntries].name, name);
    strcpy(phonebook[numEntries].number, number);
    numEntries++;
}

void searchEntry(const char* name) {
    int i;
    for(i=0; i<numEntries; i++) {
        if(strcmp(phonebook[i].name, name) == 0) {
            printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
            return;
        }
    }
    printf("Entry not found.\n");
}

void deleteEntry(const char* name) {
    int i;
    for(i=0; i<numEntries; i++) {
        if(strcmp(phonebook[i].name, name) == 0) {
            memset(&phonebook[i], 0, sizeof(Entry));
            numEntries--;
            return;
        }
    }
    printf("Entry not found.\n");
}

void printEntries() {
    int i;
    for(i=0; i<numEntries; i++) {
        printf("Name: %s\nNumber: %s\n", phonebook[i].name, phonebook[i].number);
    }
}

int main() {
    char choice;
    do {
        printf("Phone book menu:\n");
        printf("1. Add entry\n2. Search entry\n3. Delete entry\n4. Print entries\n5. Exit\n");
        scanf("%c", &choice);
        switch(choice) {
            case '1': {
                char name[MAX_NAME_LEN];
                char number[MAX_NUMBER_LEN];
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                addEntry(name, number);
                break;
            }
            case '2': {
                char name[MAX_NAME_LEN];
                printf("Enter name: ");
                scanf("%s", name);
                searchEntry(name);
                break;
            }
            case '3': {
                char name[MAX_NAME_LEN];
                printf("Enter name: ");
                scanf("%s", name);
                deleteEntry(name);
                break;
            }
            case '4': {
                printEntries();
                break;
            }
            case '5': {
                exit(0);
            }
            default: {
                printf("Invalid choice.\n");
            }
        }
    } while(1);
    return 0;
}