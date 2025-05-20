//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_NUMBER_LENGTH 20
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char number[MAX_NUMBER_LENGTH];
} Entry;

Entry phoneBook[MAX_ENTRIES];
int numEntries = 0;

void addEntry() {
    printf("Enter name: ");
    scanf("%s", phoneBook[numEntries].name);
    printf("Enter number: ");
    scanf("%s", phoneBook[numEntries].number);
    numEntries++;
}

void viewEntry(int index) {
    printf("Name: %s\n", phoneBook[index].name);
    printf("Number: %s\n", phoneBook[index].number);
}

void deleteEntry(int index) {
    for (int i = index; i < numEntries - 1; i++) {
        strcpy(phoneBook[i].name, phoneBook[i+1].name);
        strcpy(phoneBook[i].number, phoneBook[i+1].number);
    }
    numEntries--;
}

void searchEntry(char* name) {
    int found = 0;
    for (int i = 0; i < numEntries; i++) {
        if (strcmp(phoneBook[i].name, name) == 0) {
            viewEntry(i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("No entry found.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Add entry\n");
        printf("2. View entry\n");
        printf("3. Delete entry\n");
        printf("4. Search entry\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                printf("Enter index: ");
                scanf("%d", &choice);
                viewEntry(choice - 1);
                break;
            case 3:
                printf("Enter index: ");
                scanf("%d", &choice);
                deleteEntry(choice - 1);
                break;
            case 4:
                printf("Enter name: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);
                searchEntry(name);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}