//FormAI DATASET v1.0 Category: Phone Book ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_SIZE 50
#define MAX_NUMBER_SIZE 10
#define MAX_ENTRIES 100

struct PhoneBookEntry {
    char name[MAX_NAME_SIZE];
    char number[MAX_NUMBER_SIZE];
};

struct PhoneBook {
    int numEntries;
    struct PhoneBookEntry entries[MAX_ENTRIES];
};

int chooseOption();
void addEntry(struct PhoneBook* pb);
void displayEntries(struct PhoneBook* pb);
void searchEntry(struct PhoneBook* pb);
void deleteEntry(struct PhoneBook* pb);

int main() {
    struct PhoneBook pb;
    pb.numEntries = 0;

    while (1) {
        printf("1. Add Entry\n");
        printf("2. Display Entries\n");
        printf("3. Search Entry\n");
        printf("4. Delete Entry\n");
        printf("5. Exit\n");

        int option = chooseOption();

        switch (option) {
            case 1:
                addEntry(&pb);
                break;
            case 2:
                displayEntries(&pb);
                break;
            case 3:
                searchEntry(&pb);
                break;
            case 4:
                deleteEntry(&pb);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    }

    return 0;
}

int chooseOption() {
    printf("Enter option: ");
    int option;
    scanf("%d", &option);
    return option;
}

void addEntry(struct PhoneBook* pb) {
    printf("Enter name: ");
    scanf("%s", pb->entries[pb->numEntries].name);
    printf("Enter number: ");
    scanf("%s", pb->entries[pb->numEntries].number);

    pb->numEntries++;

    printf("Entry added successfully.\n");
}

void displayEntries(struct PhoneBook* pb) {
    printf("Phone book entries:\n");

    for (int i = 0; i < pb->numEntries; i++) {
        printf("%s\t%s\n", pb->entries[i].name, pb->entries[i].number);
    }
}

void searchEntry(struct PhoneBook* pb) {
    printf("Enter name to search: ");
    char searchName[MAX_NAME_SIZE];
    scanf("%s", searchName);

    for (int i = 0; i < pb->numEntries; i++) {
        if (strcmp(pb->entries[i].name, searchName) == 0) {
            printf("%s\t%s\n", pb->entries[i].name, pb->entries[i].number);
            return;
        }
    }

    printf("No results found for %s.\n", searchName);
}

void deleteEntry(struct PhoneBook* pb) {
    printf("Enter name to delete: ");
    char searchName[MAX_NAME_SIZE];
    scanf("%s", searchName);

    for (int i = 0; i < pb->numEntries; i++) {
        if (strcmp(pb->entries[i].name, searchName) == 0) {
            for (int j = i; j < pb->numEntries - 1; j++) {
                strcpy(pb->entries[j].name, pb->entries[j+1].name);
                strcpy(pb->entries[j].number, pb->entries[j+1].number);
            }

            pb->numEntries--;

            printf("%s successfully deleted from phone book.\n", searchName);
            return;
        }
    }

    printf("No entry found for %s.\n", searchName);
}